/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarsell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 18:08:25 by dmarsell          #+#    #+#             */
/*   Updated: 2019/09/30 17:50:47 by dmarsell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void		*p;

	if (size == 0)
		return (NULL);
	if (!(p = malloc(size)))
		return (NULL);
	ft_bzero(p, size);
	return (p);
}
