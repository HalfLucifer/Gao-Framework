#include "LuaScriptManager.hpp"
#include "Logger.hpp"
#include "FileSystem.hpp"



namespace Gao
{
    namespace Framework
    {

#ifdef GAO_SCRIPT_LUA_IMPLEMENTATION

		static const GaoString SCRIPT_SOURCE_FILE = "FILE";
		static const GaoString SCRIPT_SOURCE_STRING = "STRING";
		static const GaoString SCRIPT_SOURCE_FUNCTION = "FUNCTION";



        LuaScriptManager::LuaScriptManager()
            :
            m_MasterState(NULL), m_ArgumentsCount(0)
        {

        }

        LuaScriptManager::~LuaScriptManager()
        {
            lua_close(m_MasterState);
            m_MasterState = NULL;
        }

		LuaState LuaScriptManager::GetLuaState() const
		{
			return m_MasterState;
		}

		GaoVoid LuaScriptManager::SetBasePath(GaoString& basePath)
		{
			m_BasePath = basePath;
		}

        GaoBool LuaScriptManager::Create()
        {
            m_MasterState = luaL_newstate();

            if (m_MasterState != NULL)
            {
                luaL_openlibs(m_MasterState);
                

#ifdef GAO_SCRIPT_LUABIND_IMPLEMENTATION
				luabind::open(m_MasterState);
#endif
                
#ifdef GAO_SCRIPT_LUABINS_IMPLEMENTATION
                luaopen_luabins(m_MasterState);
#endif

                return TRUE;
            }

			g_Logger->Log(GAO_SCRIPT, "Failed to create Lua State.");
            return FALSE;
        }

		GaoVoid LuaScriptManager::RegisterLib(GaoConstCharPtr libName, const luaL_Reg* libList)
		{
			luaL_register(m_MasterState, libName, libList);
		}

        GaoBool LuaScriptManager::RunFromFile(GaoString& fileName)
        {
            m_WorkingFullPath = fileName;
            g_FileSystem->MakeFullPath(m_WorkingFullPath);
            
            if (luaL_dofile(m_MasterState, m_WorkingFullPath.c_str()) != LUA_CALL_SUCCESS)
            {
				LogError(SCRIPT_SOURCE_FILE, fileName);
                return FALSE;
            }

            return TRUE;
        }

        GaoBool LuaScriptManager::RunFromFullPathFile(GaoString& fileName)
        {
            if (luaL_dofile(m_MasterState, fileName.c_str()) != LUA_CALL_SUCCESS)
            {
				LogError(SCRIPT_SOURCE_FILE, fileName);
                return FALSE;
            }

            return TRUE;
        }

        GaoBool LuaScriptManager::RunFromString(GaoConstCharPtr value)
        {
            if (luaL_dostring(m_MasterState, value) != LUA_CALL_SUCCESS)
            {
				GaoString text = value;
				LogError(SCRIPT_SOURCE_STRING, text);
                return FALSE;
            }

            return TRUE;
        }

        GaoBool LuaScriptManager::CallFunction()
        {
            if (lua_pcall(m_MasterState, m_ArgumentsCount, LUA_MULTRET, 0) != LUA_CALL_SUCCESS)
            {
				LogError(SCRIPT_SOURCE_FUNCTION, m_CurrentFunction);
                assert(0);
                return FALSE;
            }

            return TRUE;
        }

        GaoBool LuaScriptManager::CallFunction(GaoConstCharPtr functionName)
        {
			m_CurrentFunction = functionName;

            lua_settop(m_MasterState, 0);
            lua_getglobal(m_MasterState, functionName);

#ifdef GAO_DEBUG
            if (lua_isfunction(m_MasterState, lua_gettop(m_MasterState)) != LUA_TYPE_MATCHED)
            {
				g_Logger->Log(GAO_SCRIPT, "Target is not a valid Lua function: %s", m_CurrentFunction.c_str());
                return FALSE;
            }
#endif

            if (lua_pcall(m_MasterState, 0, LUA_MULTRET, 0) != LUA_CALL_SUCCESS)
            {
				LogError(SCRIPT_SOURCE_FUNCTION, m_CurrentFunction);
                assert(0);
                return FALSE;
            }

            return TRUE;
        }

