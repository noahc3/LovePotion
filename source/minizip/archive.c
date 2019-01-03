#include <malloc.h>
#include <string.h>
#include <stdio.h>
#include <sys/stat.h>
#include "archive.h"
#include "fs.h"
#include "unzip.h"
#include "utils.h"
#include "love.h"
#include "lua.h"
#include "lauxlib.h"
#include <time.h>
#include "interop.h"



Result unzExtractCurrentFile(unzFile *unzHandle, int *path)
{
	Result res = 0;
	char filename[256];
	unsigned int bufsize = (64 * 1024);

	unz_file_info file_info;
	if ((res = unzGetCurrentFileInfo(unzHandle, &file_info, filename, sizeof(filename), NULL, 0, NULL, 0)) != 0)
	{
		unzClose(unzHandle);
		return -1;
	}

	void *buf = malloc(bufsize);
	if (!buf)
		return -2;

	char *filenameWithoutPath = Utils_Basename(filename);

	if ((*filenameWithoutPath) == '\0')
	{
		if ((*path) == 0)
			mkdir(filename, 0777);
	}
	else
	{
		const char *write;

		if ((*path) == 0)
			write = filename;
		else
			write = filenameWithoutPath;
		
		if ((res = unzOpenCurrentFile(unzHandle)) != UNZ_OK)
		{
			unzClose(unzHandle);
			free(buf);
			return res;
		}

		FILE *out = fopen(write, "wb");

		if ((out == NULL) && ((*path) == 0) && (filenameWithoutPath != (char *)filename))
		{
			char c = *(filenameWithoutPath - 1);
			*(filenameWithoutPath - 1) = '\0';
			//mkdir(write, 0777);
			createSubfolder(filename);
			*(filenameWithoutPath - 1) = c;
			out = fopen(write, "wb");
		}

		do
		{
			res = unzReadCurrentFile(unzHandle, buf, bufsize);

			if (res < 0)
				break;

			if (res > 0)
				fwrite(buf, 1, res, out);
		} 
		while (res > 0);

		fclose(out);

		res = unzCloseCurrentFile(unzHandle);
	}
	
	if (buf)
		free(buf);
	
	return res;
}

Result unzExtractAll(lua_State * L, const char *src, unzFile *unzHandle)
{
	Result res = 0;
	int path = 0;
	//char *filename = Utils_Basename(src);
	
	unz_global_info global_info;
	memset(&global_info, 0, sizeof(unz_global_info));
	
	if ((res = unzGetGlobalInfo(unzHandle, &global_info)) != UNZ_OK) // Get info about the zip file
	{
		unzClose(unzHandle);
		return res;
	}

	for (unsigned int i = 0; i < global_info.number_entry; i++)
	{

		//update callback
		char luaString1[500];
		sprintf(luaString1, "unzipUpdate(%d, %d)", i, global_info.number_entry);
		luaL_dostring(L, luaString1);
		
		if ((res = unzExtractCurrentFile(unzHandle, &path)) != UNZ_OK)
			break;

		if ((i + 1) < global_info.number_entry)
		{
			if ((res = unzGoToNextFile(unzHandle)) != UNZ_OK) // Could not read next file.
			{
				unzClose(unzHandle);
				return res;
			}
		}
	}

	return res;
}

Result Archive_ExtractZip(lua_State * L, const char *src, const char *dst)
{
	char tmpFile2[1024];
	char tmpPath2[1024];

	FS_MakeDir(dst);

	strncpy(tmpPath2, "sdmc:", sizeof(tmpPath2));
	strncat(tmpPath2, (char *)dst, (1024 - strlen(tmpPath2) - 1));
	chdir(tmpPath2);
	
	strncpy(tmpFile2, "sdmc:", sizeof(tmpFile2));
	strncat(tmpFile2, (char*)src, (1024 - strlen(tmpFile2) - 1));

	unzFile *unzHandle = unzOpen(tmpFile2); // Open zip file

	if (unzHandle == NULL) // not found
		return -1;

	Result res = unzExtractAll(L, src, unzHandle);
	res = unzClose(unzHandle);

	luaL_dostring(L, "unzipDone()");

	return res;
}