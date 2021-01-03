#include "../inc/uls.h"

int main(int argc, char **argv){
    if(argc){
        argv += 1;
        t_uls uls;

        if(*argv) {
            if(mx_isflag(*argv) && *(argv+1) != NULL) {
                mx_sort_strarr(argv+1, mx_better_name, false);
            } else {
                mx_sort_strarr(argv, mx_better_name, false);
            }
            mx_valid_flags(*argv);
        } 

        uls = mx_uls_init(argv);
        
        if(*argv)
            uls.status_exit = mx_valid_files(argv);
          
        if(uls.f_dirs || uls.f_files) {
            mx_ls_f(&uls);
            mx_ls_d(&uls);
        }
        else {
            if(mx_isflag(*argv) && *(argv+1) == NULL)
                mx_ls(&uls, POINT);
            if(*argv == NULL)
                mx_ls(&uls, POINT);
        }
        
        mx_del_uls(&uls);
        exit(uls.status_exit);
    }
}
