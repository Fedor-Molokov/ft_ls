/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarsell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 06:29:56 by dmarsell          #+#    #+#             */
/*   Updated: 2019/09/30 17:59:51 by dmarsell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned	ft_skipsp(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	i--;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i--;
	return (i + 1);
}

char			*ft_strtrim(char const *s)
{
	char	*strnew;
	size_t	i;
	size_t	arr;

	if (!s)
		return (NULL);
	while (*s == ' ' || *s == '\t' || *s == '\n')
		s++;
	if (*s == '\0')
		return (ft_strnew(0));
	arr = ft_skipsp((char*)s);
	if (!(strnew = (char*)malloc(sizeof(char) * arr + 1)))
		return (NULL);
	i = 0;
	while (i < arr)
	{
		strnew[i] = ((char*)s)[i];
		i++;
	}
	strnew[i] = '\0';
	return (strnew);
}
