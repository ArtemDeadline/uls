#include"../inc/uls.h"

t_sort mx_sort(t_flags flags) {
    if(flags.sort & _SIZE) 
        return mx_better_size;
    
    if(!(flags.format & _LENGTH)) {
        if(flags.time & _CTIME)
            return mx_better_ctime;
        if(flags.time & _ATIME)
            return mx_better_atime;
    }

    return mx_better_name;
}
