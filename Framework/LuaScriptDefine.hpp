/**
 * @file ScriptDefine.hpp
 * @author Jheng Wei Ciao
 *
 * Defines for script usage.
 *
 */
#ifndef GAO_FRAMEWORK_LUASCRIPTDEFINE_H
#define GAO_FRAMEWORK_LUASCRIPTDEFINE_H

#define GAO_SCRIPT_LUA_IMPLEMENTATION
#define GAO_SCRIPT_LUABIND_IMPLEMENTATION
#define GAO_SCRIPT_LUABINS_IMPLEMENTATION


#ifdef GAO_SCRIPT_LUA_IMPLEMENTATION
	//#include <lua.hpp>
    extern "C"
    {
        #include "lua.h"
        #include "lualib.h"
        #include "lauxlib.h"
#ifdef GAO_SCRIPT_LUABINS_IMPLEMENTATION
        #include "luabins.h"
#endif
    }

	typedef lua_State* LuaState;
#endif

#ifdef GAO_SCRIPT_LUABIND_IMPLEMENTATION
    #ifdef nil
        #undef nil
        #include <luabind/luabind.hpp>
        #define nil NULL
    #else    
        #include <luabind/luabind.hpp>
    #endif
#endif

#endif
