#include "ap_int.h"

typedef unsigned int u32;
typedef unsigned char u8;


static const u32 Te0[256] = {
    0xc66363a5U, 0xf87c7c84U, 0xee777799U, 0xf67b7b8dU,
    0xfff2f20dU, 0xd66b6bbdU, 0xde6f6fb1U, 0x91c5c554U,
    0x60303050U, 0x02010103U, 0xce6767a9U, 0x562b2b7dU,
    0xe7fefe19U, 0xb5d7d762U, 0x4dababe6U, 0xec76769aU,
    0x8fcaca45U, 0x1f82829dU, 0x89c9c940U, 0xfa7d7d87U,
    0xeffafa15U, 0xb25959ebU, 0x8e4747c9U, 0xfbf0f00bU,
    0x41adadecU, 0xb3d4d467U, 0x5fa2a2fdU, 0x45afafeaU,
    0x239c9cbfU, 0x53a4a4f7U, 0xe4727296U, 0x9bc0c05bU,
    0x75b7b7c2U, 0xe1fdfd1cU, 0x3d9393aeU, 0x4c26266aU,
    0x6c36365aU, 0x7e3f3f41U, 0xf5f7f702U, 0x83cccc4fU,
    0x6834345cU, 0x51a5a5f4U, 0xd1e5e534U, 0xf9f1f108U,
    0xe2717193U, 0xabd8d873U, 0x62313153U, 0x2a15153fU,
    0x0804040cU, 0x95c7c752U, 0x46232365U, 0x9dc3c35eU,
    0x30181828U, 0x379696a1U, 0x0a05050fU, 0x2f9a9ab5U,
    0x0e070709U, 0x24121236U, 0x1b80809bU, 0xdfe2e23dU,
    0xcdebeb26U, 0x4e272769U, 0x7fb2b2cdU, 0xea75759fU,
    0x1209091bU, 0x1d83839eU, 0x582c2c74U, 0x341a1a2eU,
    0x361b1b2dU, 0xdc6e6eb2U, 0xb45a5aeeU, 0x5ba0a0fbU,
    0xa45252f6U, 0x763b3b4dU, 0xb7d6d661U, 0x7db3b3ceU,
    0x5229297bU, 0xdde3e33eU, 0x5e2f2f71U, 0x13848497U,
    0xa65353f5U, 0xb9d1d168U, 0x00000000U, 0xc1eded2cU,
    0x40202060U, 0xe3fcfc1fU, 0x79b1b1c8U, 0xb65b5bedU,
    0xd46a6abeU, 0x8dcbcb46U, 0x67bebed9U, 0x7239394bU,
    0x944a4adeU, 0x984c4cd4U, 0xb05858e8U, 0x85cfcf4aU,
    0xbbd0d06bU, 0xc5efef2aU, 0x4faaaae5U, 0xedfbfb16U,
    0x864343c5U, 0x9a4d4dd7U, 0x66333355U, 0x11858594U,
    0x8a4545cfU, 0xe9f9f910U, 0x04020206U, 0xfe7f7f81U,
    0xa05050f0U, 0x783c3c44U, 0x259f9fbaU, 0x4ba8a8e3U,
    0xa25151f3U, 0x5da3a3feU, 0x804040c0U, 0x058f8f8aU,
    0x3f9292adU, 0x219d9dbcU, 0x70383848U, 0xf1f5f504U,
    0x63bcbcdfU, 0x77b6b6c1U, 0xafdada75U, 0x42212163U,
    0x20101030U, 0xe5ffff1aU, 0xfdf3f30eU, 0xbfd2d26dU,
    0x81cdcd4cU, 0x180c0c14U, 0x26131335U, 0xc3ecec2fU,
    0xbe5f5fe1U, 0x359797a2U, 0x884444ccU, 0x2e171739U,
    0x93c4c457U, 0x55a7a7f2U, 0xfc7e7e82U, 0x7a3d3d47U,
    0xc86464acU, 0xba5d5de7U, 0x3219192bU, 0xe6737395U,
    0xc06060a0U, 0x19818198U, 0x9e4f4fd1U, 0xa3dcdc7fU,
    0x44222266U, 0x542a2a7eU, 0x3b9090abU, 0x0b888883U,
    0x8c4646caU, 0xc7eeee29U, 0x6bb8b8d3U, 0x2814143cU,
    0xa7dede79U, 0xbc5e5ee2U, 0x160b0b1dU, 0xaddbdb76U,
    0xdbe0e03bU, 0x64323256U, 0x743a3a4eU, 0x140a0a1eU,
    0x924949dbU, 0x0c06060aU, 0x4824246cU, 0xb85c5ce4U,
    0x9fc2c25dU, 0xbdd3d36eU, 0x43acacefU, 0xc46262a6U,
    0x399191a8U, 0x319595a4U, 0xd3e4e437U, 0xf279798bU,
    0xd5e7e732U, 0x8bc8c843U, 0x6e373759U, 0xda6d6db7U,
    0x018d8d8cU, 0xb1d5d564U, 0x9c4e4ed2U, 0x49a9a9e0U,
    0xd86c6cb4U, 0xac5656faU, 0xf3f4f407U, 0xcfeaea25U,
    0xca6565afU, 0xf47a7a8eU, 0x47aeaee9U, 0x10080818U,
    0x6fbabad5U, 0xf0787888U, 0x4a25256fU, 0x5c2e2e72U,
    0x381c1c24U, 0x57a6a6f1U, 0x73b4b4c7U, 0x97c6c651U,
    0xcbe8e823U, 0xa1dddd7cU, 0xe874749cU, 0x3e1f1f21U,
    0x964b4bddU, 0x61bdbddcU, 0x0d8b8b86U, 0x0f8a8a85U,
    0xe0707090U, 0x7c3e3e42U, 0x71b5b5c4U, 0xcc6666aaU,
    0x904848d8U, 0x06030305U, 0xf7f6f601U, 0x1c0e0e12U,
    0xc26161a3U, 0x6a35355fU, 0xae5757f9U, 0x69b9b9d0U,
    0x17868691U, 0x99c1c158U, 0x3a1d1d27U, 0x279e9eb9U,
    0xd9e1e138U, 0xebf8f813U, 0x2b9898b3U, 0x22111133U,
    0xd26969bbU, 0xa9d9d970U, 0x078e8e89U, 0x339494a7U,
    0x2d9b9bb6U, 0x3c1e1e22U, 0x15878792U, 0xc9e9e920U,
    0x87cece49U, 0xaa5555ffU, 0x50282878U, 0xa5dfdf7aU,
    0x038c8c8fU, 0x59a1a1f8U, 0x09898980U, 0x1a0d0d17U,
    0x65bfbfdaU, 0xd7e6e631U, 0x844242c6U, 0xd06868b8U,
    0x824141c3U, 0x299999b0U, 0x5a2d2d77U, 0x1e0f0f11U,
    0x7bb0b0cbU, 0xa85454fcU, 0x6dbbbbd6U, 0x2c16163aU,
};


