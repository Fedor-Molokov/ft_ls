/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarsell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 15:06:12 by dmarsell          #+#    #+#             */
/*   Updated: 2019/09/28 21:00:30 by dmarsell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_makechar(int nb, int i, int sign, char e)
{
	char	*str;

	if (!(str = (char*)malloc(sizeof(char) * (1 + i) + sign)))
		return (NULL);
	str[i + sign] = '\0';
	i--;
	if (sign > 0)
		str[0] = 45;
	while (i + sign >= sign)
	{
		str[i + sign] = (nb % 10) + '0';
		nb /= 10;
		i--;
	}
	if (e > 0)
		str[1] = 2 + '0';
	return (str);
}

char			*ft_itoa(int n)
{
	int		i;
	int		sign;
	int		nb;
	char	e;

	i = 1;
	sign = 0;
	nb = 0;
	if (n == -2147483648)
	{
		n += 2000000000;
		i += 1;
		e = 1;
	}
	while (n < 0)
	{
		sign += 1;
		n *= -1;
	}
	nb = n;
	while (n /= 10)
		i++;
	return (ft_makechar(nb, i, sign, e));
}
