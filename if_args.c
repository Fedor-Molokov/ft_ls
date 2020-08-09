/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassunta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 15:16:04 by cassunta          #+#    #+#             */
/*   Updated: 2020/08/09 15:16:07 by cassunta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			if_valid_arg_dir(t_head *head, t_crutch *data)
{
	if (!(head->val_dir_start = (t_list *)malloc(sizeof(t_list))))
		ft_perror("ft_init() malloc: ", NULL);
	ft_null(head->val_dir_start);
	head->val_dir_start->name = ft_findlastname(data->way);
	head->val_dir_start->path = ft_strdup(data->way);
	lstat(head->val_dir_start->path, &head->val_dir_start->stat);
	head->val_dir_start->file = 0;
}

void			if_valid_arg_file(t_head *head, t_crutch *data)
{
	if (!(head->val_file_start = (t_list *)malloc(sizeof(t_list))))
		ft_perror("ft_init() malloc: ", NULL);
	ft_null(head->val_file_start);
	head->val_file_start->name = ft_strdup(data->way);
	head->val_file_start->path = ft_strdup(data->way);
	lstat(head->val_file_start->path, &head->val_file_start->stat);
	head->val_file_start->file = 1;
	data->flags |= FLAG_ARG;
}

void			if_invalid_arg(t_head *head, t_crutch *data)
{
	if (!(head->invalid_start = (t_list *)malloc(sizeof(t_list))))
		ft_perror("ft_init() malloc: ", NULL);
	ft_null(head->invalid_start);
	head->invalid_start->name = ft_strdup(data->way);
	head->invalid_start->path = ft_strdup(data->way);
	head->invalid_start->file = -1;
	data->flags |= FLAG_ARG;
}

void			ft_init(t_head *head, t_crutch *data, int file)
{
	if (file == VALID_ARG_FILE)
		if_valid_arg_file(head, data);
	else if (file == VALID_ARG_DIR)
		if_valid_arg_dir(head, data);
	else if (file == INVALID_ARG)
		if_invalid_arg(head, data);
}
