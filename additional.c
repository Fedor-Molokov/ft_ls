/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarsell <dmarsell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 02:24:15 by dmarsell          #+#    #+#             */
/*   Updated: 2020/08/04 20:21:24 by dmarsell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list     *process_arg(t_list *cur, char *way)
{
    cur->name = ft_findlastname(way);
    cur->path = ft_strdup(way);
    if(lstat(cur->path, &cur->stat) < 0)
        ft_perror("process() lstat: ", cur);
    if((ft_strcmp(cur->name, ".") != 0 ) && (ft_strcmp(cur->name, "..") != 0))
    {
        if (are_you_dir(cur))
            cur->child = in_directory(cur->path, cur->child);
    }
    return (cur);
}

void		ft_printf_exit(char *str, t_list *list)
{
	ft_printf("./ft_ls: %s: No such file or directory", str);
	free(list->name);
	free(list->path);
}

void        ft_perror(char *str, t_list *list)
{
    perror(str);
	ft_printf("%s\n", list->path);
    exit(EXIT_FAILURE);
}

// void		ft_arg_null(t_arg_list *list)
// {
// 	list->name = NULL;
// 	list->next = NULL;
// 	list->path = NULL;
// }

// void		ft_fail_null(t_fail_list *list)
// {
// 	list->name = NULL;
// 	list->next = NULL;
// 	list->path = NULL;
// }

void		ft_null(t_list *list)
{
	list->name = NULL;
	list->child = NULL;
	list->next = NULL;
	list->path = NULL;
}