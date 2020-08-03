/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarsell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 10:44:35 by dmarsell          #+#    #+#             */
/*   Updated: 2019/09/24 15:57:43 by dmarsell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	len;
	size_t	size;

	if (*needle == '\0')
		return ((char*)haystack);
	i = 0;
	len = ft_strlen((char*)haystack);
	size = ft_strlen((char*)needle);
	while (i < len)
	{
		if (ft_strncmp(&(haystack[i]), needle, size) == 0)
			return ((char*)(&(haystack[i])));
		i++;
	}
	return (NULL);
}
