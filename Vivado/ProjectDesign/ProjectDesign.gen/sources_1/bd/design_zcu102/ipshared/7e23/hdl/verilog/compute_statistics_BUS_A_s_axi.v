// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
`timescale 1ns/1ps
module compute_statistics_BUS_A_s_axi
#(parameter
    C_S_AXI_ADDR_WIDTH = 14,
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
    output wire [511:0]                  vals_i,
    input  wire [511:0]                  vals_o,
    input  wire                          vals_o_ap_vld,
    input  wire [9:0]                    hr_address0,
    input  wire                          hr_ce0,
    output wire [63:0]                   hr_q0,
    output wire                          ap_start,
    input  wire                          ap_done,
    input  wire                          ap_ready,
    input  wire                          ap_idle
);
//------------------------Address Info-------------------
// 0x0000 : Control signals
//          bit 0  - ap_start (Read/Write/COH)
//          bit 1  - ap_done (Read/COR)
//          bit 2  - ap_idle (Read)
//          bit 3  - ap_ready (Read)
//          bit 7  - auto_restart (Read/Write)
//          others - reserved
// 0x0004 : Global Interrupt Enable Register
//          bit 0  - Global Interrupt Enable (Read/Write)
//          others - reserved
// 0x0008 : IP Interrupt Enable Register (Read/Write)
//          bit 0  - enable ap_done interrupt (Read/Write)
//          bit 1  - enable ap_ready interrupt (Read/Write)
//          others - reserved
// 0x000c : IP Interrupt Status Register (Read/TOW)
//          bit 0  - ap_done (COR/TOW)
//          bit 1  - ap_ready (COR/TOW)
//          others - reserved
// 0x0040 : Data signal of vals_i
//          bit 31~0 - vals_i[31:0] (Read/Write)
// 0x0044 : Data signal of vals_i
//          bit 31~0 - vals_i[63:32] (Read/Write)
// 0x0048 : Data signal of vals_i
//          bit 31~0 - vals_i[95:64] (Read/Write)
// 0x004c : Data signal of vals_i
//          bit 31~0 - vals_i[127:96] (Read/Write)
// 0x0050 : Data signal of vals_i
//          bit 31~0 - vals_i[159:128] (Read/Write)
// 0x0054 : Data signal of vals_i
//          bit 31~0 - vals_i[191:160] (Read/Write)
// 0x0058 : Data signal of vals_i
//          bit 31~0 - vals_i[223:192] (Read/Write)
// 0x005c : Data signal of vals_i
//          bit 31~0 - vals_i[255:224] (Read/Write)
// 0x0060 : Data signal of vals_i
//          bit 31~0 - vals_i[287:256] (Read/Write)
// 0x0064 : Data signal of vals_i
//          bit 31~0 - vals_i[319:288] (Read/Write)
// 0x0068 : Data signal of vals_i
//          bit 31~0 - vals_i[351:320] (Read/Write)
// 0x006c : Data signal of vals_i
//          bit 31~0 - vals_i[383:352] (Read/Write)
// 0x0070 : Data signal of vals_i
//          bit 31~0 - vals_i[415:384] (Read/Write)
// 0x0074 : Data signal of vals_i
//          bit 31~0 - vals_i[447:416] (Read/Write)
// 0x0078 : Data signal of vals_i
//          bit 31~0 - vals_i[479:448] (Read/Write)
// 0x007c : Data signal of vals_i
//          bit 31~0 - vals_i[511:480] (Read/Write)
// 0x0080 : reserved
// 0x0084 : Data signal of vals_o
//          bit 31~0 - vals_o[31:0] (Read)
// 0x0088 : Data signal of vals_o
//          bit 31~0 - vals_o[63:32] (Read)
// 0x008c : Data signal of vals_o
//          bit 31~0 - vals_o[95:64] (Read)
// 0x0090 : Data signal of vals_o
//          bit 31~0 - vals_o[127:96] (Read)
// 0x0094 : Data signal of vals_o
//          bit 31~0 - vals_o[159:128] (Read)
// 0x0098 : Data signal of vals_o
//          bit 31~0 - vals_o[191:160] (Read)
// 0x009c : Data signal of vals_o
//          bit 31~0 - vals_o[223:192] (Read)
// 0x00a0 : Data signal of vals_o
//          bit 31~0 - vals_o[255:224] (Read)
// 0x00a4 : Data signal of vals_o
//          bit 31~0 - vals_o[287:256] (Read)
// 0x00a8 : Data signal of vals_o
//          bit 31~0 - vals_o[319:288] (Read)
// 0x00ac : Data signal of vals_o
//          bit 31~0 - vals_o[351:320] (Read)
// 0x00b0 : Data signal of vals_o
//          bit 31~0 - vals_o[383:352] (Read)
// 0x00b4 : Data signal of vals_o
//          bit 31~0 - vals_o[415:384] (Read)
// 0x00b8 : Data signal of vals_o
//          bit 31~0 - vals_o[447:416] (Read)
// 0x00bc : Data signal of vals_o
//          bit 31~0 - vals_o[479:448] (Read)
// 0x00c0 : Data signal of vals_o
//          bit 31~0 - vals_o[511:480] (Read)
// 0x00c4 : Control signal of vals_o
//          bit 0  - vals_o_ap_vld (Read/COR)
//          others - reserved
// 0x2000 ~
// 0x3fff : Memory 'hr' (600 * 64b)
//          Word 2n   : bit [31:0] - hr[n][31: 0]
//          Word 2n+1 : bit [31:0] - hr[n][63:32]
// (SC = Self Clear, COR = Clear on Read, TOW = Toggle on Write, COH = Clear on Handshake)

//------------------------Parameter----------------------
localparam
    ADDR_AP_CTRL        = 14'h0000,
    ADDR_GIE            = 14'h0004,
    ADDR_IER            = 14'h0008,
    ADDR_ISR            = 14'h000c,
    ADDR_VALS_I_DATA_0  = 14'h0040,
    ADDR_VALS_I_DATA_1  = 14'h0044,
    ADDR_VALS_I_DATA_2  = 14'h0048,
    ADDR_VALS_I_DATA_3  = 14'h004c,
    ADDR_VALS_I_DATA_4  = 14'h0050,
    ADDR_VALS_I_DATA_5  = 14'h0054,
    ADDR_VALS_I_DATA_6  = 14'h0058,
    ADDR_VALS_I_DATA_7  = 14'h005c,
    ADDR_VALS_I_DATA_8  = 14'h0060,
    ADDR_VALS_I_DATA_9  = 14'h0064,
    ADDR_VALS_I_DATA_10 = 14'h0068,
    ADDR_VALS_I_DATA_11 = 14'h006c,
    ADDR_VALS_I_DATA_12 = 14'h0070,
    ADDR_VALS_I_DATA_13 = 14'h0074,
    ADDR_VALS_I_DATA_14 = 14'h0078,
    ADDR_VALS_I_DATA_15 = 14'h007c,
    ADDR_VALS_I_CTRL    = 14'h0080,
    ADDR_VALS_O_DATA_0  = 14'h0084,
    ADDR_VALS_O_DATA_1  = 14'h0088,
    ADDR_VALS_O_DATA_2  = 14'h008c,
    ADDR_VALS_O_DATA_3  = 14'h0090,
    ADDR_VALS_O_DATA_4  = 14'h0094,
    ADDR_VALS_O_DATA_5  = 14'h0098,
    ADDR_VALS_O_DATA_6  = 14'h009c,
    ADDR_VALS_O_DATA_7  = 14'h00a0,
    ADDR_VALS_O_DATA_8  = 14'h00a4,
    ADDR_VALS_O_DATA_9  = 14'h00a8,
    ADDR_VALS_O_DATA_10 = 14'h00ac,
    ADDR_VALS_O_DATA_11 = 14'h00b0,
    ADDR_VALS_O_DATA_12 = 14'h00b4,
    ADDR_VALS_O_DATA_13 = 14'h00b8,
    ADDR_VALS_O_DATA_14 = 14'h00bc,
    ADDR_VALS_O_DATA_15 = 14'h00c0,
    ADDR_VALS_O_CTRL    = 14'h00c4,
    ADDR_HR_BASE        = 14'h2000,
    ADDR_HR_HIGH        = 14'h3fff,
    WRIDLE              = 2'd0,
    WRDATA              = 2'd1,
    WRRESP              = 2'd2,
    WRRESET             = 2'd3,
    RDIDLE              = 2'd0,
    RDDATA              = 2'd1,
    RDRESET             = 2'd2,
    ADDR_BITS                = 14;

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
    reg  [511:0]                  int_vals_i = 'b0;
    reg  [511:0]                  int_vals_o = 'b0;
    reg                           int_vals_o_ap_vld;
    // memory signals
    wire [9:0]                    int_hr_address0;
    wire                          int_hr_ce0;
    wire                          int_hr_we0;
    wire [7:0]                    int_hr_be0;
    wire [63:0]                   int_hr_d0;
    wire [63:0]                   int_hr_q0;
    wire [9:0]                    int_hr_address1;
    wire                          int_hr_ce1;
    wire                          int_hr_we1;
    wire [7:0]                    int_hr_be1;
    wire [63:0]                   int_hr_d1;
    wire [63:0]                   int_hr_q1;
    reg                           int_hr_read;
    reg                           int_hr_write;
    reg  [0:0]                    int_hr_shift;

//------------------------Instantiation------------------
// int_hr
compute_statistics_BUS_A_s_axi_ram #(
    .BYTES    ( 8 ),
    .DEPTH    ( 600 )
) int_hr (
    .clk0     ( ACLK ),
    .address0 ( int_hr_address0 ),
    .ce0      ( int_hr_ce0 ),
    .we0      ( int_hr_we0 ),
    .be0      ( int_hr_be0 ),
    .d0       ( int_hr_d0 ),
    .q0       ( int_hr_q0 ),
    .clk1     ( ACLK ),
    .address1 ( int_hr_address1 ),
    .ce1      ( int_hr_ce1 ),
    .we1      ( int_hr_we1 ),
    .be1      ( int_hr_be1 ),
    .d1       ( int_hr_d1 ),
    .q1       ( int_hr_q1 )
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
assign RVALID  = (rstate == RDDATA) & !int_hr_read;
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
                ADDR_VALS_I_DATA_0: begin
                    rdata <= int_vals_i[31:0];
                end
                ADDR_VALS_I_DATA_1: begin
                    rdata <= int_vals_i[63:32];
                end
                ADDR_VALS_I_DATA_2: begin
                    rdata <= int_vals_i[95:64];
                end
                ADDR_VALS_I_DATA_3: begin
                    rdata <= int_vals_i[127:96];
                end
                ADDR_VALS_I_DATA_4: begin
                    rdata <= int_vals_i[159:128];
                end
                ADDR_VALS_I_DATA_5: begin
                    rdata <= int_vals_i[191:160];
                end
                ADDR_VALS_I_DATA_6: begin
                    rdata <= int_vals_i[223:192];
                end
                ADDR_VALS_I_DATA_7: begin
                    rdata <= int_vals_i[255:224];
                end
                ADDR_VALS_I_DATA_8: begin
                    rdata <= int_vals_i[287:256];
                end
                ADDR_VALS_I_DATA_9: begin
                    rdata <= int_vals_i[319:288];
                end
                ADDR_VALS_I_DATA_10: begin
                    rdata <= int_vals_i[351:320];
                end
                ADDR_VALS_I_DATA_11: begin
                    rdata <= int_vals_i[383:352];
                end
                ADDR_VALS_I_DATA_12: begin
                    rdata <= int_vals_i[415:384];
                end
                ADDR_VALS_I_DATA_13: begin
                    rdata <= int_vals_i[447:416];
                end
                ADDR_VALS_I_DATA_14: begin
                    rdata <= int_vals_i[479:448];
                end
                ADDR_VALS_I_DATA_15: begin
                    rdata <= int_vals_i[511:480];
                end
                ADDR_VALS_O_DATA_0: begin
                    rdata <= int_vals_o[31:0];
                end
                ADDR_VALS_O_DATA_1: begin
                    rdata <= int_vals_o[63:32];
                end
                ADDR_VALS_O_DATA_2: begin
                    rdata <= int_vals_o[95:64];
                end
                ADDR_VALS_O_DATA_3: begin
                    rdata <= int_vals_o[127:96];
                end
                ADDR_VALS_O_DATA_4: begin
                    rdata <= int_vals_o[159:128];
                end
                ADDR_VALS_O_DATA_5: begin
                    rdata <= int_vals_o[191:160];
                end
                ADDR_VALS_O_DATA_6: begin
                    rdata <= int_vals_o[223:192];
                end
                ADDR_VALS_O_DATA_7: begin
                    rdata <= int_vals_o[255:224];
                end
                ADDR_VALS_O_DATA_8: begin
                    rdata <= int_vals_o[287:256];
                end
                ADDR_VALS_O_DATA_9: begin
                    rdata <= int_vals_o[319:288];
                end
                ADDR_VALS_O_DATA_10: begin
                    rdata <= int_vals_o[351:320];
                end
                ADDR_VALS_O_DATA_11: begin
                    rdata <= int_vals_o[383:352];
                end
                ADDR_VALS_O_DATA_12: begin
                    rdata <= int_vals_o[415:384];
                end
                ADDR_VALS_O_DATA_13: begin
                    rdata <= int_vals_o[447:416];
                end
                ADDR_VALS_O_DATA_14: begin
                    rdata <= int_vals_o[479:448];
                end
                ADDR_VALS_O_DATA_15: begin
                    rdata <= int_vals_o[511:480];
                end
                ADDR_VALS_O_CTRL: begin
                    rdata[0] <= int_vals_o_ap_vld;
                end
            endcase
        end
        else if (int_hr_read) begin
            rdata <= int_hr_q1 >> (int_hr_shift * 32);
        end
    end
end


//------------------------Register logic-----------------
assign interrupt = int_gie & (|int_isr);
assign ap_start  = int_ap_start;
assign vals_i    = int_vals_i;
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

// int_vals_i[31:0]
always @(posedge ACLK) begin
    if (ARESET)
        int_vals_i[31:0] <= 0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_VALS_I_DATA_0)
            int_vals_i[31:0] <= (WDATA[31:0] & wmask) | (int_vals_i[31:0] & ~wmask);
    end
end

// int_vals_i[63:32]
always @(posedge ACLK) begin
    if (ARESET)
        int_vals_i[63:32] <= 0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_VALS_I_DATA_1)
            int_vals_i[63:32] <= (WDATA[31:0] & wmask) | (int_vals_i[63:32] & ~wmask);
    end
end

// int_vals_i[95:64]
always @(posedge ACLK) begin
    if (ARESET)
        int_vals_i[95:64] <= 0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_VALS_I_DATA_2)
            int_vals_i[95:64] <= (WDATA[31:0] & wmask) | (int_vals_i[95:64] & ~wmask);
    end
end

// int_vals_i[127:96]
always @(posedge ACLK) begin
    if (ARESET)
        int_vals_i[127:96] <= 0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_VALS_I_DATA_3)
            int_vals_i[127:96] <= (WDATA[31:0] & wmask) | (int_vals_i[127:96] & ~wmask);
    end
end

// int_vals_i[159:128]
always @(posedge ACLK) begin
    if (ARESET)
        int_vals_i[159:128] <= 0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_VALS_I_DATA_4)
            int_vals_i[159:128] <= (WDATA[31:0] & wmask) | (int_vals_i[159:128] & ~wmask);
    end
end

// int_vals_i[191:160]
always @(posedge ACLK) begin
    if (ARESET)
        int_vals_i[191:160] <= 0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_VALS_I_DATA_5)
            int_vals_i[191:160] <= (WDATA[31:0] & wmask) | (int_vals_i[191:160] & ~wmask);
    end
end

// int_vals_i[223:192]
always @(posedge ACLK) begin
    if (ARESET)
        int_vals_i[223:192] <= 0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_VALS_I_DATA_6)
            int_vals_i[223:192] <= (WDATA[31:0] & wmask) | (int_vals_i[223:192] & ~wmask);
    end
end

// int_vals_i[255:224]
always @(posedge ACLK) begin
    if (ARESET)
        int_vals_i[255:224] <= 0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_VALS_I_DATA_7)
            int_vals_i[255:224] <= (WDATA[31:0] & wmask) | (int_vals_i[255:224] & ~wmask);
    end
end

// int_vals_i[287:256]
always @(posedge ACLK) begin
    if (ARESET)
        int_vals_i[287:256] <= 0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_VALS_I_DATA_8)
            int_vals_i[287:256] <= (WDATA[31:0] & wmask) | (int_vals_i[287:256] & ~wmask);
    end
end

// int_vals_i[319:288]
always @(posedge ACLK) begin
    if (ARESET)
        int_vals_i[319:288] <= 0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_VALS_I_DATA_9)
            int_vals_i[319:288] <= (WDATA[31:0] & wmask) | (int_vals_i[319:288] & ~wmask);
    end
end

// int_vals_i[351:320]
always @(posedge ACLK) begin
    if (ARESET)
        int_vals_i[351:320] <= 0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_VALS_I_DATA_10)
            int_vals_i[351:320] <= (WDATA[31:0] & wmask) | (int_vals_i[351:320] & ~wmask);
    end
end

// int_vals_i[383:352]
always @(posedge ACLK) begin
    if (ARESET)
        int_vals_i[383:352] <= 0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_VALS_I_DATA_11)
            int_vals_i[383:352] <= (WDATA[31:0] & wmask) | (int_vals_i[383:352] & ~wmask);
    end
end

// int_vals_i[415:384]
always @(posedge ACLK) begin
    if (ARESET)
        int_vals_i[415:384] <= 0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_VALS_I_DATA_12)
            int_vals_i[415:384] <= (WDATA[31:0] & wmask) | (int_vals_i[415:384] & ~wmask);
    end
end

// int_vals_i[447:416]
always @(posedge ACLK) begin
    if (ARESET)
        int_vals_i[447:416] <= 0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_VALS_I_DATA_13)
            int_vals_i[447:416] <= (WDATA[31:0] & wmask) | (int_vals_i[447:416] & ~wmask);
    end
end

// int_vals_i[479:448]
always @(posedge ACLK) begin
    if (ARESET)
        int_vals_i[479:448] <= 0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_VALS_I_DATA_14)
            int_vals_i[479:448] <= (WDATA[31:0] & wmask) | (int_vals_i[479:448] & ~wmask);
    end
end

// int_vals_i[511:480]
always @(posedge ACLK) begin
    if (ARESET)
        int_vals_i[511:480] <= 0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_VALS_I_DATA_15)
            int_vals_i[511:480] <= (WDATA[31:0] & wmask) | (int_vals_i[511:480] & ~wmask);
    end
end

// int_vals_o
always @(posedge ACLK) begin
    if (ARESET)
        int_vals_o <= 0;
    else if (ACLK_EN) begin
        if (vals_o_ap_vld)
            int_vals_o <= vals_o;
    end
end

// int_vals_o_ap_vld
always @(posedge ACLK) begin
    if (ARESET)
        int_vals_o_ap_vld <= 1'b0;
    else if (ACLK_EN) begin
        if (vals_o_ap_vld)
            int_vals_o_ap_vld <= 1'b1;
        else if (ar_hs && raddr == ADDR_VALS_O_CTRL)
            int_vals_o_ap_vld <= 1'b0; // clear on read
    end
end


//------------------------Memory logic-------------------
// hr
assign int_hr_address0 = hr_address0;
assign int_hr_ce0      = hr_ce0;
assign int_hr_we0      = 1'b0;
assign int_hr_be0      = 1'b0;
assign int_hr_d0       = 1'b0;
assign hr_q0           = int_hr_q0;
assign int_hr_address1 = ar_hs? raddr[12:3] : waddr[12:3];
assign int_hr_ce1      = ar_hs | (int_hr_write & WVALID);
assign int_hr_we1      = int_hr_write & w_hs;
assign int_hr_be1      = WSTRB << (waddr[2:2] * 4);
assign int_hr_d1       = {2{WDATA}};
// int_hr_read
always @(posedge ACLK) begin
    if (ARESET)
        int_hr_read <= 1'b0;
    else if (ACLK_EN) begin
        if (ar_hs && raddr >= ADDR_HR_BASE && raddr <= ADDR_HR_HIGH)
            int_hr_read <= 1'b1;
        else
            int_hr_read <= 1'b0;
    end
end

// int_hr_write
always @(posedge ACLK) begin
    if (ARESET)
        int_hr_write <= 1'b0;
    else if (ACLK_EN) begin
        if (aw_hs && AWADDR[ADDR_BITS-1:0] >= ADDR_HR_BASE && AWADDR[ADDR_BITS-1:0] <= ADDR_HR_HIGH)
            int_hr_write <= 1'b1;
        else if (w_hs)
            int_hr_write <= 1'b0;
    end
end

// int_hr_shift
always @(posedge ACLK) begin
    if (ACLK_EN) begin
        if (ar_hs)
            int_hr_shift <= raddr[2:2];
    end
end


endmodule


`timescale 1ns/1ps

module compute_statistics_BUS_A_s_axi_ram
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