//static const unsigned char Td4s[256] = {
//    0x52U, 0x09U, 0x6aU, 0xd5U, 0x30U, 0x36U, 0xa5U, 0x38U,
//    0xbfU, 0x40U, 0xa3U, 0x9eU, 0x81U, 0xf3U, 0xd7U, 0xfbU,
//    0x7cU, 0xe3U, 0x39U, 0x82U, 0x9bU, 0x2fU, 0xffU, 0x87U,
//    0x34U, 0x8eU, 0x43U, 0x44U, 0xc4U, 0xdeU, 0xe9U, 0xcbU,
//    0x54U, 0x7bU, 0x94U, 0x32U, 0xa6U, 0xc2U, 0x23U, 0x3dU,
//    0xeeU, 0x4cU, 0x95U, 0x0bU, 0x42U, 0xfaU, 0xc3U, 0x4eU,
//    0x08U, 0x2eU, 0xa1U, 0x66U, 0x28U, 0xd9U, 0x24U, 0xb2U,
//    0x76U, 0x5bU, 0xa2U, 0x49U, 0x6dU, 0x8bU, 0xd1U, 0x25U,
//    0x72U, 0xf8U, 0xf6U, 0x64U, 0x86U, 0x68U, 0x98U, 0x16U,
//    0xd4U, 0xa4U, 0x5cU, 0xccU, 0x5dU, 0x65U, 0xb6U, 0x92U,
//    0x6cU, 0x70U, 0x48U, 0x50U, 0xfdU, 0xedU, 0xb9U, 0xdaU,
//    0x5eU, 0x15U, 0x46U, 0x57U, 0xa7U, 0x8dU, 0x9dU, 0x84U,
//    0x90U, 0xd8U, 0xabU, 0x00U, 0x8cU, 0xbcU, 0xd3U, 0x0aU,
//    0xf7U, 0xe4U, 0x58U, 0x05U, 0xb8U, 0xb3U, 0x45U, 0x06U,
//    0xd0U, 0x2cU, 0x1eU, 0x8fU, 0xcaU, 0x3fU, 0x0fU, 0x02U,
//    0xc1U, 0xafU, 0xbdU, 0x03U, 0x01U, 0x13U, 0x8aU, 0x6bU,
//    0x3aU, 0x91U, 0x11U, 0x41U, 0x4fU, 0x67U, 0xdcU, 0xeaU,
//    0x97U, 0xf2U, 0xcfU, 0xceU, 0xf0U, 0xb4U, 0xe6U, 0x73U,
//    0x96U, 0xacU, 0x74U, 0x22U, 0xe7U, 0xadU, 0x35U, 0x85U,
//    0xe2U, 0xf9U, 0x37U, 0xe8U, 0x1cU, 0x75U, 0xdfU, 0x6eU,
//    0x47U, 0xf1U, 0x1aU, 0x71U, 0x1dU, 0x29U, 0xc5U, 0x89U,
//    0x6fU, 0xb7U, 0x62U, 0x0eU, 0xaaU, 0x18U, 0xbeU, 0x1bU,
//    0xfcU, 0x56U, 0x3eU, 0x4bU, 0xc6U, 0xd2U, 0x79U, 0x20U,
//    0x9aU, 0xdbU, 0xc0U, 0xfeU, 0x78U, 0xcdU, 0x5aU, 0xf4U,
//    0x1fU, 0xddU, 0xa8U, 0x33U, 0x88U, 0x07U, 0xc7U, 0x31U,
//    0xb1U, 0x12U, 0x10U, 0x59U, 0x27U, 0x80U, 0xecU, 0x5fU,
//    0x60U, 0x51U, 0x7fU, 0xa9U, 0x19U, 0xb5U, 0x4aU, 0x0dU,
//    0x2dU, 0xe5U, 0x7aU, 0x9fU, 0x93U, 0xc9U, 0x9cU, 0xefU,
//    0xa0U, 0xe0U, 0x3bU, 0x4dU, 0xaeU, 0x2aU, 0xf5U, 0xb0U,
//    0xc8U, 0xebU, 0xbbU, 0x3cU, 0x83U, 0x53U, 0x99U, 0x61U,
//    0x17U, 0x2bU, 0x04U, 0x7eU, 0xbaU, 0x77U, 0xd6U, 0x26U,
//    0xe1U, 0x69U, 0x14U, 0x63U, 0x55U, 0x21U, 0x0cU, 0x7dU,
//};
static inline u32 rotr(u32 val, int bits)
{
	return (val >> bits) | (val << (32 - bits));
}

