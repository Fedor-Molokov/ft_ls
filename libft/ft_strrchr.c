/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarsell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 09:57:36 by dmarsell          #+#    #+#             */
/*   Updated: 2019/09/24 10:44:27 by dmarsell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*save;

	save = NULL;
	while (*s != '\0')
	{
		if (*(char*)s == (char)c)
			save = (char*)s;
		s++;
	}
	if (*(char*)s == (char)c)
		save = (char*)s;
	return (save);
}
