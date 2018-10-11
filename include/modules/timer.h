/*
** modules/timer.h
** @brief : Used for time keeping
*/

#pragma once

#ifndef CPU_TICKS_PER_MSEC
    #define CPU_TICKS_PER_MSEC 19200 //-> 19200000.0f / 1000.0f
#endif

namespace Timer
{
    //Löve2D Functions

    int GetFPS(lua_State * L);
    int GetTime(lua_State * L);
    int GetDelta(lua_State * L);

    int Sleep(lua_State * L);
    
    int Step(lua_State * L);

    //End Löve2D Functions

    float GetOSTime();

    void Tick();

    int Register(lua_State * L);
}