#include"../inc/uls.h"

int mx_better_name(char *s1, char *s2,bool reverse) {
     while(*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
        s1++, s2++;
    
    if(!reverse)
        return *s1 - *s2;
    else
        return *s2 - *s1;
}
