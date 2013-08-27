/**
 * @file Sprite.hpp
 * @author Jheng Wei Ciao
 *
 * Sprite class.
 *
 */
#ifndef GAO_FRAMEWORK_SPRITE_H
#define GAO_FRAMEWORK_SPRITE_H

#include "DataType.hpp"
#include "GraphicsDefine.hpp"
#include "Transform.hpp"
#include "Texture.hpp"



namespace Gao
{
    namespace Framework
    {
        /**
         * @brief Sprite class.
         *
         * @note Sprite is defined as a alpha blended textured-quad.
         */
        class Sprite
        {

        public:

            Sprite();

            /**
             * @brief Class destructor.
             */
            virtual ~Sprite();

            virtual GaoBool Create(Transform* transform, Texture* texture);

            virtual GaoVoid Draw();

            virtual GaoVoid Draw(GaoInt16 coordX, GaoInt16 coordY);

            virtual GaoVoid DrawOffset(Transform* transform);

            virtual GaoVoid DrawOffset(GaoInt16 coordX, GaoInt16 coordY);

            virtual GaoVoid Draw(Vector2D& source1, Vector2D& source2, Vector2D& source3, Vector2D& source4,
                Vector2D& dest1, Vector2D& dest2, Vector2D& dest3, Vector2D& dest4);
            
            virtual GaoVoid SetAlpha(GaoReal32 value);
            
            virtual GaoVoid SetTransform(GaoInt16 coordX, GaoInt16 coordY);

            virtual GaoVoid SetTexture(Texture* texture);
            
//            virtual GaoVoid SetRenderBound(GaoInt16 renderOriginX, GaoInt16 renderOriginY, GaoInt16 renderEndX, GaoInt16 renderEndY);
            
            virtual GaoVoid SetTexCoords(GaoReal32 texCoordU1, GaoReal32 texCoordV1, GaoReal32 texCoordU2, GaoReal32 texCoordV2);
            
            virtual GaoVoid SetTexCoordsU(GaoReal32 texCoordU1, GaoReal32 texCoordU2);
            
            virtual GaoVoid SetTexCoordsV(GaoReal32 texCoordV1, GaoReal32 texCoordV2);

            virtual GaoVoid SetRenderSizeAndTexCoords(GaoInt16 width, GaoInt16 height, GaoReal32 texCoordU1, GaoReal32 texCoordV1, GaoReal32 texCoordU2, GaoReal32 texCoordV2);

            virtual GaoVoid SetRenderSizeAndRadius(GaoInt16 width, GaoInt16 height);

            virtual GaoVoid SetVertexData(GaoUInt16 index, GaoReal32 x, GaoReal32 y, GaoReal32 u, GaoReal32 v);

            virtual GaoVoid SetQuadVertices(GaoReal32 x1, GaoReal32 y1, GaoReal32 x2, GaoReal32 y2, GaoReal32 x3, GaoReal32 y3, GaoReal32 x4, GaoReal32 y4);

            virtual GaoVoid SetQuadTexCoords(GaoReal32 u1, GaoReal32 v1, GaoReal32 u2, GaoReal32 v2, GaoReal32 u3, GaoReal32 v3, GaoReal32 u4, GaoReal32 v4);
            
            virtual GaoVoid ToggleFlipX();
            
            virtual GaoVoid ToggleFlipY();
            
            virtual GaoVoid SetBlendingMode(GaoInt32 mode);

            virtual GaoVoid SetColor(GaoReal32 r, GaoReal32 g, GaoReal32 b);

            inline GaoVoid ModifyAlpha(GaoReal32 value);

            inline GaoVoid SetFlip(GaoBool flipX, GaoBool flipY);

//            inline GaoVoid SetRenderOrigin(GaoInt16 renderOriginX, GaoInt16 renderOriginY);
//
//            inline GaoVoid SetRenderEnd(GaoInt16 renderEndX, GaoInt16 renderEndY);
//
//            inline GaoVoid ModifyRenderOrigin(GaoInt16 renderOriginX, GaoInt16 renderOriginY);
//
//            inline GaoVoid ModifyRenderSize(GaoInt16 renderEndX, GaoInt16 renderEndY);
//
//            inline GaoVoid ModifyRenderBound(GaoInt16 renderOriginX, GaoInt16 renderOriginY, GaoInt16 renderEndX, GaoInt16 renderEndY);

            inline GaoVoid SetTranslate(GaoInt16 coordX, GaoInt16 coordY);

            inline GaoVoid SetTranslate(Vector2D& coord);
            
            inline GaoVoid SetOffset(GaoReal32 x, GaoReal32 y);

            inline GaoReal32 GetOffsetX() const;

            inline GaoReal32 GetOffsetY() const;

            inline GaoVoid ResetFlip();

            inline Transform* GetTransform() const;

			inline GaoInt16 GetWidth() const;

			inline GaoInt16 GetHeight() const;
            
            inline GaoVoid SetRenderSize(GaoInt16 width, GaoInt16 height);

            inline GaoInt16 GetRenderSizeX() const;

            inline GaoInt16 GetRenderSizeY() const;

			inline GaoReal32 GetAlpha() const;
            
			inline Texture* GetTexture();


        protected:

            Transform*		m_Transform;
            Texture*		m_Texture;
            
            GaoReal32       m_Radius[2];
            GaoReal32       m_Offset[2];
            GaoReal32		m_Alpha;
            
            GaoBool			m_FlipX;
            GaoBool			m_FlipY;
            
            GaoUInt32       m_BlendingSrcFactor;
//            GaoUInt32       m_BlendingDestFactor;
            
//            GaoInt16		m_RenderOriginX;
//            GaoInt16		m_RenderOriginY;
//            GaoInt16		m_RenderEndX;
//            GaoInt16		m_RenderEndY;

        };
    }
}

#include "Sprite.inl"

#endif
