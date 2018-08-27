/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2018, Team Shanghai Dream Equinox
*     All rights reserved.
*
* @file		ConvallariaLua.cpp
* @brief	This Program is C/C++ -- Lua Script Project.
* @author	alopex
* @version	v1.00a
* @date		2018-08-27
*/
#include "ConvallariaLua.h"

//C/C++ -- Lua Script Dynamic Link Library.

//------------------------------------------------------------------
// @Function:	 CConvallariaLua()
// @Purpose: CConvallariaLua���캯��
// @Since: v1.00a
// @Para: const char* szFile	// Lua�ļ�·��(���)
// @Return: None
//------------------------------------------------------------------
CConvallariaLua::CConvallariaLua(const char* szFile)
{
	L = luaL_newstate();
	memset(m_chFile, 0, MAX_PATH);
	memset(m_chPath, 0, MAX_PATH);
	memcpy_s(m_chFile, MAX_PATH, szFile, strlen(szFile));
}

//------------------------------------------------------------------
// @Function:	 ~CConvallariaLua()
// @Purpose: CConvallariaLua��������
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
CConvallariaLua::~CConvallariaLua()
{
	if (L)
	{
		lua_close(L);
	}
}

//------------------------------------------------------------------
// @Function:	CConvallariaLuaGetLua()
// @Purpose: CConvallariaLua��ȡLua�����
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
lua_State *CONVALLARIALUA_CALLMODE CConvallariaLua::CConvallariaLuaGetLua() const
{
	return L;
}

//------------------------------------------------------------------
// @Function:	 ConvallariaLuaInit()
// @Purpose: CConvallariaLua��ʼ��
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
BOOL CONVALLARIALUA_CALLMODE CConvallariaLua::ConvallariaLuaInit()
{
	char chArr[MAX_PATH] = { 0 };
	char* pTemp = NULL;

	GetModuleFileNameA(NULL, chArr, MAX_PATH);
	pTemp = strrchr(chArr, '\\');
	if (pTemp != NULL)
	{
		*pTemp = '\0';
	}

	strcat_s(chArr, "\\");
	strcat_s(chArr, m_chFile);
	memcpy_s(m_chPath, MAX_PATH, chArr, MAX_PATH);

	int nRet = -1;

	nRet = luaL_loadfile(L, chArr);
	if (nRet)
	{
		return FALSE;
	}

	nRet = lua_pcall(L, 0, 0, 0);
	if (nRet)
	{
		return FALSE;
	}

	return TRUE;
}

//------------------------------------------------------------------
// @Function:	 ConvallariaLuaGetGlobalInt()
// @Purpose: CConvallariaLua��ȡȫ�ֱ���(Int)
// @Since: v1.00a
// @Para: const char * szVar	// Lua�ַ�����
// @Para: int & nValue			// Int����ֵ
// @Return: None
//------------------------------------------------------------------
void CONVALLARIALUA_CALLMODE CConvallariaLua::ConvallariaLuaGetGlobalInt(const char * szVar, int & nValue)
{
	lua_getglobal(L, szVar);
	nValue = (int)lua_tonumber(L, -1);
}

//------------------------------------------------------------------
// @Function:	 ConvallariaLuaGetGlobalFloat()
// @Purpose: CConvallariaLua��ȡȫ�ֱ���(Float)
// @Since: v1.00a
// @Para: const char * szVar	// Lua�ַ�����
// @Para: float & fValue		// Float������ֵ
// @Return: None
//------------------------------------------------------------------
void CONVALLARIALUA_CALLMODE CConvallariaLua::ConvallariaLuaGetGlobalFloat(const char * szVar, float & fValue)
{
	lua_getglobal(L, szVar);
	fValue = (float)lua_tonumber(L, -1);
}

//------------------------------------------------------------------
// @Function:	 ConvallariaLuaGetGlobalDouble()
// @Purpose: CConvallariaLua��ȡȫ�ֱ���(Double)
// @Since: v1.00a
// @Para: const char * szVar	// Lua�ַ�����
// @Para: double & dValue		// Doublt˫����ֵ
// @Return: None
//------------------------------------------------------------------
void CONVALLARIALUA_CALLMODE CConvallariaLua::ConvallariaLuaGetGlobalDouble(const char * szVar, double & dValue)
{
	lua_getglobal(L, szVar);
	dValue = (double)lua_tonumber(L, -1);
}
