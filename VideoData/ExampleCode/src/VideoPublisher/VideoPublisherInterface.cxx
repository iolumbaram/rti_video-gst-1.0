/*********************************************************************************************
<<<<<<< HEAD
(c) 2005-2013 Copyright, Real-Time Innovations, Inc.  All rights reserved.
RTI grants Licensee a license to use, modify, compile, and create derivative works
of the Software.  Licensee has the right to distribute object form only for use with RTI
products.  The Software is provided �as is�, with no warranty of any type, including
any warranty for fitness for any purpose. RTI is under no obligation to maintain or
support the Software.  RTI shall not be liable for any incidental or consequential
=======
(c) 2005-2013 Copyright, Real-Time Innovations, Inc.  All rights reserved.    	                             
RTI grants Licensee a license to use, modify, compile, and create derivative works 
of the Software.  Licensee has the right to distribute object form only for use with RTI 
products.  The Software is provided �as is�, with no warranty of any type, including 
any warranty for fitness for any purpose. RTI is under no obligation to maintain or 
support the Software.  RTI shall not be liable for any incidental or consequential 
>>>>>>> 49b321f55b976b0ac9d86dfd52766685cb388d8e
damages arising out of the use or inability to use the software.
**********************************************************************************************/
#include <iostream>
#include "connext_cpp_common.h"
#include "VideoPublisherInterface.h"

using namespace com::rti::media::generated;

// ----------------------------------------------------------------------------
<<<<<<< HEAD
// The VideoPublisherInterface is the network interface to the whole
// application.  This creates a DataWriter in order to send video stream data
// over the network (or shared memory) to other applications that are
=======
// The VideoPublisherInterface is the network interface to the whole 
// application.  This creates a DataWriter in order to send video stream data
// over the network (or shared memory) to other applications that are 
>>>>>>> 49b321f55b976b0ac9d86dfd52766685cb388d8e
// interested in video streams.
//
// This interface is built from:
// 1. Network data types and topic names defined in the IDL file
<<<<<<< HEAD
// 2. XML configuration files that describe the QoS profiles that should be
//    used by individual DataWriters and DataReaders.  These describe the
=======
// 2. XML configuration files that describe the QoS profiles that should be 
//    used by individual DataWriters and DataReaders.  These describe the 
>>>>>>> 49b321f55b976b0ac9d86dfd52766685cb388d8e
//    movement and persistence characteristics of the data (how reliable should
//    this be?), as well as other QoS such as resource limits.
// 3. The code itself creates DataWriters, and selects which QoS profile to use
//    when creating the DataWriters.
<<<<<<< HEAD
//
// Writing video stream data:
// -------------------------
// This application sends video stream data, configured to act as streaming data
// This will reliably deliver the video stream to both existing and late-joining
// applications that subscribe to video stream data.  Late joining applications
// will not receive all video frames from the beginning, but will start
// receiving frames in the middle of the stream.
//
// For information on the video stream data type, please see the
// VideoData.idl file.
=======
// 
// Writing video stream data:
// -------------------------
// This application sends video stream data, configured to act as streaming data
// This will reliably deliver the video stream to both existing and late-joining 
// applications that subscribe to video stream data.  Late joining applications 
// will not receive all video frames from the beginning, but will start 
// receiving frames in the middle of the stream.
//
// For information on the video stream data type, please see the 
// VideoData.idl file.  
>>>>>>> 49b321f55b976b0ac9d86dfd52766685cb388d8e
//
// For information on the quality of service for video stream data, please
// see the video_stream_multicast.xml file.
//
// Listening to discovery data:
// ----------------------------
<<<<<<< HEAD
// This application listens to the discovery data that the RTI Connext DDS
// middleware uses to discover remote DomainParticipants, DataWriters, and
// DataReaders.  This listens just to the DataReader traffic to see if
// there is a remote DataReader that:
//   1) Has the same topic
//   2) Has been configured with USER_DATA QoS.  This USER_DATA QoS is
//      metadata that is sent as part of discovery.
//   3) Has codec information in that USER_DATA that is compatible with the
//      codecs that this application can stream.
//
=======
// This application listens to the discovery data that the RTI Connext DDS 
// middleware uses to discover remote DomainParticipants, DataWriters, and
// DataReaders.  This listens just to the DataReader traffic to see if 
// there is a remote DataReader that:
//   1) Has the same topic
//   2) Has been configured with USER_DATA QoS.  This USER_DATA QoS is 
//      metadata that is sent as part of discovery.
//   3) Has codec information in that USER_DATA that is compatible with the
//      codecs that this application can stream.
//   
>>>>>>> 49b321f55b976b0ac9d86dfd52766685cb388d8e
// If this application discovers a remote DataReader with no USER_DATA, or
// with a codec that this does not support, it uses the ignore() API to avoid
// sending data to that DataReader.
//
// ------------------------------------------------------------------------- //

