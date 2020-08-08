/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarsell <dmarsell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 02:24:15 by dmarsell          #+#    #+#             */
/*   Updated: 2020/08/08 09:23:48 by dmarsell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_perror(char *str, t_list *list)
{
	perror(str);
	ft_printf("%s\n", list->path);
	exit(EXIT_FAILURE);
}

void			ft_null(t_list *list)
{
	list->dir = NULL;
	list->name = NULL;
	list->child = NULL;
	list->next = NULL;
	list->path = NULL;
	list->pwd = NULL;
	list->grp = NULL;
	list->link = NULL;
	list->rdev_maj = 0;
	list->rdev_min = 0;
	list->format = 0;
	list->file = 0;
}

void			copy(t_list *p1, t_list *p2)
{
	p1->name = p2->name;
	p1->path = p2->path;
	p1->stat = p2->stat;
	p1->child = p2->child;
	p1->link = p2->link;
}

void			swap(t_list *a, t_list *b)
{
	t_list		tmp;

	tmp = *a;
	copy(a, b);
	copy(b, &tmp);
}
