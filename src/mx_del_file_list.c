#include"../inc/uls.h"

static void mx_d_stat(t_stat **stat) {
    mx_strdel(&(*stat)->numb_links);
    mx_strdel(&(*stat)->owner_name);
    mx_strdel(&(*stat)->group_name);
    mx_strdel(&(*stat)->size);
    mx_strdel(&(*stat)->major);
    mx_strdel(&(*stat)->time);
    if((*stat)->link)
        mx_strdel(&(*stat)->link);
    *stat = NULL;
}

static void mx_d_file(t_file *file) {
    mx_strdel(&file->names);
    mx_strdel(&file->path);

    if(file->stat)
        mx_d_stat(&file->stat);

}


void mx_del_file_list(t_list_of_files **list_of_files) {
    t_list_of_files *ptr = NULL;

    while(*list_of_files) {
        ptr = *list_of_files;
        (*list_of_files) = (*list_of_files)->next;
        mx_d_file(&ptr->file);
        free(ptr);
        ptr = NULL;
    }

    list_of_files = NULL;
}
