/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassunta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 06:03:36 by cassunta          #+#    #+#             */
/*   Updated: 2020/08/06 06:06:33 by cassunta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				file_mode(int mode)
{
	char			str[10];

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

int					type_file(t_list *nm)
{
	if (S_ISREG(nm->stat.st_mode))
		ft_putchar('-');
	if (S_ISDIR(nm->stat.st_mode))
		ft_putchar('d');
	if (S_ISLNK(nm->stat.st_mode))
		ft_putchar('l');
	if (S_ISBLK(nm->stat.st_mode))
	{
		ft_putchar('b');
		return (1);
	}
	if (S_ISCHR(nm->stat.st_mode))
	{
		ft_putchar('c');
		return (1);
	}
	if (S_ISFIFO(nm->stat.st_mode))
		ft_putchar('p');
	if (S_ISSOCK(nm->stat.st_mode))
		ft_putchar('s');
	if (S_ISWHT(nm->stat.st_mode))
		ft_putstr("w ");
	return (0);
}

char				*get_pwd(int src)
{
	struct passwd	*pwd;
	char			*res;

	pwd = getpwuid(src);
	res = ft_strdup(pwd->pw_name);
	return (res);
}

char				*get_grp(int src)
{
	struct group	*grp;
	char			*res;

	grp = getgrgid(src);
	res = ft_strdup(grp->gr_name);
	return (res);
}

void				about_file(t_list *nm)
{
	while (nm)
	{
		nm->pwd = get_pwd(nm->stat.st_uid);
		nm->grp = get_grp(nm->stat.st_gid);
		nm->rdev_min = minor(nm->stat.st_rdev);
		nm->rdev_maj = major(nm->stat.st_rdev);
		nm = nm->next;
	}
}
