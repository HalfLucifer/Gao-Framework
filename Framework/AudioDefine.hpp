/**
 * @file AudioDefine.hpp
 * @author Jheng Wei Ciao
 *
 * Defines and data types for audio usage.
 *
 */
#ifndef GAO_FRAMEWORK_AUDIODEFINE_H
#define GAO_FRAMEWORK_AUDIODEFINE_H



namespace Gao
{
    namespace Framework
    {
        /**
         * @brief Audio type can be used.
         */
        enum AudioType
        {
            Audio_Normal,    /**< Normal non-streaming audio. */
            Audio_Streaming, /**< Streaming audio.            */
        };
        
        static const GaoReal32 DEFAULT_AUDIO_VOLUME = 1.0f;
    }
}

#endif
