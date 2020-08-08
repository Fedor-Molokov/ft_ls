/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_big.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassunta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 20:12:48 by cassunta          #+#    #+#             */
/*   Updated: 2020/08/08 20:14:38 by cassunta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

size_t			len_num(int src)
{
	int			res;

	res = 1;
	while (src / 10)
	{
		res += 1;
		src = src / 10;
	}
	return (res);
}

size_t			len_grp(t_list *nm, int flags)
{
	size_t		res;

	res = 0;
	while (nm)
	{
		if (!(flags & FLAG_A) && nm->name[0] == '.' && nm->file == 0)
			nm = nm->next;
		else
		{
			if (res < ft_strlen(nm->grp))
				res = ft_strlen(nm->grp);
			nm = nm->next;
		}
	}
	return (res);
}

size_t			len_pwd(t_list *nm, int flags)
{
	size_t		res;

	res = 0;
	while (nm)
	{
		if (!(flags & FLAG_A) && nm->name[0] == '.' && nm->file == 0)
			nm = nm->next;
		else
		{
			if (res < ft_strlen(nm->pwd))
				res = ft_strlen(nm->pwd);
			nm = nm->next;
		}
	}
	return (res);
}

size_t			len_size(t_list *nm, int flags)
{
	int			res;

	res = 0;
	while (nm)
	{
		if (!(flags & FLAG_A) && nm->name[0] == '.' && nm->file == 0)
			nm = nm->next;
		else
		{
			if (res < nm->stat.st_size)
				res = nm->stat.st_size;
			nm = nm->next;
		}
	}
	res = len_num(res);
	return (res);
}

t_opt			*parse_big(t_list *nm, int flags)
{
	t_opt		*lst;

	lst = (t_opt *)malloc(sizeof(t_opt));
	lst->osize = len_size(nm, flags);
	lst->olink = len_link(nm, flags);
	lst->opwd = len_pwd(nm, flags);
	lst->ogrp = len_grp(nm, flags);
	lst->r_min = len_min(nm, flags);
	lst->r_maj = len_maj(nm, flags);
	lst->spec = is_spec(nm);
	return (lst);
}
