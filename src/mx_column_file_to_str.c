#include "../inc/uls.h"

t_list_of_files *mx_column_file_to_str(char *root_path, t_uls *uls) {
    t_list_of_files *list_of_files = NULL;
    t_list_of_files *p_list_of_files = NULL;
    DIR *dir = NULL;
    struct dirent *file = NULL;
    t_visible visible = mx_visible_flags(uls->flags);

    if(!(dir = opendir(root_path))) {
        mx_err_files(root_path);
        uls->status_exit = EXIT_FAILURE;
        return NULL;
    }

    if(!list_of_files) {
       while((file = readdir(dir)) != NULL) {
            if(visible(file->d_name)) {
                list_of_files = mx_new_file(file->d_name, root_path);
                break;
            }
        }
    }

    p_list_of_files = list_of_files;

    while((file = readdir(dir))){
        if(visible(file->d_name)) {
            p_list_of_files->next = mx_new_file(file->d_name, root_path);
            p_list_of_files = p_list_of_files->next;
        }
    }

    closedir(dir);
    return list_of_files;
}
