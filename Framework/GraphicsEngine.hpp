/**
 * @file GraphicsEngine.hpp
 * @author Jheng Wei Ciao
 *
 * Interface for graphics usage.
 *
 */
#ifndef GAO_FRAMEWORK_GRAPHICSENGINE_H
#define GAO_FRAMEWORK_GRAPHICSENGINE_H

#include "DataType.hpp"
#include "Singleton.hpp"
#include "GraphicsDefine.hpp"
#include "Dictionary.hpp"
#include "Array.hpp"

#define g_GraphicsEngine Gao::Framework::GraphicsEngine::GetSingletonPointer()



namespace Gao
{
    namespace Framework
    {
        /**
         * @brief Forward declaration.
         */
        class GraphicsRenderer;
        class Transform;
        class Texture;
        class Sprite;



        /**
         * @brief Interface class for graphics usage.
         */
        class GraphicsEngine : public Singleton<GraphicsEngine>
        {

        public:

            /**
             * @brief Renderer types.
             */
            enum RendererType
            {
                Renderer_DirectX,
                Renderer_OpenGL,
            };


        public:

            /**
             * @brief Class constructor.
             * @param renderer The renderer that graphics engine uses.
             */
            GraphicsEngine(GraphicsRenderer* renderer);

			GraphicsEngine(GraphicsRenderer* renderer, GaoBool autoReleaseRenderer);

            /**
             * @brief Class destructor.
             */
            virtual ~GraphicsEngine();

            GaoVoid SetBasePath(GaoString& imageBasePath, GaoString& fontBasePath);

            GaoVoid SetBasePath(GaoConstCharPtr imageBasePath, GaoConstCharPtr fontBasePath);
            
            GaoVoid Reset();

            /**
             * @brief The main procedure for rendering.
             */
            GaoVoid Render();

            GaoVoid PreRender();

            GaoVoid PostRender();

			GaoVoid Flush();

            GaoVoid UpdateWindow();

            GaoVoid ApplyWorldTransform(Transform* transform);

            GaoVoid ApplyWorldTransform(GaoReal32 x, GaoReal32 y);

            GaoVoid RestoreWorldTransform();

            /**
             * @brief Set the clear color.
             */
            GaoVoid SetClearColor(GaoReal32 red, GaoReal32 green, GaoReal32 blue, GaoReal32 alpha);

            /**
             * @brief Set blending function.
             */
            GaoVoid SetBlendFunction(GaoUInt32 mode);

            /**
             * @brief Create the Transform object.
             * 
             * @return The transform object.
             */
            Transform* CreateTransform();

            /**
             * @brief Create the Texture object.
             *
             * @param[in] fileName The file name of texture.
             * @return The texture object.
             * 
             * Once created, there's no need for explicit deallocation.
             * GraphicsEngine class would clean up textures pool on destroy.
             *
             */
            Texture* CreateTexture(GaoString& fileName);

            Texture* CreateTexture(GaoConstCharPtr fileName);
            
            Texture* CreateFilteredTexture(GaoConstCharPtr fileName);

            Texture* CreateSpecialTexture(GaoInt32 width, GaoInt32 height);

            GaoVoid DestroySpecialTexture();
            
            GaoBool IsSpecialTextureValid() const;

            /**
             * @brief Create the Sprite object.
             *
             * @param[in] fileName The file name of sprite.
             * @return The sprite object.
             */
            Sprite* CreateSprite(GaoString& fileName);

            Sprite* CreateSprite(GaoConstCharPtr fileName);

            Sprite* CreateSprite(Transform* transform, Texture* texture);

            Sprite* PrecreateSprite(Transform* transform);

            /**
             * @brief Reload/Unload the Texture object.
             */
            GaoBool ReloadTexture(Texture* texture);

            GaoVoid UnloadTexture(Texture* texture);

            /**
             * @brief Draw pixel/line/rect.
             */
            GaoVoid DrawPixel(GaoInt16 coordX, GaoInt16 coordY, GaoReal32 red, GaoReal32 green, GaoReal32 blue, GaoReal32 alpha);

            GaoVoid DrawLine(GaoInt16 startX, GaoInt16 startY, GaoInt16 endX, GaoInt16 endY, GaoReal32 red, GaoReal32 green, GaoReal32 blue, GaoReal32 alpha);

            GaoVoid DrawRectangle(GaoInt16 startX, GaoInt16 startY, GaoInt16 endX, GaoInt16 endY, GaoReal32 red, GaoReal32 green, GaoReal32 blue, GaoReal32 alpha);

            GaoVoid DrawCircle(GaoInt16 centerX, GaoInt16 centerY, GaoInt16 radius, GaoReal32 red, GaoReal32 green, GaoReal32 blue, GaoReal32 alpha);

            /**
             * @brief Misc functionality
             */
            GaoVoid SetLineWidth(GaoReal32 width);
            
            GaoVoid FadeScreen(GaoReal32 alpha);

            GaoBool SaveScreenshot(GaoString& fileName);

            GaoBool SaveScreenshot(GaoConstCharPtr fileName);


        private:

            /**
             * @brief Class default constructor is disallowed.
             */
            GraphicsEngine();

			GaoVoid CreateResourcePools();


        private:

            GraphicsRenderer*							m_Renderer;
			GaoBool										m_AutoReleaseRenderer;

            Array<Transform*, TRUE>*					m_TransformPool;
            Dictionary<GaoString, Texture*, TRUE>*		m_TexturesPool;
            Array<Sprite*, TRUE>*						m_SpritesPool;

        };
    }
}

#endif
