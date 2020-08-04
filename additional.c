/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarsell <dmarsell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 02:24:15 by dmarsell          #+#    #+#             */
/*   Updated: 2020/08/04 22:41:22 by dmarsell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_printf_exit(char *str, t_list *list)
{
	ft_printf("./ft_ls: %s: No such file or directory\n", str);
	free(list->name);
	free(list->path);
	return (1);
}

void        ft_perror(char *str, t_list *list)
{
    perror(str);
	ft_printf("%s\n", list->path);
    exit(EXIT_FAILURE);
}

void		ft_null(t_list *list)
{
	list->dir = NULL;
	list->name = NULL;
	list->child = NULL;
	list->next = NULL;
	list->path = NULL;
	list->link = NULL;
}