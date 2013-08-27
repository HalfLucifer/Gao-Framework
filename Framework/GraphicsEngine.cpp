#include "GraphicsEngine.hpp"
#include "GraphicsRenderer.hpp"
#include "Texture.hpp"
#include "Sprite.hpp"
#include "FileSystem.hpp"
#include "Logger.hpp"



namespace Gao
{
    namespace Framework
    {
        GraphicsEngine::GraphicsEngine()
        {

        }

        GraphicsEngine::GraphicsEngine(GraphicsRenderer* renderer)
			:
			m_Renderer(renderer), m_AutoReleaseRenderer(FALSE), m_TransformPool(NULL), m_TexturesPool(NULL), m_SpritesPool(NULL)
        {
			CreateResourcePools();
        }

		GraphicsEngine::GraphicsEngine(GraphicsRenderer* renderer, GaoBool autoReleaseRenderer)
			:
			m_Renderer(renderer), m_AutoReleaseRenderer(autoReleaseRenderer), m_TransformPool(NULL), m_TexturesPool(NULL), m_SpritesPool(NULL)
		{
			CreateResourcePools();
		}

        GraphicsEngine::~GraphicsEngine()
        {
            // Deallocate resource pools
            SAFE_DELETE(m_SpritesPool);
            SAFE_DELETE(m_TexturesPool);
            SAFE_DELETE(m_TransformPool);

			if (m_AutoReleaseRenderer)
			{
				SAFE_DELETE(m_Renderer);
			}
        }

        GaoVoid GraphicsEngine::SetBasePath(GaoString& imageBasePath, GaoString& fontBasePath)
		{
            m_Renderer->SetBasePath(imageBasePath.c_str(), fontBasePath.c_str());
        }

        GaoVoid GraphicsEngine::SetBasePath(GaoConstCharPtr imageBasePath, GaoConstCharPtr fontBasePath)
        {
            m_Renderer->SetBasePath(imageBasePath, fontBasePath);
        }
        
        GaoVoid GraphicsEngine::Reset()
        {
            m_Renderer->Reset();
        }

        GaoVoid GraphicsEngine::Render()
        {
            m_Renderer->PreRender();
            m_Renderer->DoRender();
            m_Renderer->PostRender();
        }

        GaoVoid GraphicsEngine::PreRender()
        {
            m_Renderer->PreRender();
        }

        GaoVoid GraphicsEngine::PostRender()
        {
            m_Renderer->PostRender();
        }

		GaoVoid GraphicsEngine::Flush()
		{
			m_Renderer->Flush();
		}

        GaoVoid GraphicsEngine::UpdateWindow()
        {
            m_Renderer->UpdateWindow();
        }

        GaoVoid GraphicsEngine::ApplyWorldTransform(Transform* transform)
        {
            m_Renderer->ApplyWorldTransform(transform);
        }

        GaoVoid GraphicsEngine::ApplyWorldTransform(GaoReal32 x, GaoReal32 y)
        {
            m_Renderer->ApplyWorldTransform(x, y);        
        }

        GaoVoid GraphicsEngine::RestoreWorldTransform()
        {
            m_Renderer->RestoreWorldTransform();
        }

        GaoVoid GraphicsEngine::SetClearColor(GaoReal32 red, GaoReal32 green, GaoReal32 blue, GaoReal32 alpha)
        {
            m_Renderer->SetClearColor(red, green, blue, alpha);
        }
        
        GaoVoid GraphicsEngine::SetBlendFunction(GaoUInt32 mode)
        {
            m_Renderer->SetBlendFunction(mode);
        }

        Transform* GraphicsEngine::CreateTransform()
        {
            Transform* transform = m_Renderer->CreateTransform();
            m_TransformPool->Add(transform);

            return transform; 
        }

        Texture* GraphicsEngine::CreateTexture(GaoString& fileName)
        {
            Texture* texture = NULL;

            if (!m_TexturesPool->GetAt(fileName, texture))
            {
                texture = m_Renderer->CreateTexture(fileName);

                if (texture != NULL)
                {
                    m_TexturesPool->SetAt(fileName, texture);
                }
                else
                {
                    g_Logger->Log(GAO_GRAPHICS, "Failed to create texture: %s", fileName.c_str());                
                }
            }

            return texture;
        }

        Texture* GraphicsEngine::CreateTexture(GaoConstCharPtr fileName)
        {
            GaoString fileNameString(fileName);
            return CreateTexture(fileNameString);
        }
        
        Texture* GraphicsEngine::CreateFilteredTexture(GaoConstCharPtr fileName)
        {
            Texture* texture = NULL;
            
            if (!m_TexturesPool->GetAt(fileName, texture))
            {
                GaoString fileNameString(fileName);
                texture = m_Renderer->CreateFilteredTexture(fileNameString);
                
                if (texture != NULL)
                {
                    m_TexturesPool->SetAt(fileName, texture);
                }
                else
                {
                    g_Logger->Log(GAO_GRAPHICS, "Failed to create texture: %s", fileNameString.c_str());
                }
            }
            
            return texture;            
        }
        
