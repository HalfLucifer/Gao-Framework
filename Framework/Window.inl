
namespace Gao
{
    namespace Framework
    {
        inline GaoString& Window::GetTitle()
        {
            return m_Title;
        }

        inline GaoInt16 Window::GetWidth() const
        {
            return m_Width;
        }

        inline GaoInt16 Window::GetHeight() const
        {
            return m_Height;
        }

        inline GaoInt16 Window::GetDepth() const
        {
            return m_Depth;
        }

        inline GaoBool Window::IsFullscreen() const
        {
            return m_Fullscreen;
        }

        inline GaoBool Window::IsPaused() const
        {
            return m_Paused;
        }

		inline GaoInt32 Window::GetAppPlatform() const
		{
#ifdef GAO_PLATFORM_WINTEL32
			return AppPlatform_Win;
#else
	#ifdef GAO_PLATFORM_IPHONE
			return AppPlatform_Iphone;
	#else
			return AppPlatform_Mac;
	#endif
#endif
		}

		inline	GaoInt32 Window::GetAppConfig() const
		{
#ifdef GAO_DEBUG
			return AppConfig_Debug;
#else
			return AppConfig_Release;
#endif
		}
    }
}
