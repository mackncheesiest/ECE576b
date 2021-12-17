#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

//#define COMPUTE_REF
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

void compute_statistics(double *hr, struct activity_values *vals);

void compute_statistics_ref(double *hr, struct activity_values *vals) {
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

int main(int argc, char *argv[]) {

  char buf[80];
  struct activity_values vals;
  double *hr;
  double *t;
  double acmin = -1.0, hrmin, stmin, tpmin, tmin0, tmin1;
  vals.i = 0;
  vals.len = DEFLEN;

  int status = 0;

  long tt = 0L;
  FILE *in_file, *out_file;
  bool mflag = false, inputFile = false;
#ifndef COMPUTE_REF
  FILE *out_file_expected, *out_file_actual;

  char *expected_line, *actual_line;
  size_t unused_len;
  ssize_t expected_len, actual_len;

  int curr_line;
#endif

  for (int j = 1 ; j < argc ; ++j) {
    if (strcmp(argv[j], "-r") == 0) {
      inputFile = true;
      if ((in_file = fopen(argv[(j + 1)], "r")) == NULL) {
        inputFile = false;
      }
    } else if (strcmp(argv[j], "-len") == 0) {
      vals.len = atoi(argv[(j + 1)]);
    } else if (strcmp(argv[j], "-m") == 0) {
      mflag = true;
    }
  }

  if (!inputFile) {
    printf("Incorrect input file! Using test input: \"test-100.ts\" \n");
    in_file = fopen("test-100.ts", "r");
  }
//  in_file = fopen("test-100.ts", "r");

  if ((t = (double *) malloc(vals.len * sizeof(double))) == NULL || (hr = (double *) malloc(vals.len * sizeof(double))) == NULL) {
    printf("%s: Insufficient memory\n", argv[0]);
    return -1;
  }

#ifdef COMPUTE_REF
  out_file = fopen("test-activity-out-ref.txt", "w");
  #else
  out_file = fopen("test-activity-out.txt", "w");
#endif
  while (fgets(buf, 80, in_file)) {
    int n = sscanf(buf, "%lf %lf", &(t[vals.i]), &(hr[vals.i]));

    if (n == 0) {
      continue;    /* skip empty lines in input */
    }

    if (n == 1) {
      hr[vals.i] = t[vals.i];
      t[vals.i] = tt / 2.0;
    }

    ++tt;

    if (++(vals.i) >= vals.len) {

#ifdef COMPUTE_REF
    compute_statistics_ref(hr, &vals);
#else
    compute_statistics(hr, &vals);
#endif

      if (!mflag) {
        fprintf(out_file, "%g \t %g \t %g \t %g \t %g \n", t[(vals.len / 4) - 1], vals.meanhr, vals.tpower, vals.stationarity, vals.activity);
        fprintf(out_file,
                "%g \t %g \t %g \t %g \t %g \n",
                t[(3 * (vals.len / 4)) - 1],
                vals.meanhr,
                vals.tpower,
                vals.stationarity,
                vals.activity);
      } else if ((vals.activity < acmin) || (acmin < 0.)) {
        acmin = vals.activity;
        hrmin = vals.meanhr;
        stmin = vals.stationarity;
        tpmin = vals.tpower;
        tmin0 = t[0];
        tmin1 = t[vals.len - 1];
      }

      for (vals.i = 0 ; vals.i < (vals.len / 2) ; (vals.i)++) {
        hr[vals.i] = hr[vals.i + (vals.len / 2)];
        t[vals.i] = t[vals.i + (vals.len / 2)];
      }
    }
  }

  if (mflag) {
    fprintf(out_file, "%g \t %g \t %g \t %g \t %g \t %g \n", tmin0, tmin1, hrmin, tpmin, stmin, acmin);
  }

  fclose(in_file);
  fclose(out_file);

#ifndef COMPUTE_REF
  out_file_expected = fopen("test-activity-out-ref.txt", "r");
  out_file_actual = fopen("test-activity-out.txt", "r");

  curr_line = 0;
  while (true) {
	  expected_len = getline(&expected_line, &unused_len, out_file_expected);
	  actual_len = getline(&actual_line, &unused_len, out_file_actual);

	  if (expected_len == -1 && actual_len == -1) {
		  break;
	  } else if (expected_len * actual_len < 0) { // If this product is negative, then one is -1 and the other isn't, so that's a problem
		  fprintf(stderr, "The expected file doesn't have the same number of lines as the actual file!\n");
		  status = 1;
		  break;
	  }

	  if (strcmp(expected_line, actual_line) != 0) {
		  fprintf(stderr, "The expected line and actual line differ on line %d!\nExpected line: '%s'\nActual line: '%s'\n", curr_line, expected_line, actual_line);
		  status = 1;
	  }

	  curr_line++;
  }

  if (status == 0) {
	  fprintf(stdout, "The expected file matches the actual file!\n");
  }
#endif

  return status;
}
