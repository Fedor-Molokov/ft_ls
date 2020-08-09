/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_in_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarsell <dmarsell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 01:03:54 by dmarsell          #+#    #+#             */
/*   Updated: 2020/08/09 18:18:28 by dmarsell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>

int			ft_darg(t_dop *dop, t_crutch *data, t_head *head, t_list *p_arg_dir)
{
	if (dop->arg_dir == 0)
	{
		ft_init(head, data, VALID_ARG_DIR);
		p_arg_dir = head->val_dir_start;
		dop->arg_dir++;
		return (1);
	}
	p_arg_dir = ft_dir_create(data, p_arg_dir);
	dop->arg_dir++;
	return (0);
}

int			ft_farg(t_dop *dop, t_crutch *data, t_head *head, t_list *p_arg_file)
{
	if (dop->arg_file == 0)
	{
		ft_init(head, data, VALID_ARG_FILE);
		p_arg_file = head->val_file_start;
		dop->arg_file++;
		return (1);
	}
	p_arg_file = ft_file_create(data, p_arg_file);
	return (0);
}

int			ft_inval(t_dop *dop, t_crutch *data, t_head *head, t_list *p_inval_argp)
{

	if (dop->inval_argp == 0)
	{
		ft_init(head, data, INVALID_ARG);
		p_inval_argp = head->invalid_start;
		dop->inval_argp++;
		return (1);
	}
	p_inval_argp = ft_invalid_create(data, p_inval_argp);
	return (0);
}

void			ft_prestart(t_head *head, char **argv, t_crutch *data, t_point *point)
{
	// t_list		*p_arg_dir;
	// t_list		*p_arg_file;
	// t_list		*p_inval_argp;
	t_dop		dop;

	dop.arg_dir = 0;
	dop.arg_file = 0;
	dop.inval_argp = 0;
	while(argv[data->count])
	{
		data->way = ft_parsing(argv, data->way, &data->flags, &data->count);
		head->valid = lstat(data->way, &head->stat);
		if (head->valid == -1)
		{
			if (ft_inval(&dop, data, head, point->p_inval_argp))
				continue ;
		}
		else if (S_ISDIR(head->stat.st_mode) == 0)
		{
			if (ft_farg(&dop, data, head, point->p_arg_file))
				continue ;
		}
		else
		{
			if (ft_darg(&dop, data, head, point->p_arg_dir))
				continue ;
		}
	}
	if (dop.arg_dir)
		point->p_arg_dir->next = NULL;
	if (dop.arg_file)
		point->p_arg_file->next = NULL;
	if (dop.inval_argp)
		point->p_inval_argp->next = NULL;
	// dop.arg_dir ? point->p_arg_dir->next = NULL : 1;
	// dop.arg_file ? point->p_arg_file->next = NULL : 1;
	// dop.inval_argp ? point->p_inval_argp->next = NULL : 1;
}

void			while_arg_dir(t_list *arg_dir, t_crutch data)
{
	while(arg_dir)
	{
		ft_start(data.flags, arg_dir->path);
		arg_dir->next ? write(1, "\n", 1) : 1;
		arg_dir = arg_dir->next;
	}
}

int				main(int argc, char **argv)
{
	t_head		head;
	t_crutch	data;
	t_point		point;
	
	point.p_inval_argp = NULL;
	point.p_arg_file = NULL;
	point.p_arg_dir = NULL; 
	data.arg = 0;
	data.fail= 0;
	data.flags = 0;
	data.count = 1;
	if (argc == 1)
	{
		data.way = "./";
		data.flags = FLAG_NON;
		ft_start(data.flags, data.way);
		return (0);
	}
	ft_prestart(&head, argv, &data, &point);
	point.p_inval_argp = sorting(head.invalid_start, data.flags);
	while(point.p_inval_argp)
	{
		print(point.p_inval_argp, data.flags);
		point.p_inval_argp = point.p_inval_argp->next;
	}
	ft_free(head.invalid_start);
	point.p_arg_file = sorting(head.val_file_start, data.flags);
		print(point.p_arg_file, data.flags);
	head.val_dir_start && point.p_arg_file ? write(1, "\n", 1) : 1;
	ft_free(head.val_file_start);
	point.p_arg_dir = sorting(head.val_dir_start, data.flags);
	while_arg_dir(point.p_arg_dir, data);
	ft_free(head.val_dir_start);
	return (0);
}
