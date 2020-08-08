/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassunta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 20:20:16 by cassunta          #+#    #+#             */
/*   Updated: 2020/08/08 20:20:18 by cassunta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			time_rev_sort(t_list *a, t_list *b)
{
	if (a->stat.st_mtime > b->stat.st_mtime)
		return (1);
	else if (a->stat.st_mtime == b->stat.st_mtime)
	{
		if (a->stat.st_mtimespec.tv_nsec > b->stat.st_mtimespec.tv_nsec)
			return (1);
		if (a->stat.st_mtimespec.tv_nsec == b->stat.st_mtimespec.tv_nsec)
		{
			if (ft_strcmp(a->name, b->name) < 0)
				return (1);
		}
	}
	return (0);
}

int			time_sort(t_list *a, t_list *b)
{
	if (a->stat.st_mtime < b->stat.st_mtime)
		return (1);
	else if (a->stat.st_mtime == b->stat.st_mtime)
	{
		if (a->stat.st_mtime < b->stat.st_mtime)
			return (1);
		if (a->stat.st_mtime == b->stat.st_mtime)
		{
			if (ft_strcmp(a->name, b->name) > 0)
				return (1);
		}
	}
	return (0);
}
