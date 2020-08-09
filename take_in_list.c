/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_in_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarsell <dmarsell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 01:03:54 by dmarsell          #+#    #+#             */
/*   Updated: 2020/08/09 00:38:21 by dmarsell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>

void			ft_prestart(t_head *head, char **argv, t_crutch *data)
{
	t_list		*p_arg_dir;
	t_list		*p_arg_file;
	t_list		*p_inval_argp;
	int			inval_argp;
	int			arg_file;
	int			arg_dir;

	arg_dir = 0;
	arg_file = 0;
	inval_argp = 0;
	while(argv[data->count])
	{
		data->way = ft_parsing(argv, data->way, &data->flags, &data->count);
		head->valid = lstat(data->way, &head->stat);
		if (head->valid == -1)
		{
			if (inval_argp == 0)
			{
				ft_init(head, data, INVALID_ARG);
				p_inval_argp = head->invalid_start;
				inval_argp++;
				continue ;
			}
			p_inval_argp = ft_invalid_create(data, p_inval_argp);
		}
		else if (S_ISDIR(head->stat.st_mode) == 0)
		{
			if (arg_file == 0)
			{
				ft_init(head, data, VALID_ARG_FILE);
				p_arg_file = head->val_file_start;
				arg_file++;
				continue ;
			}
			p_arg_file = ft_file_create(data, p_arg_file);
		}
		else
		{
			if (arg_dir == 0)
			{
				ft_init(head, data, VALID_ARG_DIR);
				p_arg_dir = head->val_dir_start;
				arg_dir++;
				continue ;
			}
			p_arg_dir = ft_dir_create(data, p_arg_dir);
			arg_dir++;
		}
	}
	if (arg_dir)
		p_arg_dir->next = NULL;
	if (arg_file)
		p_arg_file->next = NULL;
	if (inval_argp)
		p_inval_argp->next = NULL;
	arg_dir > 1 ? data->flags |= FLAG_ARG : 1;
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
	t_list		*arg_dir;
	t_list		*arg_file;
	t_list		*inval_argp;

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
	ft_prestart(&head, argv, &data);
	inval_argp = sorting(head.invalid_start, data.flags);
	while(inval_argp)
	{
		print(inval_argp, data.flags);
		inval_argp = inval_argp->next;
	}
	ft_free(head.invalid_start);
	arg_file = sorting(head.val_file_start, data.flags);
		print(arg_file, data.flags);
	head.val_dir_start && arg_file ? write(1, "\n", 1) : 1;
	ft_free(head.val_file_start);
	arg_dir = sorting(head.val_dir_start, data.flags);
	while_arg_dir(arg_dir, data);
	ft_free(head.val_dir_start);
	return (0);
}
