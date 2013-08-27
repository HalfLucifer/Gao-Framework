/**
 * @file LuaScriptManager.hpp
 * @author Jheng Wei Ciao
 *
 * Lua implementation for ScriptManager.
 *
 */
#ifndef GAO_FRAMEWORK_LUASCRIPTMANAGER_H
#define GAO_FRAMEWORK_LUASCRIPTMANAGER_H

#include "DataType.hpp"
#include "Singleton.hpp"
#include "LuaScriptDefine.hpp"

#define g_ScriptManager Gao::Framework::LuaScriptManager::GetSingletonPointer()



namespace Gao
{
    namespace Framework
    {
        /**
         * @brief Lua implementation for ScriptManager.
         */
		class LuaScriptManager : public Singleton<LuaScriptManager>
        {

#ifdef GAO_SCRIPT_LUA_IMPLEMENTATION

        public:

            /**
             * @brief Class default constructor.
             */
            LuaScriptManager();

            /**
             * @brief Class destructor.
             */
            //virtual ~LuaScriptManager();
			~LuaScriptManager();

			LuaState GetLuaState() const;

			GaoVoid SetBasePath(GaoString& basePath);

            GaoBool Create();

			GaoVoid RegisterLib(GaoConstCharPtr libName, const luaL_Reg* libList);

            GaoBool RunFromFile(GaoString& fileName);

            GaoBool RunFromFullPathFile(GaoString& fileName);

            GaoBool RunFromString(GaoConstCharPtr value);

            GaoBool CallFunction();

            GaoBool CallFunction(GaoConstCharPtr functionName);

            GaoBool CallFunction(GaoString& functionName);

			GaoBool GetFunction(GaoConstCharPtr functionName);

			GaoBool GetFunction(GaoString& functionName);

            GaoVoid PushValue(GaoInt16 value);

            GaoVoid PushValue(GaoInt32 value);

            GaoVoid PushValue(GaoUInt16 value);

            GaoVoid PushValue(GaoUInt32 value);

            GaoVoid PushValue(GaoReal32 value);

            GaoVoid PushValue(GaoBool value);

            GaoVoid PushValue(GaoConstCharPtr value);

            GaoVoid PushValue(GaoString& value);

            GaoVoid PushValue(GaoVoidPtr value);

            GaoBool GetTable(GaoConstCharPtr tableName);

            GaoVoid GetValue(GaoConstCharPtr variableName, GaoInt16& value);

            GaoVoid GetValue(GaoConstCharPtr variableName, GaoInt32& value);

            GaoVoid GetValue(GaoConstCharPtr variableName, GaoUInt16& value);

            GaoVoid GetValue(GaoConstCharPtr variableName, GaoUInt32& value);

            GaoVoid GetValue(GaoConstCharPtr variableName, GaoReal32& value);

            GaoVoid GetValue(GaoConstCharPtr variableName, GaoBool& value);

            GaoVoid GetValue(GaoConstCharPtr variableName, GaoString& value);

            GaoVoid GetValue(GaoConstCharPtr variableName, GaoVoidPtr& value);

            GaoVoid GetValueAt(GaoInt32 index, GaoInt16& value);

            GaoVoid GetValueAt(GaoInt32 index, GaoInt32& value);

            GaoVoid GetValueAt(GaoInt32 index, GaoUInt16& value);

            GaoVoid GetValueAt(GaoInt32 index, GaoUInt32& value);

            GaoVoid GetValueAt(GaoInt32 index, GaoReal32& value);

            GaoVoid GetValueAt(GaoInt32 index, GaoBool& value);

            GaoVoid GetValueAt(GaoInt32 index, GaoString& value);

            GaoVoid GetValueAt(GaoInt32 index, GaoVoidPtr& value);

            GaoVoid GetValueFromTable(GaoConstCharPtr tableName, GaoConstCharPtr variableName, GaoInt16& value);

            GaoVoid GetValueFromTable(GaoConstCharPtr tableName, GaoConstCharPtr variableName, GaoInt32& value);

            GaoVoid GetValueFromTable(GaoConstCharPtr tableName, GaoConstCharPtr variableName, GaoUInt16& value);

            GaoVoid GetValueFromTable(GaoConstCharPtr tableName, GaoConstCharPtr variableName, GaoUInt32& value);

            GaoVoid GetValueFromTable(GaoConstCharPtr tableName, GaoConstCharPtr variableName, GaoReal32& value);

            GaoVoid GetValueFromTable(GaoConstCharPtr tableName, GaoConstCharPtr variableName, GaoBool& value);

            GaoVoid GetValueFromTable(GaoConstCharPtr tableName, GaoConstCharPtr variableName, GaoString& value);

            GaoVoid GetValueFromTable(GaoConstCharPtr tableName, GaoConstCharPtr variableName, GaoVoidPtr& value);


		private:

			GaoVoid LogError(const GaoString& errorSource, GaoString& errorName);


        private:

            lua_State*      m_MasterState;
			GaoString       m_BasePath;
            GaoInt32        m_ArgumentsCount;
			GaoString		m_CurrentFunction;
            GaoString       m_WorkingFullPath;

			static const GaoInt32 LUA_CALL_SUCCESS = 0;
			static const GaoInt32 LUA_TYPE_MATCHED = 1;
			static const GaoInt32 LUA_GETTABLE_INDEX = -2;

#endif // End of GAO_SCRIPT_LUA_IMPLEMENTATION

        };
    }
}

#endif
