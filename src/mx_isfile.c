#include"../inc/uls.h"

bool mx_isfile(char *f_name) {
    struct stat info;

    return !stat(f_name, &info);
}
