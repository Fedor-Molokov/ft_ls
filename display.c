/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassunta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 23:13:07 by cassunta          #+#    #+#             */
/*   Updated: 2020/08/08 23:13:15 by cassunta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_total(t_list *nm, int flags)
{
	unsigned int res;

	res = 0;
	while (nm)
	{
		if (!(flags & FLAG_A) && nm->name[0] == '.')
		{
			nm = nm->next;
			continue ;
		}
		res += nm->stat.st_blocks;
		nm = nm->next;
	}
	ft_printf("total %u\n", res);
}

void			ft_free(t_list *nm)
{
	t_list		*head;

	while (nm)
	{
		nm->child ? ft_free(nm->child) : 1;
		nm->dir ? free(nm->dir) : 1;
		nm->name ? free(nm->name) : 1;
		nm->path ? free(nm->path) : 1;
		nm->link ? free(nm->link) : 1;
		nm->pwd ? free(nm->pwd) : 1;
		nm->grp ? free(nm->grp) : 1;
		head = nm;
		nm = nm->next;
		free(head);
	}
}

void			begin_of_list(t_list *nm)
{
	t_list		*cur;

	cur = nm;
	ft_printf("%s:\n", nm->dir);
}

void			big_str(t_list *nm, int flags)
{
	t_opt		*lst;

	about_file(nm);
	lst = parse_big(nm, flags);
	while (nm)
	{
		if (!(flags & FLAG_A) && nm->name[0] == '.' && nm->file == 0)
			nm = nm->next;
		else
		{
			nm->format = type_file(nm);
			file_mode(nm->stat.st_mode);
			format_num(nm->stat.st_nlink, lst->olink);
			format_str(nm->pwd, lst->opwd);
			format_str(nm->grp, lst->ogrp);
			format_maj_size(nm, lst);
			format_min_size(nm, lst);
			format_time(nm->stat.st_mtimespec.tv_sec);
			ft_putstr(nm->name);
			soft_link(nm->path);
			write(1, "\n", 1);
			nm = nm->next;
		}
	}
	free(lst);
}

int				are_you_dir(t_list *dir)
{
	t_list		*new_dir;

	if (S_ISDIR(dir->stat.st_mode))
	{
		if (!(new_dir = (t_list *)malloc(sizeof(t_list))))
			ft_perror("are_you_dir() malloc: ", dir);
		ft_null(new_dir);
		dir->child = new_dir;
		new_dir->path = dir->path;
		return (1);
	}
	dir->child = NULL;
	return (0);
}
