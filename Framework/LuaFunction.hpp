/**
 * @file LuaFunction.hpp
 * @author Jheng Wei Ciao
 *
 * All binding function for Lua.
 *
 */
#ifndef GAO_FRAMEWORK_LUAFUNCTION_H
#define GAO_FRAMEWORK_LUAFUNCTION_H

#include "DataType.hpp"
#include "LuaScriptDefine.hpp"



namespace Gao
{
    namespace Framework
    {
#ifdef GAO_SCRIPT_LUA_IMPLEMENTATION

		GaoBool RegisterLuaFunctions(LuaState state);
        
        GaoBool RegisterLuaCoreFunctions(LuaState state);

        GaoBool RegisterLuaGraphicsFunctions(LuaState state);

#endif
    }
}

#endif
