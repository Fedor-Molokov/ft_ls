/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassunta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 15:09:46 by cassunta          #+#    #+#             */
/*   Updated: 2020/08/09 15:12:26 by cassunta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				if_child(t_list *nm, int flags)
{
	while (nm)
	{
		if (nm->child)
		{
			if (!(flags & FLAG_A) && nm->name[0] == '.')
			{
				nm = nm->next;
				continue ;
			}
			write(1, "\n", 1);
			print(nm->child, flags);
		}
		nm = nm->next;
	}
}

int					print(t_list *nm, int flags)
{
	int				i;
	t_list			*cur;

	if (nm == NULL)
		return (1);
	i = 0;
	cur = nm;
	if (lstat(cur->path, &cur->stat) < 0)
		return (crutch(cur));
	(flags & FLAG_ARG) && nm->file == 0 ? begin_of_list(nm) : 1;
	!(flags & FLAG_ARG) ? flags ^= FLAG_ARG : 1;
	(flags & FLAG_L) && nm->file == 0 ? ft_total(cur, flags) : 1;
	if (flags & FLAG_L)
		big_str(cur, flags);
	else
		print_list(nm, flags);
	if_child(nm, flags);
	return (0);
}
