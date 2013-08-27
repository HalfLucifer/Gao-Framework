#include "AudioEngine.hpp"
#include "AudioRenderer.hpp"
#include "AudioResource.hpp"
#include "FileSystem.hpp"
#include "Logger.hpp"



namespace Gao
{
    namespace Framework
    {
        AudioEngine::AudioEngine()
        {

        }

        AudioEngine::AudioEngine(AudioRenderer* renderer)
            :
            m_Renderer(renderer), m_AutoReleaseRenderer(FALSE), m_AudioPool(NULL)
        {
            m_AudioPool = new Dictionary<GaoString, AudioResource*, TRUE>();
        }

        AudioEngine::AudioEngine(AudioRenderer* renderer, GaoBool autoReleaseRenderer)
            :
            m_Renderer(renderer), m_AutoReleaseRenderer(autoReleaseRenderer), m_AudioPool(NULL)
        {
            m_AudioPool = new Dictionary<GaoString, AudioResource*, TRUE>();
        }

        AudioEngine::~AudioEngine()
        {
            SAFE_DELETE(m_AudioPool);

			if (m_AutoReleaseRenderer)
			{
				SAFE_DELETE(m_Renderer);
			}
        }

        GaoVoid AudioEngine::SetBasePath(GaoString& normalBasePath, GaoString& streamingBasePath)
        {
            m_Renderer->SetBasePath(normalBasePath.c_str(), streamingBasePath.c_str());
        }

        GaoVoid AudioEngine::SetBasePath(GaoConstCharPtr normalBasePath, GaoConstCharPtr streamingBasePath)
        {
            m_Renderer->SetBasePath(normalBasePath, streamingBasePath);
        }

        AudioResource* AudioEngine::CreateAudio(AudioType type, GaoString& fileName, GaoBool looping)
        {
            AudioResource* audio = NULL;

            if (!m_AudioPool->GetAt(fileName, audio))
            {
                audio = m_Renderer->CreateAudio(type, fileName, looping);

                if (audio != NULL)
                {
                    m_AudioPool->SetAt(fileName, audio);
                }
                else
                {
                    g_Logger->Log(GAO_AUDIO, "Failed to create audio: %s", fileName.c_str());
                }
            }

            return audio;
        }

        AudioResource* AudioEngine::CreateAudio(AudioType type, GaoConstCharPtr fileName, GaoBool looping)
        {
            GaoString fileNameString(fileName);
            return CreateAudio(type, fileNameString, looping);
        }

		AudioResource* AudioEngine::CreateAudio(GaoConstCharPtr fileName)
		{
			GaoString fileNameString(fileName);
			return CreateAudio(Audio_Normal, fileNameString, FALSE);
		}
        
		AudioResource* AudioEngine::CreateStreamingAudio(GaoConstCharPtr fileName, GaoBool looping)
		{
			GaoString fileNameString(fileName);
			return CreateAudio(Audio_Streaming, fileNameString, looping);
		}

        GaoBool AudioEngine::DestroyAudio(GaoConstCharPtr fileName)
        {
            AudioResource* audio = NULL;

            if (m_AudioPool->GetAt(fileName, audio))
            {
                m_AudioPool->RemoveAt(fileName);
                return TRUE;
            }

            return FALSE;
        }

        GaoVoid AudioEngine::PlayAudio(AudioType type, GaoString& fileName)
        {
            Play(CreateAudio(type, fileName, FALSE));
        }

        GaoVoid AudioEngine::PlayAudio(AudioType type, GaoConstCharPtr fileName)
        {
            GaoString fileNameString(fileName);
            PlayAudio(type, fileNameString);
        }

		GaoVoid AudioEngine::PlayAudio(GaoConstCharPtr fileName)
		{
			GaoString fileNameString(fileName);
			PlayAudio(Audio_Normal, fileNameString);
		}

        GaoVoid AudioEngine::Play(AudioResource* audio)
        {
            if (audio != NULL)
            {
                m_Renderer->Play(audio);
            }
        }

        GaoVoid AudioEngine::Stop(AudioResource* audio)
        {
            if (audio != NULL)
            {
                m_Renderer->Stop(audio);
            }
        }
        
        GaoVoid AudioEngine::Pause(AudioResource* audio)
        {
            if (audio != NULL)
            {
                m_Renderer->Pause(audio);
            }
        }
        
        GaoVoid AudioEngine::SetLoop(AudioResource* audio, GaoBool looping)
        {
            if (audio != NULL)
            {
                m_Renderer->SetLoop(audio, looping);
            }        
        }

        GaoVoid AudioEngine::SetVolume(AudioResource* audio, GaoReal32 volume)
        {
			assert(volume >= 0.0f);

            if (audio != NULL)
            {
                m_Renderer->SetVolume(audio, volume);
            }
        }

        GaoVoid AudioEngine::SetGlobalVolumes(AudioType type, GaoReal32 volume)
        {
			assert(volume >= 0.0f);

            m_Renderer->SetGlobalVolumes(type, volume);
        }
    }
}
