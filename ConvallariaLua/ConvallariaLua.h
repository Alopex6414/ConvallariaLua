/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2018, Team Shanghai Dream Equinox
*     All rights reserved.
*
* @file		ConvallariaLua.h
* @brief	This Program is C/C++ -- Lua Script Project.
* @author	alopex
* @version	v1.00a
* @date		2018-08-27
*/
#pragma once

#ifndef __CONVALLARIALUA_H_
#define __CONVALLARIALUA_H_

//Include Windows Header File
#include <Windows.h>

//Include C/C++ Running Header File
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <mmreg.h>
#include <wchar.h>
#include <tchar.h>
#include <time.h>
#include <mmsystem.h>

//Include Lua Common Header File
#include "lua.hpp"

//Include Lua Library
#pragma comment(lib, "liblua")

//Macro Definition
#ifdef CONVALLARIALUA_EXPORTS
#define CONVALLARIALUA_API	__declspec(dllexport)
#else
#define CONVALLARIALUA_API	__declspec(dllimport)
#endif

#define CONVALLARIALUA_CALLMODE	__stdcall

//Class Definition
class CONVALLARIALUA_API CConvallariaLua
{
private:
	lua_State * L;

private:
	char m_chFile[MAX_PATH];
	char m_chPath[MAX_PATH];

public:
	CConvallariaLua(const char* szFile);			//CConvallariaLua Construction(构造函数)
	~CConvallariaLua();								//CConvallariaLua Destruction(析构函数)

	lua_State* CONVALLARIALUA_CALLMODE CConvallariaLuaGetLua() const;		//CConvallariaLua Get Lua(获取Lua虚拟机)

	BOOL CONVALLARIALUA_CALLMODE ConvallariaLuaInit();						//CConvallariaLua Initialize(初始化函数)

	void CONVALLARIALUA_CALLMODE ConvallariaLuaGetGlobalInt(const char* szVar, int& nValue);			//CConvallariaLua Get Global Int(获取全局整型)
	void CONVALLARIALUA_CALLMODE ConvallariaLuaGetGlobalFloat(const char* szVar, float& fValue);		//CConvallariaLua Get Global Float(获取全局浮点型)
	void CONVALLARIALUA_CALLMODE ConvallariaLuaGetGlobalDouble(const char* szVar, double& dValue);		//CConvallariaLua Get Global Double(获取全局双精度)

};

#endif // !__CONVALLARIALUA_H_
