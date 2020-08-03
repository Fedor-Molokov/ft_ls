/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarsell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 00:29:01 by dmarsell          #+#    #+#             */
/*   Updated: 2019/09/24 09:01:59 by dmarsell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		len;

	i = 0;
	while (dst[i] != '\0' && i < size)
		i++;
	len = i;
	while (src[i - len] != '\0' && i + 1 < size)
	{
		dst[i] = ((char*)src)[i - len];
		i++;
	}
	if (len < size)
		dst[i] = '\0';
	return (len + ft_strlen((char*)src));
}
