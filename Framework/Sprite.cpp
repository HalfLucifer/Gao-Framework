#include "Sprite.hpp"



namespace Gao
{
    namespace Framework
    {
        Sprite::Sprite()
            :
            m_Transform(NULL), m_Texture(NULL), m_Alpha(GAO_DEFAULT_ALPHA), m_FlipX(FALSE), m_FlipY(FALSE)
//            ,m_BlendingSrcFactor(GL_SRC_ALPHA), m_BlendingSrcFactor(GL_ONE_MINUS_SRC_ALPHA)
//            m_RenderOriginX(0), m_RenderOriginY(0), m_RenderEndX(0), m_RenderEndY(0),
        {
            m_Radius[0] = m_Radius[1] = 0.0f;
            m_Offset[0] = m_Offset[1] = 0.0f;
        }

        Sprite::~Sprite()
        {
            m_Texture = NULL;
            m_Transform = NULL;
        }

        GaoBool Sprite::Create(Transform* transform, Texture* texture)
        {
            return FALSE;
        }

        GaoVoid Sprite::Draw()
        {

        }

        GaoVoid Sprite::Draw(GaoInt16 coordX, GaoInt16 coordY)
        {

        }

        GaoVoid Sprite::DrawOffset(Transform* transform)
        {

        }

        GaoVoid Sprite::DrawOffset(GaoInt16 coordX, GaoInt16 coordY)
        {

        }

        GaoVoid Sprite::Draw(Vector2D& source1, Vector2D& source2, Vector2D& source3, Vector2D& source4,
            Vector2D& dest1, Vector2D& dest2, Vector2D& dest3, Vector2D& dest4)
        {

        }
        
        GaoVoid Sprite::SetAlpha(GaoReal32 value)
        {
            m_Alpha = value;
        }
        
        GaoVoid Sprite::SetTransform(GaoInt16 coordX, GaoInt16 coordY)
        {
            
        }

        GaoVoid Sprite::SetTexture(Texture* texture)
        {
            assert(texture != NULL);
            m_Texture = texture;
        }
        
//        GaoVoid Sprite::SetRenderBound(GaoInt16 renderOriginX, GaoInt16 renderOriginY, GaoInt16 renderEndX, GaoInt16 renderEndY)
//        {
//            m_RenderOriginX = renderOriginX;
//            m_RenderOriginY = renderOriginY;
//            m_RenderEndX = renderEndX;
//            m_RenderEndY = renderEndY;
//        }

        GaoVoid Sprite::SetTexCoords(GaoReal32 texCoordU1, GaoReal32 texCoordV1, GaoReal32 texCoordU2, GaoReal32 texCoordV2)
        {
        
        }

        GaoVoid Sprite::SetTexCoordsU(GaoReal32 texCoordU1, GaoReal32 texCoordU2)
        {
            
        }
        
        GaoVoid Sprite::SetTexCoordsV(GaoReal32 texCoordV1, GaoReal32 texCoordV2)
        {
            
        }

        GaoVoid Sprite::SetRenderSizeAndTexCoords(GaoInt16 width, GaoInt16 height, GaoReal32 texCoordU1, GaoReal32 texCoordV1, GaoReal32 texCoordU2, GaoReal32 texCoordV2)
        {
            
        }
        
        GaoVoid Sprite::SetRenderSizeAndRadius(GaoInt16 width, GaoInt16 height)
        {
            
        }
        
        GaoVoid Sprite::SetVertexData(GaoUInt16 index, GaoReal32 x, GaoReal32 y, GaoReal32 u, GaoReal32 v)
        {
        
        }
        
        GaoVoid Sprite::SetQuadVertices(GaoReal32 x1, GaoReal32 y1, GaoReal32 x2, GaoReal32 y2, GaoReal32 x3, GaoReal32 y3, GaoReal32 x4, GaoReal32 y4)
        {
            
        }
        
        GaoVoid Sprite::SetQuadTexCoords(GaoReal32 u1, GaoReal32 v1, GaoReal32 u2, GaoReal32 v2, GaoReal32 u3, GaoReal32 v3, GaoReal32 u4, GaoReal32 v4)
        {
            
        }

        GaoVoid Sprite::ToggleFlipX()
        {
        
        }
            
        GaoVoid Sprite::ToggleFlipY()
        {
        
        }

        GaoVoid Sprite::SetBlendingMode(GaoInt32 mode)
        {

        }
        
        GaoVoid Sprite::SetColor(GaoReal32 r, GaoReal32 g, GaoReal32 b)
        {
            
        }
    }
}
