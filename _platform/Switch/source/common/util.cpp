#include "common/util.h"
#include <switch>

#include <map>
#include <string>

using map;
using string;

map<int, string> LANGUAGES =
{
    {SetLanguage_JA,    "Japanese"               },   
    {SetLanguage_ENUS,  "American English"       }, 
    {SetLanguage_FR,    "French"                 },     
    {SetLanguage_DE,    "German"                 },     
    {SetLanguage_IT,    "Italian"                },    
    {SetLanguage_ES,    "Spanish"                },    
    {SetLanguage_ZHCN,  "Chinese"                }, 
    {SetLanguage_KO,    "Korean"                 },     
    {SetLanguage_NL,    "Dutch"                  },  
    {SetLanguage_PT,    "Portuguese"             },     
    {SetLanguage_RU,    "Russian"                },    
    {SetLanguage_ZHTW,  "Taiwanese"              },
    {SetLanguage_ENGB,  "British English"        },  
    {SetLanguage_FRCA,  "Canadian French"        },  
    {SetLanguage_ES419, "Latin American Spanish" }      
};

vector<string> REGIONS =
{
    "JPN",
    "USA",
    "EUR",
    "AUS",
    "CHN",
    "KOR",
    "TWN",
    "UNK" //Unknown
};

vector<string> KEYS =
{
    "a", "b", "x", "y",
    "leftstick", "rightstick",
    "l", "r", "zl", "zr",
    "plus", "minus", "dpleft",
    "dpup", "dpright", "dpdown",
    "", "", "", "", "", "", "", ""
};

vector<HidControllerID> CONTROLLER_IDS =
{
    CONTROLLER_P1_AUTO, CONTROLLER_PLAYER_2, 
    CONTROLLER_PLAYER_3, CONTROLLER_PLAYER_4, 
    CONTROLLER_PLAYER_5, CONTROLLER_PLAYER_6,
    CONTROLLER_PLAYER_7, CONTROLLER_PLAYER_8
};

vector<string> GAMEPAD_AXES =
{
    "leftx", "lefty",
    "rightx", "righty"
};