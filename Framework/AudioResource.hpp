/**
* @file AudioResource.hpp
* @author Jheng Wei Ciao
*
* Interface for audio resource usage.
*
*/
#ifndef GAO_FRAMEWORK_AUDIORESOURCE_H
#define GAO_FRAMEWORK_AUDIORESOURCE_H

#include "DataType.hpp"
#include "AudioDefine.hpp"



namespace Gao
{
    namespace Framework
    {
        class AudioResource
        {

        public:

            AudioResource();

            /**
             * @brief Class destructor.
             */
            virtual ~AudioResource();

            virtual GaoBool Create(AudioType type, GaoString& fileName, GaoBool loop);

            virtual GaoVoid Play();

            virtual GaoVoid Stop();
            
            virtual GaoVoid Pause();
            
            virtual GaoVoid SetLoop(GaoBool looping);

            virtual GaoVoid SetVolume(GaoReal32 volume);

			virtual GaoBool IsPlaying() const;

            inline AudioType GetType() const;


        protected:

            AudioType   m_Type;

        };
    }
}

#include "AudioResource.inl"

#endif
