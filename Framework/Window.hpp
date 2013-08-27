/**
* @file Window.hpp
* @author Jheng Wei Ciao
*
* Interface for window usage.
*
*/
#ifndef GAO_FRAMEWORK_WINDOW_H
#define GAO_FRAMEWORK_WINDOW_H

#include "DataType.hpp"



namespace Gao
{
    namespace Framework
    {
        /**
         * @brief Interface class for window-related usage.
         */
        class Window
        {

		public:

            /**
             * @brief Application platform
             */
            enum AppPlatform
            {
				AppPlatform_Win,
				AppPlatform_Mac,
				AppPlatform_Iphone,
            };

            /**
             * @brief Application configurations
             */
            enum AppConfig
            {
				AppConfig_Debug,
				AppConfig_Release,
            };


        public:

            /**
             * @brief Class default constructor.
             */
            Window();

            /**
             * @brief Class destructor.
             */
            virtual ~Window();

            /**
             * @brief The creation procedure for creating window.
             * @param title The title of window.
             * @param width Window width.
             * @param _iHeght Window height.
             * @param depth Window height.
             * @param fullscreen Determine if created on windowed or fullscreen mode.
             * @param useOpengl Determine if created using OpenGL mode.
             */
            virtual GaoBool Create(GaoString& title, GaoInt16 width, GaoInt16 height, GaoInt16 depth,
                GaoBool fullscreen, GaoBool useOpengl);

			GaoBool Create(GaoConstCharPtr title, GaoInt16 width, GaoInt16 height, GaoInt16 depth,
				GaoBool fullscreen, GaoBool useOpengl);

			GaoBool Create();

            /**
             * @brief The update procedure for processing events.
             */
            virtual GaoVoid Update();

            /**
             * @brief Terminate the window.
             */
            virtual GaoVoid Terminate();

            /**
             * @brief Minimize the window to task bar.
             */
            virtual GaoVoid Minimize();

            /**
             * @brief Change the display mode of window.
             * @param fullscreen True for fullscreen; false for windowed.
             */
            virtual GaoVoid ToggleFullscreen(GaoBool fullscreen);

            /**
             * @brief Pause the process of window.
             * @param pause True for pause; false for resume.
             */
            virtual GaoVoid TogglePause(GaoBool pause);

            /**
             * @brief Determine if window has focus.
             * @return True for focused.
             */
            virtual GaoBool HasFocus() const;

            /**
             * @brief Determine if window received quit message.
             */
            virtual GaoBool IsQuit() const;

            /**
             * @brief Set the window title.
             */
            virtual GaoVoid SetTitle(GaoString& title);

			virtual GaoVoid SetTitle(GaoConstCharPtr title);

            /**
             * @brief Get the window title.
             */
            inline GaoString& GetTitle();

            /**
             * @brief Get the window width.
             */
            inline GaoInt16 GetWidth() const;

            /**
             * @brief Get the window height.
             */
            inline GaoInt16 GetHeight() const;

            /**
             * @brief Get the window height.
             */
            inline GaoInt16 GetDepth() const;

            /**
             * @brief Determine if window is on fullscreen mode.
             */
            inline GaoBool IsFullscreen() const;

            /**
             * @brief Determine if window is paused.
             */
            inline GaoBool IsPaused() const;

			inline GaoInt32 GetAppPlatform() const;
            
			inline	GaoInt32 GetAppConfig() const;


        protected:

            GaoString      m_Title;
            GaoInt16       m_Width;
            GaoInt16       m_Height;
            GaoInt16       m_Depth;
            GaoBool        m_Fullscreen;
            GaoBool        m_Paused;

        };
    }
}

#include "Window.inl"

#endif
