#include "../inc/uls.h"

void mx_err_flags(char uncorrect_flag) {
    mx_printerr(ER_FLAGS);
    mx_print_charerr(uncorrect_flag);
    mx_printerr("\n");
    mx_printerr(HELP);
    mx_printerr("\n");
    exit(1);
}
