#include"../inc/uls.h"

int mx_better_ctime(char *f1, char *f2, bool reverse) {
    struct stat info;
    time_t s1;
    time_t s2;

    stat(f1, &info);
    s1 = info.st_ctime;

    stat(f2, &info);
    s2 = info.st_ctime;

    if(!reverse) {
        if(s1 >= s2)
            return 0;
        return 1;
    }

    if(s1 <= s2)
            return 0;
    return 1;
}
