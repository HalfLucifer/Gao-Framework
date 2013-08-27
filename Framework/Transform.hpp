/**
 * @file Transform.hpp
 * @author Jheng Wei Ciao
 *
 * Transformation class.
 *
 */
#ifndef GAO_FRAMEWORK_TRANSFORM_H
#define GAO_FRAMEWORK_TRANSFORM_H

#include "DataType.hpp"
#include "Vector2D.hpp"
#include "GraphicsDefine.hpp"



namespace Gao
{
    namespace Framework
    {
        /**
         * @brief Transformation class.
         */
        class Transform
        {

        public:

            Transform();

            virtual ~Transform();
            
            //==========================================================
            // Translation
            //==========================================================

            inline GaoVoid SetTranslate(GaoReal32 x, GaoReal32 y);

            inline GaoVoid SetTranslate(Vector2D& coord);

            inline GaoVoid ModifyTranslate(GaoReal32 x, GaoReal32 y);

            inline GaoVoid ModifyTranslate(Vector2D& coord);

            inline GaoReal32 GetTranslateX() const;

            inline GaoReal32 GetTranslateY() const;

            //==========================================================
            // Rotation
            //==========================================================

            inline GaoVoid SetRotateByRadian(GaoReal32 radian);

            inline GaoVoid SetRotateByDegree(GaoUInt32 degree);

            inline GaoVoid ModifyRotateByRadian(GaoReal32 radian);
            
            inline GaoVoid ModifyRotateByDegree(GaoUInt32 degree);

            inline GaoReal32 GetRotateByRadian() const;

            inline GaoReal32 GetRotateByDegree() const;

            //==========================================================
            // Scale
            //==========================================================
            
            inline GaoVoid SetScale(GaoReal32 scale);

            inline GaoVoid ModifyScale(GaoReal32 scale);

            inline GaoReal32 GetScale() const;

//            inline GaoBool IsRotatedOrScaled() const;
            


        private:

            GaoReal32      m_TranslateX;
            GaoReal32      m_TranslateY;
            GaoReal32      m_RotateAngle;  // Radian
            GaoReal32      m_Scale;

        };
    }
}

#include "Transform.inl"

#endif
