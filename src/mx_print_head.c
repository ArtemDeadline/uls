#include"../inc/uls.h"

static void mx_printspace(int n_spaces, int len) {
    for(int i = n_spaces; i < len; i++) {
        mx_printchar(' ');
    }
}

static void mx_print_mode(char *mode, int len) {
    mx_printstr(mode);
    mx_printspace(mx_strlen(mode), len);
}

static void mx_print_number_of_link(char *number_of_links, int len) {
    mx_printspace(mx_strlen(number_of_links),len);
    mx_printstr(number_of_links);
}

static void mx_print_owner(char *owner, int len) {
    mx_printstr(owner);
    mx_printspace(mx_strlen(owner), len);
}

static void mx_print_group(char *group, int len) {
    mx_printstr(group);
    mx_printspace(mx_strlen(group), len);
}

static void mx_print_size(char *size, int len) {
    mx_printspace(mx_strlen(size), len);
    mx_printstr(size);
}

static void mx_print_major(char *major, int len) {
    if(major) {
        mx_printspace(mx_strlen(major), len);
        mx_printstr(major);
        mx_printchar(','); 
    } else {
        mx_printspace(0, len);
        if(len) {
            mx_printchar(' ');
        }
    }
}

static void mx_print_time(char *time) {
    mx_printstr(time);
}

static void mx_print_filename(char *filename) {
    mx_printstr(filename);
}

static void mx_print_linked_file(char *filename) {
    mx_printstr(" -> ");
    mx_printstr(filename);
}

void mx_print_head(t_uls *uls) {
    t_format_l format_l;
    t_list_of_files *list_of_files = uls->list_of_files;

    mx_format_l(&format_l, list_of_files);
    while(list_of_files) {
        mx_print_mode(list_of_files->file.stat->mode, format_l.mode);
        mx_printchar(' ');
        mx_print_number_of_link(list_of_files->file.stat->numb_links, format_l.numb_links);
        mx_printchar(' ');
        mx_print_owner(list_of_files->file.stat->owner_name, format_l.owner_name);
        mx_printstr("  ");
        mx_print_group(list_of_files->file.stat->group_name, format_l.group_name);
        mx_printstr("  ");
        mx_print_major(list_of_files->file.stat->major, format_l.major);
        mx_print_size(list_of_files->file.stat->size, format_l.size);
        mx_printchar(' ');
        mx_print_time(list_of_files->file.stat->time);
        mx_printchar(' ');
        mx_print_filename(list_of_files->file.names);
        if(list_of_files->file.stat->mode[0] == _LINK)
            mx_print_linked_file(list_of_files->file.stat->link);
        mx_printchar('\n');
        
        list_of_files = list_of_files->next;
    }
}
