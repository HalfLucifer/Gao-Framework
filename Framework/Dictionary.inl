
namespace Gao
{
    namespace Framework
    {
        template<class TKey, class TValue, bool UseAutoPtr>
        Dictionary<TKey, TValue, UseAutoPtr>::Dictionary()
        {
            RemoveAll();
        }

        template<class TKey, class TValue, bool UseAutoPtr>
        Dictionary<TKey, TValue, UseAutoPtr>::~Dictionary()
        {
            RemoveAll();
        }

        template<class TKey, class TValue, bool UseAutoPtr>
        inline GaoVoid Dictionary<TKey, TValue, UseAutoPtr>::SetAt(TKey key, TValue value)
        {
			m_Map.insert(DictionaryMapValueType(key, value));
        }

        template<class TKey, class TValue, bool UseAutoPtr>
        inline GaoBool Dictionary<TKey, TValue, UseAutoPtr>::GetAt(TKey key, TValue& value)
        {
            m_Iter = m_Map.find(key);

            if (m_Iter == m_Map.end())
            {
	            return FALSE;
            }

            value = m_Iter->second;
            return TRUE;
        }

        template<class TKey, class TValue, bool UseAutoPtr>
        inline GaoBool Dictionary<TKey, TValue, UseAutoPtr>::GetFirst(TValue& value)
        {
            if (m_Map.empty())
            {
	            return FALSE;
            }

            m_Iter = m_Map.begin();
            value = m_Iter->second;
            ++ m_Iter;

            return TRUE;
        }

        template<class TKey, class TValue, bool UseAutoPtr>
        inline GaoBool Dictionary<TKey, TValue, UseAutoPtr>::GetFirst(TKey& key, TValue& value)
        {
            if (m_Map.empty())
            {
	            return FALSE;
            }

            m_Iter = m_Map.begin();
            key = m_Iter->first;
            value = m_Iter->second;
            ++ m_Iter;

            return TRUE;
        }

        template<class TKey, class TValue, bool UseAutoPtr>
        inline GaoBool Dictionary<TKey, TValue, UseAutoPtr>::GetNext(TValue& value)
        {
            if (m_Iter == m_Map.end())
            {
	            return FALSE;
            }

            value = m_Iter->second;
            ++ m_Iter;

            return TRUE;
        }

        template<class TKey, class TValue, bool UseAutoPtr>
        inline GaoBool Dictionary<TKey, TValue, UseAutoPtr>::GetNext(TKey& key, TValue& value)
        {
            if (m_Iter == m_Map.end())
            {
	            return FALSE;
            }

            key = m_Iter->first;
            value = m_Iter->second;
            ++ m_Iter;

            return TRUE;
        }

        template<class TKey, class TValue, bool UseAutoPtr>
        inline GaoVoid Dictionary<TKey, TValue, UseAutoPtr>::RemoveAt(TKey key)
        {
			RemoveAt(key, Int2Type<UseAutoPtr>());
        }

        template <class TKey, class TValue, bool UseAutoPtr>
        inline GaoVoid Dictionary<TKey, TValue, UseAutoPtr>::RemoveAll()
        {
			RemoveAll(Int2Type<UseAutoPtr>());
        }
        
        template<class TKey, class TValue, bool UseAutoPtr>
        inline GaoBool Dictionary<TKey, TValue, UseAutoPtr>::IsEmpty() const
        {
            return m_Map.empty();
        }

		template <class TKey, class TValue, bool UseAutoPtr>
		inline GaoVoid Dictionary<TKey, TValue, UseAutoPtr>::RemoveAt(TKey key, Int2Type<true>)
		{
			m_Iter = m_Map.find(key);

			if (m_Iter != m_Map.end())
			{
				SAFE_DELETE(m_Iter->second);
				m_Map.erase(m_Iter);
			}
		}

		template <class TKey, class TValue, bool UseAutoPtr>
		inline GaoVoid Dictionary<TKey, TValue, UseAutoPtr>::RemoveAt(TKey key, Int2Type<false>)
		{
			m_Map.erase(key);
		}

		template <class TKey, class TValue, bool UseAutoPtr>
		inline GaoVoid Dictionary<TKey, TValue, UseAutoPtr>::RemoveAll(Int2Type<true>)
		{
			for (m_Iter = m_Map.begin(); m_Iter != m_Map.end(); m_Iter ++)
			{
				SAFE_DELETE(m_Iter->second);
			}

			m_Map.clear();
		}

		template <class TKey, class TValue, bool UseAutoPtr>
		inline GaoVoid Dictionary<TKey, TValue, UseAutoPtr>::RemoveAll(Int2Type<false>)
		{
			m_Map.clear();
		}
    }
}
