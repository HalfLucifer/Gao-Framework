#include "GraphicsRenderer.hpp"
#include "Transform.hpp"



namespace Gao
{
    namespace Framework
    {
        GraphicsRenderer::GraphicsRenderer()
        {

        }

        GraphicsRenderer::~GraphicsRenderer()
        {

        }
        
        GaoVoid GraphicsRenderer::Reset()
        {
        
        }

        GaoVoid GraphicsRenderer::PreRender()
        {

        }

        GaoVoid GraphicsRenderer::DoRender()
        {

        }

        GaoVoid GraphicsRenderer::PostRender()
        {

        }

		GaoVoid GraphicsRenderer::Flush()
		{

		}

        GaoVoid GraphicsRenderer::UpdateWindow()
        {

        }

        GaoVoid GraphicsRenderer::ApplyWorldTransform(Transform* transform)
        {

        }

        GaoVoid GraphicsRenderer::ApplyWorldTransform(GaoReal32 x, GaoReal32 y)
        {

        }

        GaoVoid GraphicsRenderer::RestoreWorldTransform()
        {

        }
        
        GaoVoid GraphicsRenderer::SetBasePath(GaoConstCharPtr imageBasePath, GaoConstCharPtr fontBasePath)
        {
            m_ImageBasePath = imageBasePath;
            m_FontBasePath = fontBasePath;            
        }

        GaoVoid GraphicsRenderer::SetClearColor(GaoReal32 red, GaoReal32 green, GaoReal32 blue, GaoReal32 alpha)
        {

        }
        
        GaoVoid GraphicsRenderer::SetBlendFunction(GaoUInt32 mode)
        {

        }

        Transform* GraphicsRenderer::CreateTransform()
        {
            return new Transform();
        }

        Texture* GraphicsRenderer::CreateTexture(GaoString& fileName)
        {
            return NULL;
        }
        
        Texture* GraphicsRenderer::CreateFilteredTexture(GaoString& fileName)
        {
            return NULL;
        }
        
        Texture* GraphicsRenderer::CreateSpecialTexture(GaoInt32 width, GaoInt32 height)
        {
            return NULL;
        }

        GaoBool GraphicsRenderer::IsSpecialTextureValid() const
        {
            return FALSE;
        }

        Sprite* GraphicsRenderer::CreateSprite(Transform* transform, Texture* texture)
        {
            return NULL;
        }
        
        GaoBool GraphicsRenderer::ReloadTexture(Texture* texture)
        {
            return FALSE;
        }

        GaoVoid GraphicsRenderer::UnloadTexture(Texture* texture)
        {

        }

        GaoVoid GraphicsRenderer::DrawPixel(GaoInt16 coordX, GaoInt16 coordY, GaoReal32 red, GaoReal32 green, GaoReal32 blue, GaoReal32 alpha)
        {

        }

        GaoVoid GraphicsRenderer::DrawLine(GaoInt16 startX, GaoInt16 startY, GaoInt16 endX, GaoInt16 endY, GaoReal32 red, GaoReal32 green, GaoReal32 blue, GaoReal32 alpha)
        {

        }

        GaoVoid GraphicsRenderer::DrawRectangle(GaoInt16 startX, GaoInt16 startY, GaoInt16 endX, GaoInt16 endY, GaoReal32 red, GaoReal32 green, GaoReal32 blue, GaoReal32 alpha)
        {

        }
        
        GaoVoid GraphicsRenderer::DrawCircle(GaoInt16 centerX, GaoInt16 centerY, GaoInt16 radius, GaoReal32 red, GaoReal32 green, GaoReal32 blue, GaoReal32 alpha)
        {
        
        }

        GaoVoid GraphicsRenderer::SetLineWidth(GaoReal32 width)
        {
        
        }

        GaoVoid GraphicsRenderer::FadeScreen(GaoReal32 alpha)
        {

        }

        GaoBool GraphicsRenderer::SaveScreenshot(GaoString& fileName)
        {
            return FALSE;
        }
    }
}
