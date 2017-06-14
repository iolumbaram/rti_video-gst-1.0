#!/bin/sh

filename=$0
script_dir=`dirname $filename`
executable_name="VideoSubscriberz"
bin_dir=/home/hazel/rti_videodemo-gstreamer-1.0/rticonnextdds-usecases/VideoData/ExampleCode/objs/rti_connext_dds-5.2.3/x64Linux3gcc4.8.2/VideoSubscriber


if [ -f $bin_dir/$executable_name ]
then
    cd $bin_dir
    export LD_LIBRARY_PATH=/home/hazel/rti_videodemo-gstreamer-1.0/rticonnextdds-usecases/VehicleTracking/ExampleCode/thirdparty/proj-4.8.0/lib/i86Linux2.6gcc4.4.5:/home/hazel/rti_videodemo-gstreamer-1.0/rticonnextdds-usecases/VehicleTracking/ExampleCode/thirdparty/wxWidgets-2.9.4/lib/i86Linux2.6gcc4.4.5:$LD_LIBRARY_PATH
    ./$executable_name $*
else
    echo "***************************************************************"
    echo $executable_name executable does not exist in:
    echo $bin_dir
    echo ""
    echo Please, try to recompile the application using the command:
    echo " $ make -f make/Makefile.x64Linux3gcc4.8.2"
    echo "***************************************************************"
fi
