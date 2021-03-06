/* --------------------------------------------
Copyright (c) 2013, University of Granada
Copyright (c) 2013, Real-Time Innovations, Inc.
Copyright (c) 2013, Javier Povedano-Molina
All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notices, this
   list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notices,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

The views and conclusions contained in the software and documentation are those
of the authors and should not be interpreted as representing official policies,
either expressed or implied, of the copyright holders or contributors.

This work was partially completed at the University of Granada under funding by
Real-Time Innovations, Inc. (RTI).  The above license is granted with
 the permission of RTI.

-------------------------------------------- */

#include <iostream>
#include <fcntl.h>

#include <glib-object.h>
#include <string.h>

#include "VideoOutput.h"


// ----------------------------------------------------------------------------
void EMDSVideoOutput::Initialize()
{
	_frameHandler = NULL;
}

// ----------------------------------------------------------------------------
EMDSVideoOutput::EMDSVideoOutput()
{
	gst_init(NULL,NULL);
	Initialize();

}

// ----------------------------------------------------------------------------
void EMDSVideoOutput::PushFrame(EMDSBuffer *buffer)
{
<<<<<<< HEAD
	std::cout << "----videooutput.cxx pushframe" << std::endl;
=======
>>>>>>> 49b321f55b976b0ac9d86dfd52766685cb388d8e

	if (_frameHandler != NULL)
	{
		_frameHandler->FrameReady(this,buffer);
	}

	return;
}

