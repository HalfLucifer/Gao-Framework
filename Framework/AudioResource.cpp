#include "AudioResource.hpp"



namespace Gao
{
    namespace Framework
    {
        AudioResource::AudioResource()
            :
            m_Type(Audio_Normal)
        {

        }

        AudioResource::~AudioResource()
        {

        }

        GaoBool AudioResource::Create(AudioType type, GaoString& fileName, GaoBool loop)
        {
            return FALSE;
        }

        GaoVoid AudioResource::Play()
        {

        }

        GaoVoid AudioResource::Stop()
        {

        }
        
        GaoVoid AudioResource::Pause()
        {
            
        }
        
        GaoVoid AudioResource::SetLoop(GaoBool looping)
        {

        }

        GaoVoid AudioResource::SetVolume(GaoReal32 volume)
        {

        }

		GaoBool AudioResource::IsPlaying() const
		{
			return FALSE;
		}
    }
}
