#include "Logger.hpp"
#include "FileSystem.hpp"
#include <stdarg.h>



namespace Gao
{
    namespace Framework
    {
		static GaoString DEFAULT_LOG_FILE_NAME = "log.txt";

        Logger::Logger()
        {

		}

        Logger::~Logger()
        {

        }

		GaoBool Logger::Create()
		{
			return Create(DEFAULT_LOG_FILE_NAME);
		}

        GaoBool Logger::Create(GaoString& fileName)
        {
			m_FileName = fileName;

			if (g_FileSystem != NULL)
			{
				g_FileSystem->MakeFullPath(m_FileName);
			}

			// Overwrite the original file
			FILE* file = fopen(m_FileName.c_str(), "wt");

			if (file != NULL)
			{
				fclose(file);
				return TRUE;
			}

			return FALSE;
        }

        GaoBool Logger::Create(GaoConstCharPtr fileName)
        {
            GaoString fileNameString(fileName);
            return Create(fileNameString);
        }

        GaoVoid Logger::Write(GaoConstCharPtr text)
        {
			sprintf(m_Buffer, "%s\n", text);
			WriteBufferToFile();
        }

        GaoVoid Logger::Write(GaoConstCharPtr category, GaoConstCharPtr format, ...)
        {
			va_list args;
			va_start(args, format);
			vsprintf(m_VarListBuffer, format, args);
			va_end(args);

			sprintf(m_Buffer, "[%s] %s\n", category, m_VarListBuffer);
			WriteBufferToFile();
        }

		GaoVoid Logger::Show(GaoConstCharPtr text)
		{

		}

		GaoVoid Logger::Show(GaoConstCharPtr category, GaoConstCharPtr format, ...)
		{
			va_list args;
			va_start(args, format);
			vsprintf(m_VarListBuffer, format, args);
			va_end(args);

			sprintf(m_Buffer, "[%s] %s\n", category, m_VarListBuffer);
			Show(m_Buffer);
		}

		GaoVoid Logger::Log(GaoConstCharPtr text)
		{
			Write(text);
			Show(text);
		}

		GaoVoid Logger::Log(GaoConstCharPtr category, GaoConstCharPtr format, ...)
		{
			va_list args;
			va_start(args, format);
			vsprintf(m_VarListBuffer, format, args);
			va_end(args);

			sprintf(m_Buffer, "[%s] %s\n", category, m_VarListBuffer);
			WriteBufferToFile();
			Show(m_Buffer);
		}

		GaoVoid Logger::WriteBufferToFile()
		{
			FILE* file = fopen(m_FileName.c_str(), "a+");

			if (file != NULL)
			{
				fseek(file, 0, SEEK_END);
				fprintf(file, "%s", m_Buffer);
				fclose(file);
			}
		}
    }
}
