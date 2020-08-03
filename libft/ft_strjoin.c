/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarsell <dmarsell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 04:14:29 by dmarsell          #+#    #+#             */
/*   Updated: 2020/07/07 02:40:39 by dmarsell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_suffix(char const *s2, char *strnew, int len2)
{
	int		i;

	i = 0;
	while (i < len2)
	{
		*strnew = *(char*)s2;
		strnew++;
		s2++;
		i++;
	}
	*strnew = '\0';
	return (strnew);
}

static char	*ft_prefix(char const *s1, char *strnew, int len1)
{
	int		i;

	i = 0;
	while (i < len1)
	{
		*strnew = *(char*)s1;
		strnew++;
		s1++;
		i++;
	}
	*strnew = '\0';
	return (strnew);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*strnew;
	char	*prefix;
	char	*suffix;
	int		len1;
	int		len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen((char*)s1);
	len2 = ft_strlen((char*)s2);
	if (!(strnew = (char*)malloc(sizeof(char) * len1 + len2 + 1)))
		return (NULL);
	prefix = ft_prefix(s1, strnew, len1);
	suffix = ft_suffix(s2, prefix, len2);
	return (strnew);
}
