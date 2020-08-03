/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarsell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 21:04:51 by dmarsell          #+#    #+#             */
/*   Updated: 2019/09/28 21:10:47 by dmarsell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_free(char **freestr, int count)
{
	count++;
	while (count > 0)
	{
		free(freestr[count - 1]);
		count--;
	}
	free(freestr);
	return (NULL);
}

static char		**ft_fill(char **pointstr, size_t i, const char *s, char c)
{
	size_t j;
	size_t count;

	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		j = 0;
		while (s[j + i] != c && s[j + i] != '\0')
			j++;
		if (!(pointstr[count] = (char*)malloc(j + 1)))
			return (ft_free(pointstr, count));
		j = 0;
		while (s[i + j] != c && s[i + j] != '\0')
		{
			pointstr[count][j] = s[i + j];
			j++;
		}
		pointstr[count++][j] = '\0';
		i += j;
	}
	return (pointstr);
}

static char		**ft_allocation(char const *s, char c, size_t count)
{
	size_t	i;
	char	**pointstr;

	if (!(pointstr = (char**)malloc(sizeof(char*) * (count + 1))))
		return (NULL);
	pointstr[count] = NULL;
	count = 0;
	i = 0;
	return (ft_fill(pointstr, i, s, c));
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	count;
	size_t	i;

	if (!s)
		return (NULL);
	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (ft_allocation(s, c, count));
}
