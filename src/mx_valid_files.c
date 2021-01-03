#include"../inc/uls.h"

int mx_valid_files(char **argv) {
    int status_exit = EXIT_SUCCESS;

    if(!mx_isflag(argv[0]) && !mx_isfile(argv[0])) {
        mx_err_files(argv[0]);
        status_exit = EXIT_FAILURE;
    }
    for(int i = 1; argv[i]; i++) {
        if(!mx_isfile(argv[i])) {
            mx_err_files(argv[i]);
            status_exit = EXIT_FAILURE;
        }       
    }
    return status_exit;
}
