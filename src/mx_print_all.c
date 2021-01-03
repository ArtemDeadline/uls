#include"../inc/uls.h"

void mx_print_all(t_list_of_files *list_of_files) {
    struct stat stat;
    blkcnt_t total = 0;

    while(list_of_files) {
        lstat(list_of_files->file.path, &stat);
        total += stat.st_blocks;

        list_of_files = list_of_files->next;
    }

    mx_printstr("total ");
    mx_printint((int)total);
    NN;
} 
