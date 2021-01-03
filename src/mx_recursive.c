#include"../inc/uls.h"

void mx_recursive(t_uls *uls) {

    if(uls->flags.recursive) {

        t_list_of_files *files = uls->list_of_files;

        while(files) {

            if(mx_isdir(files->file.path) && mx_dots_absence(files->file.names)) {
                NN;
                mx_print_dir_name(files->file.path);
                mx_ls(uls, files->file.path);
                mx_del_file_list(&uls->list_of_files);
            }

            files = files->next;
        } 

    }

}
