/**
 * @file Array.hpp
 * @author Jheng Wei Ciao
 *
 * The encapsulation class of vector/array container for value type.
 *
 */
#ifndef GAO_FRAMEWORK_ARRAY_H
#define GAO_FRAMEWORK_ARRAY_H

#include "DataType.hpp"



namespace Gao
{
    namespace Framework
    {
        /**
         * @brief The encapsulation class of vector/array container for value type.
         */
        template <class TValue, bool UseAutoPtr>
        class Array
        {

        public:

            Array();

            virtual ~Array();

            inline GaoVoid Add(TValue value);

			inline TValue GetAt(GaoUInt32 position) const;

			inline GaoUInt32 GetSize() const;

            inline GaoVoid RemoveAt(TValue value);

            inline GaoVoid RemoveAll();


        private:

            inline GaoVoid RemoveAt(TValue value, Int2Type<true>);

            inline GaoVoid RemoveAt(TValue value, Int2Type<false>);

            inline GaoVoid RemoveAll(Int2Type<true>);

            inline GaoVoid RemoveAll(Int2Type<false>);


        private:

            typedef GaoVector<TValue> ArrayType;
            typedef typename GaoVector<TValue>::iterator ArrayIter;

            ArrayType       m_Array;
            ArrayIter       m_Iter;

        };
    }
}

#include "Array.inl"

#endif
