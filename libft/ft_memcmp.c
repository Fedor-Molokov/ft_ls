/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarsell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 22:54:57 by dmarsell          #+#    #+#             */
/*   Updated: 2019/09/24 00:06:00 by dmarsell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char*)s1 > *(unsigned char*)s2 ||
			*(unsigned char*)s1 < *(unsigned char*)s2)
		{
			return (*(unsigned char*)s1 - *(unsigned char*)s2);
		}
		s1++;
		s2++;
		i++;
	}
	return (0);
}