//#define TE0(i) Te0[((i) >> 24) & 0xff]
//#define TE1(i) rotr(Te0[((i) >> 16) & 0xff], 8)
//#define TE2(i) rotr(Te0[((i) >> 8) & 0xff], 16)
//#define TE3(i) rotr(Te0[(i) & 0xff], 24)


#ifdef _MSC_VER
	#define GETU32(p) SWAP(*((u32 *)(p)))
	#define PUTU32(ct, st) { *((u32 *)(ct)) = SWAP((st)); }
#else
	#define GETU32(pt) (((u32)(pt)[0] << 24) ^ ((u32)(pt)[1] << 16) ^ \
			((u32)(pt)[2] <<  8) ^ ((u32)(pt)[3]))
	#define PUTU32(ct, st) { \
			(ct)[0] = (u8)((st) >> 24); (ct)[1] = (u8)((st) >> 16); \
			(ct)[2] = (u8)((st) >>  8); (ct)[3] = (u8)(st); }
#endif


//int GETU32( char pt0, char pt1, char pt2, char pt3){
//	return ((int) pt0 << 24) ^ ((int) pt1 << 16) ^ ((int) pt2 << 8) ^ ((int) pt3);
//}


//int TE(int num, int i){
//	int x = Te0[(num >> (32-((i+1) * 8))) & 0xff];
//	return (x >> ((i)*8)) | (x << (32 - ((i)*8))) ; // Rotation
//}

//int TE4(int num, int i){
//	if (i == 1)
//		return (int)(Te0[((num) >> 24) & 0xff] << 8) & 0xff000000;
//	else if (i == 4)
//		return (int)(Te0[(num) & 0xff] >> 8) & 0x000000ff;
//	else
//		return (int)(Te0[((num) >> (32 - (i*8))) & 0xff]) & (0xff000000 >> ((i-1)*8));
//}

