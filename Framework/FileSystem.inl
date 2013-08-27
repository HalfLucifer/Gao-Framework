
namespace Gao
{
    namespace Framework
    {
        inline GaoVoid FileSystem::CombinePath(GaoString& combinedPath, GaoString& pathName, GaoString& fileName)
        {
            combinedPath = pathName + FILE_PATH_SEPERATOR + fileName;
        }

        inline GaoVoid FileSystem::CombinePath(GaoString& combinedPath, GaoConstCharPtr pathName,
            GaoConstCharPtr fileName)
        {
            combinedPath = pathName;
            combinedPath += FILE_PATH_SEPERATOR;
            combinedPath += fileName;
        }

        inline GaoVoid FileSystem::GetFileExtension(GaoString& fileName, GaoString& fileExtension)
        {
            size_t pos = fileName.rfind(FILE_EXTENSION_DOT);

            if (pos != GaoString::npos)
            {
                // Get the extension substring excluding the dot GaoCharacter
                fileExtension = fileName.substr(pos + 1, fileName.size());
            }
            else
            {
                fileExtension.clear();
            }
        }
        
        inline GaoVoid FileSystem::SeperateFileNameAndExtension(GaoString& fullName, GaoString& fileName, GaoString& fileExtension)
        {
            size_t pos = fullName.rfind(FILE_EXTENSION_DOT);

            if (pos != GaoString::npos)
            {
                fileName = fullName.substr(0, pos - 1);
                fileExtension = fullName.substr(pos + 1, fullName.size());
            }
        }
    }
}