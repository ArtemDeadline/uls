#include"../inc/uls.h"

void mx_print_str(t_uls *uls) {
    for(t_list_of_files *ptr = uls->list_of_files; ptr; ptr = ptr->next) {
        mx_printstr(ptr->file.names);
        NN;
    }
}
