#include"../inc/uls.h"

// флаг визначення виду виведення файлів
static void mx_type_of_format(char flag, t_t_format* format) {
    switch(flag) {
        case '1':
            *format = _STR;
            return;    
        case 'l':
            *format = _LENGTH;
            return;
        case 'C':
            *format = _MANYCOLUMNS;
            return;
    }
}

// флаг визначення видимості файлів
static void mx_type_of_visible(char flag, v_t_v_file *file) {
    switch(flag) {
        case 'a':
            *file = _ALL;
            break;
        case 'A':
            *file = _W_DOTS;
            break;
    }
}

// флаг визначення тупи часу
static void mx_type_of_time(char flag, t_t_time* time) {
    switch(flag) {
        case 'c':
            *time = _CTIME;
            break;
        case 'u':
            *time = _ATIME;
            break;
    }
}

// флаг визначення типу сортування
static void mx_type_of_sort(char flag, t_t_sort *sort) {
    switch(flag) {
        case 'S':
            *sort = _SIZE;
            break;
    }
}

// флаг розвороту
static void mx_reverse_flag(char flag, bool *reverse) {
    if (flag == 'r')
        *reverse = true;
}

// рекурсивний флаг 
static void mx_recursive_flag(char flag, bool *recursive) {
    if (flag == 'R')
        *recursive = true;
}

// definition of  flags / визначення флагів
void mx_flags_definition(t_flags *flags, char *str_flags) {
    if(!mx_isflag(str_flags))
        return;

    for(int i = 0; str_flags[i]; i++) {
        mx_type_of_format(str_flags[i], &flags->format);
        mx_type_of_visible(str_flags[i], &flags->visible);
        mx_type_of_sort(str_flags[i], &flags->sort);
        mx_type_of_time(str_flags[i], &flags->time);
        mx_reverse_flag(str_flags[i], &flags->reverse);
        mx_recursive_flag(str_flags[i], &flags->recursive);
    }
}
