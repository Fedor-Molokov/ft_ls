#include "ft_ls.h"

/*void        read_link(char *path)
{
    struct stat buf;

    stat(path, &buf);
    ft_putstr(buf->)
}*/

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
        ft_putchar('-');
    if (S_ISDIR(mode))
        ft_putchar('d');
    if (S_ISLNK(mode))
    {
        ft_putchar('l');
        //read_link(path);
    }
    if (S_ISBLK(mode))
        ft_putchar('b');
    if (S_ISCHR(mode))
        ft_putchar('c');
    if (S_ISFIFO(mode))
        ft_putchar('p');
    if (S_ISSOCK(mode))
        ft_putchar('s');
  /* if (S_ISWHT(mode))
        ft_putstr("w ");*/
}
void        hardlink(int link)
{
    ft_putnbr(link);
    ft_putstr("  ");
}

void        user_and_group(t_list *nm)
{
    struct passwd   *pwd;
    struct group    *grp;

    pwd = getpwuid(nm->stat.st_uid);
    ft_putstr(pwd->pw_name);
    ft_putchar(' ');
    grp = getgrgid(nm->stat.st_gid);
    ft_putstr(grp->gr_name);
    ft_putchar(' ');
}
void        about_file(t_list *nm)
{
    type_file(nm->stat.st_mode);
    file_mode(nm->stat.st_mode);
    hardlink(nm->stat.st_nlink);
    user_and_group(nm);
}