// ----------------------------------------------------------------------------
static gboolean bus_eos_callback(
	GstBus *bus, GstMessage *message, gpointer data)
{
	EMDSVideoDisplayOutput *vidOut =
		(EMDSVideoDisplayOutput *)data;

	/* end-of-stream */
	vidOut->GetFrameHandler()->EOSHandler(vidOut, NULL);

  /* we want to be notified again the next time there is a message
   * on the bus, so returning TRUE (FALSE means we want to stop watching
   * for messages on the bus and our callback should not be called again)
   */
  return TRUE;
}
// ----------------------------------------------------------------------------
static GstBusSyncReply bus_sync_handler(
	GstBus *bus, GstMessage *message, gpointer user_data)
{
	GstElement *outwin = NULL;
	GValue val = G_VALUE_INIT;

	outwin = gst_bin_get_by_name(GST_BIN(user_data),"sink");

	if (GST_MESSAGE_TYPE (message) != GST_MESSAGE_ELEMENT)
		return GST_BUS_PASS;

	if (!gst_structure_has_name (gst_message_get_structure(message), "prepare-xwindow-id"))
		return GST_BUS_PASS;

	g_value_init(&val,G_TYPE_BOOLEAN);
	g_value_set_boolean(&val,FALSE);
<<<<<<< HEAD
	if (outwin == NULL)
	{
		std::cout << "-----appSink is empty? seriously? " << std::endl;
	}
	if (outwin != NULL)
	{
		gst_child_proxy_set_property(GST_CHILD_PROXY(outwin),"sync",&val);
		//gst_child_proxy_set_property(GST_CHILD_PROXY(outwin),"sync",&val);
		//gst_child_proxy_set_property(GST_CHILD_PROXY(outwin),"sink_1::xpos",176,"sink_1::ypos",144,NULL);
		//gst_child_proxy_set(GST_CHILD_PROXY(outwin), "sink_1::xpos",176,"sink_1::ypos",144,NULL);

		std::cout << "-----appSrc is filled filled " << std::endl;
=======

	if (outwin != NULL)
	{
		gst_child_proxy_set_property(GST_CHILD_PROXY(outwin),"sync",&val);
>>>>>>> 49b321f55b976b0ac9d86dfd52766685cb388d8e
	}

	gst_message_unref(message);

	return GST_BUS_DROP;
}


// ----------------------------------------------------------------------------
void EMDSVideoDisplayOutput::Initialize()
{
	EMDSVideoOutput::Initialize();
	GstBus *bus = NULL;

	_frameHandler =
		new DisplayFrameHandler(this);

#ifdef _WIN32
// Create the video pipeline on Windows (sending to DirectDraw)
#define PIPELINE_STRING                                                \
	"appsrc name=\"src\" is-live=\"true\" do-timestamp=\"true\" "       \
	"caps=\"video/x-vp8, width=(int)640, height=(int)360, "             \
	"pixel-aspect-ratio=(fraction)1/1, framerate=(fraction)1000/1\" ! " \
	"queue2 ! vp8dec ! queue2 ! "                                       \
	"videorate ! video/x-raw-yuv,framerate=25/1 ! "                     \
	"videoconvert ! directdrawsink name=\"sink\""
#endif

#if defined(__linux__) || defined(__APPLE__)
#define PIPELINE_STRING                                               \
	"appsrc name=\"src\" is-live=\"true\" do-timestamp=\"true\" " \
	"caps=\"video/x-vp8, width=(int)640, height=(int)360, "       \
	"framerate=1000/1\" ! queue2 ! "                              \
	"vp8dec ! ffmpegcolorspace ! videoconvert ! autovideosink "

<<<<<<< HEAD
//webm to file
//	"v4l2src device=/dev/video0 ! " \
	"caps=\"video/x-vp8, width=(int)640, height=(int)480, "       \
	"vp8enc ! webmmux ! filesink location=/home/hazel/gstTest.webm"

//videobox with top buffer adjusted
//	"appsrc name=\"src\" is-live=\"true\" do-timestamp=\"true\" " \
	"caps=\"video/x-vp8, width=(int)640, height=(int)480, "       \
	"framerate=1000/1\" background-color=0x111111 ! queue2 ! "                              \
	"vp8dec ! ffmpegcolorspace ! videoconvert ! videobox border-alpha=0 alpha=0 fill=0 left=-0 right=-200 top=-400 bottom=-150 ! videoconvert ! autovideosink " \

//checker box
//	"appsrc name=\"src\" is-live=\"true\" do-timestamp=\"true\" " \
	"caps=\"video/x-vp8, width=(int)640, height=(int)480, "       \
	"framerate=1000/1\" pattern=4 ! queue2 ! "                              \
	"vp8dec ! ffmpegcolorspace ! videoconvert ! videobox border-alpha=0 alpha=0 fill=0 left=-0 right=-200 top=-400 bottom=-150 ! videomixer name=mix sink_0::alpha=0.7 sink_1::alpha=0.5 ! videoconvert ! autovideosink ! mix." \

//videobox
//"appsrc name=\"src\" is-live=\"true\" do-timestamp=\"true\" " \
//"caps=\"video/x-vp8, width=(int)640, height=(int)360, "       \
//"framerate=1000/1\" ! queue2 ! "                              \
//"vp8dec ! ffmpegcolorspace ! videoconvert ! videobox left=-640 right=0 top=-360 bottom=0 border-alpha=0 ! autovideosink "

//save to gstTest.webm
//	"appsrc name=\"src\" is-live=\"true\" do-timestamp=\"true\" " \
//	"caps=\"video/x-vp8, width=(int)450, height=(int)360, "       \
//	"framerate=25/1\" ! queue2 ! "                              \
//	"vp8dec ! ffmpegcolorspace ! videoconvert ! autovideosink !"	\
//	"videoconvert ! vp8enc ! caps=\"video/x-vp8, width=(int)640, height=(int)360 ! webmmux ! filesink location=/home/hazel/gstTest.webm"

//queue2 fixed app_src_push buffer problem by creating new threading from source pad
//	"appsrc name=\"src\" is-live=\"true\" do-timestamp=\"true\" " \
//	" ! video/x-vp8, width=(int)640, height=(int)360, framerate=25/1 ! queue2 ! vp8enc ! webmmux ! tcpserversink host=127.0.0.1 port=9001 sync-method=2" \


//sending encoded stream
//"appsrc name=\"src\" is-live=\"true\" do-timestamp=\"true\" " \
//"tcpserversink host=127.0.0.1 port=9001 sync-method=2" \

//original
//	"appsrc name=\"src\" is-live=\"true\" do-timestamp=\"true\" " \
//	"caps=\"video/x-vp8, width=(int)640, height=(int)360, "       \
//	"framerate=1000/1\" ! queue2 ! "                              \
//	"vp8dec ! ffmpegcolorspace ! videoconvert ! autovideosink "

=======
>>>>>>> 49b321f55b976b0ac9d86dfd52766685cb388d8e
//	"framerate=1000/1\" ! queue2 ! "                              \
//	"caps=\"video/x-vp8, width=(int)640, height=(int)360, "       \

#endif

        const char *pipelineString = PIPELINE_STRING;
        printf("Doing pipeline: %s\n", pipelineString);
	_displayPipeline =
		GST_PIPELINE(gst_parse_launch( pipelineString, NULL));

<<<<<<< HEAD
	// If the video pipeline was not created correctly, exit./*
=======
	// If the video pipeline was not created correctly, exit.
>>>>>>> 49b321f55b976b0ac9d86dfd52766685cb388d8e
	// The common causes for this include:
	//   - Plugins referenced by name above not found due to:
	//     - GStreamer not installed correctly, or
	//     - GStreamer not finding plugins due to missing GST_PLUGIN_PATH, or
	//     - Some plugins referenced above not available on your platform, or
	//     - Source code change to load different plugins
	if (_displayPipeline == NULL)
	{
		std::cout << "Error: Failed to create pipeline.  Are gstreamer "
			<< "plugins installed correctly?" << std::endl;
		return;
	}

	// Add a sync handler to the bus
	bus = gst_pipeline_get_bus(
		GST_PIPELINE (_displayPipeline));
	gst_bus_set_sync_handler (bus,
		(GstBusSyncHandler) bus_sync_handler, _displayPipeline, NULL);

	// Add a watch for EOS events
	gst_bus_add_signal_watch(bus);
	g_signal_connect(bus, "message::eos", G_CALLBACK (bus_eos_callback), this);
	gst_object_unref(bus);

	// Set the pipeline state to playing, so it actually displays video
	if (GST_STATE_CHANGE_FAILURE == gst_element_set_state(GST_ELEMENT(_displayPipeline), GST_STATE_PLAYING)) {
      std::cout << "Failed to set pipeline state to PLAYING" << std::endl;
<<<<<<< HEAD
   } else {
      std::cout << "Successfully set pipeline state to PLAYING--video actually playing" << std::endl;
=======
   //} else {
   //   std::cout << "Successfully set pipeline state to PLAYING" << std::endl;
>>>>>>> 49b321f55b976b0ac9d86dfd52766685cb388d8e
   }
}

// ----------------------------------------------------------------------------
EMDSVideoDisplayOutput::EMDSVideoDisplayOutput()
{

	Initialize();

	if (_displayPipeline == NULL)
	{
		std::cout << "Failed to create output" << std::endl;
		return;
	} else
	{
		if (GST_STATE_CHANGE_FAILURE == gst_element_set_state(GST_ELEMENT(_displayPipeline),
         GST_STATE_PLAYING)) {
         std::cout << "Failed to set pipeline state to PLAYING" << std::endl;
<<<<<<< HEAD
      } else {
         std::cout << "Successfully set pipeline state to PLAYING" << std::endl;
=======
      //} else {
      //   std::cout << "Successfully set pipeline state to PLAYING" << std::endl;
>>>>>>> 49b321f55b976b0ac9d86dfd52766685cb388d8e
      }
	}
}

// ----------------------------------------------------------------------------
std::string EMDSVideoDisplayOutput::GetStreamMetadata()
{
<<<<<<< HEAD
	std::cout << "-----getting stream metadata" << std::endl;
	GstElement *appSrc = gst_bin_get_by_name( GST_BIN(_displayPipeline),
		"src");
	std::cout << "-----appSrc " << appSrc << std::endl;
	GstPad *srcPad = gst_element_get_static_pad(appSrc, "src");
//	GstCaps *caps = gst_pad_get_allowed_caps(srcPad);
//	GstCaps *caps = gst_pad_get_pad_template_caps(srcPad);
	GstCaps *caps = gst_pad_get_current_caps(srcPad);

	char *capsStr = gst_caps_to_string(caps);
	if (appSrc == NULL)
	{
		std::cout << "-----appSrc is empty? seriously? " << std::endl;
	}
	if (appSrc != NULL)
	{
		std::cout << "-----appSrc is filled filled " << std::endl;
	}
	std::cout << "-----!!!! capsstr " << capsStr << std::endl;
=======
	GstElement *appSrc = gst_bin_get_by_name( GST_BIN(_displayPipeline),
		"src");
	GstPad *srcPad = gst_element_get_static_pad(appSrc, "src");
	GstCaps *caps = gst_pad_get_allowed_caps(srcPad);

	char *capsStr = gst_caps_to_string(caps);

>>>>>>> 49b321f55b976b0ac9d86dfd52766685cb388d8e
	return capsStr;
}
