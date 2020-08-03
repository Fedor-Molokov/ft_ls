/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarsell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 23:22:42 by dmarsell          #+#    #+#             */
/*   Updated: 2019/09/26 02:18:11 by dmarsell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*newstr;
	int		i;
	int		len;

	if (!s || !f)
		return (NULL);
	len = ft_strlen((char*)s);
	if (!(newstr = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		newstr[i] = f(((char*)s)[i]);
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
