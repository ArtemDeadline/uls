#include "../inc/uls.h"

t_list_of_files* mx_new_file(char *file_name, char *root_path) {
    t_list_of_files *file_node = malloc(sizeof(t_list_of_files));
    char *file_with_slash = NULL;

    file_node->file.names = mx_strdup(file_name);
    file_node->file.stat = NULL;
    if(root_path[mx_strlen(root_path) - 1] != '/') {
        file_with_slash = mx_strjoin(root_path, "/");
        file_node->file.path = mx_strjoin(file_with_slash, file_name);
        mx_strdel(&file_with_slash);
    } else {
        file_node->file.path = mx_strjoin(root_path, file_name);
    }
    file_node->next = NULL;

    return file_node;
}
