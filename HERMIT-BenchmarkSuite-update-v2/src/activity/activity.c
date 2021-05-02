// TODO: Notice stuff, etc.
/* file: activity.c	G. Moody	2 April 1992

-------------------------------------------------------------------------------
activity: Estimate activity level from heart rate signal
Copyright (C) 2002 George B. Moody

This program is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation; either version 2 of the License, or (at your option) any later
version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE.  See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
this program; if not, write to the Free Software Foundation, Inc., 59 Temple
Place - Suite 330, Boston, MA 02111-1307, USA.

You may contact the author by e-mail (george@mit.edu) or postal mail
(MIT Room E25-505A, Cambridge, MA 02139 USA).  For updates to this software,
please visit PhysioNet (http://www.physionet.org/).
_______________________________________________________________________________

This program derives an "activity index" from a time series of instantaneous
heart rate measurements, such as can be produced by 'tach'.  'tach' is included
in the WFDB Software Package;  for details, see
    http://www.physionet.org/physiotools/wag/tach-1.htm

For example:
    tach -r RECORD -a ANNOTATOR -Vs > fileName.ts
    activity -i fileName.ts

Each value of the activity index is derived from 'len' values in the input
heart rate time series;  by default, 5 minutes of input data are used to
produce each output value.  The input windows overlap by 50%, so that the
interval between output values is half of that specified by 'len', or 2.5
minutes by default.  Other values of 'len' can be specified on the command
line, as in:
    tach -r RECORD -a ANNOTATOR | activity 240
which would yield outputs at 1-minute intervals, based on 2-minute windows.

Use activity's '-m' option to find and output only the interval for which
the activity index is minimum.

The activity index is based on mean heart rate, total power of the observed
heart rate signal, and a heart rate stationarity index.  For details, see
"ECG-based indices of physical activity", pp. 403-406, Computers in Cardiology
1992.
*/

#define USE_ACCEL

// Accelerator AXI-lite map
// BUS_A
// // 0x0000 : Control signals
// //          bit 0  - ap_start (Read/Write/COH)
// //          bit 1  - ap_done (Read/COR)
// //          bit 2  - ap_idle (Read)
// //          bit 3  - ap_ready (Read)
// //          bit 7  - auto_restart (Read/Write)
// //          others - reserved
// // 0x0004 : Global Interrupt Enable Register
// //          bit 0  - Global Interrupt Enable (Read/Write)
// //          others - reserved
// // 0x0008 : IP Interrupt Enable Register (Read/Write)
// //          bit 0  - enable ap_done interrupt (Read/Write)
// //          bit 1  - enable ap_ready interrupt (Read/Write)
// //          others - reserved
// // 0x000c : IP Interrupt Status Register (Read/TOW)
// //          bit 0  - ap_done (COR/TOW)
// //          bit 1  - ap_ready (COR/TOW)
// //          others - reserved
// // 0x0040 : Data signal of vals_i
// //          bit 31~0 - vals_i[31:0] (Read/Write)
// // 0x0044 : Data signal of vals_i
// //          bit 31~0 - vals_i[63:32] (Read/Write)
// // 0x0048 : Data signal of vals_i
// //          bit 31~0 - vals_i[95:64] (Read/Write)
// // 0x004c : Data signal of vals_i
// //          bit 31~0 - vals_i[127:96] (Read/Write)
// // 0x0050 : Data signal of vals_i
// //          bit 31~0 - vals_i[159:128] (Read/Write)
// // 0x0054 : Data signal of vals_i
// //          bit 31~0 - vals_i[191:160] (Read/Write)
// // 0x0058 : Data signal of vals_i
// //          bit 31~0 - vals_i[223:192] (Read/Write)
// // 0x005c : Data signal of vals_i
// //          bit 31~0 - vals_i[255:224] (Read/Write)
// // 0x0060 : Data signal of vals_i
// //          bit 31~0 - vals_i[287:256] (Read/Write)
// // 0x0064 : Data signal of vals_i
// //          bit 31~0 - vals_i[319:288] (Read/Write)
// // 0x0068 : Data signal of vals_i
// //          bit 31~0 - vals_i[351:320] (Read/Write)
// // 0x006c : Data signal of vals_i
// //          bit 31~0 - vals_i[383:352] (Read/Write)
// // 0x0070 : Data signal of vals_i
// //          bit 31~0 - vals_i[415:384] (Read/Write)
// // 0x0074 : Data signal of vals_i
// //          bit 31~0 - vals_i[447:416] (Read/Write)
// // 0x0078 : Data signal of vals_i
// //          bit 31~0 - vals_i[479:448] (Read/Write)
// // 0x007c : Data signal of vals_i
// //          bit 31~0 - vals_i[511:480] (Read/Write)
// // 0x0080 : reserved
// // 0x0084 : Data signal of vals_o
// //          bit 31~0 - vals_o[31:0] (Read)
// // 0x0088 : Data signal of vals_o
// //          bit 31~0 - vals_o[63:32] (Read)
// // 0x008c : Data signal of vals_o
// //          bit 31~0 - vals_o[95:64] (Read)
// // 0x0090 : Data signal of vals_o
// //          bit 31~0 - vals_o[127:96] (Read)
// // 0x0094 : Data signal of vals_o
// //          bit 31~0 - vals_o[159:128] (Read)
// // 0x0098 : Data signal of vals_o
// //          bit 31~0 - vals_o[191:160] (Read)
// // 0x009c : Data signal of vals_o
// //          bit 31~0 - vals_o[223:192] (Read)
// // 0x00a0 : Data signal of vals_o
// //          bit 31~0 - vals_o[255:224] (Read)
// // 0x00a4 : Data signal of vals_o
// //          bit 31~0 - vals_o[287:256] (Read)
// // 0x00a8 : Data signal of vals_o
// //          bit 31~0 - vals_o[319:288] (Read)
// // 0x00ac : Data signal of vals_o
// //          bit 31~0 - vals_o[351:320] (Read)
// // 0x00b0 : Data signal of vals_o
// //          bit 31~0 - vals_o[383:352] (Read)
// // 0x00b4 : Data signal of vals_o
// //          bit 31~0 - vals_o[415:384] (Read)
// // 0x00b8 : Data signal of vals_o
// //          bit 31~0 - vals_o[447:416] (Read)
// // 0x00bc : Data signal of vals_o
// //          bit 31~0 - vals_o[479:448] (Read)
// // 0x00c0 : Data signal of vals_o
// //          bit 31~0 - vals_o[511:480] (Read)
// // 0x00c4 : Control signal of vals_o
// //          bit 0  - vals_o_ap_vld (Read/COR)
// //          others - reserved
// // 0x2000 ~
// // 0x3fff : Memory 'hr' (600 * 64b)
// //          Word 2n   : bit [31:0] - hr[n][31: 0]
// //          Word 2n+1 : bit [31:0] - hr[n][63:32]
// // (SC = Self Clear, COR = Clear on Read, TOW = Toggle on Write, COH = Clear on Handshake)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#define SEC2NANOSEC 1000000000

