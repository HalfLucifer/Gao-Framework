/**
 * @file Timer.hpp
 * @author Jheng Wei Ciao
 *
 * Interface for timer usage.
 *
 */
#ifndef GAO_FRAMEWORK_TIMER_H
#define GAO_FRAMEWORK_TIMER_H

#include "DataType.hpp"
#include "Singleton.hpp"

#define g_Timer Gao::Framework::Timer::GetSingletonPointer()



namespace Gao
{
    namespace Framework
    {
        class Timer : public Singleton<Timer>
        {

        public:

            Timer();

            virtual ~Timer();

            virtual GaoVoid Start();

            virtual GaoVoid Pause();

            virtual GaoVoid Resume();

            virtual GaoVoid Update();

            virtual GaoVoid UpdateFpsCounter();

            virtual GaoUInt32 GetFps() const;

            virtual GaoUInt32 GetElapsedTime() const;

            inline GaoUInt32 GetDeltaTime() const;

            inline GaoReal32 GetDeltaInSecond() const;

            // TODO: timer start, pause, resume


        protected:

            GaoUInt32      m_CurrentTime;
			GaoUInt32      m_LastTime;
            GaoUInt32      m_DeltaTime;
            GaoUInt32      m_LastFpsUpdateTime;
            GaoUInt32      m_DeltaFpsUpdateTime;
            GaoUInt32      m_FpsFrames;
            GaoUInt32      m_Fps;

            static const GaoUInt32 ms_FpsRefreshTime = 1000;

        };
    }
}

#include "Timer.inl"

#endif
