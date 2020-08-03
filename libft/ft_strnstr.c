/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarsell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 16:22:07 by dmarsell          #+#    #+#             */
/*   Updated: 2019/09/30 11:19:03 by dmarsell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hayst, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	if (needle[0] == '\0')
		return ((char*)hayst);
	i = 0;
	while (hayst[i] != '\0' && i < len)
	{
		j = 0;
		while (hayst[i + j] == needle[j] && hayst[i + j] != '\0' && i + j < len)
		{
			if (needle[j + 1] == '\0')
				return ((char*)(&hayst[i]));
			if (hayst[i + j + 1] == '\0')
				return (NULL);
			j++;
		}
		i++;
	}
	return (NULL);
}
