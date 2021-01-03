#include"../inc/uls.h"

bool mx_isdir(char *d_name) {
    struct stat info;

    if(stat(d_name, &info))
        return false;
    
    if(!S_ISDIR(info.st_mode))
        return false;
    
    return true;
}
