#include"../inc/uls.h"

void mx_sort_files(t_list_of_files *files, t_sort compare, bool reverse) {
    if(!files)
        return;
    bool swap = true;
    t_list_of_files *ptr = NULL;
    t_file temp_file;

    while(swap) {
        swap = false;
        ptr = files;

        while(ptr->next != NULL) {

            if(compare(ptr->file.path, ptr->next->file.path, reverse) > 0) {
                temp_file = ptr->file;
                ptr->file = ptr->next->file;
                ptr->next->file = temp_file;
                swap = true;
            }
            ptr = ptr->next;
        }
    }
}
