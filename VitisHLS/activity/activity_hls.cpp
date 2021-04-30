#include "math.h"

#define DEFLEN 600

struct activity_values {
  int i;
  int len;
  double meanhr0;
  double meanhr1;
  double tpower;
  double meanhr;
  double stationarity;
  double p;
  double activity;
};

void compute_statistics(double hr[DEFLEN], struct activity_values *vals) {
#pragma HLS INTERFACE s_axilite port=hr bundle=BUS_A
#pragma HLS INTERFACE s_axilite port=vals bundle=BUS_A
#pragma HLS INTERFACE s_axilite port=return bundle=BUS_A
  /* hr buffer full -- emit output and reset */
  vals->meanhr0 = 0.0;
  vals->meanhr1 = 0.0;
  vals->tpower = 0.0;

  for (vals->i = 0; vals->i < vals->len / 2 ; (vals->i)++) {
    vals->meanhr0 += hr[vals->i];
  }

  for (; vals->i < vals->len ; (vals->i)++) {
    vals->meanhr1 += hr[vals->i];
  }

  vals->meanhr0 /= vals->len / 2;
  vals->meanhr1 /= vals->len / 2;
  vals->meanhr = (vals->meanhr0 + vals->meanhr1) / 2;
  vals->stationarity = vals->meanhr0 - vals->meanhr1;

  if (vals->stationarity < 0) {
    vals->stationarity = -vals->stationarity;
  }

  for (vals->i = 0 ; vals->i < vals->len ; (vals->i)++) {
    vals->p = hr[vals->i] - vals->meanhr;
    vals->tpower += vals->p * vals->p;
  }

  vals->tpower /= vals->len;

  if (vals->tpower > 100.) {
    vals->tpower = 100.;
  }

  vals->activity = sqrt(((vals->meanhr - 40.) * (vals->meanhr - 40.)) + (10. * vals->stationarity * vals->stationarity) + (100. * vals->tpower));

  if (vals->meanhr < 25.) {
    /* penalty for unbelievably low heart rates */
    vals->activity += 25. - vals->meanhr;
  }
}
