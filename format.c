#include "ft_ls.h"

void			format_str(char *date, size_t big)
{
	int			diff;
	size_t		t;

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
	//ft_printf(" ");
}

void			format_time(time_t date)
{
	char		**mass;
	time_t		today;
	char		*buf;

	(void)time(&today);
	buf = ctime(&date);
	mass = ft_strsplit(buf, ' ');
	if (today - date < 14515200)
		ft_printf("%s %2s %.5s ", mass[1], mass[2], mass[3]);
	else
		ft_printf("%s %2s %.4s ", mass[1], mass[2], mass[4]);
	ft_memdel((void **)mass);
}
