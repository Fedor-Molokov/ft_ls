/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarsell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 16:26:35 by dmarsell          #+#    #+#             */
/*   Updated: 2019/09/23 19:36:08 by dmarsell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *source, int c, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n)
	{
		*(unsigned char*)dest = ((unsigned char*)source)[i];
		if (((unsigned char*)source)[i] == (unsigned char)c)
		{
			dest++;
			return ((void*)dest);
		}
		dest++;
		i++;
	}
	return (NULL);
}
