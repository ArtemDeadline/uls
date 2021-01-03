#include "../inc/uls.h"

void mx_ls_d(t_uls *uls) {
    if(uls->f_dirs) {
        mx_sort_strarr(uls->f_dirs, mx_better_name, uls->flags.reverse);
        mx_sort_strarr(uls->f_dirs, mx_sort(uls->flags), uls->flags.reverse);
        if(uls->f_files)
            NN;

        if(uls->f_dirs[1] || uls->f_files || uls->flags.recursive || uls->status_exit)
            mx_print_dir_name(uls->f_dirs[0]);
        
        mx_ls(uls, uls->f_dirs[0]);

        if(uls->f_dirs[1])
            NN;

        for(int i = 1; uls->f_dirs[i]; i++) {
            mx_print_dir_name(uls->f_dirs[i]);
            mx_ls(uls, uls->f_dirs[i]);

            if(uls->f_dirs[i+1])
                NN;
        }
    }
}
