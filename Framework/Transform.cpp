#include "Transform.hpp"



namespace Gao
{
    namespace Framework
    {
        Transform::Transform()
            :
            m_TranslateX(0.0f), m_TranslateY(0.0f), m_RotateAngle(0.0f), m_Scale(DEFAULT_TRANSFORM_SCALE)
        {

        }

        Transform::~Transform()
        {

        }
    }
}
