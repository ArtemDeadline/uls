#include "../inc/uls.h"

bool mx_hidden_dots(char *file_name) {
    return file_name[0] == '.' ? false : true;
}
