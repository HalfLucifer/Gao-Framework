
namespace Gao
{
    namespace Framework
    {
        inline GaoVoid Sprite::ModifyAlpha(GaoReal32 value)
        {
            SetAlpha(m_Alpha + value);
        }

        inline GaoVoid Sprite::SetFlip(GaoBool flipX, GaoBool flipY)
        {
            m_FlipX = flipX;
            m_FlipY = flipY;
        }

//        inline GaoVoid Sprite::SetRenderOrigin(GaoInt16 renderOriginX, GaoInt16 renderOriginY)
//        {
//            SetRenderBound(renderOriginX, renderOriginY, m_RenderEndX, m_RenderEndY);
//        }
//
//        inline GaoVoid Sprite::SetRenderEnd(GaoInt16 renderEndX, GaoInt16 renderEndY)
//        {
//            SetRenderBound(m_RenderOriginX, m_RenderOriginY, renderEndX, renderEndY);
//        }
//
//        inline GaoVoid Sprite::ModifyRenderOrigin(GaoInt16 renderOriginX, GaoInt16 renderOriginY)
//        {
//            SetRenderBound(m_RenderOriginX + renderOriginX, m_RenderOriginY + renderOriginY, m_RenderEndX, m_RenderEndY);
//        }
//
//        inline GaoVoid Sprite::ModifyRenderSize(GaoInt16 renderEndX, GaoInt16 renderEndY)
//        {
//            SetRenderBound(m_RenderOriginX, m_RenderOriginY, m_RenderEndX + renderEndX, m_RenderEndY + renderEndY);
//        }
//
//        inline GaoVoid Sprite::ModifyRenderBound(GaoInt16 renderOriginX, GaoInt16 renderOriginY,
//            GaoInt16 renderEndX, GaoInt16 renderEndY)
//        {
//            SetRenderBound(m_RenderOriginX + renderOriginX, m_RenderOriginY + renderOriginY,
//                m_RenderEndX + renderEndX, m_RenderEndY + renderEndY);
//        }

        inline GaoVoid Sprite::SetTranslate(GaoInt16 coordX, GaoInt16 coordY)
        {
            m_Transform->SetTranslate(coordX, coordY);
        }

        inline GaoVoid Sprite::SetTranslate(Vector2D& coord)
        {
            m_Transform->SetTranslate(coord);
        }
        
        inline GaoVoid Sprite::SetOffset(GaoReal32 x, GaoReal32 y)
        {
            m_Offset[0] = x;
            m_Offset[1] = y;
        }

        inline GaoReal32 Sprite::GetOffsetX() const
        {
            return m_Offset[0];
        }

        inline GaoReal32 Sprite::GetOffsetY() const
        {
            return m_Offset[1];        
        }
        
        inline GaoVoid Sprite::ResetFlip()
        {
            if (m_FlipX)
            {
                ToggleFlipX();
            }
            
            if (m_FlipY)
            {
                ToggleFlipY();
            }        
        }

        inline Transform* Sprite::GetTransform() const
        {
            return m_Transform;
        }

		inline GaoInt16 Sprite::GetWidth() const
		{
			return m_Texture->GetWidth();
		}

		inline GaoInt16 Sprite::GetHeight() const
		{
			return m_Texture->GetHeight();
		}
        
        inline GaoVoid Sprite::SetRenderSize(GaoInt16 width, GaoInt16 height)
        {
            m_Radius[0] = width * 0.5f;
            m_Radius[1] = height * 0.5f;            
        }
        
        inline GaoInt16 Sprite::GetRenderSizeX() const
        {
            return m_Radius[0] * 2.0f;
        }

        inline GaoInt16 Sprite::GetRenderSizeY() const
        {
            return m_Radius[1] * 2.0f;
        }

		inline GaoReal32 Sprite::GetAlpha() const
		{
			return m_Alpha;
		}
        
        inline Texture* Sprite::GetTexture()
        {
            return m_Texture;
        }
    }
}
