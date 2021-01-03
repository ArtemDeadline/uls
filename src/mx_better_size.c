#include"../inc/uls.h"

int mx_better_size(char *f1, char *f2, bool reverse) {
    struct stat info;
    long s1;
    long s2;

    lstat(f1, &info);
    s1 = info.st_size;

    lstat(f2, &info);
    s2 = info.st_size;

    if(!reverse) {
        if(s1 >= s2)
            return 0;
        return 1;
    }

    if(s1 <= s2)
            return 0;
    return 1;
}
