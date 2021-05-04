# 1 "aes_dec_hls.cpp"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 375 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "/media/jmack2545/data_drive/Xilinx/Vitis_HLS/2020.2/common/technology/autopilot/etc/autopilot_ssdm_op.h" 1
# 158 "/media/jmack2545/data_drive/Xilinx/Vitis_HLS/2020.2/common/technology/autopilot/etc/autopilot_ssdm_op.h"
extern "C" {






    void _ssdm_op_IfRead(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_op_IfWrite(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_op_IfNbRead(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_op_IfNbWrite(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_op_IfCanRead(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_op_IfCanWrite(...) __attribute__ ((nothrow)) __attribute__((overloadable));


    void _ssdm_StreamRead(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_StreamWrite(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_StreamNbRead(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_StreamNbWrite(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_StreamCanRead(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_StreamCanWrite(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    unsigned _ssdm_StreamSize(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_op_ReadReq(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_op_Read(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_op_WriteReq(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_op_Write(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_op_NbReadReq(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_op_NbWriteReq(...) __attribute__ ((nothrow)) __attribute__((overloadable));




    void _ssdm_op_MemShiftRead(...) __attribute__ ((nothrow)) __attribute__((overloadable));

    void _ssdm_op_Wait(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_op_Poll(...) __attribute__ ((nothrow)) __attribute__((overloadable));

    void _ssdm_op_Return(...) __attribute__ ((nothrow)) __attribute__((overloadable));


    void _ssdm_op_SpecSynModule(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_op_SpecTopModule(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_op_SpecProcessDecl(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_op_SpecProcessDef(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_op_SpecPort(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_op_SpecConnection(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_op_SpecChannel(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_op_SpecSensitive(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_op_SpecModuleInst(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_op_SpecPortMap(...) __attribute__ ((nothrow)) __attribute__((overloadable));

    void _ssdm_op_SpecReset(...) __attribute__ ((nothrow)) __attribute__((overloadable));

    void _ssdm_op_SpecPlatform(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_op_SpecClockDomain(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_op_SpecPowerDomain(...) __attribute__ ((nothrow)) __attribute__((overloadable));

    int _ssdm_op_SpecRegionBegin(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    int _ssdm_op_SpecRegionEnd(...) __attribute__ ((nothrow)) __attribute__((overloadable));

    void _ssdm_op_SpecLoopName(...) __attribute__ ((nothrow)) __attribute__((overloadable));

    void _ssdm_op_SpecLoopTripCount(...) __attribute__ ((nothrow)) __attribute__((overloadable));

    int _ssdm_op_SpecStateBegin(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    int _ssdm_op_SpecStateEnd(...) __attribute__ ((nothrow)) __attribute__((overloadable));

    void _ssdm_op_SpecInterface(...) __attribute__ ((nothrow)) __attribute__((overloadable));

    void _ssdm_op_SpecPipeline(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_op_SpecDataflowPipeline(...) __attribute__ ((nothrow)) __attribute__((overloadable));


    void _ssdm_op_SpecLatency(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_op_SpecParallel(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_op_SpecProtocol(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_op_SpecOccurrence(...) __attribute__ ((nothrow)) __attribute__((overloadable));

    void _ssdm_op_SpecResource(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_op_SpecResourceLimit(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_op_SpecCHCore(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_op_SpecFUCore(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_op_SpecIFCore(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_op_SpecIPCore(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_op_SpecKeepValue(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_op_SpecMemCore(...) __attribute__ ((nothrow)) __attribute__((overloadable));

    void _ssdm_op_SpecExt(...) __attribute__ ((nothrow)) __attribute__((overloadable));




    void _ssdm_SpecArrayDimSize(...) __attribute__ ((nothrow)) __attribute__((overloadable));

    void _ssdm_RegionBegin(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_RegionEnd(...) __attribute__ ((nothrow)) __attribute__((overloadable));

    void _ssdm_Unroll(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_UnrollRegion(...) __attribute__ ((nothrow)) __attribute__((overloadable));

    void _ssdm_InlineAll(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_InlineLoop(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_Inline(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_InlineSelf(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_InlineRegion(...) __attribute__ ((nothrow)) __attribute__((overloadable));

    void _ssdm_SpecArrayMap(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_SpecArrayPartition(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_SpecArrayReshape(...) __attribute__ ((nothrow)) __attribute__((overloadable));

    void _ssdm_SpecStream(...) __attribute__ ((nothrow)) __attribute__((overloadable));

    void _ssdm_op_SpecStable(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_op_SpecStableContent(...) __attribute__ ((nothrow)) __attribute__((overloadable));

    void _ssdm_op_SpecBindPort(...) __attribute__ ((nothrow)) __attribute__((overloadable));

    void _ssdm_op_SpecPipoDepth(...) __attribute__ ((nothrow)) __attribute__((overloadable));

    void _ssdm_SpecExpr(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_SpecExprBalance(...) __attribute__ ((nothrow)) __attribute__((overloadable));

    void _ssdm_SpecDependence(...) __attribute__ ((nothrow)) __attribute__((overloadable));

    void _ssdm_SpecLoopMerge(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_SpecLoopFlatten(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_SpecLoopRewind(...) __attribute__ ((nothrow)) __attribute__((overloadable));

    void _ssdm_SpecFuncInstantiation(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_SpecFuncBuffer(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_SpecFuncExtract(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_SpecConstant(...) __attribute__ ((nothrow)) __attribute__((overloadable));

    void _ssdm_DataPack(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_SpecDataPack(...) __attribute__ ((nothrow)) __attribute__((overloadable));

    void _ssdm_op_SpecBitsMap(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_op_SpecLicense(...) __attribute__ ((nothrow)) __attribute__((overloadable));

    void __xilinx_ip_top(...) __attribute__ ((nothrow)) __attribute__((overloadable));


}
# 2 "<built-in>" 2
# 1 "aes_dec_hls.cpp" 2
typedef unsigned int u32;
typedef unsigned char u8;


static const u32 Td0[256] = {
    0x51f4a750U, 0x7e416553U, 0x1a17a4c3U, 0x3a275e96U,
    0x3bab6bcbU, 0x1f9d45f1U, 0xacfa58abU, 0x4be30393U,
    0x2030fa55U, 0xad766df6U, 0x88cc7691U, 0xf5024c25U,
    0x4fe5d7fcU, 0xc52acbd7U, 0x26354480U, 0xb562a38fU,
    0xdeb15a49U, 0x25ba1b67U, 0x45ea0e98U, 0x5dfec0e1U,
    0xc32f7502U, 0x814cf012U, 0x8d4697a3U, 0x6bd3f9c6U,
    0x038f5fe7U, 0x15929c95U, 0xbf6d7aebU, 0x955259daU,
    0xd4be832dU, 0x587421d3U, 0x49e06929U, 0x8ec9c844U,
    0x75c2896aU, 0xf48e7978U, 0x99583e6bU, 0x27b971ddU,
    0xbee14fb6U, 0xf088ad17U, 0xc920ac66U, 0x7dce3ab4U,
    0x63df4a18U, 0xe51a3182U, 0x97513360U, 0x62537f45U,
    0xb16477e0U, 0xbb6bae84U, 0xfe81a01cU, 0xf9082b94U,
    0x70486858U, 0x8f45fd19U, 0x94de6c87U, 0x527bf8b7U,
    0xab73d323U, 0x724b02e2U, 0xe31f8f57U, 0x6655ab2aU,
    0xb2eb2807U, 0x2fb5c203U, 0x86c57b9aU, 0xd33708a5U,
    0x302887f2U, 0x23bfa5b2U, 0x02036abaU, 0xed16825cU,
    0x8acf1c2bU, 0xa779b492U, 0xf307f2f0U, 0x4e69e2a1U,
    0x65daf4cdU, 0x0605bed5U, 0xd134621fU, 0xc4a6fe8aU,
    0x342e539dU, 0xa2f355a0U, 0x058ae132U, 0xa4f6eb75U,
    0x0b83ec39U, 0x4060efaaU, 0x5e719f06U, 0xbd6e1051U,
    0x3e218af9U, 0x96dd063dU, 0xdd3e05aeU, 0x4de6bd46U,
    0x91548db5U, 0x71c45d05U, 0x0406d46fU, 0x605015ffU,
    0x1998fb24U, 0xd6bde997U, 0x894043ccU, 0x67d99e77U,
    0xb0e842bdU, 0x07898b88U, 0xe7195b38U, 0x79c8eedbU,
    0xa17c0a47U, 0x7c420fe9U, 0xf8841ec9U, 0x00000000U,
    0x09808683U, 0x322bed48U, 0x1e1170acU, 0x6c5a724eU,
    0xfd0efffbU, 0x0f853856U, 0x3daed51eU, 0x362d3927U,
    0x0a0fd964U, 0x685ca621U, 0x9b5b54d1U, 0x24362e3aU,
    0x0c0a67b1U, 0x9357e70fU, 0xb4ee96d2U, 0x1b9b919eU,
    0x80c0c54fU, 0x61dc20a2U, 0x5a774b69U, 0x1c121a16U,
    0xe293ba0aU, 0xc0a02ae5U, 0x3c22e043U, 0x121b171dU,
    0x0e090d0bU, 0xf28bc7adU, 0x2db6a8b9U, 0x141ea9c8U,
    0x57f11985U, 0xaf75074cU, 0xee99ddbbU, 0xa37f60fdU,
    0xf701269fU, 0x5c72f5bcU, 0x44663bc5U, 0x5bfb7e34U,
    0x8b432976U, 0xcb23c6dcU, 0xb6edfc68U, 0xb8e4f163U,
    0xd731dccaU, 0x42638510U, 0x13972240U, 0x84c61120U,
    0x854a247dU, 0xd2bb3df8U, 0xaef93211U, 0xc729a16dU,
    0x1d9e2f4bU, 0xdcb230f3U, 0x0d8652ecU, 0x77c1e3d0U,
    0x2bb3166cU, 0xa970b999U, 0x119448faU, 0x47e96422U,
    0xa8fc8cc4U, 0xa0f03f1aU, 0x567d2cd8U, 0x223390efU,
    0x87494ec7U, 0xd938d1c1U, 0x8ccaa2feU, 0x98d40b36U,
    0xa6f581cfU, 0xa57ade28U, 0xdab78e26U, 0x3fadbfa4U,
    0x2c3a9de4U, 0x5078920dU, 0x6a5fcc9bU, 0x547e4662U,
    0xf68d13c2U, 0x90d8b8e8U, 0x2e39f75eU, 0x82c3aff5U,
    0x9f5d80beU, 0x69d0937cU, 0x6fd52da9U, 0xcf2512b3U,
    0xc8ac993bU, 0x10187da7U, 0xe89c636eU, 0xdb3bbb7bU,
    0xcd267809U, 0x6e5918f4U, 0xec9ab701U, 0x834f9aa8U,
    0xe6956e65U, 0xaaffe67eU, 0x21bccf08U, 0xef15e8e6U,
    0xbae79bd9U, 0x4a6f36ceU, 0xea9f09d4U, 0x29b07cd6U,
    0x31a4b2afU, 0x2a3f2331U, 0xc6a59430U, 0x35a266c0U,
    0x744ebc37U, 0xfc82caa6U, 0xe090d0b0U, 0x33a7d815U,
    0xf104984aU, 0x41ecdaf7U, 0x7fcd500eU, 0x1791f62fU,
    0x764dd68dU, 0x43efb04dU, 0xccaa4d54U, 0xe49604dfU,
    0x9ed1b5e3U, 0x4c6a881bU, 0xc12c1fb8U, 0x4665517fU,
    0x9d5eea04U, 0x018c355dU, 0xfa877473U, 0xfb0b412eU,
    0xb3671d5aU, 0x92dbd252U, 0xe9105633U, 0x6dd64713U,
    0x9ad7618cU, 0x37a10c7aU, 0x59f8148eU, 0xeb133c89U,
    0xcea927eeU, 0xb761c935U, 0xe11ce5edU, 0x7a47b13cU,
    0x9cd2df59U, 0x55f2733fU, 0x1814ce79U, 0x73c737bfU,
    0x53f7cdeaU, 0x5ffdaa5bU, 0xdf3d6f14U, 0x7844db86U,
    0xcaaff381U, 0xb968c43eU, 0x3824342cU, 0xc2a3405fU,
    0x161dc372U, 0xbce2250cU, 0x283c498bU, 0xff0d9541U,
    0x39a80171U, 0x080cb3deU, 0xd8b4e49cU, 0x6456c190U,
    0x7bcb8461U, 0xd532b670U, 0x486c5c74U, 0xd0b85742U,
};

static const u8 Td4s[256] = {
    0x52U, 0x09U, 0x6aU, 0xd5U, 0x30U, 0x36U, 0xa5U, 0x38U,
    0xbfU, 0x40U, 0xa3U, 0x9eU, 0x81U, 0xf3U, 0xd7U, 0xfbU,
    0x7cU, 0xe3U, 0x39U, 0x82U, 0x9bU, 0x2fU, 0xffU, 0x87U,
    0x34U, 0x8eU, 0x43U, 0x44U, 0xc4U, 0xdeU, 0xe9U, 0xcbU,
    0x54U, 0x7bU, 0x94U, 0x32U, 0xa6U, 0xc2U, 0x23U, 0x3dU,
    0xeeU, 0x4cU, 0x95U, 0x0bU, 0x42U, 0xfaU, 0xc3U, 0x4eU,
    0x08U, 0x2eU, 0xa1U, 0x66U, 0x28U, 0xd9U, 0x24U, 0xb2U,
    0x76U, 0x5bU, 0xa2U, 0x49U, 0x6dU, 0x8bU, 0xd1U, 0x25U,
    0x72U, 0xf8U, 0xf6U, 0x64U, 0x86U, 0x68U, 0x98U, 0x16U,
    0xd4U, 0xa4U, 0x5cU, 0xccU, 0x5dU, 0x65U, 0xb6U, 0x92U,
    0x6cU, 0x70U, 0x48U, 0x50U, 0xfdU, 0xedU, 0xb9U, 0xdaU,
    0x5eU, 0x15U, 0x46U, 0x57U, 0xa7U, 0x8dU, 0x9dU, 0x84U,
    0x90U, 0xd8U, 0xabU, 0x00U, 0x8cU, 0xbcU, 0xd3U, 0x0aU,
    0xf7U, 0xe4U, 0x58U, 0x05U, 0xb8U, 0xb3U, 0x45U, 0x06U,
    0xd0U, 0x2cU, 0x1eU, 0x8fU, 0xcaU, 0x3fU, 0x0fU, 0x02U,
    0xc1U, 0xafU, 0xbdU, 0x03U, 0x01U, 0x13U, 0x8aU, 0x6bU,
    0x3aU, 0x91U, 0x11U, 0x41U, 0x4fU, 0x67U, 0xdcU, 0xeaU,
    0x97U, 0xf2U, 0xcfU, 0xceU, 0xf0U, 0xb4U, 0xe6U, 0x73U,
    0x96U, 0xacU, 0x74U, 0x22U, 0xe7U, 0xadU, 0x35U, 0x85U,
    0xe2U, 0xf9U, 0x37U, 0xe8U, 0x1cU, 0x75U, 0xdfU, 0x6eU,
    0x47U, 0xf1U, 0x1aU, 0x71U, 0x1dU, 0x29U, 0xc5U, 0x89U,
    0x6fU, 0xb7U, 0x62U, 0x0eU, 0xaaU, 0x18U, 0xbeU, 0x1bU,
    0xfcU, 0x56U, 0x3eU, 0x4bU, 0xc6U, 0xd2U, 0x79U, 0x20U,
    0x9aU, 0xdbU, 0xc0U, 0xfeU, 0x78U, 0xcdU, 0x5aU, 0xf4U,
    0x1fU, 0xddU, 0xa8U, 0x33U, 0x88U, 0x07U, 0xc7U, 0x31U,
    0xb1U, 0x12U, 0x10U, 0x59U, 0x27U, 0x80U, 0xecU, 0x5fU,
    0x60U, 0x51U, 0x7fU, 0xa9U, 0x19U, 0xb5U, 0x4aU, 0x0dU,
    0x2dU, 0xe5U, 0x7aU, 0x9fU, 0x93U, 0xc9U, 0x9cU, 0xefU,
    0xa0U, 0xe0U, 0x3bU, 0x4dU, 0xaeU, 0x2aU, 0xf5U, 0xb0U,
    0xc8U, 0xebU, 0xbbU, 0x3cU, 0x83U, 0x53U, 0x99U, 0x61U,
    0x17U, 0x2bU, 0x04U, 0x7eU, 0xbaU, 0x77U, 0xd6U, 0x26U,
    0xe1U, 0x69U, 0x14U, 0x63U, 0x55U, 0x21U, 0x0cU, 0x7dU,
};
static const u8 rcons[] = {
    0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1B, 0x36

};



static inline u32 rotr(u32 val, int bits)
{
    return (val >> bits) | (val << (32 - bits));
}
# 147 "aes_dec_hls.cpp"
__attribute__((sdx_kernel("rijndaelDecrypt_hls", 0))) void rijndaelDecrypt_hls(u32 rk[44], u8 ct[16], u8 pt[16]){_ssdm_SpecArrayDimSize(rk, 44);_ssdm_SpecArrayDimSize(ct, 16);_ssdm_SpecArrayDimSize(pt, 16);
#pragma HLS TOP name=rijndaelDecrypt_hls
# 147 "aes_dec_hls.cpp"

#pragma HLS INTERFACE s_axilite port=rk bundle=BUS
#pragma HLS INTERFACE s_axilite port=ct bundle=BUS
#pragma HLS INTERFACE s_axilite port=pt bundle=BUS
#pragma HLS INTERFACE s_axilite port=return bundle=BUS

 u32 s0, s1, s2, s3, t0, t1, t2, t3;
   const int Nr = 10;

   s0 = (((u32)(ct)[0] << 24) ^ ((u32)(ct)[1] << 16) ^ ((u32)(ct)[2] << 8) ^ ((u32)(ct)[3])) ^ rk[0];
   s1 = (((u32)(ct + 4)[0] << 24) ^ ((u32)(ct + 4)[1] << 16) ^ ((u32)(ct + 4)[2] << 8) ^ ((u32)(ct + 4)[3])) ^ rk[1];
   s2 = (((u32)(ct + 8)[0] << 24) ^ ((u32)(ct + 8)[1] << 16) ^ ((u32)(ct + 8)[2] << 8) ^ ((u32)(ct + 8)[3])) ^ rk[2];
   s3 = (((u32)(ct + 12)[0] << 24) ^ ((u32)(ct + 12)[1] << 16) ^ ((u32)(ct + 12)[2] << 8) ^ ((u32)(ct + 12)[3])) ^ rk[3];


   t0 = Td0[((s0) >> 24) & 0xff] ^ rotr(Td0[((s3) >> 16) & 0xff], 8) ^ rotr(Td0[((s2) >> 8) & 0xff], 16) ^ rotr(Td0[(s1) & 0xff], 24) ^ rk[4 * 1]; t1 = Td0[((s1) >> 24) & 0xff] ^ rotr(Td0[((s0) >> 16) & 0xff], 8) ^ rotr(Td0[((s3) >> 8) & 0xff], 16) ^ rotr(Td0[(s2) & 0xff], 24) ^ rk[4 * 1 + 1]; t2 = Td0[((s2) >> 24) & 0xff] ^ rotr(Td0[((s1) >> 16) & 0xff], 8) ^ rotr(Td0[((s0) >> 8) & 0xff], 16) ^ rotr(Td0[(s3) & 0xff], 24) ^ rk[4 * 1 + 2]; t3 = Td0[((s3) >> 24) & 0xff] ^ rotr(Td0[((s2) >> 16) & 0xff], 8) ^ rotr(Td0[((s1) >> 8) & 0xff], 16) ^ rotr(Td0[(s0) & 0xff], 24) ^ rk[4 * 1 + 3];;
   s0 = Td0[((t0) >> 24) & 0xff] ^ rotr(Td0[((t3) >> 16) & 0xff], 8) ^ rotr(Td0[((t2) >> 8) & 0xff], 16) ^ rotr(Td0[(t1) & 0xff], 24) ^ rk[4 * 2]; s1 = Td0[((t1) >> 24) & 0xff] ^ rotr(Td0[((t0) >> 16) & 0xff], 8) ^ rotr(Td0[((t3) >> 8) & 0xff], 16) ^ rotr(Td0[(t2) & 0xff], 24) ^ rk[4 * 2 + 1]; s2 = Td0[((t2) >> 24) & 0xff] ^ rotr(Td0[((t1) >> 16) & 0xff], 8) ^ rotr(Td0[((t0) >> 8) & 0xff], 16) ^ rotr(Td0[(t3) & 0xff], 24) ^ rk[4 * 2 + 2]; s3 = Td0[((t3) >> 24) & 0xff] ^ rotr(Td0[((t2) >> 16) & 0xff], 8) ^ rotr(Td0[((t1) >> 8) & 0xff], 16) ^ rotr(Td0[(t0) & 0xff], 24) ^ rk[4 * 2 + 3];;
   t0 = Td0[((s0) >> 24) & 0xff] ^ rotr(Td0[((s3) >> 16) & 0xff], 8) ^ rotr(Td0[((s2) >> 8) & 0xff], 16) ^ rotr(Td0[(s1) & 0xff], 24) ^ rk[4 * 3]; t1 = Td0[((s1) >> 24) & 0xff] ^ rotr(Td0[((s0) >> 16) & 0xff], 8) ^ rotr(Td0[((s3) >> 8) & 0xff], 16) ^ rotr(Td0[(s2) & 0xff], 24) ^ rk[4 * 3 + 1]; t2 = Td0[((s2) >> 24) & 0xff] ^ rotr(Td0[((s1) >> 16) & 0xff], 8) ^ rotr(Td0[((s0) >> 8) & 0xff], 16) ^ rotr(Td0[(s3) & 0xff], 24) ^ rk[4 * 3 + 2]; t3 = Td0[((s3) >> 24) & 0xff] ^ rotr(Td0[((s2) >> 16) & 0xff], 8) ^ rotr(Td0[((s1) >> 8) & 0xff], 16) ^ rotr(Td0[(s0) & 0xff], 24) ^ rk[4 * 3 + 3];;
   s0 = Td0[((t0) >> 24) & 0xff] ^ rotr(Td0[((t3) >> 16) & 0xff], 8) ^ rotr(Td0[((t2) >> 8) & 0xff], 16) ^ rotr(Td0[(t1) & 0xff], 24) ^ rk[4 * 4]; s1 = Td0[((t1) >> 24) & 0xff] ^ rotr(Td0[((t0) >> 16) & 0xff], 8) ^ rotr(Td0[((t3) >> 8) & 0xff], 16) ^ rotr(Td0[(t2) & 0xff], 24) ^ rk[4 * 4 + 1]; s2 = Td0[((t2) >> 24) & 0xff] ^ rotr(Td0[((t1) >> 16) & 0xff], 8) ^ rotr(Td0[((t0) >> 8) & 0xff], 16) ^ rotr(Td0[(t3) & 0xff], 24) ^ rk[4 * 4 + 2]; s3 = Td0[((t3) >> 24) & 0xff] ^ rotr(Td0[((t2) >> 16) & 0xff], 8) ^ rotr(Td0[((t1) >> 8) & 0xff], 16) ^ rotr(Td0[(t0) & 0xff], 24) ^ rk[4 * 4 + 3];;
   t0 = Td0[((s0) >> 24) & 0xff] ^ rotr(Td0[((s3) >> 16) & 0xff], 8) ^ rotr(Td0[((s2) >> 8) & 0xff], 16) ^ rotr(Td0[(s1) & 0xff], 24) ^ rk[4 * 5]; t1 = Td0[((s1) >> 24) & 0xff] ^ rotr(Td0[((s0) >> 16) & 0xff], 8) ^ rotr(Td0[((s3) >> 8) & 0xff], 16) ^ rotr(Td0[(s2) & 0xff], 24) ^ rk[4 * 5 + 1]; t2 = Td0[((s2) >> 24) & 0xff] ^ rotr(Td0[((s1) >> 16) & 0xff], 8) ^ rotr(Td0[((s0) >> 8) & 0xff], 16) ^ rotr(Td0[(s3) & 0xff], 24) ^ rk[4 * 5 + 2]; t3 = Td0[((s3) >> 24) & 0xff] ^ rotr(Td0[((s2) >> 16) & 0xff], 8) ^ rotr(Td0[((s1) >> 8) & 0xff], 16) ^ rotr(Td0[(s0) & 0xff], 24) ^ rk[4 * 5 + 3];;
   s0 = Td0[((t0) >> 24) & 0xff] ^ rotr(Td0[((t3) >> 16) & 0xff], 8) ^ rotr(Td0[((t2) >> 8) & 0xff], 16) ^ rotr(Td0[(t1) & 0xff], 24) ^ rk[4 * 6]; s1 = Td0[((t1) >> 24) & 0xff] ^ rotr(Td0[((t0) >> 16) & 0xff], 8) ^ rotr(Td0[((t3) >> 8) & 0xff], 16) ^ rotr(Td0[(t2) & 0xff], 24) ^ rk[4 * 6 + 1]; s2 = Td0[((t2) >> 24) & 0xff] ^ rotr(Td0[((t1) >> 16) & 0xff], 8) ^ rotr(Td0[((t0) >> 8) & 0xff], 16) ^ rotr(Td0[(t3) & 0xff], 24) ^ rk[4 * 6 + 2]; s3 = Td0[((t3) >> 24) & 0xff] ^ rotr(Td0[((t2) >> 16) & 0xff], 8) ^ rotr(Td0[((t1) >> 8) & 0xff], 16) ^ rotr(Td0[(t0) & 0xff], 24) ^ rk[4 * 6 + 3];;
   t0 = Td0[((s0) >> 24) & 0xff] ^ rotr(Td0[((s3) >> 16) & 0xff], 8) ^ rotr(Td0[((s2) >> 8) & 0xff], 16) ^ rotr(Td0[(s1) & 0xff], 24) ^ rk[4 * 7]; t1 = Td0[((s1) >> 24) & 0xff] ^ rotr(Td0[((s0) >> 16) & 0xff], 8) ^ rotr(Td0[((s3) >> 8) & 0xff], 16) ^ rotr(Td0[(s2) & 0xff], 24) ^ rk[4 * 7 + 1]; t2 = Td0[((s2) >> 24) & 0xff] ^ rotr(Td0[((s1) >> 16) & 0xff], 8) ^ rotr(Td0[((s0) >> 8) & 0xff], 16) ^ rotr(Td0[(s3) & 0xff], 24) ^ rk[4 * 7 + 2]; t3 = Td0[((s3) >> 24) & 0xff] ^ rotr(Td0[((s2) >> 16) & 0xff], 8) ^ rotr(Td0[((s1) >> 8) & 0xff], 16) ^ rotr(Td0[(s0) & 0xff], 24) ^ rk[4 * 7 + 3];;
   s0 = Td0[((t0) >> 24) & 0xff] ^ rotr(Td0[((t3) >> 16) & 0xff], 8) ^ rotr(Td0[((t2) >> 8) & 0xff], 16) ^ rotr(Td0[(t1) & 0xff], 24) ^ rk[4 * 8]; s1 = Td0[((t1) >> 24) & 0xff] ^ rotr(Td0[((t0) >> 16) & 0xff], 8) ^ rotr(Td0[((t3) >> 8) & 0xff], 16) ^ rotr(Td0[(t2) & 0xff], 24) ^ rk[4 * 8 + 1]; s2 = Td0[((t2) >> 24) & 0xff] ^ rotr(Td0[((t1) >> 16) & 0xff], 8) ^ rotr(Td0[((t0) >> 8) & 0xff], 16) ^ rotr(Td0[(t3) & 0xff], 24) ^ rk[4 * 8 + 2]; s3 = Td0[((t3) >> 24) & 0xff] ^ rotr(Td0[((t2) >> 16) & 0xff], 8) ^ rotr(Td0[((t1) >> 8) & 0xff], 16) ^ rotr(Td0[(t0) & 0xff], 24) ^ rk[4 * 8 + 3];;
   t0 = Td0[((s0) >> 24) & 0xff] ^ rotr(Td0[((s3) >> 16) & 0xff], 8) ^ rotr(Td0[((s2) >> 8) & 0xff], 16) ^ rotr(Td0[(s1) & 0xff], 24) ^ rk[4 * 9]; t1 = Td0[((s1) >> 24) & 0xff] ^ rotr(Td0[((s0) >> 16) & 0xff], 8) ^ rotr(Td0[((s3) >> 8) & 0xff], 16) ^ rotr(Td0[(s2) & 0xff], 24) ^ rk[4 * 9 + 1]; t2 = Td0[((s2) >> 24) & 0xff] ^ rotr(Td0[((s1) >> 16) & 0xff], 8) ^ rotr(Td0[((s0) >> 8) & 0xff], 16) ^ rotr(Td0[(s3) & 0xff], 24) ^ rk[4 * 9 + 2]; t3 = Td0[((s3) >> 24) & 0xff] ^ rotr(Td0[((s2) >> 16) & 0xff], 8) ^ rotr(Td0[((s1) >> 8) & 0xff], 16) ^ rotr(Td0[(s0) & 0xff], 24) ^ rk[4 * 9 + 3];;

   rk += Nr << 2;


   s0 = (Td4s[((t0) >> 24) & 0xff] << 24) ^ (Td4s[((t3) >> 16) & 0xff] << 16) ^ (Td4s[((t2) >> 8) & 0xff] << 8) ^ (Td4s[(t1) & 0xff]) ^ rk[0];
   { (pt)[0] = (u8)((s0) >> 24); (pt)[1] = (u8)((s0) >> 16); (pt)[2] = (u8)((s0) >> 8); (pt)[3] = (u8)(s0); };
   s1 = (Td4s[((t1) >> 24) & 0xff] << 24) ^ (Td4s[((t0) >> 16) & 0xff] << 16) ^ (Td4s[((t3) >> 8) & 0xff] << 8) ^ (Td4s[(t2) & 0xff]) ^ rk[1];
   { (pt + 4)[0] = (u8)((s1) >> 24); (pt + 4)[1] = (u8)((s1) >> 16); (pt + 4)[2] = (u8)((s1) >> 8); (pt + 4)[3] = (u8)(s1); };
   s2 = (Td4s[((t2) >> 24) & 0xff] << 24) ^ (Td4s[((t1) >> 16) & 0xff] << 16) ^ (Td4s[((t0) >> 8) & 0xff] << 8) ^ (Td4s[(t3) & 0xff]) ^ rk[2];
   { (pt + 8)[0] = (u8)((s2) >> 24); (pt + 8)[1] = (u8)((s2) >> 16); (pt + 8)[2] = (u8)((s2) >> 8); (pt + 8)[3] = (u8)(s2); };
   s3 = (Td4s[((t3) >> 24) & 0xff] << 24) ^ (Td4s[((t2) >> 16) & 0xff] << 16) ^ (Td4s[((t1) >> 8) & 0xff] << 8) ^ (Td4s[(t0) & 0xff]) ^ rk[3];
   { (pt + 12)[0] = (u8)((s3) >> 24); (pt + 12)[1] = (u8)((s3) >> 16); (pt + 12)[2] = (u8)((s3) >> 8); (pt + 12)[3] = (u8)(s3); };
}