#define TE0(i) Te0[((i) >> 24) & 0xff]
#define TE1(i) rotr(Te0[((i) >> 16) & 0xff], 8)
#define TE2(i) rotr(Te0[((i) >> 8) & 0xff], 16)
#define TE3(i) rotr(Te0[(i) & 0xff], 24)
#define TE41(i) ((Te0[((i) >> 24) & 0xff] << 8) & 0xff000000)
#define TE42(i) (Te0[((i) >> 16) & 0xff] & 0x00ff0000)
#define TE43(i) (Te0[((i) >> 8) & 0xff] & 0x0000ff00)
#define TE44(i) ((Te0[(i) & 0xff] >> 8) & 0x000000ff)

#define TE421(i) ((Te0[((i) >> 16) & 0xff] << 8) & 0xff000000)
#define TE432(i) (Te0[((i) >> 8) & 0xff] & 0x00ff0000)
#define TE443(i) (Te0[(i) & 0xff] & 0x0000ff00)
#define TE414(i) ((Te0[((i) >> 24) & 0xff] >> 8) & 0x000000ff)
#define TE4(i) ((Te0[(i)] >> 8) & 0x000000ff)



//void ROUND(int *d, int *s, int rk0, int rk1, int rk2, int rk3){
//	d[0] = TE(s[0], 0) ^ TE(s[1], 1) ^ TE(s[2], 2) ^ TE(s[3], 3) ^ rk0;
//	d[1] = TE(s[1], 1) ^ TE(s[2], 2) ^ TE(s[3], 3) ^ TE(s[0], 0) ^ rk1;
//	d[2] = TE(s[2], 2) ^ TE(s[3], 3) ^ TE(s[0], 0) ^ TE(s[1], 1) ^ rk2;
//	d[3] = TE(s[3], 3) ^ TE(s[0], 0) ^ TE(s[1], 1) ^ TE(s[2], 2) ^ rk3;
//}
#define ROUND(i,d,s) \
		d##0 = TE0(s##0) ^ TE1(s##1) ^ TE2(s##2) ^ TE3(s##3) ^ rk[4 * i]; \
		d##1 = TE0(s##1) ^ TE1(s##2) ^ TE2(s##3) ^ TE3(s##0) ^ rk[4 * i + 1]; \
		d##2 = TE0(s##2) ^ TE1(s##3) ^ TE2(s##0) ^ TE3(s##1) ^ rk[4 * i + 2]; \
		d##3 = TE0(s##3) ^ TE1(s##0) ^ TE2(s##1) ^ TE3(s##2) ^ rk[4 * i + 3]


//void PUTU32(char *ct, int st){
//	ct[0] = (char) ((st) >> 24);
//	ct[1] = (char) ((st) >> 16);
//	ct[2] = (char) ((st) >> 8);
//	ct[3] = (char) (st);
//}

//struct key {
//	int k0; int k1; int k2; int k3; int k4; int k5; int k6; int k7; int k8; int k9; int k10; int k11; int k12; int k13; int k14; int k15;
//	int k16; int k17; int k18; int k19; int k20; int k21; int k22; int k23; int k24; int k25; int k26; int k27; int k28; int k29; int k30; int k31;
//	int k32; int k33; int k34; int k35; int k36; int k37; int k38; int k39; int k40; int k41; int k42; int k43;
//};
//
//struct text {
//	char t0; char t1; char t2; char t3; char t4; char t5; char t6; char t7;
//	char t8; char t9; char t10; char t11; char t12; char t13; char t14; char t15;
//};

