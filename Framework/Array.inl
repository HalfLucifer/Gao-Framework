
namespace Gao
{
    namespace Framework
    {
        template<class TValue, bool UseAutoPtr>
        Array<TValue, UseAutoPtr>::Array()
        {
            RemoveAll();
        }

        template<class TValue, bool UseAutoPtr>
        Array<TValue, UseAutoPtr>::~Array()
        {
            RemoveAll();
        }

        template <class TValue, bool UseAutoPtr>
        inline GaoVoid Array<TValue, UseAutoPtr>::Add(TValue value)
        {
            m_Array.push_back(value);
        }

        template <class TValue, bool UseAutoPtr>
        inline GaoVoid Array<TValue, UseAutoPtr>::RemoveAt(TValue value)
        {
            RemoveAt(value, Int2Type<UseAutoPtr>());
        }

        template <class TValue, bool UseAutoPtr>
        inline GaoVoid Array<TValue, UseAutoPtr>::RemoveAll()
        {
            RemoveAll(Int2Type<UseAutoPtr>());
        }

        template <class TValue, bool UseAutoPtr>
        inline GaoVoid Array<TValue, UseAutoPtr>::RemoveAt(TValue value, Int2Type<true>)
        {
            for (m_Iter = m_Array.begin(); m_Iter != m_Array.end(); m_Iter ++)
            {
                if ((*m_Iter) == value)
                {
                    SAFE_DELETE(*m_Iter);
                    m_Array.erase(m_Iter);

                    return;
                }
            }
        }

        template <class TValue, bool UseAutoPtr>
        inline GaoVoid Array<TValue, UseAutoPtr>::RemoveAt(TValue value, Int2Type<false>)
        {
            for (m_Iter = m_Array.begin(); m_Iter != m_Array.end(); m_Iter ++)
            {
                if ((*m_Iter) == value)
                {
                    m_Array.erase(m_Iter);
                    return;
                }
            }
        }

        template <class TValue, bool UseAutoPtr>
        inline GaoVoid Array<TValue, UseAutoPtr>::RemoveAll(Int2Type<true>)
        {
            for (m_Iter = m_Array.begin(); m_Iter != m_Array.end(); m_Iter ++)
            {
                SAFE_DELETE(*m_Iter);
            }

            m_Array.clear();
        }

        template <class TValue, bool UseAutoPtr>
        inline GaoVoid Array<TValue, UseAutoPtr>::RemoveAll(Int2Type<false>)
        {
            m_Array.clear();
        }

        template <class TValue, bool UseAutoPtr>
        inline TValue Array<TValue, UseAutoPtr>::GetAt(GaoUInt32 position) const
        {
			assert(position < m_Array.size());

            return m_Array[position];
        }

        template <class TValue, bool UseAutoPtr>
        inline GaoUInt32 Array<TValue, UseAutoPtr>::GetSize() const
        {
            return static_cast<GaoUInt32>(m_Array.size());
        }
    }
}
