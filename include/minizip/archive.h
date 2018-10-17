#ifndef NX_SHELL_ARCHIVE_H
#define NX_SHELL_ARCHIVE_H

#include <switch.h>
#include "lua.h"

Result Archive_ExtractZip(lua_State * L, const char *src, const char *dst);

#endif