#include <stdio.h>
#include <string.h>

#define VEC_SIZE 128

struct hls_values {
	int A;
	int B;
	int C;
};

void vector_add(struct hls_values* vals) {
#pragma HLS INTERFACE s_axilite port=vals bundle=BUS_A
#pragma HLS INTERFACE s_axilite port=return bundle=BUS_A

	vals->C = vals->A + vals->B;
//	*C = *A + *B;
}
