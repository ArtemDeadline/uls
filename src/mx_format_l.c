#include"../inc/uls.h"

static void mx_format_l_default(t_format_l *format) {
    format->mode = 0;
    format->numb_links = 0;
    format->owner_name = 0;
    format->group_name = 0;
    format->size = 0;
    format->major = 0;
}

void mx_format_l(t_format_l *format_l, t_list_of_files *list_of_files) {
    mx_format_l_default(format_l);
    
    while(list_of_files) {

        if(mx_strlen(list_of_files->file.stat->mode) > format_l->mode)
            format_l->mode = mx_strlen(list_of_files->file.stat->mode);

        if(mx_strlen(list_of_files->file.stat->numb_links) > format_l->numb_links)
            format_l->numb_links = mx_strlen(list_of_files->file.stat->numb_links);
                
        if(mx_strlen(list_of_files->file.stat->owner_name) > format_l->owner_name)
            format_l->owner_name = mx_strlen(list_of_files->file.stat->owner_name);
        
        if(mx_strlen(list_of_files->file.stat->group_name) > format_l->group_name)
            format_l->group_name = mx_strlen(list_of_files->file.stat->group_name);

        if(mx_strlen(list_of_files->file.stat->size) > format_l->size)
            format_l->size = mx_strlen(list_of_files->file.stat->size);

        if(mx_strlen(list_of_files->file.stat->major) > format_l->major)
            format_l->major = mx_strlen(list_of_files->file.stat->major);

        list_of_files = list_of_files->next;

    }
}
