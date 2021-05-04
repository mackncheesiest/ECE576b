; ModuleID = '/localhome/jmack2545/ece576b/VitisHLS/aes_encrypt/aes_encrypt/aes_encrypt/.autopilot/db/a.g.ld.5.gdce.bc'
source_filename = "llvm-link"
target datalayout = "e-m:e-i64:64-i128:128-i256:256-i512:512-i1024:1024-i2048:2048-i4096:4096-n8:16:32:64-S128-v16:16-v24:32-v32:32-v48:64-v96:128-v192:256-v256:256-v512:512-v1024:1024"
target triple = "fpga64-xilinx-none"

; Function Attrs: argmemonly noinline
define void @apatb_rijndaelEncrypt_hls_ir(i32* %rk, i8* %pt, i8* %ct) local_unnamed_addr #0 {
entry:
  %rk_copy = alloca [44 x i32], align 512
  %pt_copy = alloca [16 x i8], align 512
  %ct_copy = alloca [16 x i8], align 512
  %0 = bitcast i32* %rk to [44 x i32]*
  %1 = bitcast i8* %pt to [16 x i8]*
  %2 = bitcast i8* %ct to [16 x i8]*
  call fastcc void @copy_in([44 x i32]* %0, [44 x i32]* nonnull align 512 %rk_copy, [16 x i8]* %1, [16 x i8]* nonnull align 512 %pt_copy, [16 x i8]* %2, [16 x i8]* nonnull align 512 %ct_copy)
  %3 = getelementptr inbounds [44 x i32], [44 x i32]* %rk_copy, i32 0, i32 0
  %4 = getelementptr inbounds [16 x i8], [16 x i8]* %pt_copy, i32 0, i32 0
  %5 = getelementptr inbounds [16 x i8], [16 x i8]* %ct_copy, i32 0, i32 0
  call void @apatb_rijndaelEncrypt_hls_hw(i32* %3, i8* %4, i8* %5)
  call fastcc void @copy_out([44 x i32]* %0, [44 x i32]* nonnull align 512 %rk_copy, [16 x i8]* %1, [16 x i8]* nonnull align 512 %pt_copy, [16 x i8]* %2, [16 x i8]* nonnull align 512 %ct_copy)
  ret void
}

; Function Attrs: argmemonly noinline
define internal fastcc void @copy_in([44 x i32]* readonly, [44 x i32]* noalias align 512, [16 x i8]* readonly, [16 x i8]* noalias align 512, [16 x i8]* readonly, [16 x i8]* noalias align 512) unnamed_addr #1 {
entry:
  call fastcc void @onebyonecpy_hls.p0a44i32([44 x i32]* align 512 %1, [44 x i32]* %0)
  call fastcc void @onebyonecpy_hls.p0a16i8([16 x i8]* align 512 %3, [16 x i8]* %2)
  call fastcc void @onebyonecpy_hls.p0a16i8([16 x i8]* align 512 %5, [16 x i8]* %4)
  ret void
}

; Function Attrs: argmemonly noinline
define internal fastcc void @onebyonecpy_hls.p0a44i32([44 x i32]* noalias align 512, [44 x i32]* noalias readonly) unnamed_addr #2 {
entry:
  %2 = icmp eq [44 x i32]* %0, null
  %3 = icmp eq [44 x i32]* %1, null
  %4 = or i1 %2, %3
  br i1 %4, label %ret, label %copy

copy:                                             ; preds = %entry
  br label %for.loop

