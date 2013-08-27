
namespace Gao
{
    namespace Framework
    {
        template<class T>
        T* Singleton<T>::ms_Singleton = NULL;

        template<class T>
        Singleton<T>::Singleton()
        {
            ms_Singleton = static_cast<T*>(this);
        }

        template<class T>
        Singleton<T>::~Singleton()
        {
            ms_Singleton = NULL;
        }

        template<class T>
        inline T& Singleton<T>::GetSingleton()
        {
            return *ms_Singleton;
        }

        template<class T>
        inline T* Singleton<T>::GetSingletonPointer()
        {
            return ms_Singleton;
        }
    }
}
