/**
 * @file AudioRenderer.hpp
 * @author Jheng Wei Ciao
 *
 * Renderer interface for audio usage.
 *
 */
#ifndef GAO_FRAMEWORK_AUDIORENDERER_H
#define GAO_FRAMEWORK_AUDIORENDERER_H

#include "DataType.hpp"
#include "AudioDefine.hpp"



namespace Gao
{
    namespace Framework
    {
        /**
         * @brief Forward declaration.
         */
        class AudioResource;



        /**
         * @brief Interface class for audio renderer.
         */
        class AudioRenderer
        {

        public:

            AudioRenderer();

            virtual ~AudioRenderer();
            
            GaoVoid SetBasePath(GaoConstCharPtr normalBasePath, GaoConstCharPtr streamingBasePath);

            virtual AudioResource* CreateAudio(AudioType type, GaoString& fileName, GaoBool looping);

            virtual GaoVoid Play(AudioResource* audio);

            virtual GaoVoid Stop(AudioResource* audio);

            virtual GaoVoid SetLoop(AudioResource* audio, GaoBool looping);

            virtual GaoVoid Pause(AudioResource* audio);
            
            virtual GaoVoid SetVolume(AudioResource* audio, GaoReal32 volume);

            virtual GaoVoid SetGlobalVolumes(AudioType type, GaoReal32 volume);

            
        protected:
            
            GaoString       m_NormalBasePath;
            GaoString       m_StreamingBasePath;
            GaoString       m_WorkingFullPath;
            
        };
    }
}

#endif
