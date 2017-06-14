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
#include <vector>
#include <sstream>
#include "connext_cpp_common.h"
#include "VideoSubscriberInterface.h"
#include "CommonInfrastructure/VideoBuffer.h"

using namespace DDS;
using namespace com::rti::media::generated;


// ------------------------------------------------------------------------- //
<<<<<<< HEAD
// The VideoSubscriberInterface is the network interface to the whole application.  This
// creates DataReaders and DataWriters in order to receive and send data.
//
// This interface is built from:
// 1. Network data types and topic names defined in the IDL file
// 2. XML configuration files that describe the QoS profiles that should be
//    used by individual DataWriters and DataReaders.  These describe the
//    movement and persistence characteristics of the data (how reliable should
//    this be?), as well as other QoS such as resource limits.
// 3. The code itself creates DataReaders and DataWriters, and selects which
//    profile to use when creating the DataReaders and DataWriters.
//
// For information on the video data type, please see the VideoData.idl
// file.
=======
// The VideoSubscriberInterface is the network interface to the whole application.  This 
// creates DataReaders and DataWriters in order to receive and send data.  
//
// This interface is built from:
// 1. Network data types and topic names defined in the IDL file
// 2. XML configuration files that describe the QoS profiles that should be 
//    used by individual DataWriters and DataReaders.  These describe the 
//    movement and persistence characteristics of the data (how reliable should
//    this be?), as well as other QoS such as resource limits.
// 3. The code itself creates DataReaders and DataWriters, and selects which 
//    profile to use when creating the DataReaders and DataWriters.
//
// For information on the video data type, please see the VideoData.idl
// file.  
>>>>>>> 49b321f55b976b0ac9d86dfd52766685cb388d8e
//
// For information on the quality of service for streaming video, please
// see the video_stream_multicast.xml file.
//
// Reading video stream data:
// -------------------------
// This class reads video stream data, and displays it.
//
// For information on the video stream data type, please see VideoData.idl
//
// This class receives the video data reliably, but this can be changed in the
<<<<<<< HEAD
// video_stream_multicast.xml file. For more information on the QoS, please
// see that file.
//
// This class uses a listener to be notified of the arrival of video frames.
// The listener is installed at the time that we create the DataReader.  The
// listener is notified of frames arriving from within the middleware's queue,
// which is the fastest way to be notified of data arriving.
// If you reuse this code, BE CAREFUL NOT TO BLOCK inside the
// on_data_available callback, because you risk losing data.
// ------------------------------------------------------------------------- //