//void rijndaelEncrypt_hls(struct key *rk, struct text *pt, struct text *ct){
void rijndaelEncrypt_hls(u32 rk[44], u8 pt[16], u8 ct[16]){

	//ap_int<32>
	//int s0, s1, s2, s3, t0, t1, t2, t3;

#pragma HLS INTERFACE s_axilite port=rk bundle=BUS_A
#pragma HLS INTERFACE s_axilite port=pt bundle=BUS_A
#pragma HLS INTERFACE s_axilite port=ct bundle=BUS_A
#pragma HLS INTERFACE s_axilite port=return bundle=BUS_A
//#pragma HLS INTERFACE ap_ctrl_hs port=return bundle=BUS_A

//	int s[4], t[4];
	u32 s0, s1, s2, s3, t0, t1, t2, t3;
	const int Nr = 10;

//	s[0] = GETU32(pt[0], pt[1], pt[2], pt[3]) ^ rk[0];
//	s[1] = GETU32(pt[4], pt[5], pt[6], pt[7]) ^ rk[1];
//	s[2] = GETU32(pt[8], pt[9], pt[10], pt[11]) ^ rk[2];
//	s[3] = GETU32(pt[12], pt[13], pt[14], pt[15]) ^ rk[3];
	s0 = GETU32(pt     ) ^ rk[0];
	s1 = GETU32(pt +  4) ^ rk[1];
	s2 = GETU32(pt +  8) ^ rk[2];
	s3 = GETU32(pt + 12) ^ rk[3];


//	ROUND(t, s, rk[4], rk[5], rk[6], rk[7]); //ROUND(1, t, s, rk);
//	ROUND(s, t, rk[8], rk[9], rk[10], rk[11]) ;//ROUND(2, s, t, rk);
//	ROUND(t, s, rk[12], rk[13], rk[14], rk[15]); //ROUND(3, t, s, rk);
//	ROUND(s, t, rk[16], rk[17], rk[18], rk[19]); //ROUND(4, s, t, rk);
//	ROUND(t, s, rk[20], rk[21], rk[22], rk[23]); //ROUND(5, t, s, rk);
//	ROUND(s, t, rk[24], rk[25], rk[26], rk[27]);  //ROUND(6, s, t, rk);
//	ROUND(t, s, rk[28], rk[29], rk[30], rk[31]);  //ROUND(7, t, s, rk);
//	ROUND(s, t, rk[32], rk[33], rk[34], rk[35]);  //ROUND(8, s, t, rk);
//	ROUND(t, s, rk[36], rk[37], rk[38], rk[39]);//ROUND(9, t, s, rk);

	ROUND(1,t,s);
	ROUND(2,s,t);
	ROUND(3,t,s);
	ROUND(4,s,t);
	ROUND(5,t,s);
	ROUND(6,s,t);
	ROUND(7,t,s);
	ROUND(8,s,t);
	ROUND(9,t,s);

	rk += Nr << 2;

    //int index = Nr << 2;
    //rk += Nr << 2;



    // Final round
	s0 = TE41(t0) ^ TE42(t1) ^ TE43(t2) ^ TE44(t3) ^ rk[0];
	PUTU32(ct     , s0);
	s1 = TE41(t1) ^ TE42(t2) ^ TE43(t3) ^ TE44(t0) ^ rk[1];
	PUTU32(ct +  4, s1);
	s2 = TE41(t2) ^ TE42(t3) ^ TE43(t0) ^ TE44(t1) ^ rk[2];
	PUTU32(ct +  8, s2);
	s3 = TE41(t3) ^ TE42(t0) ^ TE43(t1) ^ TE44(t2) ^ rk[3];
	PUTU32(ct + 12, s3);


//    s[0] = TE4(t[0], 1) ^ TE4(t[1], 2) ^ TE4(t[2], 3) ^ TE4(t[3], 4) ^ rk[40];
//    //PUTU32(ct, s[0]);
//	ct[0] = (char) ((s[0]) >> 24);
//	ct[1] = (char) ((s[0]) >> 16);
//	ct[2] = (char) ((s[0]) >> 8);
//	ct[3] = (char) (s[0]);
//
//	s[1] = TE4(t[1], 1) ^ TE4(t[2], 2) ^ TE4(t[3], 3) ^ TE4(t[0], 4) ^ rk[41];
//    //PUTU32(ct + 4, s[1]);
//	ct[4] = (char) ((s[1]) >> 24);
//	ct[5] = (char) ((s[1]) >> 16);
//	ct[6] = (char) ((s[1]) >> 8);
//	ct[7] = (char) (s[1]);
//
//    s[2] = TE4(t[2], 1) ^ TE4(t[3], 2) ^ TE4(t[0], 3) ^ TE4(t[1], 4) ^ rk[42];
//    //PUTU32(ct + 8, s[2]);
//	ct[8] = (char) ((s[2]) >> 24);
//	ct[9] = (char) ((s[2]) >> 16);
//	ct[10] = (char) ((s[2]) >> 8);
//	ct[11] = (char) (s[2]);
//
//    s[3] = TE4(t[3], 1) ^ TE4(t[0], 2) ^ TE4(t[1], 3) ^ TE4(t[2], 4) ^ rk[43];
//    //PUTU32(ct + 12, s[3]);
//	ct[12] = (char) ((s[3]) >> 24);
//	ct[13] = (char) ((s[3]) >> 16);
//	ct[14] = (char) ((s[3]) >> 8);
//	ct[15] = (char) (s[3]);

//    for (int i=0; i < 16; i++)
//    	ct[i] = s[0];
}
