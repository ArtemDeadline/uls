#include"../inc/uls.h"

static void mx_size_file_list(t_uls *uls) {
    
    t_list_of_files *ptr = uls->list_of_files;

    while(ptr) {
        mx_stat_init(&ptr->file, uls->flags);
        ptr = ptr->next;
    }
    mx_print_head(uls);
}

void mx_format(t_uls *uls) {
    switch(uls->flags.format)
    {
        case _LENGTH:
            mx_size_file_list(uls);
            break;
        
        case _STR:
            mx_print_str(uls);
            break;
        
        case _MANYCOLUMNS:
            mx_print_strs(uls);
            break;
    }
}
