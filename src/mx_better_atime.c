#include"../inc/uls.h"

int mx_better_atime(char *f1, char *f2, bool reverse) {
    struct stat info;
    time_t s1;
    time_t s2;

    lstat(f1, &info);
    s1 = info.st_atime;

    lstat(f2, &info);
    s2 = info.st_atime;

    if(!reverse) {
        if(s1 >= s2)
            return 0;
        return 1;
    }

    if(s1 <= s2)
            return 0;
    return 1;
}
