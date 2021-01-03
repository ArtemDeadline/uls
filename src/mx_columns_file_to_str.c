#include"../inc/uls.h"


t_list_of_files *mx_columns_file_to_str(char *root_path, char **f_files) {
    t_list_of_files *list_of_files = NULL;
    t_list_of_files *p_list_of_files = NULL;

    list_of_files = mx_new_file(f_files[0], root_path);
    p_list_of_files = list_of_files;

    for(int i = 1; f_files[i]; i++) {
        p_list_of_files->next = mx_new_file(f_files[i], root_path);
        p_list_of_files = p_list_of_files->next;
    }

    return list_of_files;
}
