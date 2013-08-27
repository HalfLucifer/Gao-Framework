
namespace Gao
{
    namespace Framework
    {
        inline GaoVoid Transform::SetTranslate(GaoReal32 x, GaoReal32 y)
        {
            m_TranslateX = x;
            m_TranslateY = y;
        }

        inline GaoVoid Transform::SetTranslate(Vector2D& coord)
        {
            m_TranslateX = coord.X;
            m_TranslateY = coord.Y;
        }

        inline GaoVoid Transform::ModifyTranslate(GaoReal32 x, GaoReal32 y)
        {
            m_TranslateX += x;
            m_TranslateY += y;
        }

        inline GaoVoid Transform::ModifyTranslate(Vector2D& coord)
        {
            m_TranslateX += coord.X;
            m_TranslateY += coord.Y;
        }

        inline GaoReal32 Transform::GetTranslateX() const
        {
            return m_TranslateX;
        }

        inline GaoReal32 Transform::GetTranslateY() const
        {
            return m_TranslateY;
        }

#ifdef GAO_GRAPHICS_ROTATION_UNIT_DEGREE

        inline GaoVoid Transform::SetRotateByRadian(GaoReal32 radian)
        {
            m_RotateAngle = radian * 180 / GAO_PI;
        }

        inline GaoVoid Transform::SetRotateByDegree(GaoUInt32 degree)
        {
            m_RotateAngle = degree;
        }

        inline GaoVoid Transform::ModifyRotateByRadian(GaoReal32 radian)
        {
            m_RotateAngle += (radian * 180 / GAO_PI);
        }

        inline GaoVoid Transform::ModifyRotateByDegree(GaoUInt32 degree)
        {
            m_RotateAngle += degree;
        }

        inline GaoReal32 Transform::GetRotateByRadian() const
        {
            return m_RotateAngle * 180 / GAO_PI;
        }

        inline GaoReal32 Transform::GetRotateByDegree() const
        {
            return m_RotateAngle;
        }
        
#else

        inline GaoVoid Transform::SetRotateByRadian(GaoReal32 radian)
        {
            m_RotateAngle = radian;
        }

        inline GaoVoid Transform::SetRotateByDegree(GaoUInt32 degree)
        {
            m_RotateAngle = degree * GAO_PI / 180.0f;
        }

        inline GaoVoid Transform::ModifyRotateByRadian(GaoReal32 radian)
        {
            m_RotateAngle += radian;
        }

        inline GaoVoid Transform::ModifyRotateByDegree(GaoUInt32 degree)
        {
            m_RotateAngle += (degree * GAO_PI / 180.0f);
        }

        inline GaoReal32 Transform::GetRotateByRadian() const
        {
            return m_RotateAngle;
        }

        inline GaoReal32 Transform::GetRotateByDegree() const
        {
            return m_RotateAngle * GAO_PI / 180.0f;
        }
        
#endif

        inline GaoVoid Transform::SetScale(GaoReal32 scale)
        {
            m_Scale = scale;
        }

        inline GaoVoid Transform::ModifyScale(GaoReal32 scale)
        {
            m_Scale += scale;
        }

        inline GaoReal32 Transform::GetScale() const
        {
            return m_Scale;
        }
    }
}
