/**
 * @file CoreDefine.hpp
 * @author Jheng Wei Ciao
 *
 * Core preprocessor definition and macros.
 *
 */
#ifndef GAO_FRAMEWORK_COREDEFINE_H
#define GAO_FRAMEWORK_COREDEFINE_H



/**
 * @brief Platform definition.
 */
#ifdef WIN32
    #define GAO_PLATFORM_WINTEL32
#else
    #ifdef IPHONE
		#define GAO_PLATFORM_IPHONE
	#else
		#define GAO_PLATFORM_MACOSX
	#endif
#endif



/**
 * @brief Configuration definition.
 */
#ifdef GAO_PLATFORM_WINTEL32
    #ifdef _DEBUG
        #define GAO_DEBUG
    #else
        #define GAO_RELEASE
    #endif
#else
    #ifdef DEBUG
        #define GAO_DEBUG
    #else
        #define GAO_RELEASE
    #endif
#endif



/**
 * @brief CRT-warning disabled definition.
 */
#ifdef GAO_PLATFORM_WINTEL32
    #define _CRT_SECURE_NO_DEPRECATE
    //#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers
#endif



/**
 * @brief Useful macro definition.
 */
#define SAFE_DELETE(p) { if (p != NULL) { delete p; p = NULL; } }



/**
 * @brief Constant definition.
 */
#define GAO_CORE        "Core"
#define GAO_GRAPHICS    "Graphics"
#define GAO_AUDIO       "Audio"
#define GAO_INPUT       "Input"
#define GAO_IO          "IO"
#define GAO_SCRIPT      "Script"
#define GAO_GUI         "Gui"
#define GAO_GAME        "Game"

#define MAX_BUFFER_SIZE  2048

#endif
