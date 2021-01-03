#include"../inc/uls.h"

bool mx_dots_absence(char *file_name) {
    return !mx_strcmp(file_name, ".") || !mx_strcmp(file_name, "..") ? false : true; 
}