struct timespec main_start, main_end;
struct timespec kernel_start, kernel_end;

#define DEFLEN  600  /* 5 minutes at 2 samples/sec */

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

#ifdef USE_ACCEL
//--------------------------------------- Accelerator stuff start ------------------------------------//
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>

struct timespec accel_TX_start, accel_TX_end;
struct timespec accel_compute_start, accel_compute_end;
struct timespec accel_RX_start, accel_RX_end;

#define ACCEL_BASE_ADDR 0xA0000000
// 4x 4kB pages
#define ACCEL_MMAP_SIZE 16384
#define UDMABUF_MMAP_SIZE 4096

#define OFFSET_TO_STRUCT_INPUT 16
#define OFFSET_TO_STRUCT_OUTPUT 33
#define OFFSET_TO_HR_MEMORY 2048

int accel_control_fd;
volatile unsigned int* accel_control_base_addr;

void init_accel() {
  accel_control_fd = open("/dev/mem", O_RDWR | O_SYNC);
  if (accel_control_fd < 0) {
    printf("[activity] Cannot open /dev/mem. Exiting...\n");
    exit(1);
  }

  accel_control_base_addr = (volatile unsigned int *) mmap(0, ACCEL_MMAP_SIZE, PROT_READ | PROT_WRITE, 
                                                  MAP_SHARED, accel_control_fd, ACCEL_BASE_ADDR);

  if (accel_control_base_addr == MAP_FAILED) {
    printf("[activity] Can't obtain memory map to accel control. Exiting...\n");
    exit(1);
  }
}

void close_accel() {
  munmap((void*) accel_control_base_addr, ACCEL_MMAP_SIZE);
  close(accel_control_fd);
}

void __attribute__((constructor)) setup() {
  printf("[activity] Initializing accelerator...\n");
  init_accel();  
  printf("[activity] Initialization complete!\n");
}

void __attribute__((destructor)) teardown() {
  printf("[activity] Tearing down accelerator...\n");
  close_accel();
  printf("[activity] Teardown complete!\n");
}

void accel_write_reg(volatile unsigned int* base, unsigned int offset, int data) { *(base + offset) = data; }

void accel_enable_input(volatile unsigned int* base) { accel_write_reg(base, 0, 0x01); }

struct timespec accel_TX_start, accel_TX_end;
struct timespec accel_compute_start, accel_compute_end;
struct timespec accel_RX_start, accel_RX_end;

