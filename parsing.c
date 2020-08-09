/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarsell <dmarsell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 22:37:52 by dmarsell          #+#    #+#             */
/*   Updated: 2020/08/08 21:24:54 by dmarsell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_usage(char c)
{
	ft_printf("./ft_ls: illegal option -- %c\n", c);
	ft_putstr("usage: ls [-Raltr] [file ...]\n");
	exit(0);
}

void		ft_flags(char **argv, int *flags, int *i, int *j)
{
	if (argv[*j][*i] == '-' && *j == 1)
		*flags |= FLAG_NEXT;
	if (argv[*j][*i] == 'l')
		*flags |= FLAG_L;
	if (argv[*j][*i] == 'a')
		*flags |= FLAG_A;
	if (argv[*j][*i] == 't')
		*flags |= FLAG_T;
	if (argv[*j][*i] == 'R')
		*flags |= FLAG_R;
	if (argv[*j][*i] == 'r')
		*flags |= FLAG_MIN_R;
	if (argv[*j][*i] < 49 && !(*flags & FLAG_NEXT))
		ft_usage(argv[*j][*i]);
	if (argv[*j][*i] > 49 && argv[*j][*i] < 65)
		ft_usage(argv[*j][*i]);
	if (argv[*j][*i] > 87 && argv[*j][*i] < 97)
		ft_usage(argv[*j][*i]);
	if (argv[*j][*i] > 120)
		ft_usage(argv[*j][*i]);
	(*i)++;
}

char		*ft_parsing_next(char **argv, char *way, int *flags, int *count)
{
	int		i;
	int		j;

	j = 1;
	i = 1;
	while (argv[j] && *count == 1)
	{
		while (argv[j][i] && argv[j][0] == '-')
			ft_flags(argv, flags, &i, &j);
		if (*flags & FLAG_NEXT)
		{
			if (argv[2])
				way = argv[++(*count)];
			else
				way = "./";
			(*count)++;
			break ;
		}
		if (argv[j][0] != '-')
		{
			way = argv[j];
			*count = ++j;
			return (way);
		}
		i = 1;
		j++;
	}
	if (!(argv[j]))
	{
		way = "./";
		*count = j;
	}
	return (way);
}

char		*ft_parsing(char **argv, char *way, int *flags, int *count)
{
	if (argv[1][0] != '-' && *count == 1)
	{
		way = argv[1];
		*flags = FLAG_NON;
		(*count)++;
		return (way);
	}
	if (*count == 1)
		return (ft_parsing_next(argv, way, flags, count));
	if ((*count > 1))
		way = argv[(*count)++];
	return (way);
}