for.loop:                                         ; preds = %for.loop, %copy
  %for.loop.idx3 = phi i64 [ 0, %copy ], [ %for.loop.idx.next, %for.loop ]
  %dst.addr.gep1 = getelementptr [44 x i32], [44 x i32]* %0, i64 0, i64 %for.loop.idx3
  %5 = bitcast i32* %dst.addr.gep1 to i8*
  %src.addr.gep2 = getelementptr [44 x i32], [44 x i32]* %1, i64 0, i64 %for.loop.idx3
  %6 = bitcast i32* %src.addr.gep2 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %5, i8* align 1 %6, i64 4, i1 false)
  %for.loop.idx.next = add nuw nsw i64 %for.loop.idx3, 1
  %exitcond = icmp ne i64 %for.loop.idx.next, 44
  br i1 %exitcond, label %for.loop, label %ret

ret:                                              ; preds = %for.loop, %entry
  ret void
}

; Function Attrs: argmemonly nounwind
declare void @llvm.memcpy.p0i8.p0i8.i64(i8* nocapture writeonly, i8* nocapture readonly, i64, i1) #3

; Function Attrs: argmemonly noinline
define internal fastcc void @onebyonecpy_hls.p0a16i8([16 x i8]* noalias align 512, [16 x i8]* noalias readonly) unnamed_addr #2 {
entry:
  %2 = icmp eq [16 x i8]* %0, null
  %3 = icmp eq [16 x i8]* %1, null
  %4 = or i1 %2, %3
  br i1 %4, label %ret, label %copy

copy:                                             ; preds = %entry
  br label %for.loop

for.loop:                                         ; preds = %for.loop, %copy
  %for.loop.idx1 = phi i64 [ 0, %copy ], [ %for.loop.idx.next, %for.loop ]
  %dst.addr = getelementptr [16 x i8], [16 x i8]* %0, i64 0, i64 %for.loop.idx1
  %src.addr = getelementptr [16 x i8], [16 x i8]* %1, i64 0, i64 %for.loop.idx1
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %dst.addr, i8* align 1 %src.addr, i64 1, i1 false)
  %for.loop.idx.next = add nuw nsw i64 %for.loop.idx1, 1
  %exitcond = icmp ne i64 %for.loop.idx.next, 16
  br i1 %exitcond, label %for.loop, label %ret

ret:                                              ; preds = %for.loop, %entry
  ret void
}

; Function Attrs: argmemonly noinline
define internal fastcc void @copy_out([44 x i32]*, [44 x i32]* noalias readonly align 512, [16 x i8]*, [16 x i8]* noalias readonly align 512, [16 x i8]*, [16 x i8]* noalias readonly align 512) unnamed_addr #4 {
entry:
  call fastcc void @onebyonecpy_hls.p0a44i32([44 x i32]* %0, [44 x i32]* align 512 %1)
  call fastcc void @onebyonecpy_hls.p0a16i8([16 x i8]* %2, [16 x i8]* align 512 %3)
  call fastcc void @onebyonecpy_hls.p0a16i8([16 x i8]* %4, [16 x i8]* align 512 %5)
  ret void
}

declare void @apatb_rijndaelEncrypt_hls_hw(i32*, i8*, i8*)

define void @rijndaelEncrypt_hls_hw_stub_wrapper(i32*, i8*, i8*) #5 {
entry:
  %3 = bitcast i32* %0 to [44 x i32]*
  %4 = bitcast i8* %1 to [16 x i8]*
  %5 = bitcast i8* %2 to [16 x i8]*
  call void @copy_out([44 x i32]* null, [44 x i32]* %3, [16 x i8]* null, [16 x i8]* %4, [16 x i8]* null, [16 x i8]* %5)
  %6 = bitcast [44 x i32]* %3 to i32*
  %7 = bitcast [16 x i8]* %4 to i8*
  %8 = bitcast [16 x i8]* %5 to i8*
  call void @rijndaelEncrypt_hls_hw_stub(i32* %6, i8* %7, i8* %8)
  call void @copy_in([44 x i32]* null, [44 x i32]* %3, [16 x i8]* null, [16 x i8]* %4, [16 x i8]* null, [16 x i8]* %5)
  ret void
}

declare void @rijndaelEncrypt_hls_hw_stub(i32*, i8*, i8*)

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