void compute_statistics_accel(struct activity_values *vals, double *hr) {
  clock_gettime(CLOCK_MONOTONIC_RAW, &accel_TX_start);
  unsigned int i = 0;
  // Memcpy the input struct to the input struct registers
  memcpy((accel_control_base_addr + OFFSET_TO_STRUCT_INPUT), vals, sizeof(struct activity_values));
  // *(accel_control_base_addr + OFFSET_TO_STRUCT_INPUT + 0) = vals->i;
  // *(accel_control_base_addr + OFFSET_TO_STRUCT_INPUT + 1) = vals->len;
  // *(accel_control_base_addr + OFFSET_TO_STRUCT_INPUT + 2) = vals->meanhr0;
  // *(accel_control_base_addr + OFFSET_TO_STRUCT_INPUT + 4) = vals->meanhr1;
  // *(accel_control_base_addr + OFFSET_TO_STRUCT_INPUT + 6) = vals->tpower;
  // *(accel_control_base_addr + OFFSET_TO_STRUCT_INPUT + 8) = vals->meanhr;
  // *(accel_control_base_addr + OFFSET_TO_STRUCT_INPUT + 10) = vals->stationarity;
  // *(accel_control_base_addr + OFFSET_TO_STRUCT_INPUT + 12) = vals->p;
  // *(accel_control_base_addr + OFFSET_TO_STRUCT_INPUT + 14) = vals->activity;

  // Memcpy the HR array to the HR memory
  memcpy((accel_control_base_addr + OFFSET_TO_HR_MEMORY), hr, DEFLEN * sizeof(double));

  clock_gettime(CLOCK_MONOTONIC_RAW, &accel_compute_start);

  // printf("Enabling the start bit on the accelerator\n");
  // Enable the input -- the accelerator seems to set it back to 0x00 on its own once it completes
  accel_enable_input(accel_control_base_addr);

  // Wait for complete or something
  unsigned int status = 0;
  while (true) {
    status = (*accel_control_base_addr); 
    if ((status & 0x02) == 0x02) {
      // printf("Exiting loop, status = 0x%x\n", status);
      break;
    }
    else if (i % 100000 == 0) {
      // printf("Waiting for accelerator to complete...... (status: 0x%x)\n", *accel_control_base_addr);
    } 
    i++;
  }

  clock_gettime(CLOCK_MONOTONIC_RAW, &accel_RX_start);

  // Copy the output values of the struct back
  // memcpy(vals, (accel_control_base_addr + OFFSET_TO_STRUCT_OUTPUT), sizeof(struct activity_values));
  unsigned long int upper_half, lower_half, combined_word;
  double* dest;

  vals->i = *(accel_control_base_addr + OFFSET_TO_STRUCT_OUTPUT);
  vals->len = *(accel_control_base_addr + OFFSET_TO_STRUCT_OUTPUT + 1);

  upper_half = *(accel_control_base_addr + OFFSET_TO_STRUCT_OUTPUT + 3);
  lower_half = *(accel_control_base_addr + OFFSET_TO_STRUCT_OUTPUT + 2);
  combined_word = (upper_half << 32) | (lower_half);
  dest = &(vals->meanhr0);
  memcpy(dest, &combined_word, sizeof(double));
  
  upper_half = *(accel_control_base_addr + OFFSET_TO_STRUCT_OUTPUT + 5);
  lower_half = *(accel_control_base_addr + OFFSET_TO_STRUCT_OUTPUT + 4);
  combined_word = (upper_half << 32) | (lower_half);
  dest = &(vals->meanhr1);
  memcpy(dest, &combined_word, sizeof(double));

  upper_half = *(accel_control_base_addr + OFFSET_TO_STRUCT_OUTPUT + 7);
  lower_half = *(accel_control_base_addr + OFFSET_TO_STRUCT_OUTPUT + 6);
  combined_word = (upper_half << 32) | (lower_half);
  dest = &(vals->tpower);
  memcpy(dest, &combined_word, sizeof(double));

  upper_half = *(accel_control_base_addr + OFFSET_TO_STRUCT_OUTPUT + 9);
  lower_half = *(accel_control_base_addr + OFFSET_TO_STRUCT_OUTPUT + 8);
  combined_word = (upper_half << 32) | (lower_half);
  dest = &(vals->meanhr);
  memcpy(dest, &combined_word, sizeof(double));
  
  upper_half = *(accel_control_base_addr + OFFSET_TO_STRUCT_OUTPUT + 11);
  lower_half = *(accel_control_base_addr + OFFSET_TO_STRUCT_OUTPUT + 10);
  combined_word = (upper_half << 32) | (lower_half);
  dest = &(vals->stationarity);
  memcpy(dest, &combined_word, sizeof(double));

  upper_half = *(accel_control_base_addr + OFFSET_TO_STRUCT_OUTPUT + 13);
  lower_half = *(accel_control_base_addr + OFFSET_TO_STRUCT_OUTPUT + 12);
  combined_word = (upper_half << 32) | (lower_half);
  dest = &(vals->p);
  memcpy(dest, &combined_word, sizeof(double));

  upper_half = *(accel_control_base_addr + OFFSET_TO_STRUCT_OUTPUT + 15);
  lower_half = *(accel_control_base_addr + OFFSET_TO_STRUCT_OUTPUT + 14);
  combined_word = (upper_half << 32) | (lower_half);
  dest = &(vals->activity);
  memcpy(dest, &combined_word, sizeof(double));

  clock_gettime(CLOCK_MONOTONIC_RAW, &accel_RX_end);
  // printf("Accelerator execution complete!\n\n");
}
//---------------------------------------- Accelerator stuff end -------------------------------------//
#endif


