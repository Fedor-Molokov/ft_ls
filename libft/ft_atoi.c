/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarsell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 17:20:51 by dmarsell          #+#    #+#             */
/*   Updated: 2019/09/30 15:10:00 by dmarsell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_makeint(char *str, long long lint, int sign)
{
	while (*str >= '0' && *str <= '9')
	{
		if (lint > 9223372368547758 && sign == -1)
			return (0);
		if (lint > 9223372368547758 && sign == 1)
			return (-1);
		lint = lint * 10 + *str - '0';
		str++;
	}
	return (lint * sign);
}

int				ft_atoi(const char *str)
{
	int			i;
	int			sign;

	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 45)
	{
		sign = -1;
		i++;
	}
	else if (str[i] == 43)
		i++;
	return (ft_makeint((char*)(str + i), 0, sign));
}
