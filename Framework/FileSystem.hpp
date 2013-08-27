/**
 * @file FileSystem.hpp
 * @author Jheng Wei Ciao
 *
 * Interface for I/O(file accessing) usage.
 *
 */
#ifndef GAO_FRAMEWORK_FILESYSTEM_H
#define GAO_FRAMEWORK_FILESYSTEM_H

#include "DataType.hpp"
#include "Singleton.hpp"

#define g_FileSystem Gao::Framework::FileSystem::GetSingletonPointer()



namespace Gao
{
    namespace Framework
    {
        static GaoString FILE_EXTENSION_DOT = ".";
        static GaoString FILE_STAR_SIGN = "*";
        static GaoString FILE_PATH_SEPERATOR = "/";
        static GaoString FILE_EMPTY_STRING = "";

        typedef GaoBool (*EnumProc) (GaoCharPtr fileName, GaoBool _bIsFolder, GaoVoidPtr userData);



        /**
         * @brief Interface class for I/O usage.
         */
        class FileSystem : public Singleton<FileSystem>
        {

        public:

            /**
             * @brief Class default constructor.
             */
            FileSystem();

            /**
             * @brief Class destructor.
             */
            virtual ~FileSystem();

            /**
             * @brief Retrieve full path for specified file name.
             *
             * @param[in] fileName The file name.
             * @return The full path.
             */
            virtual GaoCharPtr MakeFullPath(GaoConstCharPtr fileName);

            virtual GaoVoid MakeFullPath(GaoString& fileName);

            virtual GaoVoid MakeCombinedFullPath(GaoString& pathName, GaoString& fileName, GaoString& fullPath);

            // TODO: file open, close, read, write

            // TODO: is file exist
            virtual GaoBool Exists() const;

            /**
             * @brief Enumerate files and folders in specified path.
             *
             * @param[in] folderPath The path for enumerating process.
             * @param[in] fileExtension The file extension to enumerate. Use '*' for all files.
             * @param[in] enumProc The callback function for customized handling.
             * @param[in] userData The user data passed to callback function.
             */
            virtual GaoVoid EnumerateFolder(GaoString& folderPath, GaoString& fileExtension,
                EnumProc enumProc, GaoVoidPtr userData);

            virtual GaoCharPtr GetUserFolder() const;

            virtual GaoBool CreateUserDirectory(GaoConstCharPtr directoryName);

            virtual GaoVoid LaunchUrl(GaoString& urlName, GaoBool maximized);

            virtual GaoVoid LaunchFile(GaoString& fileName, GaoBool maximized);

            /**
             * @brief Combine path name and file name with correct seperator ('/' or '\\')
             *
             * @param[in] combinedPath The combined path.
             * @param[in] pathName The path name not including seperator GaoCharacter.
             * @param[in] fileName The file name not including seperator GaoCharacter.
             */
            inline GaoVoid CombinePath(GaoString& combinedPath, GaoString& pathName, GaoString& fileName);

            inline GaoVoid CombinePath(GaoString& combinedPath, GaoConstCharPtr pathName, GaoConstCharPtr fileName);

            inline GaoVoid GetFileExtension(GaoString& fileName, GaoString& fileExtension);
            
            inline GaoVoid SeperateFileNameAndExtension(GaoString& fullName, GaoString& fileName, GaoString& fileExtension);

            // TODO: ZIP archieve

        };
    }
}

#include "FileSystem.inl"

#endif
