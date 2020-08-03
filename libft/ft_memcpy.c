/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarsell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 15:57:05 by dmarsell          #+#    #+#             */
/*   Updated: 2019/09/23 16:26:29 by dmarsell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *source, size_t count)
{
	size_t		i;

	if (dest == NULL && source == NULL)
		return (0);
	i = 0;
	while (i < count)
	{
		((char*)dest)[i] = ((char*)source)[i];
		i++;
	}
	return (dest);
}
