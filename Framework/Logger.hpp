/**
 * @file Logger.hpp
 * @author Jheng Wei Ciao
 *
 * Interface for debug usage.
 *
 */
#ifndef GAO_FRAMEWORK_Logger_H
#define GAO_FRAMEWORK_Logger_H

#include "DataType.hpp"
#include "Singleton.hpp"

#define g_Logger Gao::Framework::Logger::GetSingletonPointer()



namespace Gao
{
    namespace Framework
    {
        class Logger : public Singleton<Logger>
        {

        public:

            Logger();

            virtual ~Logger();

			GaoBool Create();

            GaoBool Create(GaoString& fileName);

            GaoBool Create(GaoConstCharPtr fileName);

            GaoVoid Write(GaoConstCharPtr text);

            GaoVoid Write(GaoConstCharPtr category, GaoConstCharPtr format, ...);

			virtual GaoVoid Show(GaoConstCharPtr text);

			GaoVoid Show(GaoConstCharPtr category, GaoConstCharPtr format, ...);

			GaoVoid Log(GaoConstCharPtr text);

			GaoVoid Log(GaoConstCharPtr category, GaoConstCharPtr format, ...);


		protected:

			GaoVoid WriteBufferToFile();


		protected:

			GaoString      m_FileName;
			GaoChar        m_Buffer[MAX_BUFFER_SIZE];
			GaoChar        m_VarListBuffer[MAX_BUFFER_SIZE];

        };
    }
}

#endif
