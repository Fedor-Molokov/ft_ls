#include "ft_ls.h"

void        file_mode(int mode)
{
    char    str[10];

    str[0] = (S_IRUSR & mode) ? 'r' : '-';
    str[1] = (S_IWUSR & mode) ? 'w' : '-';
    str[2] = (S_IXUSR & mode) ? 'x' : '-';
    str[3] = (S_IRGRP & mode) ? 'r' : '-';
    str[4] = (S_IWGRP & mode) ? 'w' : '-';
    str[5] = (S_IXGRP & mode) ? 'x' : '-';
    str[6] = (S_IROTH & mode) ? 'r' : '-';
    str[7] = (S_IWOTH & mode) ? 'w' : '-';
    str[8] = (S_IXOTH & mode) ? 'x' : '-';
    str[9] = '\0';
    if (S_ISUID & mode)
        str[2] = str[2] == '-' ? 'S' : 's';
    if (S_ISGID & mode)
        str[5] = str[5] == '-' ? 'S' : 's';
    if (S_ISVTX & mode)
        str[8] = str[8] == '-' ? 'T' : 't';
    ft_putstr(str);
    write(1, " ", 1);
}

void        type_file(int mode)
{
    if (S_ISREG(mode))
        ft_putstr("-");
    if (S_ISDIR(mode))
        ft_putstr("d");
    if (S_ISLNK(mode))
        ft_putstr("l");
    if (S_ISBLK(mode))
        ft_putstr("b");
    if (S_ISCHR(mode))
        ft_putstr("c");
    if (S_ISFIFO(mode))
        ft_putstr("p");
    if (S_ISSOCK(mode))
        ft_putstr("s");
  /* if (S_ISWHT(mode))
        ft_putstr("w ");*/
}

void        about_file(t_list *nm)
{
    type_file(nm->stat.st_mode);
    file_mode(nm->stat.st_mode);
}