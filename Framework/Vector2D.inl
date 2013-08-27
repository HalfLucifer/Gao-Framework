
namespace Gao
{
    namespace Framework
    {
        inline Vector2D Vector2D::operator = (const Vector2D& v)
        {
            X = v.X;
            Y = v.Y;
            return (*this);
        }

        inline Vector2D Vector2D::operator + (const Vector2D& v)
        {
            return Vector2D(X + v.X, Y + v.Y);
        }

        inline Vector2D Vector2D::operator - (const Vector2D& v)
        {
            return Vector2D(X - v.X, Y - v.Y);
        }

        inline Vector2D Vector2D::operator * (const Vector2D& v)
        {
            return Vector2D(X * v.X, Y * v.Y);
        }

        inline Vector2D Vector2D::operator * (GaoReal32 value)
        {
            return Vector2D(X * value, Y * value);
        }

        inline Vector2D Vector2D::operator / (const Vector2D& v)
        {
            return Vector2D(X / v.X, Y / v.Y);
        }

        inline Vector2D Vector2D::operator / (GaoReal32 value)
        {
            return Vector2D(X / value, Y / value);
        }

        inline Vector2D& Vector2D::operator += (const Vector2D& v)
        {
            X += v.X;
            Y += v.Y;
            return (*this);
        }

        inline Vector2D& Vector2D::operator -= (const Vector2D& v)
        {
            X -= v.X;
            Y -= v.Y;
            return (*this);
        }

        inline Vector2D& Vector2D::operator *= (const Vector2D& v)
        {
            X *= v.X;
            Y *= v.Y;
            return (*this);
        }

        inline Vector2D& Vector2D::operator *= (GaoReal32 value)
        {
            X *= value;
            Y *= value;
            return (*this);
        }

        inline Vector2D& Vector2D::operator /= (const Vector2D& v)
        {
            X /= v.X;
            Y /= v.Y;
            return (*this);
        }

        inline Vector2D& Vector2D::operator /= (GaoReal32 value)
        {
            X /= value;
            Y /= value;
            return (*this);
        }

        inline GaoVoid Vector2D::Set(GaoReal32 x, GaoReal32 y)
        {
            X = x;
            Y = y;
        }

        inline GaoVoid Vector2D::Normalize()
        {
            GaoReal32 length = Length();
            if (length == 0)
            {
                return;
            }

            X /= length;
            Y /= length;
        }

        inline GaoReal32 Vector2D::Length() const
        {
            return Sqrt<GaoReal32>(X * X + Y * Y);
        }

        inline GaoReal32 Vector2D::SqrLength() const
        {
            return (X * X + Y * Y);
        }

        inline GaoReal32 Vector2D::DotProduct(const Vector2D& v) const
        {
            return (X * v.X + Y * v.Y);
        }
    }
}