        GaoBool LuaScriptManager::CallFunction(GaoString& functionName)
        {
			m_CurrentFunction = functionName;

            lua_settop(m_MasterState, 0);
            lua_getglobal(m_MasterState, functionName.c_str());

#ifdef GAO_DEBUG
            if (lua_isfunction(m_MasterState, lua_gettop(m_MasterState)) != LUA_TYPE_MATCHED)
            {
				g_Logger->Log(GAO_SCRIPT, "Target is not a valid Lua function: %s", m_CurrentFunction.c_str());
                return FALSE;
            }
#endif
            
            if (lua_pcall(m_MasterState, 0, LUA_MULTRET, 0) != LUA_CALL_SUCCESS)
            {
				LogError(SCRIPT_SOURCE_FUNCTION, m_CurrentFunction);
                assert(0);
                return FALSE;
            }

            return TRUE;
        }

		GaoBool LuaScriptManager::GetFunction(GaoConstCharPtr functionName)
		{
			lua_settop(m_MasterState, 0);
			lua_getglobal(m_MasterState, functionName);

#ifdef GAO_DEBUG
			if (lua_isfunction(m_MasterState, lua_gettop(m_MasterState)) == LUA_TYPE_MATCHED)
			{
				m_ArgumentsCount = 0;
				m_CurrentFunction = functionName;
				return TRUE;
			}

			return FALSE;
#else
            m_ArgumentsCount = 0;
            m_CurrentFunction = functionName;
            return TRUE;
#endif
		}

		GaoBool LuaScriptManager::GetFunction(GaoString& functionName)
		{
			lua_settop(m_MasterState, 0);
			lua_getglobal(m_MasterState, functionName.c_str());

#ifdef GAO_DEBUG
			if (lua_isfunction(m_MasterState, lua_gettop(m_MasterState)) == LUA_TYPE_MATCHED)
			{
				m_ArgumentsCount = 0;
				m_CurrentFunction = functionName;
				return TRUE;
			}

			return FALSE;
#else
            m_ArgumentsCount = 0;
            m_CurrentFunction = functionName;
            return TRUE;
#endif
		}

        GaoVoid LuaScriptManager::PushValue(GaoInt16 value)
        {
            lua_pushnumber(m_MasterState, value);
            ++ m_ArgumentsCount;
        }

        GaoVoid LuaScriptManager::PushValue(GaoInt32 value)
        {
            lua_pushnumber(m_MasterState, value);
            ++ m_ArgumentsCount;
        }

        GaoVoid LuaScriptManager::PushValue(GaoUInt16 value)
        {
            lua_pushnumber(m_MasterState, value);
            ++ m_ArgumentsCount;
        }

        GaoVoid LuaScriptManager::PushValue(GaoUInt32 value)
        {
            lua_pushnumber(m_MasterState, value);
            ++ m_ArgumentsCount;
        }

        GaoVoid LuaScriptManager::PushValue(GaoReal32 value)
        {
            lua_pushnumber(m_MasterState, value);
            ++ m_ArgumentsCount;
        }

        GaoVoid LuaScriptManager::PushValue(GaoBool value)
        {
            lua_pushboolean(m_MasterState, value);
            ++ m_ArgumentsCount;
        }

        GaoVoid LuaScriptManager::PushValue(GaoConstCharPtr value)
        {
            lua_pushstring(m_MasterState, value);
            ++ m_ArgumentsCount;
        }

        GaoVoid LuaScriptManager::PushValue(GaoString& value)
        {
            lua_pushstring(m_MasterState, value.c_str());
            ++ m_ArgumentsCount;
        }

        GaoVoid LuaScriptManager::PushValue(GaoVoidPtr value)
        {
            if (value != NULL)
            {
                lua_pushlightuserdata(m_MasterState, value);
            }
            else
            {
                lua_pushnil(m_MasterState);
            }
            ++ m_ArgumentsCount;
        }

        GaoBool LuaScriptManager::GetTable(GaoConstCharPtr tableName)
        {
            lua_getglobal(m_MasterState, tableName);

            if (lua_istable(m_MasterState, lua_gettop(m_MasterState)) == LUA_TYPE_MATCHED)
            {
                return TRUE;
            }

            return FALSE;
        }

        GaoVoid LuaScriptManager::GetValue(GaoConstCharPtr variableName, GaoInt16& value)
        {
            lua_getglobal(m_MasterState, variableName);
            value = static_cast<GaoInt16>(luaL_checkint(m_MasterState, lua_gettop(m_MasterState)));
        }

        GaoVoid LuaScriptManager::GetValue(GaoConstCharPtr variableName, GaoInt32& value)
        {
            lua_getglobal(m_MasterState, variableName);
            value = luaL_checkint(m_MasterState, lua_gettop(m_MasterState));
        }

