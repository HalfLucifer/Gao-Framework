#include "Window.hpp"



namespace Gao
{
    namespace Framework
    {
        static GaoString DEFAULT_TITLE = "Gao Framework App";
        static const GaoInt16 DEFAULT_WIDTH = 640;
        static const GaoInt16 DEFAULT_HEIGHT = 480;
        static const GaoInt16 DEFAULT_DEPTH = -1;
        static const GaoBool DEFAULT_FULLSCREEN = FALSE;
        static const GaoBool DEFAULT_USE_OPENGL = FALSE;



        Window::Window()
            :
            m_Width(0), m_Height(0), m_Depth(0), m_Fullscreen(FALSE), m_Paused(FALSE)
        {

        }

        Window::~Window()
        {

        }

        GaoBool Window::Create(GaoString& title, GaoInt16 width, GaoInt16 height, GaoInt16 depth,
            GaoBool fullscreen, GaoBool useOpengl)
        {
            return FALSE;
        }

		GaoBool Window::Create(GaoConstCharPtr title, GaoInt16 width, GaoInt16 height, GaoInt16 depth,
			GaoBool fullscreen, GaoBool useOpengl)
		{
			GaoString titleString(title);
			return Create(titleString, width, height, depth, fullscreen, useOpengl);
		}

		GaoBool Window::Create()
		{
			return Create(DEFAULT_TITLE, DEFAULT_WIDTH, DEFAULT_HEIGHT, DEFAULT_DEPTH,
				DEFAULT_FULLSCREEN, DEFAULT_USE_OPENGL);
		}

        GaoVoid Window::Update()
        {

        }

        GaoVoid Window::Terminate()
        {

        }

        GaoVoid Window::Minimize()
        {

        }

        GaoVoid Window::ToggleFullscreen(GaoBool fullscreen)
        {
            m_Fullscreen = fullscreen;
        }

        GaoVoid Window::TogglePause(GaoBool pause)
        {
            m_Paused = pause;
        }

        GaoBool Window::HasFocus() const
        {
            return FALSE;
        }

        GaoBool Window::IsQuit() const
        {
            return FALSE;
        }

        GaoVoid Window::SetTitle(GaoString& title)
        {

        }

		GaoVoid Window::SetTitle(GaoConstCharPtr title)
		{

		}
    }
}
