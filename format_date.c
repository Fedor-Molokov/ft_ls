#include "ft_ls.h"


void            format_maj_size(t_list *nm, t_opt *lst)
{
    size_t         big;

    big = ((lst->osize > lst->r_maj) ? lst->osize : lst->r_maj);
    if (nm->format == 1)
        format_num(lst->r_maj, big);
    if (nm->format == 0)
        format_num(nm->stat.st_size, big);
}

/*void            format_min_size(t_list *nm, t_opt *lst)
{
    int         diff;

    if (nm->format == 1)
    {
        diff = (int )lst->r_min - len_num(nm->rdev_min);
        while (diff > 0)
        {
            write(1, "1", 1);
            diff--;
        }
        ft_printf("%d,  ");
    }
    if (nm->format == 0)
    {
        diff = lst->r_min + 3;
        while (diff > 0)
        {
            write(1, "1", 1);
            diff--;
        }
    }
}*/

void            format_time(time_t date)
{
    char        *buf;
    int         t;
    int         i;


    i = 0;
    buf = ctime(&date);
    t = ft_strlen(buf) - 1;
    while (t > 0)
    {
        ft_putchar(buf[i]);
        i++;
        t--;
    }
    ft_printf("  ");
}

void            soft_link(char *way)
{
    char        buf[1024];
    int         len;

    len = readlink(way, buf, sizeof buf);
    if (len > 0)
    {
        buf[len] = '\0';
        ft_printf(" -> %s", buf);
    }
}

void            format_str(char *date, size_t big)
{
    int         diff;
    int         t;

    t = ft_strlen(date);
    ft_printf("%s", date);
    if (t < big)
    {
        diff = big - t;
        while (diff > 0)
        {
            ft_putchar(' ');
            diff--;
        }
    }
    ft_printf("  ");
}

void            format_num(int date, int big)
{
    int         diff;

    if (len_num(date) < big)
    {
        diff = big - len_num(date);
        while (diff > 0)
        {
            write(1, " ", 1);
            diff--;
        }
    }
    ft_printf("%d  ", date);
}