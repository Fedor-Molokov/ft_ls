/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarsell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 17:51:42 by dmarsell          #+#    #+#             */
/*   Updated: 2019/09/28 21:55:33 by dmarsell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t		i;

	i = 0;
	if (n == 0)
		return (0);
	while (str1[i] && str2[i])
	{
		if ((n - 1 == i) || (str1[i] != str2[i])
				|| str1[i] == '\0' || str2[i] == '\0')
			break ;
		i++;
	}
	return ((int)((unsigned char)str1[i] - (unsigned char)str2[i]));
}
