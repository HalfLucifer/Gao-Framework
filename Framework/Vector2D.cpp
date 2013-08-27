#include "Vector2D.hpp"



namespace Gao
{
    namespace Framework
    {
        Vector2D::Vector2D()
            :
            X(0.0f), Y(0.0f)
        {

        }

        Vector2D::Vector2D(GaoReal32 x, GaoReal32 y)
            :
            X(x), Y(y)
        {

        }

        Vector2D::Vector2D(const Vector2D& v)
            :
            X(v.X), Y(v.Y)
        {

        }

        Vector2D::~Vector2D()
        {

        }
    }
}