        Texture* GraphicsEngine::CreateSpecialTexture(GaoInt32 width, GaoInt32 height)
        {
            Texture* texture = NULL;
            
            if (m_TexturesPool->GetAt("SpecialTexture", texture))
            {
                m_TexturesPool->RemoveAt("SpecialTexture");
            }
            
            texture = m_Renderer->CreateSpecialTexture(width, height);
            m_TexturesPool->SetAt("SpecialTexture", texture);
            
            return texture;
        }
        
        GaoVoid GraphicsEngine::DestroySpecialTexture()
        {
            Texture* texture = NULL;
            
            if (m_TexturesPool->GetAt("SpecialTexture", texture))
            {
                m_TexturesPool->RemoveAt("SpecialTexture");
            }
        }
        
        GaoBool GraphicsEngine::IsSpecialTextureValid() const
        {
            return m_Renderer->IsSpecialTextureValid();
        }

        Sprite* GraphicsEngine::CreateSprite(GaoString& fileName)
        {
            Sprite* sprite = NULL;

            Transform* pkTransform = CreateTransform();
            Texture* texture = CreateTexture(fileName);

            if (pkTransform != NULL && texture != NULL)
            {
                sprite = m_Renderer->CreateSprite(pkTransform, texture);

                if (sprite != NULL)
                {
                    m_SpritesPool->Add(sprite);
                }
				else
				{
					g_Logger->Log(GAO_GRAPHICS, "Failed to create sprite: %s", fileName.c_str());                
				}
            }

            return sprite;
        }

        Sprite* GraphicsEngine::CreateSprite(GaoConstCharPtr fileName)
        {
            GaoString fileNameString(fileName);
            return CreateSprite(fileNameString);
        }

        Sprite* GraphicsEngine::CreateSprite(Transform* transform, Texture* texture)
        {
            Sprite* sprite = m_Renderer->CreateSprite(transform, texture);

            if (sprite != NULL)
            {
                m_SpritesPool->Add(sprite);
            }

            return sprite;
        }

        Sprite* GraphicsEngine::PrecreateSprite(Transform* transform)
        {
            return CreateSprite(transform, NULL);
        }

        GaoBool GraphicsEngine::ReloadTexture(Texture* texture)
        {
            return m_Renderer->ReloadTexture(texture);
        }

        GaoVoid GraphicsEngine::UnloadTexture(Texture* texture)
        {
            m_Renderer->UnloadTexture(texture);        
        }

        GaoVoid GraphicsEngine::DrawPixel(GaoInt16 coordX, GaoInt16 coordY, GaoReal32 red, GaoReal32 green, GaoReal32 blue, GaoReal32 alpha)
        {
            m_Renderer->DrawPixel(coordX, coordY, red, green, blue, alpha);
        }

        GaoVoid GraphicsEngine::DrawLine(GaoInt16 startX, GaoInt16 startY, GaoInt16 endX, GaoInt16 endY, GaoReal32 red, GaoReal32 green, GaoReal32 blue, GaoReal32 alpha)
        {
            m_Renderer->DrawLine(startX, startY, endX, endY, red, green, blue, alpha);
        }

        GaoVoid GraphicsEngine::DrawRectangle(GaoInt16 startX, GaoInt16 startY, GaoInt16 endX, GaoInt16 endY, GaoReal32 red, GaoReal32 green, GaoReal32 blue, GaoReal32 alpha)
        {
            m_Renderer->DrawRectangle(startX, startY, endX, endY, red, green, blue, alpha);
        }

        GaoVoid GraphicsEngine::DrawCircle(GaoInt16 centerX, GaoInt16 centerY, GaoInt16 radius, GaoReal32 red, GaoReal32 green, GaoReal32 blue, GaoReal32 alpha)
        {
            m_Renderer->DrawCircle(centerX, centerY, radius, red, green, blue, alpha);        
        }
        
        GaoVoid GraphicsEngine::SetLineWidth(GaoReal32 width)
        {
            m_Renderer->SetLineWidth(width);
        }

        GaoVoid GraphicsEngine::FadeScreen(GaoReal32 alpha)
        {
            m_Renderer->FadeScreen(alpha);
        }

        GaoBool GraphicsEngine::SaveScreenshot(GaoString& fileName)
        {
            return m_Renderer->SaveScreenshot(fileName);
        }

        GaoBool GraphicsEngine::SaveScreenshot(GaoConstCharPtr fileName)
        {
            GaoString fileNameString(fileName);
            return SaveScreenshot(fileNameString);
        }

		GaoVoid GraphicsEngine::CreateResourcePools()
		{
			m_TransformPool = new Array<Transform*, TRUE>();
			m_TexturesPool = new Dictionary<GaoString, Texture*, TRUE>();
			m_SpritesPool = new Array<Sprite*, TRUE>();
		}

        // TODO: make some code inline =_=
    }
}
