

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from pidcontrol.idl
using RTI Code Generator (rtiddsgen) version 4.3.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#include <iosfwd>
#include <iomanip>
#include <cmath>
#include <limits>

#ifndef NDDS_STANDALONE_TYPE
#include "rti/topic/cdr/Serialization.hpp"
#include "pidcontrolPlugin.hpp"
#else
#include "rti/topic/cdr/SerializationHelpers.hpp"
#endif

#include "pidcontrol.hpp"

#include <rti/util/ostream_operators.hpp>

// ---- LampControl: 

LampControl::LampControl() :
    m_lampID_ (0) ,
    m_count_r_ (0) ,
    m_intensity_ (0.0f)  {

}   

LampControl::LampControl (int32_t lampID_,bool count_r_,float intensity_):
    m_lampID_(lampID_), 
    m_count_r_(count_r_), 
    m_intensity_(intensity_) {
}

void LampControl::swap(LampControl& other_)  noexcept 
{
    using std::swap;
    swap(m_lampID_, other_.m_lampID_);
    swap(m_count_r_, other_.m_count_r_);
    swap(m_intensity_, other_.m_intensity_);
}  

bool LampControl::operator == (const LampControl& other_) const {
    if (m_lampID_ != other_.m_lampID_) {
        return false;
    }
    if (m_count_r_ != other_.m_count_r_) {
        return false;
    }
    if (std::fabs(m_intensity_ - other_.m_intensity_) > std::numeric_limits< float>::epsilon()
    && !(std::fabs(m_intensity_ - other_.m_intensity_) < (std::numeric_limits< float>::min)())) {
        return false;
    }
    return true;
}

bool LampControl::operator != (const LampControl& other_) const {
    return !this->operator ==(other_);
}

std::ostream& operator << (std::ostream& o,const LampControl& sample)
{
    ::rti::util::StreamFlagSaver flag_saver (o);
    o <<"[";
    o << "lampID: " << sample.lampID ()<<", ";
    o << "count_r: " << sample.count_r ()<<", ";
    o << "intensity: " << std::setprecision(9) << sample.intensity ();
    o <<"]";
    return o;
}

#ifdef NDDS_STANDALONE_TYPE
namespace rti {
    namespace topic {
    }
}

#else
// --- Type traits: -------------------------------------------------

namespace rti { 
    namespace topic {

        template<>
        struct native_type_code< ::LampControl > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member LampControl_g_tc_members[3]=
                {

                    {
                        (char *)"lampID",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_KEY_MEMBER , /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"count_r",/* Member name */
                        {
                            1,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"intensity",/* Member name */
                        {
                            2,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode LampControl_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"LampControl", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        3, /* Number of members */
                        LampControl_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for LampControl*/

                if (is_initialized) {
                    return &LampControl_g_tc;
                }

                is_initialized = RTI_TRUE;

                LampControl_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                LampControl_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
                LampControl_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::interpreter::initialize_bool_typecode();
                LampControl_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

                /* Initialize the values for member annotations. */
                LampControl_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
                LampControl_g_tc_members[0]._annotations._defaultValue._u.long_value = 0;
                LampControl_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_LONG;
                LampControl_g_tc_members[0]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
                LampControl_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
                LampControl_g_tc_members[0]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;
                LampControl_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_BOOLEAN;
                LampControl_g_tc_members[1]._annotations._defaultValue._u.boolean_value = 0;
                LampControl_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_FLOAT;
                LampControl_g_tc_members[2]._annotations._defaultValue._u.float_value = 0.0f;
                LampControl_g_tc_members[2]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
                LampControl_g_tc_members[2]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
                LampControl_g_tc_members[2]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
                LampControl_g_tc_members[2]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;

                LampControl_g_tc._data._sampleAccessInfo = sample_access_info();
                LampControl_g_tc._data._typePlugin = type_plugin_info();    

                return &LampControl_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                ::LampControl *sample;

                static RTIXCdrMemberAccessInfo LampControl_g_memberAccessInfos[3] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo LampControl_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &LampControl_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    ::LampControl);
                if (sample == NULL) {
                    return NULL;
                }

                LampControl_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->lampID() - (char *)sample);

                LampControl_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->count_r() - (char *)sample);

                LampControl_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->intensity() - (char *)sample);

                LampControl_g_sampleAccessInfo.memberAccessInfos = 
                LampControl_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::LampControl);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        LampControl_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        LampControl_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                LampControl_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                LampControl_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::LampControl >;

                LampControl_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &LampControl_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin LampControl_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &LampControl_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::StructType& dynamic_type< ::LampControl >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::LampControl >::get())));
        }
    }
}

namespace dds { 
    namespace topic {
        void topic_type_support< ::LampControl >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                ::LampControlPlugin_new,
                ::LampControlPlugin_delete);
        }

        std::vector<char>& topic_type_support< ::LampControl >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const ::LampControl& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = LampControlPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = LampControlPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< ::LampControl >::from_cdr_buffer(::LampControl& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = LampControlPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create ::LampControl from cdr buffer");
        }

        void topic_type_support< ::LampControl >::reset_sample(::LampControl& sample) 
        {
            sample.lampID(0);
            sample.count_r(0);
            sample.intensity(0.0f);
        }

        void topic_type_support< ::LampControl >::allocate_sample(::LampControl& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample);
        }
    }
}  

#endif // NDDS_STANDALONE_TYPE
