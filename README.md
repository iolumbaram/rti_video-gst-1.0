<<<<<<< HEAD
rticonnextdds-usecases
======================

Case + Code Overview
--------------------

This repository is part of Real-Time Innovations' Case + Code project, 
a project to create code for real-world RTI Connext DDS use cases.

The respository contains examples that illustrate a variety of DDS use cases, 
from vehicle tracking to manufacturing and automation.  Some of the use case
examples will be focused on real applications such as air traffic control, 
and some will be focused on deployment scenarios such as monitoring remote
devices over a wide area network.

The examples in this repository are meant to illustrate simplified real-world 
uses of the RTI Connext DDS product, focusing on:
- How to represent objects and model data in IDL for each specific use case
- How to tune quality of service (QoS) for use-case-specific requirements such as scalability, latency, or throughput
- How to create applications with both DataWriters and DataReaders

These use case examples should be a stepping stone for creating real 
distributed applications based on RTI Connext DDS. Additional information 
about each use case can be found on [RTI's Case + Code page](http://www.rti.com/resources/usecases/index.html)
and in the Docs/ directory of the individual use case examples.

RTI Connext DDS Overview
------------------------

RTI Connext DDS software includes the world's leading implementation of the 
Object Management Group (OMG) Data Distribution Service (DDS). DDS is the only 
open standard for messaging that supports the unique needs of both enterprise 
and real-time systems. Its open interfaces and advanced integration 
capabilities slash costs across a system's lifecycle, from initial development 
and integration through on-going maintenance and upgrades.
# rti_videodemo-gstreamer-1.0

This repository referrenced to:

https://github.com/reiniert/rticonnextdds-usecases && https://github.com/gds-emt/rticonnextdds-usecases

Original project repository doesn't seem to be compatible with an Android application for RTI video demo, which its precompiled .apk can be found at https://github.com/rticommunity/rticonnextdds-videodemo-android

This repository targets architecutre Makefile.x64Linux3gcc4.8.2 and uses gstreamer 1.0.

Prior to buidling the code, execute install.sh to get gstreamer 1.0 and change directory paths accordingly
	1. Makefile.x64Linux3gcc4.8.2
	2. both executable scripts

------------------
Buidling the code
------------------
1. change directory to VideoData/ExampleCode
2. make -f make/Makefile.x64Linux3gcc4.8.2

------------------
Running the code
------------------
1. Publisher and Subscriber batch files can be found under VideoData/ExampleCode/scripts

------------------------
With Android application
------------------------
0. Execute Publisher first prior to Subscriber

1. PC (Pub) ----- Android (Sub)
  Tested and working. 
  Multiple Android devices can subscribe to PC application (Tested with two devices)
   
2. PC (Sub) ----- Android (Pub)
  Verified with rtiddsspy that video data stream is availbe from DataWriter (Android)
  Topic name: VideoData



=======
# rti_video-demo-gstreamer-1.0
>>>>>>> ae3b64f4ce218cddce54e550280b218ab9e71414
