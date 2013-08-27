/**
 * @file DataType.hpp
 * @author Jheng Wei Ciao
 *
 * Core data type definition.
 *
 */
#ifndef GAO_FRAMEWORK_DATATYPE_H
#define GAO_FRAMEWORK_DATATYPE_H

#include "CoreDefine.hpp"
#include <string>
#include <vector>
#include <map>
#include <list>
#include <deque>
#include <cassert>



#ifdef GAO_PLATFORM_WINTEL32

    typedef char              GaoChar;
    typedef signed char       GaoChar8;
    typedef unsigned char     GaoUChar8;
    typedef signed char       GaoInt8;
    typedef unsigned char     GaoUInt8;
    typedef signed short      GaoInt16;
    typedef unsigned short    GaoUInt16;
    typedef signed int        GaoInt32;
    typedef unsigned int      GaoUInt32;
    typedef __int64           GaoInt64;
    typedef unsigned __int64  GaoUInt64;

    typedef unsigned char     GaoByte;
    typedef bool              GaoBool;
    typedef GaoInt32          GaoLong;
    typedef GaoUInt32         GaoULong;
    typedef GaoUInt32         GaoULong32;
    typedef GaoInt32          GaoSLong32;
    typedef float             GaoReal32;
    typedef double            GaoReal64;

    typedef char*             GaoCharPtr;
    typedef const char*       GaoConstCharPtr;
    typedef signed char*      GaoChar8Ptr;
    typedef unsigned char*    GaoUChar8Ptr;
    typedef signed char*      GaoInt8Ptr;
    typedef unsigned char*    GaoUInt8Ptr;
    typedef signed short*     GaoInt16Ptr;
    typedef unsigned short*   GaoUInt16Ptr;
    typedef signed int*       GaoInt32Ptr;
    typedef unsigned int*     GaoUInt32Ptr;
    typedef __int64*          GaoInt64Ptr;
    typedef unsigned __int64* GaoUInt64Ptr;

    typedef unsigned char*    GaoBytePtr;
    typedef GaoUInt32*        GaoBoolPtr;
    typedef GaoUInt32*        GaoULongPtr;
    typedef GaoInt32*         GaoLongPtr;
    typedef GaoUInt32*        GaoULong32Ptr;
    typedef GaoInt32*         GaoSLong32Ptr;
    typedef float*            GaoReal32Ptr;
    typedef double*           GaoReal64Ptr;
    typedef void              GaoVoid;
    typedef void*             GaoVoidPtr;

#else // GAO_PLATFORM_MACOSX

    typedef char              GaoChar;
    typedef signed char       GaoChar8;
    typedef unsigned char     GaoUChar8;
    typedef signed char       GaoInt8;
    typedef unsigned char     GaoUInt8;
    typedef signed short      GaoInt16;
    typedef unsigned short    GaoUInt16;
    typedef signed int        GaoInt32;
    typedef unsigned int      GaoUInt32;
    //typedef __int64           GaoInt64;
    //typedef unsigned __int64  GaoUInt64;

    typedef unsigned char     GaoByte;
    typedef bool              GaoBool;
    typedef GaoInt32          GaoLong;
    typedef GaoUInt32         GaoULong;
    typedef GaoUInt32         GaoULong32;
    typedef GaoInt32          GaoSLong32;
    typedef float             GaoReal32;
    typedef double            GaoReal64;

    typedef char*             GaoCharPtr;
    typedef const char*       GaoConstCharPtr;
    typedef signed char*      GaoChar8Ptr;
    typedef unsigned char*    GaoUChar8Ptr;
    typedef signed char*      GaoInt8Ptr;
    typedef unsigned char*    GaoUInt8Ptr;
    typedef signed short*     GaoInt16Ptr;
    typedef unsigned short*   GaoUInt16Ptr;
    typedef signed int*       GaoInt32Ptr;
    typedef unsigned int*     GaoUInt32Ptr;
    //typedef __int64*          GaoInt64Ptr;
    //typedef unsigned __int64* GaoUInt64Ptr;

    typedef unsigned char*    GaoBytePtr;
    typedef GaoUInt32*        GaoBoolPtr;
    typedef GaoUInt32*        GaoULongPtr;
    typedef GaoInt32*         GaoLongPtr;
    typedef GaoUInt32*        GaoULong32Ptr;
    typedef GaoInt32*         GaoSLong32Ptr;
    typedef float*            GaoReal32Ptr;
    typedef double*           GaoReal64Ptr;
    typedef void              GaoVoid;
    typedef void*             GaoVoidPtr;

#endif



typedef std::string           GaoString;

#ifdef _UNICODE
    typedef std::wstring      GaoTString;
#else
    typedef std::string       GaoTString;
#endif

#define GaoVector     std::vector
#define GaoMap        std::map
#define GaoList       std::list
#define GaoDeque      std::deque



//#ifdef GAO_PLATFORM_WINTEL32

	#ifdef TRUE
	#undef TRUE
	#endif
	#define TRUE 1

	#ifdef FALSE
	#undef FALSE
	#endif
	#define FALSE 0

	#ifdef NULL
	#undef NULL
	#endif
	#define NULL 0

//#else // GAO_PLATFORM_MACOSX
/*
	#ifdef TRUE
	#undef TRUE
	#endif
	#define TRUE YES

	#ifdef FALSE
	#undef FALSE
	#endif
	#define FALSE NO

	#ifdef NULL
	#undef NULL
	#endif
	#define NULL nil
*/
//#endif



/**
 * @brief Integral constants to types template
 */
template<int V>
struct Int2Type
{
    enum { value = V };
};

#endif
