
namespace Gao
{
    namespace Framework
    {
/*    
        template<class T>
        inline T Abs<T>(T value)
        {
            return ::abs(value);
        }

        template<class T>
        inline T Sqrt<T>(T value)
        {
            return ::sqrtf(value);
        }
*/
		inline GaoReal32 ConvertRadianToDegree(GaoReal32 radian)
		{
			return radian * 180.0f / GAO_PI;
		}

		inline GaoReal32 ConvertDegreeToRadian(GaoReal32 degree)
		{
			return degree * GAO_PI / 180.0f;
		}
    }
}
