#include "ft_ls.h"

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

void            format_str(char *date, int big)
{
    int         diff;

    if (ft_strlen(date) < big)
    {
        diff = big - ft_strlen(date);
        while (diff > 0)
        {
            write(1, " ", 1);
            diff--;
        }
    }
    ft_printf("%s  ", date);
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