// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
`timescale 1ns/1ps
module rijndaelDecrypt_hls_BUS_s_axi
#(parameter
    C_S_AXI_ADDR_WIDTH = 9,
    C_S_AXI_DATA_WIDTH = 32
)(
    input  wire                          ACLK,
    input  wire                          ARESET,
    input  wire                          ACLK_EN,
    input  wire [C_S_AXI_ADDR_WIDTH-1:0] AWADDR,
    input  wire                          AWVALID,
    output wire                          AWREADY,
    input  wire [C_S_AXI_DATA_WIDTH-1:0] WDATA,
    input  wire [C_S_AXI_DATA_WIDTH/8-1:0] WSTRB,
    input  wire                          WVALID,
    output wire                          WREADY,
    output wire [1:0]                    BRESP,
    output wire                          BVALID,
    input  wire                          BREADY,
    input  wire [C_S_AXI_ADDR_WIDTH-1:0] ARADDR,
    input  wire                          ARVALID,
    output wire                          ARREADY,
    output wire [C_S_AXI_DATA_WIDTH-1:0] RDATA,
    output wire [1:0]                    RRESP,
    output wire                          RVALID,
    input  wire                          RREADY,
    output wire                          interrupt,
    input  wire [3:0]                    ct_address0,
    input  wire                          ct_ce0,
    output wire [7:0]                    ct_q0,
    input  wire [3:0]                    pt_address0,
    input  wire                          pt_ce0,
    input  wire                          pt_we0,
    input  wire [7:0]                    pt_d0,
    input  wire [5:0]                    rk_address0,
    input  wire                          rk_ce0,
    output wire [31:0]                   rk_q0,
    output wire                          ap_start,
    input  wire                          ap_done,
    input  wire                          ap_ready,
    input  wire                          ap_idle
);
//------------------------Address Info-------------------
// 0x000 : Control signals
//         bit 0  - ap_start (Read/Write/COH)
//         bit 1  - ap_done (Read/COR)
//         bit 2  - ap_idle (Read)
//         bit 3  - ap_ready (Read)
//         bit 7  - auto_restart (Read/Write)
//         others - reserved
// 0x004 : Global Interrupt Enable Register
//         bit 0  - Global Interrupt Enable (Read/Write)
//         others - reserved
// 0x008 : IP Interrupt Enable Register (Read/Write)
//         bit 0  - enable ap_done interrupt (Read/Write)
//         bit 1  - enable ap_ready interrupt (Read/Write)
//         others - reserved
// 0x00c : IP Interrupt Status Register (Read/TOW)
//         bit 0  - ap_done (COR/TOW)
//         bit 1  - ap_ready (COR/TOW)
//         others - reserved
// 0x010 ~
// 0x01f : Memory 'ct' (16 * 8b)
//         Word n : bit [ 7: 0] - ct[4n]
//                  bit [15: 8] - ct[4n+1]
//                  bit [23:16] - ct[4n+2]
//                  bit [31:24] - ct[4n+3]
// 0x020 ~
// 0x02f : Memory 'pt' (16 * 8b)
//         Word n : bit [ 7: 0] - pt[4n]
//                  bit [15: 8] - pt[4n+1]
//                  bit [23:16] - pt[4n+2]
//                  bit [31:24] - pt[4n+3]
// 0x100 ~
// 0x1ff : Memory 'rk' (44 * 32b)
//         Word n : bit [31:0] - rk[n]
// (SC = Self Clear, COR = Clear on Read, TOW = Toggle on Write, COH = Clear on Handshake)

//------------------------Parameter----------------------
localparam
    ADDR_AP_CTRL = 9'h000,
    ADDR_GIE     = 9'h004,
    ADDR_IER     = 9'h008,
    ADDR_ISR     = 9'h00c,
    ADDR_CT_BASE = 9'h010,
    ADDR_CT_HIGH = 9'h01f,
    ADDR_PT_BASE = 9'h020,
    ADDR_PT_HIGH = 9'h02f,
    ADDR_RK_BASE = 9'h100,
    ADDR_RK_HIGH = 9'h1ff,
    WRIDLE       = 2'd0,
    WRDATA       = 2'd1,
    WRRESP       = 2'd2,
    WRRESET      = 2'd3,
    RDIDLE       = 2'd0,
    RDDATA       = 2'd1,
    RDRESET      = 2'd2,
    ADDR_BITS                = 9;

//------------------------Local signal-------------------
    reg  [1:0]                    wstate = WRRESET;
    reg  [1:0]                    wnext;
    reg  [ADDR_BITS-1:0]          waddr;
    wire [C_S_AXI_DATA_WIDTH-1:0] wmask;
    wire                          aw_hs;
    wire                          w_hs;
    reg  [1:0]                    rstate = RDRESET;
    reg  [1:0]                    rnext;
    reg  [C_S_AXI_DATA_WIDTH-1:0] rdata;
    wire                          ar_hs;
    wire [ADDR_BITS-1:0]          raddr;
    // internal registers
    reg                           int_ap_idle;
    reg                           int_ap_ready;
    reg                           int_ap_done = 1'b0;
    reg                           int_ap_start = 1'b0;
    reg                           int_auto_restart = 1'b0;
    reg                           int_gie = 1'b0;
    reg  [1:0]                    int_ier = 2'b0;
    reg  [1:0]                    int_isr = 2'b0;
    // memory signals
    wire [1:0]                    int_ct_address0;
    wire                          int_ct_ce0;
    wire                          int_ct_we0;
    wire [3:0]                    int_ct_be0;
    wire [31:0]                   int_ct_d0;
    wire [31:0]                   int_ct_q0;
    wire [1:0]                    int_ct_address1;
    wire                          int_ct_ce1;
    wire                          int_ct_we1;
    wire [3:0]                    int_ct_be1;
    wire [31:0]                   int_ct_d1;
    wire [31:0]                   int_ct_q1;
    reg                           int_ct_read;
    reg                           int_ct_write;
    reg  [1:0]                    int_ct_shift;
    wire [1:0]                    int_pt_address0;
    wire                          int_pt_ce0;
    wire                          int_pt_we0;
    wire [3:0]                    int_pt_be0;
    wire [31:0]                   int_pt_d0;
    wire [31:0]                   int_pt_q0;
    wire [1:0]                    int_pt_address1;
    wire                          int_pt_ce1;
    wire                          int_pt_we1;
    wire [3:0]                    int_pt_be1;
    wire [31:0]                   int_pt_d1;
    wire [31:0]                   int_pt_q1;
    reg                           int_pt_read;
    reg                           int_pt_write;
    reg  [1:0]                    int_pt_shift;
    wire [5:0]                    int_rk_address0;
    wire                          int_rk_ce0;
    wire                          int_rk_we0;
    wire [3:0]                    int_rk_be0;
    wire [31:0]                   int_rk_d0;
    wire [31:0]                   int_rk_q0;
    wire [5:0]                    int_rk_address1;
    wire                          int_rk_ce1;
    wire                          int_rk_we1;
    wire [3:0]                    int_rk_be1;
    wire [31:0]                   int_rk_d1;
    wire [31:0]                   int_rk_q1;
    reg                           int_rk_read;
    reg                           int_rk_write;

//------------------------Instantiation------------------
// int_ct
rijndaelDecrypt_hls_BUS_s_axi_ram #(
    .BYTES    ( 4 ),
    .DEPTH    ( 4 )
) int_ct (
    .clk0     ( ACLK ),
    .address0 ( int_ct_address0 ),
    .ce0      ( int_ct_ce0 ),
    .we0      ( int_ct_we0 ),
    .be0      ( int_ct_be0 ),
    .d0       ( int_ct_d0 ),
    .q0       ( int_ct_q0 ),
    .clk1     ( ACLK ),
    .address1 ( int_ct_address1 ),
    .ce1      ( int_ct_ce1 ),
    .we1      ( int_ct_we1 ),
    .be1      ( int_ct_be1 ),
    .d1       ( int_ct_d1 ),
    .q1       ( int_ct_q1 )
);
// int_pt
rijndaelDecrypt_hls_BUS_s_axi_ram #(
    .BYTES    ( 4 ),
    .DEPTH    ( 4 )
) int_pt (
    .clk0     ( ACLK ),
    .address0 ( int_pt_address0 ),
    .ce0      ( int_pt_ce0 ),
    .we0      ( int_pt_we0 ),
    .be0      ( int_pt_be0 ),
    .d0       ( int_pt_d0 ),
    .q0       ( int_pt_q0 ),
    .clk1     ( ACLK ),
    .address1 ( int_pt_address1 ),
    .ce1      ( int_pt_ce1 ),
    .we1      ( int_pt_we1 ),
    .be1      ( int_pt_be1 ),
    .d1       ( int_pt_d1 ),
    .q1       ( int_pt_q1 )
);
// int_rk
rijndaelDecrypt_hls_BUS_s_axi_ram #(
    .BYTES    ( 4 ),
    .DEPTH    ( 44 )
) int_rk (
    .clk0     ( ACLK ),
    .address0 ( int_rk_address0 ),
    .ce0      ( int_rk_ce0 ),
    .we0      ( int_rk_we0 ),
    .be0      ( int_rk_be0 ),
    .d0       ( int_rk_d0 ),
    .q0       ( int_rk_q0 ),
    .clk1     ( ACLK ),
    .address1 ( int_rk_address1 ),
    .ce1      ( int_rk_ce1 ),
    .we1      ( int_rk_we1 ),
    .be1      ( int_rk_be1 ),
    .d1       ( int_rk_d1 ),
    .q1       ( int_rk_q1 )
);


//------------------------AXI write fsm------------------
assign AWREADY = (wstate == WRIDLE);
assign WREADY  = (wstate == WRDATA) && (!ar_hs);
assign BRESP   = 2'b00;  // OKAY
assign BVALID  = (wstate == WRRESP);
assign wmask   = { {8{WSTRB[3]}}, {8{WSTRB[2]}}, {8{WSTRB[1]}}, {8{WSTRB[0]}} };
assign aw_hs   = AWVALID & AWREADY;
assign w_hs    = WVALID & WREADY;

// wstate
always @(posedge ACLK) begin
    if (ARESET)
        wstate <= WRRESET;
    else if (ACLK_EN)
        wstate <= wnext;
end

// wnext
always @(*) begin
    case (wstate)
        WRIDLE:
            if (AWVALID)
                wnext = WRDATA;
            else
                wnext = WRIDLE;
        WRDATA:
            if (w_hs)
                wnext = WRRESP;
            else
                wnext = WRDATA;
        WRRESP:
            if (BREADY)
                wnext = WRIDLE;
            else
                wnext = WRRESP;
        default:
            wnext = WRIDLE;
    endcase
end

// waddr
always @(posedge ACLK) begin
    if (ACLK_EN) begin
        if (aw_hs)
            waddr <= AWADDR[ADDR_BITS-1:0];
    end
end

//------------------------AXI read fsm-------------------
assign ARREADY = (rstate == RDIDLE);
assign RDATA   = rdata;
assign RRESP   = 2'b00;  // OKAY
assign RVALID  = (rstate == RDDATA) & !int_ct_read & !int_pt_read & !int_rk_read;
assign ar_hs   = ARVALID & ARREADY;
assign raddr   = ARADDR[ADDR_BITS-1:0];

// rstate
always @(posedge ACLK) begin
    if (ARESET)
        rstate <= RDRESET;
    else if (ACLK_EN)
        rstate <= rnext;
end

// rnext
always @(*) begin
    case (rstate)
        RDIDLE:
            if (ARVALID)
                rnext = RDDATA;
            else
                rnext = RDIDLE;
        RDDATA:
            if (RREADY & RVALID)
                rnext = RDIDLE;
            else
                rnext = RDDATA;
        default:
            rnext = RDIDLE;
    endcase
end

// rdata
always @(posedge ACLK) begin
    if (ACLK_EN) begin
        if (ar_hs) begin
            rdata <= 'b0;
            case (raddr)
                ADDR_AP_CTRL: begin
                    rdata[0] <= int_ap_start;
                    rdata[1] <= int_ap_done;
                    rdata[2] <= int_ap_idle;
                    rdata[3] <= int_ap_ready;
                    rdata[7] <= int_auto_restart;
                end
                ADDR_GIE: begin
                    rdata <= int_gie;
                end
                ADDR_IER: begin
                    rdata <= int_ier;
                end
                ADDR_ISR: begin
                    rdata <= int_isr;
                end
            endcase
        end
        else if (int_ct_read) begin
            rdata <= int_ct_q1;
        end
        else if (int_pt_read) begin
            rdata <= int_pt_q1;
        end
        else if (int_rk_read) begin
            rdata <= int_rk_q1;
        end
    end
end


//------------------------Register logic-----------------
assign interrupt = int_gie & (|int_isr);
assign ap_start  = int_ap_start;
// int_ap_start
always @(posedge ACLK) begin
    if (ARESET)
        int_ap_start <= 1'b0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_AP_CTRL && WSTRB[0] && WDATA[0])
            int_ap_start <= 1'b1;
        else if (ap_ready)
            int_ap_start <= int_auto_restart; // clear on handshake/auto restart
    end
end

// int_ap_done
always @(posedge ACLK) begin
    if (ARESET)
        int_ap_done <= 1'b0;
    else if (ACLK_EN) begin
        if (ap_done)
            int_ap_done <= 1'b1;
        else if (ar_hs && raddr == ADDR_AP_CTRL)
            int_ap_done <= 1'b0; // clear on read
    end
end

// int_ap_idle
always @(posedge ACLK) begin
    if (ARESET)
        int_ap_idle <= 1'b0;
    else if (ACLK_EN) begin
            int_ap_idle <= ap_idle;
    end
end

// int_ap_ready
always @(posedge ACLK) begin
    if (ARESET)
        int_ap_ready <= 1'b0;
    else if (ACLK_EN) begin
            int_ap_ready <= ap_ready;
    end
end

// int_auto_restart
always @(posedge ACLK) begin
    if (ARESET)
        int_auto_restart <= 1'b0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_AP_CTRL && WSTRB[0])
            int_auto_restart <=  WDATA[7];
    end
end

// int_gie
always @(posedge ACLK) begin
    if (ARESET)
        int_gie <= 1'b0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_GIE && WSTRB[0])
            int_gie <= WDATA[0];
    end
end

// int_ier
always @(posedge ACLK) begin
    if (ARESET)
        int_ier <= 1'b0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_IER && WSTRB[0])
            int_ier <= WDATA[1:0];
    end
end

// int_isr[0]
always @(posedge ACLK) begin
    if (ARESET)
        int_isr[0] <= 1'b0;
    else if (ACLK_EN) begin
        if (int_ier[0] & ap_done)
            int_isr[0] <= 1'b1;
        else if (w_hs && waddr == ADDR_ISR && WSTRB[0])
            int_isr[0] <= int_isr[0] ^ WDATA[0]; // toggle on write
    end
end

// int_isr[1]
always @(posedge ACLK) begin
    if (ARESET)
        int_isr[1] <= 1'b0;
    else if (ACLK_EN) begin
        if (int_ier[1] & ap_ready)
            int_isr[1] <= 1'b1;
        else if (w_hs && waddr == ADDR_ISR && WSTRB[0])
            int_isr[1] <= int_isr[1] ^ WDATA[1]; // toggle on write
    end
end


//------------------------Memory logic-------------------
// ct
assign int_ct_address0 = ct_address0 >> 2;
assign int_ct_ce0      = ct_ce0;
assign int_ct_we0      = 1'b0;
assign int_ct_be0      = 1'b0;
assign int_ct_d0       = 1'b0;
assign ct_q0           = int_ct_q0 >> (int_ct_shift * 8);
assign int_ct_address1 = ar_hs? raddr[3:2] : waddr[3:2];
assign int_ct_ce1      = ar_hs | (int_ct_write & WVALID);
assign int_ct_we1      = int_ct_write & w_hs;
assign int_ct_be1      = WSTRB;
assign int_ct_d1       = WDATA;
// pt
assign int_pt_address0 = pt_address0 >> 2;
assign int_pt_ce0      = pt_ce0;
assign int_pt_we0      = pt_we0;
assign int_pt_be0      = 1 << pt_address0[1:0];
assign int_pt_d0       = {4{pt_d0}};
assign int_pt_address1 = ar_hs? raddr[3:2] : waddr[3:2];
assign int_pt_ce1      = ar_hs | (int_pt_write & WVALID);
assign int_pt_we1      = int_pt_write & w_hs;
assign int_pt_be1      = WSTRB;
assign int_pt_d1       = WDATA;
// rk
assign int_rk_address0 = rk_address0;
assign int_rk_ce0      = rk_ce0;
assign int_rk_we0      = 1'b0;
assign int_rk_be0      = 1'b0;
assign int_rk_d0       = 1'b0;
assign rk_q0           = int_rk_q0;
assign int_rk_address1 = ar_hs? raddr[7:2] : waddr[7:2];
assign int_rk_ce1      = ar_hs | (int_rk_write & WVALID);
assign int_rk_we1      = int_rk_write & w_hs;
assign int_rk_be1      = WSTRB;
assign int_rk_d1       = WDATA;
// int_ct_read
always @(posedge ACLK) begin
    if (ARESET)
        int_ct_read <= 1'b0;
    else if (ACLK_EN) begin
        if (ar_hs && raddr >= ADDR_CT_BASE && raddr <= ADDR_CT_HIGH)
            int_ct_read <= 1'b1;
        else
            int_ct_read <= 1'b0;
    end
end

// int_ct_write
always @(posedge ACLK) begin
    if (ARESET)
        int_ct_write <= 1'b0;
    else if (ACLK_EN) begin
        if (aw_hs && AWADDR[ADDR_BITS-1:0] >= ADDR_CT_BASE && AWADDR[ADDR_BITS-1:0] <= ADDR_CT_HIGH)
            int_ct_write <= 1'b1;
        else if (w_hs)
            int_ct_write <= 1'b0;
    end
end

// int_ct_shift
always @(posedge ACLK) begin
    if (ACLK_EN) begin
        if (ct_ce0)
            int_ct_shift <= ct_address0[1:0];
    end
end

// int_pt_read
always @(posedge ACLK) begin
    if (ARESET)
        int_pt_read <= 1'b0;
    else if (ACLK_EN) begin
        if (ar_hs && raddr >= ADDR_PT_BASE && raddr <= ADDR_PT_HIGH)
            int_pt_read <= 1'b1;
        else
            int_pt_read <= 1'b0;
    end
end

// int_pt_write
always @(posedge ACLK) begin
    if (ARESET)
        int_pt_write <= 1'b0;
    else if (ACLK_EN) begin
        if (aw_hs && AWADDR[ADDR_BITS-1:0] >= ADDR_PT_BASE && AWADDR[ADDR_BITS-1:0] <= ADDR_PT_HIGH)
            int_pt_write <= 1'b1;
        else if (w_hs)
            int_pt_write <= 1'b0;
    end
end

// int_pt_shift
always @(posedge ACLK) begin
    if (ACLK_EN) begin
        if (pt_ce0)
            int_pt_shift <= pt_address0[1:0];
    end
end

// int_rk_read
always @(posedge ACLK) begin
    if (ARESET)
        int_rk_read <= 1'b0;
    else if (ACLK_EN) begin
        if (ar_hs && raddr >= ADDR_RK_BASE && raddr <= ADDR_RK_HIGH)
            int_rk_read <= 1'b1;
        else
            int_rk_read <= 1'b0;
    end
end

// int_rk_write
always @(posedge ACLK) begin
    if (ARESET)
        int_rk_write <= 1'b0;
    else if (ACLK_EN) begin
        if (aw_hs && AWADDR[ADDR_BITS-1:0] >= ADDR_RK_BASE && AWADDR[ADDR_BITS-1:0] <= ADDR_RK_HIGH)
            int_rk_write <= 1'b1;
        else if (w_hs)
            int_rk_write <= 1'b0;
    end
end


endmodule


`timescale 1ns/1ps