void compute_statistics(struct activity_values *vals, double *hr) {
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

  clock_gettime(CLOCK_MONOTONIC_RAW, &main_start);
  char buf[80];
  struct activity_values vals;
  double *hr;
  double *t;
  double acmin = -1.0, hrmin, stmin, tpmin, tmin0, tmin1;
  vals.i = 0;
  vals.len = DEFLEN;

  long tt = 0L;
  FILE *in_file, *out_file;
  bool mflag = false, inputFile = false;

#ifdef USE_ACCEL
  printf("Utilizing the accelerator\n");
#else
  printf("Not utilizing accelerator, using CPU implementation\n");
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

  if ((t = (double *) malloc(vals.len * sizeof(double))) == NULL || (hr = (double *) malloc(vals.len * sizeof(double))) == NULL) {
    printf("%s: Insufficient memory\n", argv[0]);
    return -1;
  }

  out_file = fopen("test-activity-out.txt", "w");
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

      // printf("Dumping struct values BEFORE calling compute_statistics:\n");
      // printf("i: %d, len: %d, meanhr0: %lf, meanhr1: %lf, tpower: %lf, meanhr: %lf, stationarity: %lf, p: %lf, activity: %lf\n\n",
      //         vals.i, vals.len, vals.meanhr0, vals.meanhr1, vals.tpower, vals.meanhr, vals.stationarity, vals.p, vals.activity);
      clock_gettime(CLOCK_MONOTONIC_RAW, &kernel_start);
#ifdef USE_ACCEL
      compute_statistics_accel(&vals, hr);
#else
      compute_statistics(&vals, hr);
#endif
      clock_gettime(CLOCK_MONOTONIC_RAW, &kernel_end);
      // printf("Dumping struct values AFTER calling compute_statistics:\n");
      // printf("i: %d, len: %d, meanhr0: %lf, meanhr1: %lf, tpower: %lf, meanhr: %lf, stationarity: %lf, p: %lf, activity: %lf\n\n",
      //         vals.i, vals.len, vals.meanhr0, vals.meanhr1, vals.tpower, vals.meanhr, vals.stationarity, vals.p, vals.activity);

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

  clock_gettime(CLOCK_MONOTONIC_RAW, &main_end);

  unsigned long int e2e_time = (main_end.tv_sec * SEC2NANOSEC + main_end.tv_nsec) - (main_start.tv_sec * SEC2NANOSEC + main_start.tv_nsec);
  unsigned long int kernel_time = (kernel_end.tv_sec * SEC2NANOSEC + kernel_end.tv_nsec) - (kernel_start.tv_sec * SEC2NANOSEC + kernel_start.tv_nsec);

#ifndef USE_ACCEL
  printf("CPU-based activity: full execution took %ld ns, kernel execution took %ld ns\n", e2e_time, kernel_time);
#else
  accel_TX_end = accel_compute_start;
  accel_compute_end = accel_RX_start;

  unsigned long int accel_TX_time = (accel_TX_end.tv_sec * SEC2NANOSEC + accel_TX_end.tv_nsec) - (accel_TX_start.tv_sec * SEC2NANOSEC + accel_TX_start.tv_nsec);
  unsigned long int accel_compute_time = (accel_compute_end.tv_sec * SEC2NANOSEC + accel_compute_end.tv_nsec) - (accel_compute_start.tv_sec * SEC2NANOSEC + accel_compute_start.tv_nsec);
  unsigned long int accel_RX_time = (accel_RX_end.tv_sec * SEC2NANOSEC + accel_RX_end.tv_nsec) - (accel_RX_start.tv_sec * SEC2NANOSEC + accel_RX_start.tv_nsec);

  printf("Accel-based activity: full execution took %ld ns, kernel execution took %ld ns, accel TX took %ld ns, accel compute took %ld ns, accel RX took %ld ns\n",
          e2e_time, kernel_time, accel_TX_time, accel_compute_time, accel_RX_time);
#endif
  return 0;
}
