#include"../inc/uls.h"

static int mx_maxlen_f_name(t_list_of_files *files) {
    int max = 0;
    int tmp = 0;

    for(t_list_of_files *ptr = files; ptr; ptr = ptr->next) {
        if((tmp = mx_strlen(ptr->file.names)) > max)
            max = tmp;
    }

    return max;
}
static int mx_files_len(t_list_of_files *files) {
    int len = 0;

    for(; files; files = files->next)
        len++;
    
    return len;
}

static char **mx_list_to_arr(t_list_of_files *files) {
    char **str_arr = NULL;
    int index = 0;
    int size = mx_files_len(files);

    str_arr = malloc(sizeof(char*) * (size + 1));
    
    for(t_list_of_files *ptr = files; ptr; ptr = ptr->next)
        str_arr[index++] = ptr->file.names;
    str_arr[index] = NULL;
    return str_arr;
}

static void mx_print_tab(int len, int max) {
    int i;
    int j;

    for(j = 1; ;j++) {
        if(max < (j * 8 - 1))
            break;
    }

    i = j * 8 - len;

    for(int k = 0; k < i; k += 8) {
        mx_printchar('\t');
    }
}

static void mx_print_m_column(char **files, int maxlen, int win_col,int size) {
    int cols = (win_col / ((8 - (maxlen % 8)) + maxlen));
    int rows = size / cols;

    if(size % cols) {
        rows++;
    }

    for(int i = 0; i < rows; i++) {
        for(int j = 0; i + j < size; j+= rows) {
            mx_printstr(files[i+j]);
            if(files[i + j + 1] && (i + j +rows < size))
                mx_print_tab(mx_strlen(files[i+j]), maxlen);
        }
        NN;
    }
}

void mx_print_strs(t_uls *uls) {
    struct winsize win;
    int maxlen = mx_maxlen_f_name(uls->list_of_files);
    int size = mx_files_len(uls->list_of_files);
    char **files = mx_list_to_arr(uls->list_of_files);
    ioctl(1, TIOCGWINSZ, &win);
    if(isatty(1)){
        mx_print_m_column(files, maxlen, win.ws_col, size);
    } else {
        mx_print_str(uls);
    }
    free(files);

}