module rijndaelDecrypt_hls_BUS_s_axi_ram
#(parameter
    BYTES  = 4,
    DEPTH  = 256,
    AWIDTH = log2(DEPTH)
) (
    input  wire               clk0,
    input  wire [AWIDTH-1:0]  address0,
    input  wire               ce0,
    input  wire               we0,
    input  wire [BYTES-1:0]   be0,
    input  wire [BYTES*8-1:0] d0,
    output reg  [BYTES*8-1:0] q0,
    input  wire               clk1,
    input  wire [AWIDTH-1:0]  address1,
    input  wire               ce1,
    input  wire               we1,
    input  wire [BYTES-1:0]   be1,
    input  wire [BYTES*8-1:0] d1,
    output reg  [BYTES*8-1:0] q1
);
//------------------------Local signal-------------------
reg  [BYTES*8-1:0] mem[0:DEPTH-1];
//------------------------Task and function--------------
function integer log2;
    input integer x;
    integer n, m;
begin
    n = 1;
    m = 2;
    while (m < x) begin
        n = n + 1;
        m = m * 2;
    end
    log2 = n;
end
endfunction
//------------------------Body---------------------------
// read port 0
always @(posedge clk0) begin
    if (ce0) q0 <= mem[address0];
end

// read port 1
always @(posedge clk1) begin
    if (ce1) q1 <= mem[address1];
end

genvar i;
generate
    for (i = 0; i < BYTES; i = i + 1) begin : gen_write
        // write port 0
        always @(posedge clk0) begin
            if (ce0 & we0 & be0[i]) begin
                mem[address0][8*i+7:8*i] <= d0[8*i+7:8*i];
            end
        end
        // write port 1
        always @(posedge clk1) begin
            if (ce1 & we1 & be1[i]) begin
                mem[address1][8*i+7:8*i] <= d1[8*i+7:8*i];
            end
        end
    end
endgenerate

endmodule