VideoPublisherInterface::VideoPublisherInterface(
			std::vector<std::string> xmlFiles,
<<<<<<< HEAD
			CodecCompatibleHandler *codecCompatibilityHandler)
=======
			CodecCompatibleHandler *codecCompatibilityHandler) 
>>>>>>> 49b321f55b976b0ac9d86dfd52766685cb388d8e
{

	_communicator = new DDSCommunicator();

	// Create a discovery listener
<<<<<<< HEAD
	// This will listen to discovery information and will call back the
	// codecCompatibilityHandler.  The codecCompatibilityHandler will
	// query the video framework to see if the remote DataReader's codec is
	// compatible with the codec we are publishing.
	VideoPublisherDiscoveryListener *discoveryListener =
=======
	// This will listen to discovery information and will call back the 
	// codecCompatibilityHandler.  The codecCompatibilityHandler will 
	// query the video framework to see if the remote DataReader's codec is
	// compatible with the codec we are publishing.
	VideoPublisherDiscoveryListener *discoveryListener = 
>>>>>>> 49b321f55b976b0ac9d86dfd52766685cb388d8e
		new VideoPublisherDiscoveryListener(codecCompatibilityHandler);

	// Create a DomainParticipant
	// Start by creating a DomainParticipant.  Generally you will have only
	// one DomainParticipant per application.  A DomainParticipant is
	// responsible for starting the discovery process, allocating resources,
<<<<<<< HEAD
	// and being the factory class used to create Publishers, Subscribers,
	// Topics, etc.
	// Note that the QoS profile and QoS library names are constants that are
	// defined in the .idl file.
	if (NULL == _communicator->CreateParticipant(0, xmlFiles,
				QOS_LIBRARY, QOS_PROFILE_STREAMING_DATA,
				discoveryListener, DATAREADER_DISCOVERY_KIND))
=======
	// and being the factory class used to create Publishers, Subscribers, 
	// Topics, etc.
	// Note that the QoS profile and QoS library names are constants that are 
	// defined in the .idl file. 
	if (NULL == _communicator->CreateParticipant(0, xmlFiles, 
				QOS_LIBRARY, QOS_PROFILE_STREAMING_DATA,
				discoveryListener, DATAREADER_DISCOVERY_KIND)) 
>>>>>>> 49b321f55b976b0ac9d86dfd52766685cb388d8e
	{
		std::stringstream errss;
		errss << "Failed to create DomainParticipant object";
		throw errss.str();
	}

	// Create a Publisher
	// This application only writes data, so we only need to create a
<<<<<<< HEAD
	// publisher.
	// Note that one Publisher can be used to create multiple DataWriters
	DDS::Publisher *pub = _communicator->CreatePublisher();

	if (pub == NULL)
=======
	// publisher.  
	// Note that one Publisher can be used to create multiple DataWriters
	DDS::Publisher *pub = _communicator->CreatePublisher();

	if (pub == NULL) 
>>>>>>> 49b321f55b976b0ac9d86dfd52766685cb388d8e
	{
		std::stringstream errss;
		errss << "Failed to create Publisher object";
		throw errss.str();
	}


	// Creating a Topic
<<<<<<< HEAD
	// The Topic object is the description of the data that you will be
	// sending. It associates a particular data type with a name that
=======
	// The Topic object is the description of the data that you will be 
	// sending. It associates a particular data type with a name that 
>>>>>>> 49b321f55b976b0ac9d86dfd52766685cb388d8e
	// describes the meaning of the data.  Along with the data types, and
	// whether your application is reading or writing particular data, this
	// is the data interface of your application.

<<<<<<< HEAD
	// This topic has the name VIDEO_TOPIC - a constant
	// string that is defined in the .idl file.  (It is not required that
	// you define your topic name in IDL, but it is a best practice for
	// ensuring the data interface of an application is all defined in one
	// place. You can register all topics and types up-front, if you nee
	DDS::Topic *topic = _communicator->CreateTopic<VideoStream>(
		VIDEO_TOPIC);

	// Create a DataWriter.
=======
	// This topic has the name VIDEO_TOPIC - a constant  
	// string that is defined in the .idl file.  (It is not required that
	// you define your topic name in IDL, but it is a best practice for
	// ensuring the data interface of an application is all defined in one 
	// place. You can register all topics and types up-front, if you nee
	DDS::Topic *topic = _communicator->CreateTopic<VideoStream>( 
		VIDEO_TOPIC);

	// Create a DataWriter.  
>>>>>>> 49b321f55b976b0ac9d86dfd52766685cb388d8e
	// This creates a single DataWriter that writes video stream data, with QoS
	// that is used for streaming data.

	// Choose a QoS policy for streaming data (the choice to use multicast is
	// decided by the DataReader, not the DataWriter)
<<<<<<< HEAD
	// Note that the QoS profile and QoS library names are constants that are
	// defined in the .idl file.
   DDS::DataWriterQos writer_qos;
   Connext::get_datawriter_qos_from_profile(writer_qos,
      QOS_LIBRARY, QOS_PROFILE_STREAMING_DATA);
	DDS::DataWriter *writer = pub->create_datawriter(topic,
      writer_qos,	NULL, DDS_STATUS_MASK_NONE);

	// Downcast the generic datawriter to a video stream DataWriter
	_writer = VideoStreamDataWriter::narrow(writer);

	if (_writer == NULL)
	{
		std::stringstream errss;
		errss <<
=======
	// Note that the QoS profile and QoS library names are constants that are 
	// defined in the .idl file. 
   DDS::DataWriterQos writer_qos;
   Connext::get_datawriter_qos_from_profile(writer_qos,
      QOS_LIBRARY, QOS_PROFILE_STREAMING_DATA);
	DDS::DataWriter *writer = pub->create_datawriter(topic, 
      writer_qos,	NULL, DDS_STATUS_MASK_NONE);

	// Downcast the generic datawriter to a video stream DataWriter 
	_writer = VideoStreamDataWriter::narrow(writer);

	if (_writer == NULL) 
	{
		std::stringstream errss;
		errss << 
>>>>>>> 49b321f55b976b0ac9d86dfd52766685cb388d8e
			"VideoPublisherInterface(): failure to create writer. "
			"Inconsistent Qos?";
		throw errss.str();
	}

<<<<<<< HEAD
	if (_writer != NULL)
	{
		std::cout << "-------QoS matches and created writer" << std::endl;
	}

=======
>>>>>>> 49b321f55b976b0ac9d86dfd52766685cb388d8e
}

// ----------------------------------------------------------------------------
// Destructor.
// Deletes the DataWriter, and the Communicator object
VideoPublisherInterface::~VideoPublisherInterface()
{
	DDS::Publisher *pub = _writer->get_publisher();
	pub->delete_datawriter(_writer);
	_writer = NULL;

	delete _communicator;
}


// ----------------------------------------------------------------------------
// Sends the videos tream over a transport (such as shared memory or UDPv4)
bool VideoPublisherInterface::Write(DdsAutoType<VideoStream> data)
{
	DDS_ReturnCode_t retcode = DDS_RETCODE_OK;
	DDS_InstanceHandle_t handle = DDS_HANDLE_NIL;

<<<<<<< HEAD
	// This actually sends the video data over the network.
	retcode = _writer->write(data, handle);

	if (retcode != DDS_RETCODE_OK)
=======
	// This actually sends the video data over the network.  
	retcode = _writer->write(data, handle);

	if (retcode != DDS_RETCODE_OK) 
>>>>>>> 49b321f55b976b0ac9d86dfd52766685cb388d8e
	{
		return false;
	}

<<<<<<< HEAD
	std::cout << "Writing sample #" << data.sequence_number
		<< ", length: " << data.frame.length() << std::endl;
=======
	/* std::cout << "Writing sample #" << data.sequence_number
		<< ", length: " << data.frame.length() << std::endl; */
>>>>>>> 49b321f55b976b0ac9d86dfd52766685cb388d8e

	return true;

}

// ----------------------------------------------------------------------------
<<<<<<< HEAD
// Sends a deletion message for the streaming video data over a transport (such
=======
// Sends a deletion message for the streaming video data over a transport (such 
>>>>>>> 49b321f55b976b0ac9d86dfd52766685cb388d8e
// as shared memory or UDPv4) This uses the unregiste_instance call to notify
// other applications that this video stream has ended
bool VideoPublisherInterface::Delete(DdsAutoType<VideoStream> data)
{
	DDS_ReturnCode_t retcode = DDS_RETCODE_OK;
	DDS_InstanceHandle_t handle = DDS_HANDLE_NIL;
<<<<<<< HEAD
	std::cout << "----deletion of messages for the streaming video data (shared memory)" << std::endl;
	// Note that the deletion maps to an "unregister" in the RTI Connext
	// DDS world.  This allows the instance to be cleaned up entirely,
	// so the space can be reused for another instance.  If you call
	// "dispose" it will not clean up the space for a new instance -
=======

	// Note that the deletion maps to an "unregister" in the RTI Connext
	// DDS world.  This allows the instance to be cleaned up entirely, 
	// so the space can be reused for another instance.  If you call
	// "dispose" it will not clean up the space for a new instance - 
>>>>>>> 49b321f55b976b0ac9d86dfd52766685cb388d8e
	// instead it marks the current instance disposed and expects that you
	// might reuse the same instance again later.
	retcode = _writer->unregister_instance(data, handle);

	if (retcode != DDS_RETCODE_OK)
	{
		return false;
	}

	return true;
}

// ----------------------------------------------------------------------------
<<<<<<< HEAD
// This is a listener callback that is called from an RTI Connext DDS
// middleware thread.  It is called when the local DomainParticipant discovers
// a remote DataReader.
//
// What this does:
//   1. Check if the DataReader is reading the Topic that this application is
//      writing
//   2. Check if the (remote) DataReader has used the user_data QoS to send
=======
// This is a listener callback that is called from an RTI Connext DDS 
// middleware thread.  It is called when the local DomainParticipant discovers
// a remote DataReader.
// 
// What this does:
//   1. Check if the DataReader is reading the Topic that this application is
//      writing
//   2. Check if the (remote) DataReader has used the user_data QoS to send 
>>>>>>> 49b321f55b976b0ac9d86dfd52766685cb388d8e
//      metadata about the codec(s) it supports.
//   3. If the (remote) DataReader does not have applicable codecs, ignore it.
//
void VideoPublisherDiscoveryListener::on_data_available(DDSDataReader *reader)
{
<<<<<<< HEAD
	// Cast the DataReader passed into this callback to a
=======
	// Cast the DataReader passed into this callback to a 
>>>>>>> 49b321f55b976b0ac9d86dfd52766685cb388d8e
	// "SubscriptionBuiltinTopicDataDataReader" that gets notifications about
	// remote DataReaders.
#if (CONNEXT_HAS_BUILTINTOPICS == 1)
	DDS::SubscriptionBuiltinTopicDataDataReader *builtin_reader =
		(DDS::SubscriptionBuiltinTopicDataDataReader*) reader;
	DDS_SubscriptionBuiltinTopicDataSeq data_seq;
	DDS_SampleInfoSeq info_seq;
	DDS_ReturnCode_t retcode;

	// Used to retrieve the metadata that was stored in the user_data Qos to
	// send as part of discovery.
	char *readerData;
<<<<<<< HEAD
	//below gives terminate called after throwing an instance of 'std::logic_error' what():  basic_string::_S_construct null not valid Aborted (core dumped)

	//std::string readerData_str = std::string(readerData);
	//std::cout << "++retrieved metadata (from user_data Qos)  " << readerData<< 	std::endl;
	std::cout << "++retrieved metadata (from user_data Qos)  " <<	std::endl;

	// We only process newly seen participants
	retcode = builtin_reader->take(data_seq, info_seq, DDS_LENGTH_UNLIMITED,
		DDS_ANY_SAMPLE_STATE, DDS_NEW_VIEW_STATE,
		DDS_ANY_INSTANCE_STATE);

		std::cout << "return code from newly seen participant  " << retcode << 	std::endl;

	// It is unlikely that we will be notified if there is nodata, but we do
	// not treat it as an error.
	if (retcode == DDS_RETCODE_NO_DATA)
	{

		return;
	}

	if (retcode != DDS_RETCODE_OK)
	{
		std::cout << "Error: failed to access data from the built-in reader"
=======
    
	// We only process newly seen participants
	retcode = builtin_reader->take(data_seq, info_seq, DDS_LENGTH_UNLIMITED, 
		DDS_ANY_SAMPLE_STATE, DDS_NEW_VIEW_STATE, 
		DDS_ANY_INSTANCE_STATE);

	// It is unlikely that we will be notified if there is nodata, but we do
	// not treat it as an error.
	if (retcode == DDS_RETCODE_NO_DATA)
	{	
		return;
	}

	if (retcode != DDS_RETCODE_OK) 
	{
		std::cout << "Error: failed to access data from the built-in reader" 
>>>>>>> 49b321f55b976b0ac9d86dfd52766685cb388d8e
			<< std::endl;
		return;
	}

	// Iterate over all the notifications we have received about new
	// DataReaders that we have discovered.
<<<<<<< HEAD
	for(int i = 0; i < data_seq.length(); ++i)
=======
	for(int i = 0; i < data_seq.length(); ++i) 
>>>>>>> 49b321f55b976b0ac9d86dfd52766685cb388d8e
	{
		// Having valid_data = false is a normal scenario if we are receiving
		// a notification that a DataReader was shut down.
		if (!info_seq[i].valid_data)
		{
			continue;
		}

<<<<<<< HEAD
		// If I have discovered a DataReader that is not reading the same
=======
		// If I have discovered a DataReader that is not reading the same 
>>>>>>> 49b321f55b976b0ac9d86dfd52766685cb388d8e
		// video topic that this application is writing, do not bother
		// to check whether that DataReader has metadata.
		if (0 != strcmp(data_seq[i].topic_name, VIDEO_TOPIC))
		{
			continue;
		}

		readerData = NULL;

		bool isCompatible = false;

		// see if there is user_data associated with the DataReader
<<<<<<< HEAD
		std::cout << "----Any user_data associated with the DataReader?" << std::endl;
		if (data_seq[i].user_data.value.length() != 0)
		{
			// This sequence is guaranteed to be contiguous

			readerData = (char*)&data_seq[i].user_data.value[0];

			// Call back the handler (which will call the video
			// infrastructure) to find out if the remote codec is compatible
			// with the codecs this application is publishing.
			isCompatible = _handler->CodecsCompatible(readerData);
			std::cout << "-----Found subscriber WITH user_data:  " << readerData << std::endl;
		} else {
         std::cout << "------Found subscriber with no user_data" << std::endl;
			isCompatible = _handler->CodecsCompatible("");
      }

		if (!isCompatible)
		{
			// Will not write to this DataReader.  Using the ignore()
			// API to ignore the participant and
=======
		if (data_seq[i].user_data.value.length() != 0) 
		{
			// This sequence is guaranteed to be contiguous
			readerData = (char*)&data_seq[i].user_data.value[0];

			// Call back the handler (which will call the video 
			// infrastructure) to find out if the remote codec is compatible
			// with the codecs this application is publishing.
			isCompatible = _handler->CodecsCompatible(readerData);
		} else {
         std::cout << "Found subscriber with no user_data" << std::endl;
			isCompatible = _handler->CodecsCompatible("");
      }
		
		if (!isCompatible) 
		{
			// Will not write to this DataReader.  Using the ignore() 
			// API to ignore the participant and 
>>>>>>> 49b321f55b976b0ac9d86dfd52766685cb388d8e
			std::cout << "Discovered a DataReader with an incompatible codec. "
				<< "Ignoring it (not sending it any data)" << std::endl;
			DDSDomainParticipant *participant =
				reader->get_subscriber()->get_participant();
			retcode = participant->ignore_subscription(info_seq[i].instance_handle);
<<<<<<< HEAD
			if (retcode != DDS_RETCODE_OK)
=======
			if (retcode != DDS_RETCODE_OK) 
>>>>>>> 49b321f55b976b0ac9d86dfd52766685cb388d8e
			{
				std::cout << "Error ignoring participant: " << retcode << std::endl;
				return;
			}
		}
	}
<<<<<<< HEAD

	// Returning the loaned discovery data to the middleware.  Note that the
	// data was loaned to the application because the application passed an
	// empty sequence to the take() call.  This is more efficient than
	// copying the data into a local buffer.
	builtin_reader->return_loan(data_seq, info_seq);
	std::cout << "------loan data? " << builtin_reader << std::endl;
=======
	
	// Returning the loaned discovery data to the middleware.  Note that the
	// data was loaned to the application because the application passed an 
	// empty sequence to the take() call.  This is more efficient than 
	// copying the data into a local buffer.
	builtin_reader->return_loan(data_seq, info_seq);
>>>>>>> 49b321f55b976b0ac9d86dfd52766685cb388d8e
#elif (CONNEXT_HAS_BUILTINTOPICS == -1)
#if (VIDEODATA_MATCH_EMPTY_USERDATA == 1)
    /* Need to invoke compatibility check to make sure internal state of _handler gets updated
	    (this is due to a side-effect in the method CodecsCompatible()) */
    _handler->CodecsCompatible(std::string(""));
#elif (VIDEODATA_MATCH_EMPTY_USERDATA == -1)
#else /* VIDEODATA_MATCH_EMPTY_USERDATA */
   #error Incorrect setup: VIDEODATA_MATCH_EMPTY_USERDATA should be defined and have the value -1 or 1
#endif /* VIDEODATA_MATCH_EMPTY_USERDATA */
#else /* CONNEXT_HAS_BUILTINTOPICS */
   #error Incorrect setup: CONNEXT_HAS_BUILTINTOPIC should be defined and have the value -1 or 1
#endif /* CONNEXT_HAS_BUILTINTOPICS */


}
<<<<<<< HEAD
=======

>>>>>>> 49b321f55b976b0ac9d86dfd52766685cb388d8e
