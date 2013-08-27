/**
 * @file Dictionary.hpp
 * @author Jheng Wei Ciao
 *
 * The encapsulation class of map container for value type.
 *
 */
#ifndef GAO_FRAMEWORK_DICTIONARY_H
#define GAO_FRAMEWORK_DICTIONARY_H

#include "DataType.hpp"



namespace Gao
{
    namespace Framework
    {
        /**
         * @brief The encapsulation class of map container for value type.
         */
        template <class TKey, class TValue, bool UseAutoPtr>
        class Dictionary
        {

        public:

            Dictionary();

            virtual ~Dictionary();

            inline GaoVoid SetAt(TKey key, TValue value);

            inline GaoBool GetAt(TKey key, TValue& value);

            inline GaoBool GetFirst(TValue& value);

            inline GaoBool GetFirst(TKey& key, TValue& value);

            inline GaoBool GetNext(TValue& value);

            inline GaoBool GetNext(TKey& key, TValue& value);

            inline GaoVoid RemoveAt(TKey key);

            inline GaoVoid RemoveAll();
            
            inline GaoBool IsEmpty() const;


		private:

			inline GaoVoid RemoveAt(TKey key, Int2Type<true>);

			inline GaoVoid RemoveAt(TKey key, Int2Type<false>);

			inline GaoVoid RemoveAll(Int2Type<true>);

			inline GaoVoid RemoveAll(Int2Type<false>);


        private:

            typedef GaoMap<TKey, TValue> DictionaryMap;
            typedef typename GaoMap<TKey, TValue>::iterator DictionaryMapIter;
			typedef typename GaoMap<TKey, TValue>::value_type DictionaryMapValueType;

            DictionaryMap       m_Map;
            DictionaryMapIter   m_Iter;

        };
    }
}

#include "Dictionary.inl"

#endif
