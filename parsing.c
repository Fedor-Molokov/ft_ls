/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarsell <dmarsell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 22:37:52 by dmarsell          #+#    #+#             */
/*   Updated: 2020/08/04 00:43:37 by dmarsell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_ls.h"

// char    *ft_parsing_next(char **argv, char *way, int *flags, int *count)
// {
//     while(argv[*count])
//     {
//         way = argv[*count];
//     }
    
// }

char    *ft_parsing(char **argv, char *way, int *flags, int *count)
{
    int     i;
    int     j;

    j = 1;
    i = 1;
    if (argv[1][0] != '-' && *count == 1)
    {
        way = argv[1];
        *flags = FLAG_NON;
        (*count)++;
        return (way);
    }
    while (argv[j] && *count == 1)
    {
        while (argv[j][i] && argv[j][0] == '-')
        {
            if (argv[j][i] == 'l')
                *flags |= FLAG_L;
            if (argv[j][i] == 'a')
                *flags |= FLAG_A;
            if (argv[j][i] == 't')
                *flags |= FLAG_T;
            if (argv[j][i] == 'R')
                *flags |= FLAG_R;
            if (argv[j][i] == 'r')
                *flags |= FLAG_MIN_R;    
            i++;
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
    if (*count > 1)
        way = argv[(*count)++];
    return (way);
}