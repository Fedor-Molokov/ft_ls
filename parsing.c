/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarsell <dmarsell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 22:37:52 by dmarsell          #+#    #+#             */
/*   Updated: 2020/08/04 00:49:55 by dmarsell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_ls.h"

void    ft_flags(char **argv, int *flags, int *i, int *j)
{
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
    (*i)++; 
}

char    *ft_parsing_next(char **argv, char *way, int *flags, int *count)
{
    int     i;
    int     j;

    j = 1;
    i = 1;
    while (argv[j] && *count == 1)
    {
        while (argv[j][i] && argv[j][0] == '-')
            ft_flags(argv, flags, &i, &j);
        if (argv[j][0] != '-')
        {
            way = argv[j];
            *count = ++j;
            return (way);
        }
        i = 1;
        j++;
    }
    return (way);
}

char    *ft_parsing(char **argv, char *way, int *flags, int *count)
{
    if (argv[1][0] != '-' && *count == 1)
    {
        way = argv[1];
        *flags = FLAG_NON;
        (*count)++;
        return (way);
    }
    if (*count == 1)
        return(ft_parsing_next(argv, way, flags, count));
    if (*count > 1)
        way = argv[(*count)++];
    return (way);
}