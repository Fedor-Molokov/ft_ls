/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarsell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 15:43:42 by dmarsell          #+#    #+#             */
/*   Updated: 2019/09/22 20:15:17 by dmarsell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	unsigned long	i;
	char			*save;

	save = dest;
	i = 0;
	while (i < n)
	{
		if (*src != '\0')
		{
			*dest = *src;
			src++;
		}
		else if (*src == '\0')
			*dest = '\0';
		dest++;
		i++;
	}
	return (save);
}
