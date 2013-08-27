/**
 * @file Singleton.hpp
 * @author Jheng Wei Ciao
 *
 * Templated singleton class for inheritant.
 *
 */
#ifndef GAO_FRAMEWORK_SINGLETON_H
#define GAO_FRAMEWORK_SINGLETON_H



namespace Gao
{
    namespace Framework
    {
        template<class T>
        class Singleton
        {

        public:

            Singleton();

            virtual ~Singleton();

            static inline T& GetSingleton();

            static inline T* GetSingletonPointer();


        private:

            static T* ms_Singleton;

        };
    }
}

#include "Singleton.inl"

#endif
