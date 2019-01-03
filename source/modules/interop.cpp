#include "common/runtime.h"

#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>



// http://stackoverflow.com/a/11366985
extern "C" bool createSubfolder(const char* pathC) {
    std::string path = string(pathC);
	bool bSuccess = false;
    int nRC = ::mkdir(path.c_str(), 0775);
    if(nRC == -1)
    {
        switch(errno)
        {
            case ENOENT:
                //parent didn't exist, try to create it
                if(createSubfolder(path.substr(0, path.find_last_of('/')).c_str()))
                    //Now, try to create again.
                    bSuccess = 0 == ::mkdir(path.c_str(), 0775);
                else
                    bSuccess = false;
                break;
            case EEXIST:
                //Done!
                bSuccess = true;
                break;std::string getHost();
            default:
                bSuccess = false;
                break;
        }
    }
    else
        bSuccess = true;
    
    return bSuccess;
}