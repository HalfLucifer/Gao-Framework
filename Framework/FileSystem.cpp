#include "FileSystem.hpp"



namespace Gao
{
    namespace Framework
    {
        FileSystem::FileSystem()
        {

        }

        FileSystem::~FileSystem()
        {

        }

        GaoCharPtr FileSystem::MakeFullPath(GaoConstCharPtr fileName)
        {
            return NULL;
        }

        GaoVoid FileSystem::MakeFullPath(GaoString& fileName)
        {

        }
        
        GaoVoid FileSystem::MakeCombinedFullPath(GaoString& pathName, GaoString& fileName, GaoString& fullPath)
        {
            
        }

        GaoBool FileSystem::Exists() const
        {
            return FALSE;
        }

        GaoVoid FileSystem::EnumerateFolder(GaoString& folderPath, GaoString& fileExtension, EnumProc enumProc,
            GaoVoidPtr userData)
        {

        }

        GaoCharPtr FileSystem::GetUserFolder() const
        {
            return NULL;
        }

        GaoBool FileSystem::CreateUserDirectory(GaoConstCharPtr directoryName)
        {
            return FALSE;
        }

        GaoVoid FileSystem::LaunchUrl(GaoString& urlName, GaoBool maximized)
        {

        }

        GaoVoid FileSystem::LaunchFile(GaoString& fileName, GaoBool maximized)
        {

        }
    }
}
