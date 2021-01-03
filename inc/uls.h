#ifndef ULS
#define ULS

#include "../libmx/inc/libmx.h"

#include <string.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <dirent.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <sys/xattr.h>
#include <sys/acl.h>

#define HALF_A_YEAR 15778463
#define NN mx_printstr("\n")
#define MINOR(x) ((x) & 0xFFFFFF)
#define MAJOR(x) (((x) >> 24) & 0xFF)
#define POINT "."
#define ALL_FLAGS "lRaA1lCSucr"
#define ER_FLAGS "uls: illegal option -- "
#define HELP "usage: uls [lRaA1lCSucr] [file ...]"

enum e_t_format {
    _MANYCOLUMNS,
    _STR,
    _LENGTH
} typedef t_t_format;

enum e_t_v_file {
    _H_DOTS,  
    _ALL,             
    _W_DOTS 
} typedef v_t_v_file;

enum e_t_time {
    _MTIME, 
    _CTIME, 
    _ATIME  
} typedef t_t_time;

enum e_t_sort {
    _NAME, 
    _SIZE, 
} typedef t_t_sort;

enum e_type_of_file {
    _SGID = 's',
    _STICKY_BIT_ON = 't',
     _READ = 'r',
    _WRITE = 'w',
    _EXECUTE = 'x',
    _SUID = 'S',
    _STICKY_BIT_OFF = 'T',
    _NO_PERMISSION = '-'
    
} typedef t_type_of_file;

enum e_file_mode {
    _FIFO = 'p',
     _BLOCK = 'b',    
    _DIR = 'd',
     _CHARACTER = 'c', 
    _LINK = 'l',
    _SOCKET = 's',
    _OTHER = '-'
} typedef t_file_mode;

struct s_flags {
    t_t_format format; 
    v_t_v_file visible; 
    t_t_time time;  
    t_t_sort sort; 
    bool reverse; 
    bool recursive; 
    

} typedef t_flags;

struct s_format_l {
    int mode;
    int numb_links;
    int owner_name;
    int group_name;
    int size;
    int major;
} typedef t_format_l;

struct s_stat {
    char mode[11];
    char *numb_links;
    char *owner_name;
    char *group_name;
    char *size;
    char *time;
    char *major;
    char *link;
} typedef t_stat;

struct s_file {
    char *path;
    char *names;
    t_stat *stat;
} typedef t_file;      

struct s_list_of_files {
    t_file file;
    struct s_list_of_files *next;
} typedef t_list_of_files;

struct s_uls {
    t_list_of_files *list_of_files;
    t_flags flags;
    char **f_dirs;
    char **f_files;
    int status_exit;
} typedef t_uls;

typedef bool (*t_visible)(char*);
typedef int  (*t_sort)(char*, char*, bool);
typedef void (*t_format)(t_uls);


t_visible mx_visible_flags(t_flags flags);
t_sort mx_sort(t_flags flags);


//void mx_program(char **argv);
t_uls mx_uls_init(char **argv);
bool mx_isfile(char *f_name);
bool mx_isdir(char *d_name);
bool mx_isflag(char *flags);
bool mx_checking(char *file_name);
bool mx_hidden_dots(char *file_name);
bool mx_dots_absence(char *file_name);
int mx_valid_files(char **argv);
void mx_valid_flags(char *str_flags);
void mx_err_files(char *d_name);
void mx_err_flags(char uncorrect_flag);

int mx_better_size(char *f1, char *f2, bool reverse);
int mx_better_name(char *f1, char *f2, bool reverse);
int mx_better_atime(char *f1, char *f2, bool reverse);
int mx_better_ctime(char *f1, char *f2, bool reverse);
int mx_normaly_error_fail(char *f1, char *f2, bool reverse);

void mx_print_dir_name(char *d_name);
void mx_format(t_uls *uls);
void mx_print_str(t_uls *uls);
void mx_print_head(t_uls *uls);
void mx_print_all(t_list_of_files *files);
void mx_print_strs(t_uls *uls);

void mx_flags_definition(t_flags *flags, char *str_flags);

t_list_of_files *mx_column_file_to_str(char *main_path, t_uls *uls);
t_list_of_files *mx_new_file(char *f_name, char *root_path);
t_list_of_files *mx_columns_file_to_str(char *root_path, char **f_files);
void mx_del_file_list(t_list_of_files **list_of_files);
void mx_del_uls(t_uls *uls);

void mx_flag_long(t_uls *uls);

void mx_stat_init(t_file *file, t_flags flags);

#define mx_list_of_files(X, Y) _Generic((X),\
    char*:   _Generic((Y),\
        t_uls*: mx_column_file_to_strfunc,\
        char**: mx_columns_file_to_str_star\
    ),\
    char[2]:  _Generic((Y),\
        t_uls*: mx_column_file_to_strfunc,\
        char**: mx_columns_file_to_str_star\
    )\
)(X, Y)


void mx_ls_d(t_uls *uls);
void mx_ls_f(t_uls *uls);
void mx_ls(t_uls *uls, char *d_name);


void mx_format_l(t_format_l *format_l, t_list_of_files *list_of_files);

void mx_recursive(t_uls *uls);

void mx_sort_strarr(char **arr,t_sort sort, bool reverse);
void mx_sort_files(t_list_of_files *files, t_sort sort, bool reverse);

#endif
