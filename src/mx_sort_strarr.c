#include"../inc/uls.h"

void mx_sort_strarr(char **argv, t_sort sort, bool reverse) {

    if(!argv)
        return;

    bool swap = true;

    char *temp;

    while(swap) {
        swap = false;
        
        for(int i = 0; argv[i + 1] != NULL; i++) {

            if(sort(argv[i],argv[i + 1], reverse) > 0) {
                temp = argv[i];
                argv[i] = argv[i+1];
                argv[i+1] = temp;
                swap = true;
            }
            
        }
    }
}
