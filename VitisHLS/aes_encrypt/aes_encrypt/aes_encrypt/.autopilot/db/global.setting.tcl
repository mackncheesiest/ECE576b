
set TopModule "rijndaelEncrypt_hls"
set ClockPeriod 2
set ClockList ap_clk
set HasVivadoClockPeriod 0
set CombLogicFlag 0
set PipelineFlag 0
set DataflowTaskPipelineFlag 1
set TrivialPipelineFlag 0
set noPortSwitchingFlag 0
set FloatingPointFlag 0
set FftOrFirFlag 0
set NbRWValue 0
set intNbAccess 0
set NewDSPMapping 1
set HasDSPModule 0
set ResetLevelFlag 0
set ResetStyle control
set ResetSyncFlag 1
set ResetRegisterFlag 0
set ResetVariableFlag 0
set ResetRegisterNum 0
set FsmEncStyle onehot
set MaxFanout 0
set RtlPrefix {}
set RtlSubPrefix rijndaelEncrypt_hls_
set ExtraCCFlags {}
set ExtraCLdFlags {}
set SynCheckOptions {}
set PresynOptions {}
set PreprocOptions {}
set SchedOptions {}
set BindOptions {}
set RtlGenOptions {}
set RtlWriterOptions {}
set CbcGenFlag {}
set CasGenFlag {}
set CasMonitorFlag {}
set AutoSimOptions {}
set ExportMCPathFlag 0
set SCTraceFileName mytrace
set SCTraceFileFormat vcd
set SCTraceOption all
set TargetInfo xczu9eg:-ffvb1156:-2-e
set SourceFiles {sc {} c ../../../../../../../home/jmack2545/Downloads/rijndaelEncrypt_hls.cpp}
set SourceFlags {sc {} c {{}}}
set DirectiveFile /localhome/jmack2545/ece576b/VitisHLS/aes_encrypt/aes_encrypt/aes_encrypt/aes_encrypt.directive
set TBFiles {verilog ../../../../../../../home/jmack2545/Downloads/aes_tb_1.cpp bc ../../../../../../../home/jmack2545/Downloads/aes_tb_1.cpp vhdl ../../../../../../../home/jmack2545/Downloads/aes_tb_1.cpp sc ../../../../../../../home/jmack2545/Downloads/aes_tb_1.cpp cas ../../../../../../../home/jmack2545/Downloads/aes_tb_1.cpp c {}}
set SpecLanguage C
set TVInFiles {bc {} c {} sc {} cas {} vhdl {} verilog {}}
set TVOutFiles {bc {} c {} sc {} cas {} vhdl {} verilog {}}
set TBTops {verilog {} bc {} vhdl {} sc {} cas {} c {}}
set TBInstNames {verilog {} bc {} vhdl {} sc {} cas {} c {}}
set XDCFiles {}
set ExtraGlobalOptions {"area_timing" 1 "clock_gate" 1 "impl_flow" map "power_gate" 0}
set TBTVFileNotFound {}
set AppFile ../hls.app
set ApsFile aes_encrypt.aps
set AvePath ../..
set DefaultPlatform DefaultPlatform
set multiClockList {}
set SCPortClockMap {}
set intNbAccess 0
set PlatformFiles {{DefaultPlatform {xilinx/zynquplus/zynquplus xilinx/zynquplus/zynquplus_fpv7}}}
set HPFPO 0
