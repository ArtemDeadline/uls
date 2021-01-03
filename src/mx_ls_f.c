#include "../inc/uls.h"

void mx_ls_f(t_uls *uls) {

    if(!uls->f_files)
        return;
    mx_sort_strarr(uls->f_files, mx_better_name, uls->flags.reverse);
    mx_sort_strarr(uls->f_files, mx_sort(uls->flags), uls->flags.reverse);
    uls->list_of_files = mx_columns_file_to_str(POINT, uls->f_files);
    //sort
    mx_format(uls);
    mx_del_file_list(&uls->list_of_files);
}
