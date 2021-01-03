#include "../inc/uls.h"

bool mx_isflag(char *flag) {
    if(!flag)
        return false;
    return flag[0] == '-' && flag[1] != '\0' ? true : false;
}
