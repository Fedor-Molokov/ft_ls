/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_big2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassunta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 20:07:49 by cassunta          #+#    #+#             */
/*   Updated: 2020/08/08 20:10:39 by cassunta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					len_maj(t_list *nm, int flags)
{
	int				tmp;
	int				res;

	tmp = 0;
	while (nm)
	{
		if (!(flags & FLAG_A) && nm->name[0] == '.' && nm->file == 0)
			nm = nm->next;
		else
		{
			if (tmp < nm->rdev_maj)
				tmp = nm->rdev_maj;
			nm = nm->next;
		}
	}
	res = len_num(tmp);
	return (res);
}

int					len_min(t_list *nm, int flags)
{
	int				tmp;
	int				res;

	tmp = 0;
	res = 0;
	while (nm)
	{
		if (!(flags & FLAG_A) && nm->name[0] == '.' && nm->file == 0)
			nm = nm->next;
		else
		{
			if (tmp < nm->rdev_min)
				tmp = nm->rdev_min;
			nm = nm->next;
		}
	}
	res = len_num(tmp);
	return (res);
}

size_t				len_link(t_list *nm, int flags)
{
	int				res;

	res = 0;
	while (nm)
	{
		if (!(flags & FLAG_A) && nm->name[0] == '.' && nm->file == 0)
			nm = nm->next;
		else
		{
			if (res < nm->stat.st_nlink)
				res = nm->stat.st_nlink;
			nm = nm->next;
		}
	}
	res = len_num(res);
	return (res);
}

int					is_spec(t_list *nm)
{
	int				res;

	res = 0;
	while (nm)
	{
		if ((S_ISCHR(nm->stat.st_mode)) || (S_ISBLK(nm->stat.st_mode)))
		{
			res = 1;
			return (res);
		}
		nm = nm->next;
	}
	return (res);
}
