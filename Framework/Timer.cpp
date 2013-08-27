#include "Timer.hpp"



namespace Gao
{
    namespace Framework
    {
        Timer::Timer()
            :
            m_CurrentTime(0), m_LastTime(0), m_DeltaTime(0), m_LastFpsUpdateTime(0), m_DeltaFpsUpdateTime(0),
            m_FpsFrames(0), m_Fps(0)
        {

        }

        Timer::~Timer()
        {

        }

        GaoVoid Timer::Start()
        {

        }

        GaoVoid Timer::Pause()
        {

        }

        GaoVoid Timer::Resume()
        {

        }

        GaoVoid Timer::Update()
        {
            m_CurrentTime = GetElapsedTime();
            m_DeltaTime = m_CurrentTime - m_LastTime;
            m_LastTime = m_CurrentTime;
        }

        GaoVoid Timer::UpdateFpsCounter()
        {
            m_FpsFrames++;
            m_DeltaFpsUpdateTime = m_CurrentTime - m_LastFpsUpdateTime;

            if (m_DeltaFpsUpdateTime >= ms_FpsRefreshTime)
            {
                m_Fps = static_cast<GaoUInt32>(m_FpsFrames * ms_FpsRefreshTime / static_cast<GaoReal32>(m_DeltaFpsUpdateTime));
                m_FpsFrames = 0;
                m_LastFpsUpdateTime = m_CurrentTime;
            }
        }

        GaoUInt32 Timer::GetFps() const
        {
            return m_Fps;
        }

        GaoUInt32 Timer::GetElapsedTime() const
        {
            return 0;
        }
    }
}
