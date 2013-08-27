/**
 * @file Application.hpp
 * @author Jheng Wei Ciao
 *
 * Interface for application usage.
 *
 */
#ifndef GAO_FRAMEWORK_APPLICATION_H
#define GAO_FRAMEWORK_APPLICATION_H

#include "DataType.hpp"
#include "Singleton.hpp"

#define g_Application Gao::Framework::Application::GetSingletonPointer()



namespace Gao
{
    namespace Framework
    {
        /**
         * @brief Interface class for application usage.
         *
         * Each project should derived from the class, and override functions.
         *
         */
        class Application : public Singleton<Application>
        {

        public:

            /**
             * @brief Class default constructor.
             */
            Application();

            /**
             * @brief Class destructor.
             */
            virtual ~Application();

            /**
             * @brief Application's initialization procedure.
             *
             * Do initialization procedure and call OnInitialize() right before Run() starts.
             *
             */
            GaoBool Initialize();

            /**
             * @brief Application's cleanup procedure.
             *
             * Do cleanup procedure and call OnTerminate() right after Run() exists.
             *
             */
            GaoVoid Terminate();

            /**
             * @brief Application's main loop procedure.
             *
             * Do loop while application's on running state. Call OnUpdate() and OnRender() in order.
             *
             */
            GaoVoid Run();


        protected:

            /**
             * @brief Overriden in subclass for custom initialization process.
             */
            virtual GaoBool OnInitialize();

            /**
             * @brief Overriden in subclass for custom cleanup process.
             */
            virtual GaoVoid OnTerminate();

            /**
             * @brief Overriden in subclass for custom update process.
             */
            virtual GaoVoid OnUpdate();

            /**
             * @brief Overriden in subclass for custom render process.
             */
            virtual GaoVoid OnRender();
            
            /**
             * @brief Overriden in subclass for custom render process.
             */
            virtual GaoVoid OnPause(GaoBool onPause);

            /**
             * @brief Overriden in subclass for custom application lifetime condition.
             *
             * @retval TRUE continues the main loop.
             * @retval FALSE terminates the main loop.
             */
            virtual GaoBool IsAppRunning();

        };
    }
}

#endif
