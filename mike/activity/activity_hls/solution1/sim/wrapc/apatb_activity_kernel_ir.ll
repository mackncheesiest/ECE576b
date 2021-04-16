; ModuleID = '/home/mikesinouye/ECE576b/mike/activity/activity_hls/solution1/.autopilot/db/a.g.ld.5.gdce.bc'
source_filename = "llvm-link"
target datalayout = "e-m:e-i64:64-i128:128-i256:256-i512:512-i1024:1024-i2048:2048-i4096:4096-n8:16:32:64-S128-v16:16-v24:32-v32:32-v48:64-v96:128-v192:256-v256:256-v512:512-v1024:1024"
target triple = "fpga64-xilinx-none"

; Function Attrs: argmemonly noinline
define void @apatb_activity_kernel_ir(i32 %len, double* %hr, double* %t, double* %meanhr, double* %tpower, double* %stationarity, double* %activity, double* %acmin, double* %hrmin, double* %stmin, double* %tpmin, double* %tmin0, double* %tmin1) local_unnamed_addr #0 {
entry:
  %hr_copy = alloca double, align 512
  %t_copy = alloca double, align 512
  %meanhr_copy = alloca double, align 512
  %tpower_copy = alloca double, align 512
  %stationarity_copy = alloca double, align 512
  %activity_copy = alloca double, align 512
  %acmin_copy = alloca double, align 512
  %hrmin_copy = alloca double, align 512
  %stmin_copy = alloca double, align 512
  %tpmin_copy = alloca double, align 512
  %tmin0_copy = alloca double, align 512
  %tmin1_copy = alloca double, align 512
  call fastcc void @copy_in(double* %hr, double* nonnull align 512 %hr_copy, double* %t, double* nonnull align 512 %t_copy, double* %meanhr, double* nonnull align 512 %meanhr_copy, double* %tpower, double* nonnull align 512 %tpower_copy, double* %stationarity, double* nonnull align 512 %stationarity_copy, double* %activity, double* nonnull align 512 %activity_copy, double* %acmin, double* nonnull align 512 %acmin_copy, double* %hrmin, double* nonnull align 512 %hrmin_copy, double* %stmin, double* nonnull align 512 %stmin_copy, double* %tpmin, double* nonnull align 512 %tpmin_copy, double* %tmin0, double* nonnull align 512 %tmin0_copy, double* %tmin1, double* nonnull align 512 %tmin1_copy)
  call void @apatb_activity_kernel_hw(i32 %len, double* %hr_copy, double* %t_copy, double* %meanhr_copy, double* %tpower_copy, double* %stationarity_copy, double* %activity_copy, double* %acmin_copy, double* %hrmin_copy, double* %stmin_copy, double* %tpmin_copy, double* %tmin0_copy, double* %tmin1_copy)
  call fastcc void @copy_out(double* %hr, double* nonnull align 512 %hr_copy, double* %t, double* nonnull align 512 %t_copy, double* %meanhr, double* nonnull align 512 %meanhr_copy, double* %tpower, double* nonnull align 512 %tpower_copy, double* %stationarity, double* nonnull align 512 %stationarity_copy, double* %activity, double* nonnull align 512 %activity_copy, double* %acmin, double* nonnull align 512 %acmin_copy, double* %hrmin, double* nonnull align 512 %hrmin_copy, double* %stmin, double* nonnull align 512 %stmin_copy, double* %tpmin, double* nonnull align 512 %tpmin_copy, double* %tmin0, double* nonnull align 512 %tmin0_copy, double* %tmin1, double* nonnull align 512 %tmin1_copy)
  ret void
}

; Function Attrs: argmemonly noinline
define internal fastcc void @copy_in(double* readonly, double* noalias align 512, double* readonly, double* noalias align 512, double* readonly, double* noalias align 512, double* readonly, double* noalias align 512, double* readonly, double* noalias align 512, double* readonly, double* noalias align 512, double* readonly, double* noalias align 512, double* readonly, double* noalias align 512, double* readonly, double* noalias align 512, double* readonly, double* noalias align 512, double* readonly, double* noalias align 512, double* readonly, double* noalias align 512) unnamed_addr #1 {
entry:
  call fastcc void @onebyonecpy_hls.p0f64(double* align 512 %1, double* %0)
  call fastcc void @onebyonecpy_hls.p0f64(double* align 512 %3, double* %2)
  call fastcc void @onebyonecpy_hls.p0f64(double* align 512 %5, double* %4)
  call fastcc void @onebyonecpy_hls.p0f64(double* align 512 %7, double* %6)
  call fastcc void @onebyonecpy_hls.p0f64(double* align 512 %9, double* %8)
  call fastcc void @onebyonecpy_hls.p0f64(double* align 512 %11, double* %10)
  call fastcc void @onebyonecpy_hls.p0f64(double* align 512 %13, double* %12)
  call fastcc void @onebyonecpy_hls.p0f64(double* align 512 %15, double* %14)
  call fastcc void @onebyonecpy_hls.p0f64(double* align 512 %17, double* %16)
  call fastcc void @onebyonecpy_hls.p0f64(double* align 512 %19, double* %18)
  call fastcc void @onebyonecpy_hls.p0f64(double* align 512 %21, double* %20)
  call fastcc void @onebyonecpy_hls.p0f64(double* align 512 %23, double* %22)
  ret void
}

