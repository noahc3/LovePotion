extern "C" 
{
    #include <lua.h>
    #include <lualib.h>
    #include <lauxlib.h>

    #include <compat-5.2.h>
    #include <luaobj.h>
}

#include <map>
#include <vector>
#include <stdarg.h>

#include <switch.h>

#include "common/types.h"
#include "common/variant.h"
#include "common/util.h"

void love_getfield(lua_State * L, const char * field)
{
    lua_getfield(L, LUA_GLOBALSINDEX, "love");
    lua_getfield(L, -1, field);
    lua_remove(L, -2);
}

int love_preload(lua_State * L, lua_CFunction function, const char * name)
{
    lua_getglobal(L, "package");
    lua_getfield(L, -1, "preload");
    lua_pushcfunction(L, function);
    lua_setfield(L, -2, name);
    lua_pop(L, 2);

    return 0;
}

void love_register(lua_State * L, int index, void * object)
{
    love_get_registry(L, OBJECTS);

    lua_pushlightuserdata(L, object);    //light userdata key
    lua_pushvalue(L, index);                //push the userdata value to the key
    lua_settable(L, -3);                //set the taaable (╯°□°）╯︵ ┻━┻

    lua_setfield(L, LUA_REGISTRYINDEX, "_loveobjects");

    //lua_pop(L, 1);
    printf("Registered %p to _loveobjects!\n", object);
}

void love_push_userdata(lua_State * L, void * object)
{
    if (!object)
        return;

    love_get_registry(L, OBJECTS);
    lua_pushlightuserdata(L, object);
    lua_gettable(L, -2);
    lua_remove(L, -2);
}

bool love_is_registered(lua_State * L, void * object)
{
    bool valid = true;

    if (!object)
        return false;

    love_get_registry(L, OBJECTS);
    lua_pushlightuserdata(L, object);
    lua_gettable(L, -2);
    lua_remove(L, -2);

    if (lua_isnil(L, 2))
        valid = false;

    lua_pop(L, 1);

    return valid;
}

int love_get_registry(lua_State * L, REGISTRY registry)
{
    switch(registry)
    {
        case OBJECTS:
            lua_getfield(L, LUA_REGISTRYINDEX, "_loveobjects");
            return 1;
        default:
            return luaL_error(L, "Attempted to use invalid registry."); 
    }
}

double clamp(double low, double value, double high)
{
    return std::min(high, std::max(low, value));
}