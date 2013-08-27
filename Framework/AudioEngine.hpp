/**
 * @file AudioEngine.hpp
 * @author Jheng Wei Ciao
 *
 * Interface for audio usage.
 *
 */
#ifndef GAO_FRAMEWORK_AUDIOENGINE_H
#define GAO_FRAMEWORK_AUDIOENGINE_H

#include "DataType.hpp"
#include "Singleton.hpp"
#include "AudioDefine.hpp"
#include "Dictionary.hpp"

#define g_AudioEngine Gao::Framework::AudioEngine::GetSingletonPointer()



namespace Gao
{
    namespace Framework
    {
        /**
         * @brief Forward declaration.
         */
        class AudioRenderer;
        class AudioResource;



        /**
         * @brief Interface class for audio.
         */
        class AudioEngine : public Singleton<AudioEngine>
        {

        public:

            /**
             * @brief Class constructor.
             * @param renderer The renderer that audio engine uses.
             */
            AudioEngine(AudioRenderer* renderer);

			AudioEngine(AudioRenderer* renderer, GaoBool autoReleaseRenderer);

            /**
             * @brief Class destructor.
             */
            virtual ~AudioEngine();

			GaoVoid SetBasePath(GaoString& normalBasePath, GaoString& streamingBasePath);

            GaoVoid SetBasePath(GaoConstCharPtr normalBasePath, GaoConstCharPtr streamingBasePath);

            AudioResource* CreateAudio(AudioType type, GaoString& fileName, GaoBool looping);

            AudioResource* CreateAudio(AudioType type, GaoConstCharPtr fileName, GaoBool looping);

			AudioResource* CreateAudio(GaoConstCharPtr fileName);

			AudioResource* CreateStreamingAudio(GaoConstCharPtr fileName, GaoBool looping);
            
            GaoBool DestroyAudio(GaoConstCharPtr fileName);

            GaoVoid PlayAudio(AudioType type, GaoString& fileName);

            GaoVoid PlayAudio(AudioType type, GaoConstCharPtr fileName);

			GaoVoid PlayAudio(GaoConstCharPtr fileName);

            GaoVoid Play(AudioResource* audio);

            GaoVoid Stop(AudioResource* audio);

            GaoVoid Pause(AudioResource* audio);

            GaoVoid SetLoop(AudioResource* audio, GaoBool looping);

            GaoVoid SetVolume(AudioResource* audio, GaoReal32 volume);

            GaoVoid SetGlobalVolumes(AudioType type, GaoReal32 volume);


        private:

            /**
             * @brief Class default constructor is disallowed.
             */
            AudioEngine();


        private:

            AudioRenderer*  m_Renderer;
			GaoBool			m_AutoReleaseRenderer;
			Dictionary<GaoString, AudioResource*, TRUE>*    m_AudioPool;

        };
    }
}

#endif
