/**
 * @file GraphicsRenderer.hpp
 * @author Jheng Wei Ciao
 *
 * Renderer interface for graphics usage.
 *
 */
#ifndef GAO_FRAMEWORK_GRAPHICSRENDERER_H
#define GAO_FRAMEWORK_GRAPHICSRENDERER_H

#include "DataType.hpp"
#include "GraphicsDefine.hpp"



namespace Gao
{
    namespace Framework
    {
        /**
         * @brief Forward declaration.
         */
        class Transform;
        class Texture;
        class Sprite;



        /**
         * @brief Interface class for graphics renderer.
         */
        class GraphicsRenderer
        {

        public:

            /**
             * @brief Class default constructor.
             */
            GraphicsRenderer();

            /**
             * @brief Class destructor.
             */
            virtual ~GraphicsRenderer();

            /**
             * @brief Reset renderer-related resource.
             */
            virtual GaoVoid Reset();

            /**
             * @brief Pre-process of rendering procedure.
             */
            virtual GaoVoid PreRender();

            /**
             * @brief The rendering procedure.
             */
            virtual GaoVoid DoRender();

            /**
             * @brief Post-process of rendering procedure.
             */
            virtual GaoVoid PostRender();

			virtual GaoVoid Flush();

            virtual GaoVoid UpdateWindow();

            virtual GaoVoid ApplyWorldTransform(Transform* transform);

            virtual GaoVoid ApplyWorldTransform(GaoReal32 x, GaoReal32 y);

            virtual GaoVoid RestoreWorldTransform();
            
            virtual GaoVoid SetBasePath(GaoConstCharPtr imageBasePath, GaoConstCharPtr fontBasePath);

            /**
             * @brief Set the clear color.
             */
            virtual GaoVoid SetClearColor(GaoReal32 red, GaoReal32 green, GaoReal32 blue, GaoReal32 alpha);

            /**
             * @brief Set blending function.
             */
            virtual GaoVoid SetBlendFunction(GaoUInt32 mode);

            /**
             * @brief Create the Transform object.
             */
            virtual Transform* CreateTransform();

            /**
             * @brief Create the Texture object.
             */
            virtual Texture* CreateTexture(GaoString& fileName);
            
            virtual Texture* CreateFilteredTexture(GaoString& fileName);
            
            virtual Texture* CreateSpecialTexture(GaoInt32 width, GaoInt32 height);
            
            virtual GaoBool IsSpecialTextureValid() const;

            /**
             * @brief Create the Sprite object.
             */
            virtual Sprite* CreateSprite(Transform* transform, Texture* texture);

            /**
             * @brief Reload/Unload the Texture object.
             */
            virtual GaoBool ReloadTexture(Texture* texture);

            virtual GaoVoid UnloadTexture(Texture* texture);

            /**
             * @brief Draw pixel/line/rectangle/circular.
             */
            virtual GaoVoid DrawPixel(GaoInt16 coordX, GaoInt16 coordY, GaoReal32 red, GaoReal32 green, GaoReal32 blue, GaoReal32 alpha);

            virtual GaoVoid DrawLine(GaoInt16 startX, GaoInt16 startY, GaoInt16 endX, GaoInt16 endY, GaoReal32 red, GaoReal32 green, GaoReal32 blue, GaoReal32 alpha);

			virtual GaoVoid DrawRectangle(GaoInt16 startX, GaoInt16 startY, GaoInt16 endX, GaoInt16 endY, GaoReal32 red, GaoReal32 green, GaoReal32 blue, GaoReal32 alpha);
                
            virtual GaoVoid DrawCircle(GaoInt16 centerX, GaoInt16 centerY, GaoInt16 radius, GaoReal32 red, GaoReal32 green, GaoReal32 blue, GaoReal32 alpha);

            /**
             * @brief Misc functionality
             */
            virtual GaoVoid SetLineWidth(GaoReal32 width);

            virtual GaoVoid FadeScreen(GaoReal32 alpha);

            virtual GaoBool SaveScreenshot(GaoString& fileName);
            
            
        protected:

            GaoString	m_ImageBasePath;
            GaoString	m_FontBasePath;
            GaoString	m_WorkingFullPath;

        };
    }
}

#endif
