#include "../inc/uls.h"

void mx_del_uls(t_uls *uls) {
    if(uls->f_dirs)
        mx_del_strarr(&uls->f_dirs);
    if(uls->f_files)
        mx_del_strarr(&uls->f_files);
    if(uls->list_of_files)
        mx_del_file_list(&uls->list_of_files);
}
