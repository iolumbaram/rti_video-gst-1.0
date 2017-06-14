
/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from VideoData.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef VideoDataSupport_1974959821_h
#define VideoDataSupport_1974959821_h

/* Uses */
#include "VideoData.h"

#ifndef ndds_cpp_h
#include "ndds/ndds_cpp.h"
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)

class __declspec(dllimport) DDSTypeSupport;
class __declspec(dllimport) DDSDataWriter;
class __declspec(dllimport) DDSDataReader;

#endif

namespace com {
    namespace rti {
        namespace media {
            namespace generated {
                /* ========================================================================= */
                /**
                Uses:     T

                Defines:  TTypeSupport, TDataWriter, TDataReader

                Organized using the well-documented "Generics Pattern" for
                implementing generics in C and C++.
                */

                #if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
                /* If the code is building on Windows, start exporting symbols.
                */
                #undef NDDSUSERDllExport
                #define NDDSUSERDllExport __declspec(dllexport)

                #endif

                DDS_TYPESUPPORT_CPP(VideoStreamTypeSupport, VideoStream);

                DDS_DATAWRITER_CPP(VideoStreamDataWriter, VideoStream);
                DDS_DATAREADER_CPP(VideoStreamDataReader, VideoStreamSeq, VideoStream);

                #if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
                /* If the code is building on Windows, stop exporting symbols.
                */
                #undef NDDSUSERDllExport
                #define NDDSUSERDllExport
                #endif
            } /* namespace generated  */
        } /* namespace media  */
    } /* namespace rti  */
} /* namespace com  */

#endif  /* VideoDataSupport_1974959821_h */

