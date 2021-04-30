; ModuleID = '/localhome/jmack2545/ece576b/VitisHLS/activity_hls/activity_soln/.autopilot/db/a.g.ld.5.gdce.bc'
source_filename = "llvm-link"
target datalayout = "e-m:e-i64:64-i128:128-i256:256-i512:512-i1024:1024-i2048:2048-i4096:4096-n8:16:32:64-S128-v16:16-v24:32-v32:32-v48:64-v96:128-v192:256-v256:256-v512:512-v1024:1024"
target triple = "fpga64-xilinx-none"

%struct.activity_values = type { i32, i32, double, double, double, double, double, double, double }

; Function Attrs: noinline
define void @apatb_compute_statistics_ir(double* %hr, %struct.activity_values* %vals) local_unnamed_addr #0 {
entry:
  %malloccall = tail call i8* @malloc(i64 4800)
  %hr_copy = bitcast i8* %malloccall to [600 x double]*
  %vals_copy = alloca %struct.activity_values, align 512
  %0 = bitcast double* %hr to [600 x double]*
  call fastcc void @copy_in([600 x double]* %0, [600 x double]* %hr_copy, %struct.activity_values* %vals, %struct.activity_values* nonnull align 512 %vals_copy)
  %1 = getelementptr inbounds [600 x double], [600 x double]* %hr_copy, i32 0, i32 0
  call void @apatb_compute_statistics_hw(double* %1, %struct.activity_values* %vals_copy)
  call fastcc void @copy_out([600 x double]* %0, [600 x double]* %hr_copy, %struct.activity_values* %vals, %struct.activity_values* nonnull align 512 %vals_copy)
  tail call void @free(i8* %malloccall)
  ret void
}

declare noalias i8* @malloc(i64) local_unnamed_addr

; Function Attrs: argmemonly noinline
define internal fastcc void @copy_in([600 x double]* readonly, [600 x double]* noalias, %struct.activity_values* readonly, %struct.activity_values* noalias align 512) unnamed_addr #1 {
entry:
  call fastcc void @onebyonecpy_hls.p0a600f64([600 x double]* %1, [600 x double]* %0)
  call fastcc void @onebyonecpy_hls.p0struct.activity_values(%struct.activity_values* align 512 %3, %struct.activity_values* %2)
  ret void
}

; Function Attrs: argmemonly noinline
define internal fastcc void @onebyonecpy_hls.p0a600f64([600 x double]* noalias, [600 x double]* noalias readonly) unnamed_addr #2 {
entry:
  %2 = icmp eq [600 x double]* %0, null
  %3 = icmp eq [600 x double]* %1, null
  %4 = or i1 %2, %3
  br i1 %4, label %ret, label %copy

copy:                                             ; preds = %entry
  br label %for.loop

for.loop:                                         ; preds = %for.loop, %copy
  %for.loop.idx3 = phi i64 [ 0, %copy ], [ %for.loop.idx.next, %for.loop ]
  %dst.addr.gep1 = getelementptr [600 x double], [600 x double]* %0, i64 0, i64 %for.loop.idx3
  %5 = bitcast double* %dst.addr.gep1 to i8*
  %src.addr.gep2 = getelementptr [600 x double], [600 x double]* %1, i64 0, i64 %for.loop.idx3
  %6 = bitcast double* %src.addr.gep2 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %5, i8* align 1 %6, i64 8, i1 false)
  %for.loop.idx.next = add nuw nsw i64 %for.loop.idx3, 1
  %exitcond = icmp ne i64 %for.loop.idx.next, 600
  br i1 %exitcond, label %for.loop, label %ret

ret:                                              ; preds = %for.loop, %entry
  ret void
}

; Function Attrs: argmemonly nounwind
declare void @llvm.memcpy.p0i8.p0i8.i64(i8* nocapture writeonly, i8* nocapture readonly, i64, i1) #3

; Function Attrs: argmemonly noinline
define internal fastcc void @onebyonecpy_hls.p0struct.activity_values(%struct.activity_values* noalias align 512, %struct.activity_values* noalias readonly) unnamed_addr #2 {
entry:
  %2 = icmp eq %struct.activity_values* %0, null
  %3 = icmp eq %struct.activity_values* %1, null
  %4 = or i1 %2, %3
  br i1 %4, label %ret, label %copy

