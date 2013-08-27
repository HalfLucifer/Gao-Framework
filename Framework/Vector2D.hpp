/**
 * @file Vector2D.hpp
 * @author Jheng Wei Ciao
 *
 * 2D vector class.
 *
 */
#ifndef GAO_FRAMEWORK_VECTOR2D_H
#define GAO_FRAMEWORK_VECTOR2D_H

#include "DataType.hpp"
#include "MathDefine.hpp"



namespace Gao
{
    namespace Framework
    {
        class Vector2D
        {

        public:

            Vector2D();

            Vector2D(GaoReal32 x, GaoReal32 y);

            Vector2D(const Vector2D& v);

            ~Vector2D();

            inline Vector2D operator = (const Vector2D& v);

            inline Vector2D operator + (const Vector2D& v);

            inline Vector2D operator - (const Vector2D& v);

            inline Vector2D operator * (const Vector2D& v);

            inline Vector2D operator * (GaoReal32 value);

            inline Vector2D operator / (const Vector2D& v);

            inline Vector2D operator / (GaoReal32 value);

            inline Vector2D& operator += (const Vector2D& v);

            inline Vector2D& operator -= (const Vector2D& v);

            inline Vector2D& operator *= (const Vector2D& v);

            inline Vector2D& operator *= (GaoReal32 value);

            inline Vector2D& operator /= (const Vector2D& v);

            inline Vector2D& operator /= (GaoReal32 value);

            inline GaoVoid Set(GaoReal32 x, GaoReal32 y);

            inline GaoVoid Normalize();

            inline GaoReal32 Length() const;

            inline GaoReal32 SqrLength() const;

            inline GaoReal32 DotProduct(const Vector2D& v) const;


        public:

            GaoReal32 X;
            GaoReal32 Y;

        };
    }
}

#include "Vector2D.inl"

#endif
