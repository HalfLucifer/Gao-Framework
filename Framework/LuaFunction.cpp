#include "LuaFunction.hpp"
#include "AudioEngine.hpp"
#include "AudioRenderer.hpp"
#include "AudioResource.hpp"
#include "Window.hpp"
#include "Logger.hpp"
#include "FileSystem.hpp"
#include "InputSystem.hpp"
#include "Timer.hpp"



namespace Gao
{
    namespace Framework
    {

#ifdef GAO_SCRIPT_LUA_IMPLEMENTATION
        
        GaoBool RegisterLuaFunctions(LuaState state)
        {
            RegisterLuaCoreFunctions(state);
            RegisterLuaGraphicsFunctions(state);
            
            return TRUE;
        }

        GaoBool RegisterLuaCoreFunctions(LuaState state)
		{

#ifdef GAO_SCRIPT_LUABIND_IMPLEMENTATION

			using namespace luabind;

			//
			// Logger
			//
			module(state)
			[
				class_<Logger>("Logger")
					.def(constructor<>())
                    .def("Create", (GaoBool(Logger::*)())&Logger::Create)
                    .def("Create", (GaoBool(Logger::*)(GaoConstCharPtr))&Logger::Create)
					.def("Write", (GaoVoid(Logger::*)(GaoConstCharPtr))&Logger::Write)
					.def("Show", (GaoVoid(Logger::*)(GaoConstCharPtr))&Logger::Show)
					.def("Log", (GaoVoid(Logger::*)(GaoConstCharPtr))&Logger::Log)
			];

			//
			// FileSystem
			//
			module(state)
			[
				class_<FileSystem>("FileSystem")
					.def(constructor<>())
			];

			//
			// Timer
			//
			module(state)
			[
				class_<Timer>("Timer")
					.def(constructor<>())
                    .def("Update", &Timer::Update)
                    .def("UpdateFpsCounter", &Timer::UpdateFpsCounter)
                    .def("GetFps", &Timer::GetFps)
                    .def("GetElapsedTime", &Timer::GetElapsedTime)
                    .def("GetDeltaTime", &Timer::GetDeltaTime)
                    .def("GetDeltaInSecond", &Timer::GetDeltaInSecond)
			];

            //
            // Window
            //
			module(state)
			[
				class_<Window>("Window")
					.enum_("AppPlatform")
					[
						value("PLATFORM_WIN", Window::AppPlatform_Win),
						value("PLATFORM_MAC", Window::AppPlatform_Mac),
						value("PLATFORM_IPHONE", Window::AppPlatform_Iphone)
					]

					.enum_("AppConfig")
					[
						value("CONFIG_DEBUG", Window::AppConfig_Debug),
						value("CONFIG_RELEASE", Window::AppConfig_Release)
					]

					.def(constructor<>())
					.def("Create", (GaoBool(Window::*)())&Window::Create)
					.def("Create", (GaoBool(Window::*)(GaoConstCharPtr, GaoInt16, GaoInt16, GaoInt16, GaoBool, GaoBool))&Window::Create)
					.def("SetTitle", (GaoVoid(Window::*)(GaoConstCharPtr))&Window::SetTitle)
                    .def("Update", &Window::Update)
                    .def("ToggleFullscreen", &Window::ToggleFullscreen)
					.def("HasFocus", &Window::HasFocus)
					.def("IsQuit", &Window::IsQuit)
					.def("GetAppPlatform", &Window::GetAppPlatform)
					.def("GetAppConfig", &Window::GetAppConfig)
			];

			//
			// AudioEngine
			//
			module(state)
			[
				class_<AudioEngine>("AudioEngine")
					.enum_("AudioType")
					[
						value("AUDIO_NORMAL", Audio_Normal),
						value("AUDIO_STREAMING", Audio_Streaming)
					]

					.def(constructor<AudioRenderer*>())
                    .def("SetBasePath", (GaoVoid(AudioEngine::*)(GaoConstCharPtr, GaoConstCharPtr))&AudioEngine::SetBasePath)
					.def("CreateAudio", (AudioResource*(AudioEngine::*)(GaoConstCharPtr))&AudioEngine::CreateAudio)
					.def("CreateAudio", (AudioResource*(AudioEngine::*)(AudioType, GaoConstCharPtr, GaoBool))&AudioEngine::CreateAudio)
                    .def("CreateStreamingAudio", &AudioEngine::CreateStreamingAudio)
                    .def("DestroyAudio", &AudioEngine::DestroyAudio)
					.def("PlayAudio", (GaoVoid(AudioEngine::*)(GaoConstCharPtr))&AudioEngine::PlayAudio)
					.def("PlayAudio", (GaoVoid(AudioEngine::*)(AudioType, GaoConstCharPtr))&AudioEngine::PlayAudio)
					.def("Play", &AudioEngine::Play)
					.def("Stop", &AudioEngine::Stop)
                    .def("Pause", &AudioEngine::Pause)
					.def("SetLoop", &AudioEngine::SetLoop)
					.def("SetVolume", &AudioEngine::SetVolume)
					.def("SetGlobalVolumes", &AudioEngine::SetGlobalVolumes)
			];

            //
            // AudioRenderer
            //
			module(state)
			[
				class_<AudioRenderer>("AudioRenderer")
					.def(constructor<>())
			];

            //
            // AudioResource
            //
			module(state)
			[
				class_<AudioResource>("AudioResource")
					.def(constructor<>())
					.def("Play", &AudioResource::Play)
					.def("Stop", &AudioResource::Stop)
					.def("SetVolume", &AudioResource::SetVolume)
					.def("IsPlaying", &AudioResource::IsPlaying)
			];

#endif // End of GAO_SCRIPT_LUABIND_IMPLEMENTATION

            return TRUE;
        }

#endif // End of GAO_SCRIPT_LUA_IMPLEMENTATION

    }
}
