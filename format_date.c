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

void            format_min_size(t_list *nm, t_opt *lst)
{
    int         diff;

    diff = 0;
    if (nm->format == 1)
    {
        diff = lst->r_min - len_num(nm->rdev_min);
        while (diff > 0)
        {
            ft_putchar(' ');
            diff--;
        }
        ft_putnbr(nm->rdev_min);
        ft_putchar(',');
    }
    if (nm->format == 0)
    {
        diff = lst->r_min + 1;
        while (diff > 0)
        {
            ft_putchar(' ');
            diff--;
        }
    }
}

void            soft_link(char *way)
{
	char        buf[1024];
	int			len;

	len = readlink(way, buf, sizeof buf);
	if (len > 0)
	{
	    buf[len] = '\0';
	    ft_printf(" -> %s", buf);
	}
}

void            format_num(int date, size_t big)
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