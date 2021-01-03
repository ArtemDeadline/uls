#include "../inc/uls.h"

static char** mx_dirs_init(char **argv) {
    char **f_dirs = NULL;
    int size = 0;
    int index = 0;

    for(int i = 0; argv[i]; i++) {
        if(mx_isdir(argv[i]))
            size++;
    }

    if(!size) 
        return NULL;
    
    f_dirs = malloc(sizeof(char*) * (size + 1));

    for(int i = 0; argv[i]; i++) {
        if(mx_isdir(argv[i]))
            f_dirs[index++] = mx_strdup(argv[i]);
    }

    f_dirs[index] = NULL;
    return f_dirs;
}

static char** mx_files_init(char **argv) {
    char **f_files = NULL;
    int size = 0;
    int index = 0;

    for(int i = 0; argv[i]; i++) {
        if(mx_isfile(argv[i]) && !mx_isdir(argv[i]))
            size++;
    }

    if(!size)
        return NULL;
    
    f_files = malloc(sizeof(char*) * (size + 1));
    
    for(int i = 0; argv[i]; i++) {
        if(mx_isfile(argv[i]) && !mx_isdir(argv[i]))
            f_files[index++] = mx_strdup(argv[i]);
    }

    f_files[index] = NULL;
    return f_files;
}

static t_flags mx_flags_init() {
    t_flags flags;

    flags.visible = _H_DOTS;
    flags.sort = _NAME;
    flags.time = _MTIME;
    flags.format = _MANYCOLUMNS;
    flags.reverse = false;
    flags.recursive = false;

    return flags;
}

// init uls
t_uls mx_uls_init(char **argv) {

    t_uls uls;
    
    uls.flags = mx_flags_init();
    uls.f_files = mx_files_init(argv);
    uls.f_dirs = mx_dirs_init(argv);
    uls.list_of_files = NULL;
    uls.status_exit = EXIT_SUCCESS;

    if(*argv)
        mx_flags_definition(&uls.flags, *argv);

    return uls;
}