        GaoVoid LuaScriptManager::GetValue(GaoConstCharPtr variableName, GaoUInt16& value)
        {
            lua_getglobal(m_MasterState, variableName);
            value = static_cast<GaoUInt16>(luaL_checkint(m_MasterState, lua_gettop(m_MasterState)));
        }

        GaoVoid LuaScriptManager::GetValue(GaoConstCharPtr variableName, GaoUInt32& value)
        {
            lua_getglobal(m_MasterState, variableName);
            value = static_cast<GaoUInt32>(luaL_checkint(m_MasterState, lua_gettop(m_MasterState)));
        }

        GaoVoid LuaScriptManager::GetValue(GaoConstCharPtr variableName, GaoReal32& value)
        {
            lua_getglobal(m_MasterState, variableName);
            value = static_cast<GaoReal32>(luaL_checknumber(m_MasterState, lua_gettop(m_MasterState)));
        }

        GaoVoid LuaScriptManager::GetValue(GaoConstCharPtr variableName, GaoBool& value)
        {
            lua_getglobal(m_MasterState, variableName);
            if (lua_toboolean(m_MasterState, lua_gettop(m_MasterState)) != 0)
            {
                value = TRUE;
            }
            else
            {
                value = FALSE;
            }
        }

        GaoVoid LuaScriptManager::GetValue(GaoConstCharPtr variableName, GaoString& value)
        {
            lua_getglobal(m_MasterState, variableName);
            value = luaL_checkstring(m_MasterState, lua_gettop(m_MasterState));
        }

        GaoVoid LuaScriptManager::GetValue(GaoConstCharPtr variableName, GaoVoidPtr& value)
        {
            lua_getglobal(m_MasterState, variableName);
            value = lua_touserdata(m_MasterState, lua_gettop(m_MasterState));
        }

        GaoVoid LuaScriptManager::GetValueAt(GaoInt32 index, GaoInt16& value)
        {
            value = static_cast<GaoInt16>(luaL_checkint(m_MasterState, index));
        }

        GaoVoid LuaScriptManager::GetValueAt(GaoInt32 index, GaoInt32& value)
        {
            value = luaL_checkint(m_MasterState, index);
        }

        GaoVoid LuaScriptManager::GetValueAt(GaoInt32 index, GaoUInt16& value)
        {
            value = static_cast<GaoUInt16>(luaL_checkint(m_MasterState, index));
        }

        GaoVoid LuaScriptManager::GetValueAt(GaoInt32 index, GaoUInt32& value)
        {
            value = static_cast<GaoUInt32>(luaL_checkint(m_MasterState, index));
        }

        GaoVoid LuaScriptManager::GetValueAt(GaoInt32 index, GaoReal32& value)
        {
            value = static_cast<GaoReal32>(luaL_checknumber(m_MasterState, index));
        }

        GaoVoid LuaScriptManager::GetValueAt(GaoInt32 index, GaoBool& value)
        {
            if (lua_toboolean(m_MasterState, index) != 0)
            {
                value = TRUE;
            }
            else
            {
                value = FALSE;
            }
        }

        GaoVoid LuaScriptManager::GetValueAt(GaoInt32 index, GaoString& value)
        {
            value = luaL_checkstring(m_MasterState, index);
        }

        GaoVoid LuaScriptManager::GetValueAt(GaoInt32 index, GaoVoidPtr& value)
        {
            value = lua_touserdata(m_MasterState, index);
        }

        GaoVoid LuaScriptManager::GetValueFromTable(GaoConstCharPtr tableName, GaoConstCharPtr variableName,
            GaoInt16& value)
        {
            lua_getglobal(m_MasterState, tableName);

            if (lua_istable(m_MasterState, lua_gettop(m_MasterState)) == LUA_TYPE_MATCHED)
            {
                lua_pushstring(m_MasterState, variableName);
                lua_gettable(m_MasterState, LUA_GETTABLE_INDEX);
                value = static_cast<GaoInt16>(luaL_checkint(m_MasterState, lua_gettop(m_MasterState)));
            }

            lua_pop(m_MasterState, 1);
        }

        GaoVoid LuaScriptManager::GetValueFromTable(GaoConstCharPtr tableName, GaoConstCharPtr variableName,
            GaoInt32& value)
        {
            lua_getglobal(m_MasterState, tableName);

            if (lua_istable(m_MasterState, lua_gettop(m_MasterState)) == LUA_TYPE_MATCHED)
            {
                lua_pushstring(m_MasterState, variableName);
                lua_gettable(m_MasterState, LUA_GETTABLE_INDEX);
                value = luaL_checkint(m_MasterState, lua_gettop(m_MasterState));
            }

            lua_pop(m_MasterState, 1);
        }

