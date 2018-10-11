#pragma once

//Error/Quit
extern bool ERROR;
extern bool LOVE_QUIT;
extern FILE * logFile;

extern "C"
{
    #include <lua.h>
    #include <lualib.h>
    #include <lauxlib.h>

    #include <compat-5.2.h>
    #include <luaobj.h>
}

//Libs
#include <curl/curl.h>
#include <SDL.h>
#include <SDL_mixer.h>

//C++ headers
#include <map>
#include <queue>

//C headers
#include <errno.h>
#include <malloc.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

using std::string;
using std::vector;
using std::pair;
using std::make_pair;
using std::map;
using std::queue;

#define LOG(fmt, ...) \
    fprintf(logFile, "%s:%d:\n" fmt "\n", __PRETTY_FUNCTION__, __LINE__, ## __VA_ARGS__)