/**
 * @file GraphicsDefine.hpp
 * @author Jheng Wei Ciao
 *
 * Defines and data types for graphics usage.
 *
 */
#ifndef GAO_FRAMEWORK_GRAPHICSDEFINE_H
#define GAO_FRAMEWORK_GRAPHICSDEFINE_H



//#define GAO_GRAPHICS_GLES2

#define GAO_GRAPHICS_COLOR_UNIT_FLOAT
//#define GAO_GRAPHICS_COLOR_UNIT_UBYTE

#define GAO_GRAPHICS_ROTATION_UNIT_DEGREE
//#define GAO_GRAPHICS_ROTATION_UNIT_RADIAN

#define GAO_DEFAULT_BLENDING_WHITEOUT
//#define GAO_DEFAULT_BLENDING_FADEOUT



namespace Gao
{
    namespace Framework
    {
        /**
         * @brief Text align type.
         */
        enum AlignType
        {
            Align_Left,  /**< Left aligned text. */
            Align_Right, /**< Right aligned text. */
        };

        enum BlendMode
        {
            BlendWhiteout = 0,  // glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA)
            BlendFadeout  = 1,  // glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA)
        };

#ifdef GAO_GRAPHICS_COLOR_UNIT_FLOAT
    #define GAO_DEFAULT_COLOR 1.0f
    #define GAO_DEFAULT_ALPHA 1.0f
#else
    #define GAO_DEFAULT_COLOR 255
    #define GAO_DEFAULT_ALPHA 255
#endif
        
        static const GaoReal32 DEFAULT_TRANSFORM_SCALE = 1.0f;
    }



	static const GaoString IMAGE_PNG_EXTENSION = "png";
	static const GaoString IMAGE_JPG_EXTENSION = "jpg";
	static const GaoString IMAGE_BMP_EXTENSION = "bmp";
	static const GaoString IMAGE_TGA_EXTENSION = "tga";
}

#endif
