/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slash_strjoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarsell <dmarsell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 18:12:00 by cassunta          #+#    #+#             */
/*   Updated: 2020/08/04 02:25:36 by dmarsell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*slash_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*str;
	int             slash;

	i = ft_strlen(s1);
	s1[i - 1] == '/' ? (slash = 0) : (slash = 1);
	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1 + slash);
	if (str == NULL)
		return (NULL);
	while (s1[i])
		str[j++] = s1[i++];
	if (slash)
        str[j++] = '/';
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	return (str);
}