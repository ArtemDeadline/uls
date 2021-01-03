#include"../inc/uls.h"

static bool mx_valid_flag(char flag) {
    char *p_flags = ALL_FLAGS;

    while(*p_flags) {

        if(*p_flags == flag)
            return true;
        
        p_flags++;
    }
    
    return false;
}

void mx_valid_flags(char *flags) {
    if(!mx_isflag(flags++))
        return;

    while(*flags) {

        if(!mx_valid_flag(*flags))
            mx_err_flags(*flags);

        flags++;
    }

    return;
}
