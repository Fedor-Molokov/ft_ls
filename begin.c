/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassunta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 12:54:29 by cassunta          #+#    #+#             */
/*   Updated: 2020/08/09 12:56:41 by cassunta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					crutch(t_list *list)
{
	if ((ft_strcmp("/dev/fd/3", list->path) == 0))
	{
		ft_printf("%s\n", list->path);
		ft_putstr("./ft_ls: 3: Not a directory");
	}
	else if ((ft_strcmp("/dev/fd/4", list->path) == 0))
		ft_printf("./ft_ls: %s: directory causes a cycle\n", list->name);
	else
		ft_printf("./ft_ls: %s: No such file or directory\n", list->name);
	return (0);
}

int					ft_start(int flags, char *way)
{
	t_list			*names;
	t_list			*go;

	if (way == NULL)
		return (-1);
	if (!(names = (t_list *)malloc(sizeof(t_list))))
		ft_perror("ft_start() malloc: ", names);
	ft_null(names);
	go = in_directory(way, names, flags);
	go = sorting(go, flags);
	print(go, flags);
	ft_free(go);
	return (0);
}

t_list				*in_directory(char *way, t_list *names, int flags)
{
	struct dirent	*entry;
	DIR				*dirp;
	t_list			*cur;

	if (!(dirp = opendir(way)))
		return (ft_start_file(way, names));
	if (!(entry = readdir(dirp)))
		ft_perror("in_directory() readdir: ", names);
	cur = names;
	while (entry)
	{
		process(cur, entry->d_name, way, flags);
		if ((entry = readdir(dirp)))
		{
			if (!(cur->next = (t_list *)malloc(sizeof(t_list))))
				ft_perror("in_directory() malloc: ", cur);
			cur = cur->next;
			ft_null(cur);
		}
	}
	cur->next = NULL;
	if (closedir(dirp) < 0)
		ft_perror("in_directory() closedir: ", cur);
	return (names);
}

void				process(t_list *cur, char *name, char *way, int flags)
{
	cur->name = ft_strdup(name);
	cur->path = slash_strjoin(way, cur->name);
	cur->dir = ft_strdup(way);
	if (lstat(cur->path, &cur->stat) < 0)
		ft_perror("process() lstat: ", cur);
	if ((flags & FLAG_R) && (ft_strcmp(cur->name, ".") != 0)
	&& (ft_strcmp(cur->name, "..") != 0))
	{
		if (are_you_dir(cur))
			cur->child = in_directory(cur->path, cur->child, flags);
	}
}

void				print_list(t_list *nm, int flags)
{
	while (nm)
	{
		if (!(flags & FLAG_A) && nm->name[0] == '.' && nm->file == 0)
			nm = nm->next;
		else
		{
			ft_printf("%s\n", nm->name);
			nm = nm->next;
		}
	}
}
