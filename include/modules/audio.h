/*
** audio.h
** @brief	: Audio component control
** @warn	: Must be initialized for output
*/

#pragma once

namespace Audio
{
	void Initialize();

	//Löve2D Functions

	int Play(lua_State * L);
	int Stop(lua_State * L);
	
	int SetVolume(lua_State * L);

	//End Löve2D Functions

	void Exit();
	
	int Register(lua_State * L);
}