#include"../inc/uls.h" 

void mx_err_files(char *d_name) {
    mx_printerr("uls: ");
    if(errno == 13) {
    while(!mx_alpha(*d_name)) {d_name++;}
    }
    mx_printerr(d_name);
    mx_printerr(": " );
    perror(NULL);
}