; Function Attrs: argmemonly noinline
define internal fastcc void @onebyonecpy_hls.p0f64(double* noalias align 512, double* noalias readonly) unnamed_addr #2 {
entry:
  %2 = icmp eq double* %0, null
  %3 = icmp eq double* %1, null
  %4 = or i1 %2, %3
  br i1 %4, label %ret, label %copy

copy:                                             ; preds = %entry
  %5 = bitcast double* %0 to i8*
  %6 = bitcast double* %1 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %5, i8* align 1 %6, i64 8, i1 false)
  br label %ret

ret:                                              ; preds = %copy, %entry
  ret void
}

; Function Attrs: argmemonly nounwind
declare void @llvm.memcpy.p0i8.p0i8.i64(i8* nocapture writeonly, i8* nocapture readonly, i64, i1) #3

; Function Attrs: argmemonly noinline
define internal fastcc void @copy_out(double*, double* noalias readonly align 512, double*, double* noalias readonly align 512, double*, double* noalias readonly align 512, double*, double* noalias readonly align 512, double*, double* noalias readonly align 512, double*, double* noalias readonly align 512, double*, double* noalias readonly align 512, double*, double* noalias readonly align 512, double*, double* noalias readonly align 512, double*, double* noalias readonly align 512, double*, double* noalias readonly align 512, double*, double* noalias readonly align 512) unnamed_addr #4 {
entry:
  call fastcc void @onebyonecpy_hls.p0f64(double* %0, double* align 512 %1)
  call fastcc void @onebyonecpy_hls.p0f64(double* %2, double* align 512 %3)
  call fastcc void @onebyonecpy_hls.p0f64(double* %4, double* align 512 %5)
  call fastcc void @onebyonecpy_hls.p0f64(double* %6, double* align 512 %7)
  call fastcc void @onebyonecpy_hls.p0f64(double* %8, double* align 512 %9)
  call fastcc void @onebyonecpy_hls.p0f64(double* %10, double* align 512 %11)
  call fastcc void @onebyonecpy_hls.p0f64(double* %12, double* align 512 %13)
  call fastcc void @onebyonecpy_hls.p0f64(double* %14, double* align 512 %15)
  call fastcc void @onebyonecpy_hls.p0f64(double* %16, double* align 512 %17)
  call fastcc void @onebyonecpy_hls.p0f64(double* %18, double* align 512 %19)
  call fastcc void @onebyonecpy_hls.p0f64(double* %20, double* align 512 %21)
  call fastcc void @onebyonecpy_hls.p0f64(double* %22, double* align 512 %23)
  ret void
}

declare void @apatb_activity_kernel_hw(i32, double*, double*, double*, double*, double*, double*, double*, double*, double*, double*, double*, double*)

define void @activity_kernel_hw_stub_wrapper(i32, double*, double*, double*, double*, double*, double*, double*, double*, double*, double*, double*, double*) #5 {
entry:
  call void @copy_out(double* null, double* %1, double* null, double* %2, double* null, double* %3, double* null, double* %4, double* null, double* %5, double* null, double* %6, double* null, double* %7, double* null, double* %8, double* null, double* %9, double* null, double* %10, double* null, double* %11, double* null, double* %12)
  call void @activity_kernel_hw_stub(i32 %0, double* %1, double* %2, double* %3, double* %4, double* %5, double* %6, double* %7, double* %8, double* %9, double* %10, double* %11, double* %12)
  call void @copy_in(double* null, double* %1, double* null, double* %2, double* null, double* %3, double* null, double* %4, double* null, double* %5, double* null, double* %6, double* null, double* %7, double* null, double* %8, double* null, double* %9, double* null, double* %10, double* null, double* %11, double* null, double* %12)
  ret void
}

declare void @activity_kernel_hw_stub(i32, double*, double*, double*, double*, double*, double*, double*, double*, double*, double*, double*, double*)

attributes #0 = { argmemonly noinline "fpga.wrapper.func"="wrapper" }
attributes #1 = { argmemonly noinline "fpga.wrapper.func"="copyin" }
attributes #2 = { argmemonly noinline "fpga.wrapper.func"="onebyonecpy_hls" }
attributes #3 = { argmemonly nounwind }
attributes #4 = { argmemonly noinline "fpga.wrapper.func"="copyout" }
attributes #5 = { "fpga.wrapper.func"="stub" }

!llvm.dbg.cu = !{}
!llvm.ident = !{!0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0}
!llvm.module.flags = !{!1, !2, !3}
!blackbox_cfg = !{!4}

!0 = !{!"clang version 7.0.0 "}
!1 = !{i32 2, !"Dwarf Version", i32 4}
!2 = !{i32 2, !"Debug Info Version", i32 3}
!3 = !{i32 1, !"wchar_size", i32 4}
!4 = !{}
