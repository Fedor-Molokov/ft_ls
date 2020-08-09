/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_arg_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarsell <dmarsell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 19:03:41 by dmarsell          #+#    #+#             */
/*   Updated: 2020/08/09 19:05:26 by dmarsell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_darg(t_crutch *data, t_head *head, t_point *point)
{
	if (head->arg_dir == 0)
	{
		ft_init(head, data, VALID_ARG_DIR);
		point->p_arg_dir = head->val_dir_start;
		head->arg_dir++;
		return (1);
	}
	point->p_arg_dir = ft_dir_create(data, point->p_arg_dir);
	head->arg_dir++;
	return (0);
}

int			ft_farg(t_crutch *data, t_head *head, t_point *point)
{
	if (head->arg_file == 0)
	{
		ft_init(head, data, VALID_ARG_FILE);
		point->p_arg_file = head->val_file_start;
		head->arg_file++;
		return (1);
	}
	point->p_arg_file = ft_file_create(data, point->p_arg_file);
	return (0);
}

int			ft_inval(t_crutch *data, t_head *head, t_point *point)
{

	if (head->inval_argp == 0)
	{
		ft_init(head, data, INVALID_ARG);
		point->p_inval_argp = head->invalid_start;
		head->inval_argp++;
		return (1);
	}
	point->p_inval_argp = ft_invalid_create(data, point->p_inval_argp);
	return (0);
}