#include "Application.hpp"



namespace Gao
{
    namespace Framework
    {
        Application::Application()
        {

        }

        Application::~Application()
        {

        }

        GaoBool Application::Initialize()
        {
            return OnInitialize();
        }

        GaoVoid Application::Terminate()
        {
            OnTerminate();
        }

        GaoVoid Application::Run()
        {
            while (IsAppRunning())
            {
                OnUpdate();
                OnRender();
            }
        }

        GaoBool Application::OnInitialize()
        {
            return TRUE;
        }

        GaoVoid Application::OnTerminate()
        {

        }

        GaoVoid Application::OnUpdate()
        {

        }

        GaoVoid Application::OnRender()
        {

        }
        
        GaoVoid Application::OnPause(GaoBool onPause)
        {
            
        }

        GaoBool Application::IsAppRunning()
        {
            return TRUE;
        }
    }
}
