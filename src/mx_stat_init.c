#include"../inc/uls.h"

static void mx_mode(mode_t mode, char *file_mode) {

//type of file
    file_mode[0] = S_ISBLK(mode) ? _BLOCK :
              S_ISCHR(mode) ? _CHARACTER :
              S_ISDIR(mode) ? _DIR :
              S_ISLNK(mode) ? _LINK :
              S_ISFIFO(mode) ? _FIFO :
              S_ISSOCK(mode) ? _SOCKET : _OTHER;
//judge permission for owner
    file_mode[1] = S_IRUSR & mode ? _READ : _NO_PERMISSION;
    file_mode[2] = S_IWUSR & mode ? _WRITE : _NO_PERMISSION;
    file_mode[3] = S_IXUSR & mode ? 
                   (S_ISUID & mode ? _SGID : _EXECUTE) :
                   (S_ISUID & mode ? _SUID : _NO_PERMISSION);
//judge permission for owner group
    file_mode[4] = S_IRGRP & mode ? _READ : _NO_PERMISSION;
    file_mode[5] = S_IWGRP & mode ? _WRITE : _NO_PERMISSION;
    file_mode[6] = S_IXGRP & mode ? 
                   (S_ISGID & mode ? _SGID : _EXECUTE) :
                   (S_ISGID & mode ? _SUID : _NO_PERMISSION);
//judge permission for others
    file_mode[7] = S_IROTH & mode ? _READ : _NO_PERMISSION;
    file_mode[8] = S_IWOTH & mode ? _WRITE : _NO_PERMISSION;
    file_mode[9] = S_IXOTH & mode ? 
                   (S_ISTXT & mode ? _STICKY_BIT_ON : _EXECUTE) :
                   (S_ISTXT & mode ? _STICKY_BIT_OFF : _NO_PERMISSION);
    

}

static void mx_acl(char *file, char *file_mode) {
    ssize_t xattr;
    acl_t acl;

    xattr = listxattr(file, NULL, 0, XATTR_NOFOLLOW);
    acl = acl_get_file(file, ACL_TYPE_EXTENDED);
    
    if(xattr > 0)
        file_mode[10] = '@';
    else 
        if(acl == NULL)
        file_mode[10] = ' ';
    else
        file_mode[10] = '+';
    file_mode[11] = '\0';
    
    acl_free(acl);
        
}

static void mx_nlink(nlink_t links, char**number_of_links) {
    *number_of_links = mx_itoa(links);
}

static void mx_gname(gid_t gid, char **owner_name) {
    if(getgrgid(gid) == NULL)
        *owner_name = mx_itoa(gid);
    else
        *owner_name = mx_strdup(getgrgid(gid)->gr_name);
}

static void mx_uname(gid_t uid, char **owner_name) {
    if(getpwuid(uid) == NULL)
        *owner_name = mx_itoa(uid);
    else
        *owner_name = mx_strdup(getpwuid(uid)->pw_name);
}

static void mx_size(t_file *file, mode_t mode, size_t size, dev_t dev) {
    if(S_ISBLK(mode) || S_ISCHR(mode)) {
        file->stat->major = mx_itoa(MAJOR(dev));
        file->stat->size = mx_itoa(MINOR(dev));
    } else {
        file->stat->size = mx_itoa(size);
        file->stat->major = NULL;
    }
}

static void mx_time(time_t _time, char **time_) {
    char *format_time = ctime(&_time);
    time_t curr_time = time(NULL);
    *time_ = mx_strnew(12);

    if(curr_time - HALF_A_YEAR < _time)
        *time_ = mx_strncpy(*time_,format_time + 4, 12);
    else {
        *time_ = mx_strncpy(*time_, format_time + 4, 6);
        mx_strcpy(*time_ + 6, "  ");
        mx_strncpy(*time_ + 8, format_time + 20, 4);
    }
}

static void mx_link(mode_t mode, off_t st_size, char *full_path, char **link) {    
    if(S_ISLNK(mode)) {
        *link = mx_strnew(st_size);
        readlink(full_path, *link, st_size);
    } else {
        *link = NULL;
    }
}

void mx_stat_init(t_file *file, t_flags flags) {
    struct stat stat;

        file->stat = malloc(sizeof(t_stat));
        
        lstat(file->path, &stat);

        mx_mode(stat.st_mode, file->stat->mode);
        mx_acl(file->path, file->stat->mode);
        mx_nlink(stat.st_nlink, &file->stat->numb_links);
        mx_uname(stat.st_uid, &file->stat->owner_name);
        mx_gname(stat.st_gid, &file->stat->group_name);
        mx_size(file, stat.st_mode, stat.st_size, stat.st_rdev);

        if(flags.time == _ATIME)
            mx_time(stat.st_atime, &file->stat->time);
        if(flags.time == _CTIME)
            mx_time(stat.st_ctime, &file->stat->time);
        if(flags.time  == _MTIME)
            mx_time(stat.st_mtime, &file->stat->time);

        mx_link(stat.st_mode, stat.st_size, file->path, &file->stat->link);

}
