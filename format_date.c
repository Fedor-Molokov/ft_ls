#include "ft_ls.h"

void				format_min_size(t_list *nm, t_opt *lst)
{
	size_t			big;

	big = ((lst->osize > lst->r_min) ? lst->osize : lst->r_min);
	if (nm->format == 1 && ((ft_strcmp(nm->name, "autofs_nowait") == 0 ||
			ft_strcmp(nm->name, "autofs_notrigger") == 0) || ft_strcmp(nm->name, "autofs_homedirmounter") == 0))
		ft_printf(" %0#10x ", nm->rdev_min);
	if (nm->format == 0)
		format_num(nm->stat.st_size, big);
}


void				format_maj_size(t_list *nm, t_opt *lst)
{
	int				diff;

	diff = 0;
	if (nm->format == 1)
	{
		diff = lst->r_maj - len_num(nm->rdev_maj);
		while (diff > 0)
		{
			ft_putchar(' ');
			diff--;
		}
		ft_printf(" %d,", nm->rdev_maj);
	}
	if (nm->format == 0 && (lst->spec == 1))
	{
		diff = lst->r_maj + 2;
		while (diff > 0)
		{
			ft_putchar(' ');
			diff--;
		}
	}
}

void			soft_link(char *way)
{
	char		buf[1024];
	int			len;

	len = readlink(way, buf, sizeof buf);
	if (len > 0)
	{
		buf[len] = '\0';
		ft_printf(" -> %s", buf);
	}
}

void			format_num(int date, size_t big)
{
	int			diff;

	if (len_num(date) < big)
	{
		diff = big - len_num(date);
		while (diff > 0)
		{
			write(1, " ", 1);
			diff--;
		}
	}
	ft_printf("%d ", date);
}