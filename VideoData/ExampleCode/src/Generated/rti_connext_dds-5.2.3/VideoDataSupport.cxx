
/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from VideoData.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#include "VideoDataSupport.h"
#include "VideoDataPlugin.h"

#ifndef dds_c_log_impl_h              
#include "dds_c/dds_c_log_impl.h"                                
#endif        

namespace com {
    namespace rti {
        namespace media {
            namespace generated {

                /* ========================================================================= */
                /**
                <<IMPLEMENTATION>>

                Defines:   TData,
                TDataWriter,
                TDataReader,
                TTypeSupport

                Configure and implement 'VideoStream' support classes.

                Note: Only the #defined classes get defined
                */

                /* ----------------------------------------------------------------- */
                /* DDSDataWriter
                */

                /**
                <<IMPLEMENTATION >>

                Defines:   TDataWriter, TData
                */

                /* Requires */
                #define TTYPENAME   VideoStreamTYPENAME

                /* Defines */
                #define TDataWriter VideoStreamDataWriter
                #define TData       com::rti::media::generated::VideoStream

                #include "dds_cpp/generic/dds_cpp_data_TDataWriter.gen"

                #undef TDataWriter
                #undef TData

                #undef TTYPENAME

                /* ----------------------------------------------------------------- */
                /* DDSDataReader
                */

                /**
                <<IMPLEMENTATION >>

                Defines:   TDataReader, TDataSeq, TData
                */

                /* Requires */
                #define TTYPENAME   VideoStreamTYPENAME

                /* Defines */
                #define TDataReader VideoStreamDataReader
                #define TDataSeq    VideoStreamSeq
                #define TData       com::rti::media::generated::VideoStream

                #include "dds_cpp/generic/dds_cpp_data_TDataReader.gen"

                #undef TDataReader
                #undef TDataSeq
                #undef TData

                #undef TTYPENAME

                /* ----------------------------------------------------------------- */
                /* TypeSupport

                <<IMPLEMENTATION >>

                Requires:  TTYPENAME,
                TPlugin_new
                TPlugin_delete
                Defines:   TTypeSupport, TData, TDataReader, TDataWriter
                */

                /* Requires */
                #define TTYPENAME    VideoStreamTYPENAME
                #define TPlugin_new  com::rti::media::generated::VideoStreamPlugin_new
                #define TPlugin_delete  com::rti::media::generated::VideoStreamPlugin_delete

                /* Defines */
                #define TTypeSupport VideoStreamTypeSupport
                #define TData        com::rti::media::generated::VideoStream
                #define TDataReader  VideoStreamDataReader
                #define TDataWriter  VideoStreamDataWriter
                #define TGENERATE_SER_CODE
                #define TGENERATE_TYPECODE

                #include "dds_cpp/generic/dds_cpp_data_TTypeSupport.gen"

                #undef TTypeSupport
                #undef TData
                #undef TDataReader
                #undef TDataWriter
                #undef TGENERATE_TYPECODE
                #undef TGENERATE_SER_CODE
                #undef TTYPENAME
                #undef TPlugin_new
                #undef TPlugin_delete

            } /* namespace generated  */
        } /* namespace media  */
    } /* namespace rti  */
} /* namespace com  */

