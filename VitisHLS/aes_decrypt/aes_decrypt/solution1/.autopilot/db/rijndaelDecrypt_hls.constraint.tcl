set clock_constraint { \
    name clk \
    module rijndaelDecrypt_hls \
    port ap_clk \
    period 2 \
    uncertainty 0.54 \
}

set all_path {}

set false_path {}

