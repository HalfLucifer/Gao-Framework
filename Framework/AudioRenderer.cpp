#include "AudioRenderer.hpp"



namespace Gao
{
    namespace Framework
    {
        AudioRenderer::AudioRenderer()
        {

        }

        AudioRenderer::~AudioRenderer()
        {

        }

        GaoVoid AudioRenderer::SetBasePath(GaoConstCharPtr normalBasePath, GaoConstCharPtr streamingBasePath)
        {
            m_NormalBasePath = normalBasePath;
            m_StreamingBasePath = streamingBasePath;
        }
        
        AudioResource* AudioRenderer::CreateAudio(AudioType type, GaoString& fileName, GaoBool looping)
        {
            return NULL;
        }

        GaoVoid AudioRenderer::Play(AudioResource* audio)
        {

        }

        GaoVoid AudioRenderer::Stop(AudioResource* audio)
        {

        }
        
        GaoVoid AudioRenderer::Pause(AudioResource* audio)
        {

        }
        
        GaoVoid AudioRenderer::SetLoop(AudioResource* audio, GaoBool looping)
        {

        }
        
        GaoVoid AudioRenderer::SetVolume(AudioResource* audio, GaoReal32 volume)
        {

        }

        GaoVoid AudioRenderer::SetGlobalVolumes(AudioType type, GaoReal32 volume)
        {

        }
    }
}
