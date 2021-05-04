<project xmlns="com.autoesl.autopilot.project" name="activity_hls" top="compute_statistics">
    <includePaths/>
    <libraryPaths/>
    <Simulation argv="-r ../../../../test-100.ts">
        <SimFlow name="csim" csimMode="0" lastCsimMode="0"/>
    </Simulation>
    <files xmlns="">
        <file name="../../activity_test.cpp" sc="0" tb="1" cflags=" -Wno-unknown-pragmas" csimflags=" -Wno-unknown-pragmas" blackbox="false"/>
        <file name="myfile.cpp" sc="0" tb="false" cflags="" csimflags="" blackbox="false"/>
        <file name="bytestrm_util.h" sc="0" tb="false" cflags="" csimflags="" blackbox="false"/>
        <file name="activity_hls.cpp" sc="0" tb="false" cflags="" csimflags="" blackbox="false"/>
    </files>
    <solutions xmlns="">
        <solution name="activity_soln" status="active"/>
    </solutions>
</project>

