#pragma once

//Libs
#include <curl/curl.h>
#include <png.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <SDL.h>
#include <SDL2_gfxPrimitives.h>

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

#include <switch.h>

#include "objects/object/object.h"

#include "common/types.h"
#include "common/variant.h"
#include "common/util.h"
#include "common/console.h"
#include "modules/love.h"
#include "common/error.h"

#include "socket/luasocket.h"
#include "socket/common.h"

using std::string;
using std::vector;
using std::pair;
using std::make_pair;
using std::map;
using std::queue;