VideoSubscriberInterface::VideoSubscriberInterface(
							std::vector<std::string>qosFileNames,
							std::string videoMetadata,
							bool multicastVideoStreams)
{
=======
// video_stream_multicast.xml file. For more information on the QoS, please 
// see that file.
//
// This class uses a listener to be notified of the arrival of video frames.
// The listener is installed at the time that we create the DataReader.  The 
// listener is notified of frames arriving from within the middleware's queue,
// which is the fastest way to be notified of data arriving. 
// If you reuse this code, BE CAREFUL NOT TO BLOCK inside the 
// on_data_available callback, because you risk losing data.
// ------------------------------------------------------------------------- //

VideoSubscriberInterface::VideoSubscriberInterface( 
							std::vector<std::string>qosFileNames,
							std::string videoMetadata,
							bool multicastVideoStreams)
{ 
>>>>>>> 49b321f55b976b0ac9d86dfd52766685cb388d8e

	std::string profileName;


<<<<<<< HEAD

	// Choose a QoS policy for streaming data, and if you plan to use multicast
	// video data, select a QoS profile that supports multicast streaming data.
	// Note that the QoS profile and QoS library names are constants that are
	// defined in the .idl file.
=======
	
	// Choose a QoS policy for streaming data, and if you plan to use multicast
	// video data, select a QoS profile that supports multicast streaming data.
	// Note that the QoS profile and QoS library names are constants that are 
	// defined in the .idl file. 
>>>>>>> 49b321f55b976b0ac9d86dfd52766685cb388d8e
	if (multicastVideoStreams)
	{
		profileName = QOS_PROFILE_MULTICAST_DATA;
	}
	else
	{
		profileName = QOS_PROFILE_STREAMING_DATA;
	}
	_communicator = new DDSCommunicator();

	// Calling the DDSCommunicator class's CreateParticipant method.
	// This creates the DomainParticpant, the first step in creating a DDS
	// application.  This starts the discovery process.  For more information
	// on what the DomainParticipant is responsible for, and how to configure
	// it, see the DDSCommunicator class.
<<<<<<< HEAD
	if (NULL == _communicator->CreateParticipant(0, qosFileNames,
					QOS_LIBRARY, profileName.c_str()))
=======
	if (NULL == _communicator->CreateParticipant(0, qosFileNames, 
					QOS_LIBRARY, profileName.c_str())) 
>>>>>>> 49b321f55b976b0ac9d86dfd52766685cb388d8e
	{
		std::stringstream errss;
		errss << "Failed to create DomainParticipant object";
		throw errss.str();
	}


	// Note that if you want to publish data from this interface,
	// you can do this by calling the DDSCommunicator class's CreatePublisher
	// method. You do _not_ need to create one publisher per DataWriter.


<<<<<<< HEAD
	// Creating a DDS subscriber.
	// You do _not_ need to create one subscriber per DataReader.
	Subscriber *subscriber = _communicator->CreateSubscriber();
	if (subscriber == NULL)
=======
	// Creating a DDS subscriber.  
	// You do _not_ need to create one subscriber per DataReader.
	Subscriber *subscriber = _communicator->CreateSubscriber();
	if (subscriber == NULL) 
>>>>>>> 49b321f55b976b0ac9d86dfd52766685cb388d8e
	{
		std::stringstream errss;
		errss << "Failed to create Subscriber object";
		throw errss.str();
	}

	// Creating the VideoStreamReader object.
<<<<<<< HEAD
	// We could give the application access to the DataReader directly, but
	// this simplifies the application's access - in this case, we can choose
	// to let the application store the data in the DataReader's queue, and
	// query it directly from the DataReader but we create an object to hide
	// that decision from the user.
	// Initialize the receiver with the QoS profile defined in the
	// video_stream_multicast.xml file
	_VideoStreamReader = new VideoStreamReader(
		this,
		subscriber,
=======
	// We could give the application access to the DataReader directly, but 
	// this simplifies the application's access - in this case, we can choose 
	// to let the application store the data in the DataReader's queue, and 
	// query it directly from the DataReader but we create an object to hide
	// that decision from the user.
	// Initialize the receiver with the QoS profile defined in the 
	// video_stream_multicast.xml file
	_VideoStreamReader = new VideoStreamReader(
		this, 
		subscriber, 
>>>>>>> 49b321f55b976b0ac9d86dfd52766685cb388d8e
		QOS_LIBRARY,
		profileName.c_str(),
		videoMetadata);

<<<<<<< HEAD
	if (_VideoStreamReader == NULL)
=======
	if (_VideoStreamReader == NULL) 
>>>>>>> 49b321f55b976b0ac9d86dfd52766685cb388d8e
	{
		std::stringstream errss;
		errss << "Failed to create VideoStreamReader object";
		throw errss.str();
	}

<<<<<<< HEAD
	if(_VideoStreamReader != NULL)
	{
		std::cout << "-----VideoStreamReader NOT here: an object where app store data (QoS, Metadata) to directly query from DataReader" << std::endl;
	}

=======
>>>>>>> 49b321f55b976b0ac9d86dfd52766685cb388d8e
}

// ------------------------------------------------------------------------- //
// Deleting the Video Stream Reader, and the communicator
<<<<<<< HEAD
// infrastructure.  See the individual destructors to see how these are
=======
// infrastructure.  See the individual destructors to see how these are 
>>>>>>> 49b321f55b976b0ac9d86dfd52766685cb388d8e
// deleted.
VideoSubscriberInterface::~VideoSubscriberInterface()
{

	delete _VideoStreamReader;
	delete _communicator;
}

// ------------------------------------------------------------------------- //
// This creates the DDS Listener that receives updates about video data.
//
// This listener class receives notifications from the middleware's threads
<<<<<<< HEAD
// that data is available.  Note that this means that the users of this
=======
// that data is available.  Note that this means that the users of this 
>>>>>>> 49b321f55b976b0ac9d86dfd52766685cb388d8e
// listener SHOULD NEVER BLOCK or else risk data loss.  This listener does
// nothing but call the registered event handlers, which means this is the
// responsibility of the event handlers not to block.
void VideoStreamListener::on_data_available(DataReader *reader)
{
<<<<<<< HEAD
	VideoStreamDataReader *videoReader =
=======
	VideoStreamDataReader *videoReader = 
>>>>>>> 49b321f55b976b0ac9d86dfd52766685cb388d8e
		VideoStreamDataReader::narrow(reader);
	VideoStreamSeq dataSeq;
	SampleInfoSeq infoSeq;
	DDS_ReturnCode_t retCode = DDS_RETCODE_OK;

	if (videoReader == NULL)
	{
<<<<<<< HEAD
		return;
	}
	if (videoReader != NULL)
	{
		std::cout << "---videoReader: Video Stream Data Reader " << '\n';
	}

=======
		return;	
	}
>>>>>>> 49b321f55b976b0ac9d86dfd52766685cb388d8e
	while (retCode != DDS_RETCODE_NO_DATA)
	{

		retCode = videoReader->take(dataSeq, infoSeq, DDS::LENGTH_UNLIMITED,
         DDS::ANY_SAMPLE_STATE, DDS::ANY_VIEW_STATE, DDS::ANY_INSTANCE_STATE);

		if ((retCode != DDS_RETCODE_OK) &&
			(retCode != DDS_RETCODE_NO_DATA))
		{
			std::cout << "Error receiving data" << std::endl;
			return;
		}

		for (int i = 0; i < dataSeq.length(); i++)
		{
			if (infoSeq[i].valid_data == DDS_BOOLEAN_TRUE)
			{
				if ((infoSeq[i].publication_sequence_number.low
						% 50) == 1)
				{
					std::cout << ". " << std::flush;
				}

            if (0 != _last_seq_nr) {
               if (infoSeq[i].publication_sequence_number.low != _last_seq_nr + 1) {
                  std::cout << "Missed seqnr(s): previous was " << _last_seq_nr << ", current is " << infoSeq[i].publication_sequence_number.low  << std::endl;
               }
            }
<<<<<<< HEAD
            std::cout << dataSeq[i].sequence_number << ": " << dataSeq[i].frame.length() << " bytes in frame" << std::endl;

            _last_seq_nr = infoSeq[i].publication_sequence_number.low;

				double timestamp = infoSeq[i].source_timestamp.sec +
						(infoSeq[i].source_timestamp.nanosec / NANOSEC_TO_SEC);

				_reader->NotifyHandlers(&dataSeq[i], dataSeq[i].stream_id,
=======
            //std::cout << dataSeq[i].sequence_number << ": " << dataSeq[i].frame.length() << " bytes in frame" << std::endl;

            _last_seq_nr = infoSeq[i].publication_sequence_number.low;

				double timestamp = infoSeq[i].source_timestamp.sec + 
						(infoSeq[i].source_timestamp.nanosec / NANOSEC_TO_SEC);

				_reader->NotifyHandlers(&dataSeq[i], dataSeq[i].stream_id, 
>>>>>>> 49b321f55b976b0ac9d86dfd52766685cb388d8e
					timestamp);
			}
		}

		// Returning the loaned video data to the middleware.  Note that the
<<<<<<< HEAD
		// data was loaned to the application because the application passed an
		// empty sequence to the take() call.  This is more efficient than
=======
		// data was loaned to the application because the application passed an 
		// empty sequence to the take() call.  This is more efficient than 
>>>>>>> 49b321f55b976b0ac9d86dfd52766685cb388d8e
		// copying the data into a local buffer.
		videoReader->return_loan(dataSeq, infoSeq);
	}


}

// ------------------------------------------------------------------------- //
// This creates the DDS DataReader that receives updates about video frames.
VideoStreamReader::VideoStreamReader(
<<<<<<< HEAD
			VideoSubscriberInterface *comm,
			Subscriber *sub,
			const std::string &qosLibrary,
			const std::string &qosProfile,
			const std::string &videoMetadata)
{

	if (comm == NULL)
=======
			VideoSubscriberInterface *comm, 
			Subscriber *sub, 
			const std::string &qosLibrary, 
			const std::string &qosProfile,
			const std::string &videoMetadata) 
{

	if (comm == NULL) 
>>>>>>> 49b321f55b976b0ac9d86dfd52766685cb388d8e
	{
		std::stringstream errss;
		errss << "VideoStreamReader(): bad parameter \"app\"";
		throw errss.str();
	}

	_communicator = comm;

	// Creating a Topic
<<<<<<< HEAD
	// The topic object is the description of the data that you will be
	// sending. It associates a particular data type with a name that
=======
	// The topic object is the description of the data that you will be 
	// sending. It associates a particular data type with a name that 
>>>>>>> 49b321f55b976b0ac9d86dfd52766685cb388d8e
	// describes the meaning of the data.  Along with the data types, and
	// whether your application is reading or writing particular data, this
	// is the data interface of your application.

<<<<<<< HEAD
	// This topic has the name VIDEO_TOPIC - a constant string
	// that is defined in the .idl file.  (It is not required that you define
=======
	// This topic has the name VIDEO_TOPIC - a constant string 
	// that is defined in the .idl file.  (It is not required that you define  
>>>>>>> 49b321f55b976b0ac9d86dfd52766685cb388d8e
	// your topic name in IDL, but it is a best practice for ensuring the data
	// interface of an application is all defined in one place.)
	// Generally you can register all topics and types up-front if
	// necessary.
	Topic *topic = _communicator->GetCommunicator()->CreateTopic<VideoStream>(
										VIDEO_TOPIC);

	_listener = new VideoStreamListener(this);
<<<<<<< HEAD
	if (_listener == NULL)
=======
	if (_listener == NULL) 
>>>>>>> 49b321f55b976b0ac9d86dfd52766685cb388d8e
	{
		std::stringstream errss;
		errss << "VideoStreamReader(): failure to create VideoListener.";
		throw errss.str();
	}

	// Setting the user_data QoS:
	// We read the QoS library and profile from the file and then we take that
	// QoS and add the user_data in code.
<<<<<<< HEAD
	// user_data is a QoS that is used to specify data that should be sent
=======
	// user_data is a QoS that is used to specify data that should be sent 
>>>>>>> 49b321f55b976b0ac9d86dfd52766685cb388d8e
	// along with discovery.  So, whenever another DomainParticipant discovers
	// this DataReader, it have access to this user_data.

	// In this case, we are using the user_data to send metadata about the
	// video codecs that are being supported.  So, if a remote Video Example
	// Publisher application discovers this application, it will check whether
<<<<<<< HEAD
	// it can provide video that supports the same video codecs that are
=======
	// it can provide video that supports the same video codecs that are 
>>>>>>> 49b321f55b976b0ac9d86dfd52766685cb388d8e
	// supported by the subscribing application.  If they share compatible
	// codecs, it will start publishing video data.
	DDS::DataReaderQos reader_qos;
   if (!(qosLibrary.empty() && qosProfile.empty())) {
<<<<<<< HEAD
      DDS_ReturnCode_t retcode =
=======
      DDS_ReturnCode_t retcode = 
>>>>>>> 49b321f55b976b0ac9d86dfd52766685cb388d8e
         Connext::get_datareader_qos_from_profile(reader_qos,
            qosLibrary, qosProfile);
      if (retcode != DDS::RETCODE_OK) {
         std::stringstream errss;
         errss << "Failed to get DataReaderQos from profile";
         throw errss.str();
      }
   } else {
<<<<<<< HEAD
		 std::cout << "-----Gotten DataReaderQoS from profile" << std::endl;
=======
>>>>>>> 49b321f55b976b0ac9d86dfd52766685cb388d8e
      reader_qos = DDS::DATAREADER_QOS_DEFAULT;
   }

#if (CONNEXT_HAS_USERDATA == 1)
<<<<<<< HEAD
	std::cout << "-----connext has userdata" << std::endl;
	reader_qos.user_data.value.from_array(
		reinterpret_cast<const DDS_Octet *>(videoMetadata.c_str()),
		videoMetadata.length());
#elif (CONNEXT_HAS_USERDATA == -1)
	std::cout << "-----NO DataReaderQoS from profile" << std::endl;
=======
	reader_qos.user_data.value.from_array(
		reinterpret_cast<const DDS_Octet *>(videoMetadata.c_str()), 
		videoMetadata.length());
#elif (CONNEXT_HAS_USERDATA == -1)
>>>>>>> 49b321f55b976b0ac9d86dfd52766685cb388d8e
   /* Deliberately empty line */
#else  /*CONNEXT_HAS_USERDATA */
   #error Incorrect setup: macro CONNEXT_HAS_USERDATA should be defined and have value -1 or 1
#endif  /*CONNEXT_HAS_USERDATA */

	// Creating a DataReader
	// This DataReader will receive the video data, and will store it in its
	// queue, to be retrieved by listener in the on_data_available callback
<<<<<<< HEAD
	DataReader *reader = sub->create_datareader(topic,
=======
	DataReader *reader = sub->create_datareader(topic, 
>>>>>>> 49b321f55b976b0ac9d86dfd52766685cb388d8e
		reader_qos, _listener, DDS_DATA_AVAILABLE_STATUS);
	if (reader == NULL)
	{
		std::stringstream errss;
		errss << "VideoStreamReader(): failure to create DataReader.";
		throw errss.str();
	}

	 // Down casting to the type-specific reader
	 _reader = VideoStreamDataReader::narrow(reader);

}

// ------------------------------------------------------------------------- //
// Destory the video stream DataReader and WaitSet.  Note that this uses
// the DDS factories that created various objects to later delete them.
VideoStreamReader::~VideoStreamReader()
{

	/* _reader->delete_contained_entities(); */
	Subscriber *sub = _reader->get_subscriber();
	sub->delete_datareader(_reader);

}

void VideoStreamReader::RegisterVideoHandler(VideoEventHandler *handler)
{
	_eventHandlers.push_back(handler);
<<<<<<< HEAD
	std::cout << "----Registering video handler" << '\n';
=======
>>>>>>> 49b321f55b976b0ac9d86dfd52766685cb388d8e
}

void VideoStreamReader::UnregisterVideoHandler(VideoEventHandler *handler)
{
	for (std::vector<VideoEventHandler *>::iterator it = _eventHandlers.begin();
		it != _eventHandlers.end(); it++)
	{
		if ((*it) == handler)
		{
			_eventHandlers.erase(it);
<<<<<<< HEAD
			std::cout << "---Erasing video handler" << '\n';
		}
	}

=======
		}
	}
			
>>>>>>> 49b321f55b976b0ac9d86dfd52766685cb388d8e
}

// ----------------------------------------------------------------------------
//
// Notify handlers of frame events that a frame has arrived
<<<<<<< HEAD
//
void VideoStreamReader::NotifyHandlers(VideoStream *frame,
	long streamId, double timestamp)
{
	EMDSBuffer *buffer = NULL;
	std::cout << "-----Frame arrived, halders of frame event " << std::endl;
	std::cout << "-----buffer:  " << buffer << std::endl;
=======
// 
void VideoStreamReader::NotifyHandlers(VideoStream *frame, 
	long streamId, double timestamp)
{
	EMDSBuffer *buffer = NULL;

>>>>>>> 49b321f55b976b0ac9d86dfd52766685cb388d8e
	for (std::vector<VideoEventHandler *>::iterator it = _eventHandlers.begin();
		it != _eventHandlers.end(); it++)
	{
		DDS_Octet *frameBinaryData = frame->frame.get_contiguous_buffer();

		// Allocate a new buffer
<<<<<<< HEAD
		EMDSBuffer *buffer = new EMDSBuffer(frame->frame.length());
		std::cout << "-----NEW Buffer created " << std::endl;
		// Copy the data and metadata into the new buffer
		std::cout << "-----Copying data and metadat into the new Buffer" << std::endl;
		buffer->SetData(frameBinaryData, frame->frame.length());
		buffer->SetSeqn(frame->sequence_number);
		buffer->SetTimestamp(timestamp);
		std::cout << "-----NEW Buffer: " <<buffer<< std::endl;
		// If this is not the video end, notify the handler that a new
		// frame update should be processed
		(*it)->OnFrameUpdate(buffer, streamId);
	}
}
=======
		EMDSBuffer *buffer = new EMDSBuffer(frame->frame.length()); 

		// Copy the data and metadata into the new buffer
		buffer->SetData(frameBinaryData, frame->frame.length());		
		buffer->SetSeqn(frame->sequence_number);
		buffer->SetTimestamp(timestamp);

		// If this is not the video end, notify the handler that a new
		// frame update should be processed 
		(*it)->OnFrameUpdate(buffer, streamId);
	}
}



>>>>>>> 49b321f55b976b0ac9d86dfd52766685cb388d8e
