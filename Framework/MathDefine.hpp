/**
 * @file BaseMath.hpp
 * @author Jheng Wei Ciao
 *
 * Interface for math usage.
 *
 */
#ifndef GAO_FRAMEWORK_MATH_H
#define GAO_FRAMEWORK_MATH_H

#include "DataType.hpp"
#include <stdlib.h>
#include <math.h>



namespace Gao
{
    namespace Framework
    {
		static const GaoReal32 GAO_PI = 3.1415927410125732f;
		static const GaoReal32 GAO_HALF_PI = 0.5f * GAO_PI;
		static const GaoReal32 GAO_TWO_PI = 2.0f * GAO_PI;



//        template<class T> inline T Abs(T value);

//        template<class T> inline T Sqrt(T value);

        template<class T> inline T Abs(T value)
        {
            return ::abs(value);
        }

        template<class T> inline T Sqrt(T value)
        {
            return ::sqrtf(value);
        }

		inline GaoReal32 ConvertRadianToDegree(GaoReal32 radian);

		inline GaoReal32 ConvertDegreeToRadian(GaoReal32 degree);
    }
}

#include "MathDefine.inl"

#endif