copy:                                             ; preds = %entry
  %5 = bitcast %struct.activity_values* %0 to i8*
  %6 = bitcast %struct.activity_values* %1 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %5, i8* align 1 %6, i64 4, i1 false)
  %.12.gep11 = getelementptr %struct.activity_values, %struct.activity_values* %0, i32 0, i32 1
  %7 = bitcast i32* %.12.gep11 to i8*
  %.1.gep12 = getelementptr %struct.activity_values, %struct.activity_values* %1, i32 0, i32 1
  %8 = bitcast i32* %.1.gep12 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %7, i8* align 1 %8, i64 4, i1 false)
  %.23.gep13 = getelementptr %struct.activity_values, %struct.activity_values* %0, i32 0, i32 2
  %9 = bitcast double* %.23.gep13 to i8*
  %.2.gep14 = getelementptr %struct.activity_values, %struct.activity_values* %1, i32 0, i32 2
  %10 = bitcast double* %.2.gep14 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %9, i8* align 1 %10, i64 8, i1 false)
  %.34.gep15 = getelementptr %struct.activity_values, %struct.activity_values* %0, i32 0, i32 3
  %11 = bitcast double* %.34.gep15 to i8*
  %.3.gep16 = getelementptr %struct.activity_values, %struct.activity_values* %1, i32 0, i32 3
  %12 = bitcast double* %.3.gep16 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %11, i8* align 1 %12, i64 8, i1 false)
  %.45.gep17 = getelementptr %struct.activity_values, %struct.activity_values* %0, i32 0, i32 4
  %13 = bitcast double* %.45.gep17 to i8*
  %.4.gep18 = getelementptr %struct.activity_values, %struct.activity_values* %1, i32 0, i32 4
  %14 = bitcast double* %.4.gep18 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %13, i8* align 1 %14, i64 8, i1 false)
  %.56.gep19 = getelementptr %struct.activity_values, %struct.activity_values* %0, i32 0, i32 5
  %15 = bitcast double* %.56.gep19 to i8*
  %.5.gep20 = getelementptr %struct.activity_values, %struct.activity_values* %1, i32 0, i32 5
  %16 = bitcast double* %.5.gep20 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %15, i8* align 1 %16, i64 8, i1 false)
  %.67.gep21 = getelementptr %struct.activity_values, %struct.activity_values* %0, i32 0, i32 6
  %17 = bitcast double* %.67.gep21 to i8*
  %.6.gep22 = getelementptr %struct.activity_values, %struct.activity_values* %1, i32 0, i32 6
  %18 = bitcast double* %.6.gep22 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %17, i8* align 1 %18, i64 8, i1 false)
  %.78.gep23 = getelementptr %struct.activity_values, %struct.activity_values* %0, i32 0, i32 7
  %19 = bitcast double* %.78.gep23 to i8*
  %.7.gep24 = getelementptr %struct.activity_values, %struct.activity_values* %1, i32 0, i32 7
  %20 = bitcast double* %.7.gep24 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %19, i8* align 1 %20, i64 8, i1 false)
  %.89.gep25 = getelementptr %struct.activity_values, %struct.activity_values* %0, i32 0, i32 8
  %21 = bitcast double* %.89.gep25 to i8*
  %.8.gep26 = getelementptr %struct.activity_values, %struct.activity_values* %1, i32 0, i32 8
  %22 = bitcast double* %.8.gep26 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %21, i8* align 1 %22, i64 8, i1 false)
  br label %ret

ret:                                              ; preds = %copy, %entry
  ret void
}

; Function Attrs: argmemonly noinline
define internal fastcc void @copy_out([600 x double]*, [600 x double]* noalias readonly, %struct.activity_values*, %struct.activity_values* noalias readonly align 512) unnamed_addr #4 {
entry:
  call fastcc void @onebyonecpy_hls.p0a600f64([600 x double]* %0, [600 x double]* %1)
  call fastcc void @onebyonecpy_hls.p0struct.activity_values(%struct.activity_values* %2, %struct.activity_values* align 512 %3)
  ret void
}

declare void @free(i8*) local_unnamed_addr

declare void @apatb_compute_statistics_hw(double*, %struct.activity_values*)

define void @compute_statistics_hw_stub_wrapper(double*, %struct.activity_values*) #5 {
entry:
  %2 = bitcast double* %0 to [600 x double]*
  call void @copy_out([600 x double]* null, [600 x double]* %2, %struct.activity_values* null, %struct.activity_values* %1)
  %3 = bitcast [600 x double]* %2 to double*
  call void @compute_statistics_hw_stub(double* %3, %struct.activity_values* %1)
  call void @copy_in([600 x double]* null, [600 x double]* %2, %struct.activity_values* null, %struct.activity_values* %1)
  ret void
}

declare void @compute_statistics_hw_stub(double*, %struct.activity_values*)

attributes #0 = { noinline "fpga.wrapper.func"="wrapper" }
attributes #1 = { argmemonly noinline "fpga.wrapper.func"="copyin" }
attributes #2 = { argmemonly noinline "fpga.wrapper.func"="onebyonecpy_hls" }
attributes #3 = { argmemonly nounwind }
attributes #4 = { argmemonly noinline "fpga.wrapper.func"="copyout" }
attributes #5 = { "fpga.wrapper.func"="stub" }

!llvm.dbg.cu = !{}
!llvm.ident = !{!0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0}
!llvm.module.flags = !{!1, !2, !3}
!blackbox_cfg = !{!4}

!0 = !{!"clang version 7.0.0 "}
!1 = !{i32 2, !"Dwarf Version", i32 4}
!2 = !{i32 2, !"Debug Info Version", i32 3}
!3 = !{i32 1, !"wchar_size", i32 4}
!4 = !{}
