#include <math.h>

void activity_kernel(int len, double* hr, double* t, double* meanhr, double* tpower, double* stationarity, double* activity, double* acmin, double* hrmin, double* stmin, double* tpmin, double* tmin0, double* tmin1) {

      double meanhr0, meanhr1, p;
      int i;

      /* hr buffer full -- emit output and reset */
      meanhr0 = meanhr1 = *tpower = 0.0;

      for (i = 0 ; i < len / 2 ; i++) {
        meanhr0 += hr[i];
      }

      for (; i < len ; i++) {
        meanhr1 += hr[i];
      }

      meanhr0 /= len / 2;
      meanhr1 /= len / 2;
      *meanhr = (meanhr0 + meanhr1) / 2;
      *stationarity = meanhr0 - meanhr1;

      if (*stationarity < 0) {
        *stationarity = -1.0 * (*stationarity);
      }

      for (i = 0 ; i < len ; i++) {
        p = hr[i] - *meanhr;
        *tpower += p * p;
      }

      *tpower /= len;

      if (*tpower > 100.) {
        *tpower = 100.;
      }

      *activity = sqrt(((*meanhr - 40.) * (*meanhr - 40.)) + (10. * *stationarity * *stationarity) + (100. * *tpower));

      if (*meanhr < 25.) {
        /* penalty for unbelievably low heart rates */
        *activity += 25. - *meanhr;
      }
      
      if ((*activity < *acmin) || (*acmin < 0.)) {
        *acmin = *activity;
        *hrmin = *meanhr;
        *stmin = *stationarity;
        *tpmin = *tpower;
        *tmin0 = t[0];
        *tmin1 = t[len - 1];
      }

}
