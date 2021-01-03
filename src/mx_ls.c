#include"../inc/uls.h"

void mx_ls(t_uls *uls, char *d_name) {
    
    uls->list_of_files = mx_column_file_to_str(d_name, uls);

    if(uls->list_of_files) {
        mx_sort_files(uls->list_of_files, mx_better_name, uls->flags.reverse);
        mx_sort_files(uls->list_of_files, mx_sort(uls->flags), uls->flags.reverse);
        if(uls->flags.format & _LENGTH)
            mx_print_all(uls->list_of_files);
        mx_format(uls);
        mx_recursive(uls);
    }
    
}