        GaoVoid LuaScriptManager::GetValueFromTable(GaoConstCharPtr tableName, GaoConstCharPtr variableName,
            GaoUInt16& value)
        {
            lua_getglobal(m_MasterState, tableName);

            if (lua_istable(m_MasterState, lua_gettop(m_MasterState)) == LUA_TYPE_MATCHED)
            {
                lua_pushstring(m_MasterState, variableName);
                lua_gettable(m_MasterState, LUA_GETTABLE_INDEX);
                value = static_cast<GaoUInt16>(luaL_checkint(m_MasterState, lua_gettop(m_MasterState)));
            }

            lua_pop(m_MasterState, 1);
        }

        GaoVoid LuaScriptManager::GetValueFromTable(GaoConstCharPtr tableName, GaoConstCharPtr variableName,
            GaoUInt32& value)
        {
            lua_getglobal(m_MasterState, tableName);

            if (lua_istable(m_MasterState, lua_gettop(m_MasterState)) == LUA_TYPE_MATCHED)
            {
                lua_pushstring(m_MasterState, variableName);
                lua_gettable(m_MasterState, LUA_GETTABLE_INDEX);
                value = static_cast<GaoUInt32>(luaL_checkint(m_MasterState, lua_gettop(m_MasterState)));
            }

            lua_pop(m_MasterState, 1);
        }

        GaoVoid LuaScriptManager::GetValueFromTable(GaoConstCharPtr tableName, GaoConstCharPtr variableName,
            GaoReal32& value)
        {
            lua_getglobal(m_MasterState, tableName);

            if (lua_istable(m_MasterState, lua_gettop(m_MasterState)) == LUA_TYPE_MATCHED)
            {
                lua_pushstring(m_MasterState, variableName);
                lua_gettable(m_MasterState, LUA_GETTABLE_INDEX);
                value = static_cast<GaoReal32>(luaL_checknumber(m_MasterState, lua_gettop(m_MasterState)));
            }

            lua_pop(m_MasterState, 1);
        }

        GaoVoid LuaScriptManager::GetValueFromTable(GaoConstCharPtr tableName, GaoConstCharPtr variableName,
            GaoBool& value)
        {
            lua_getglobal(m_MasterState, tableName);

            if (lua_istable(m_MasterState, lua_gettop(m_MasterState)) == LUA_TYPE_MATCHED)
            {
                lua_pushstring(m_MasterState, variableName);
                lua_gettable(m_MasterState, LUA_GETTABLE_INDEX);

                if (lua_toboolean(m_MasterState, lua_gettop(m_MasterState)) != 0)
                {
                    value = TRUE;
                }
                else
                {
                    value = FALSE;
                }
            }

            lua_pop(m_MasterState, 1);
        }

        GaoVoid LuaScriptManager::GetValueFromTable(GaoConstCharPtr tableName, GaoConstCharPtr variableName,
            GaoString& value)
        {
            lua_getglobal(m_MasterState, tableName);

            if (lua_istable(m_MasterState, lua_gettop(m_MasterState)) == LUA_TYPE_MATCHED)
            {
                lua_pushstring(m_MasterState, variableName);
                lua_gettable(m_MasterState, LUA_GETTABLE_INDEX);
                value = luaL_checkstring(m_MasterState, lua_gettop(m_MasterState));
            }

            lua_pop(m_MasterState, 1);
        }

        GaoVoid LuaScriptManager::GetValueFromTable(GaoConstCharPtr tableName, GaoConstCharPtr variableName,
            GaoVoidPtr& value)
        {
            lua_getglobal(m_MasterState, tableName);

            if (lua_istable(m_MasterState, lua_gettop(m_MasterState)) == LUA_TYPE_MATCHED)
            {
                lua_pushstring(m_MasterState, variableName);
                lua_gettable(m_MasterState, LUA_GETTABLE_INDEX);
                value = lua_touserdata(m_MasterState, lua_gettop(m_MasterState));
            }

            lua_pop(m_MasterState, 1);
        }

		GaoVoid LuaScriptManager::LogError(const GaoString& errorSource, GaoString& errorName)
		{
			g_Logger->Log(
				GAO_SCRIPT, "Failed to run from %s: %s\n  => %s",
				errorSource.c_str(), errorName.c_str(), luaL_checkstring(m_MasterState, lua_gettop(m_MasterState)));
		}

#endif // End of GAO_SCRIPT_LUA_IMPLEMENTATION

    }
}
