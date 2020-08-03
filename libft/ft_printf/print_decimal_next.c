/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal_next.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarsell <dmarsell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 19:11:14 by dmarsell          #+#    #+#             */
/*   Updated: 2020/07/16 11:28:01 by dmarsell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_space_decimal(char *ap, int *precision, int len, flags *f)
{
	int		i;

	if (len > *precision)
	{
		if (f->precision == 0 && f->dot && f->percent != -2)
			i = f->weidth;
		else
			i = f->weidth - len;
	}
	else
		i = f->weidth - *precision;
	f->percent == -1 ? i-- : 1;
	((f->precision > len) && (ap[0] == '-' \
	|| f->plus) && !(f->minus)) ? i-- : 1;
	f->plus && ap[0] != '-' && !(f->minus) ? i-- : 1;
	f->space ? f->space = 0 : 1;
	while (i-- > 0)
		f->print ? ft_putchar_fd(' ', FD) : 1;
}

void		to_weidth_decimal_next_n_n(char *ap, int *len, flags *f)
{
	if (f->minus == 0 && f->zero == 1)
	{
		if (f->space && ap[0] != '-' && !(f->plus) && f->print)
		{
			write(FD, " ", 1);
			f->space = 0;
			(*len)++;
		}
		print_zero_decimal(ap, len, f);
		print_str_decimal(ap, len, f);
	}
}

void		to_weidth_decimal_n_n(char *ap, int precision, int *len, flags *f)
{
	if (f->minus == 0 && f->zero == 0)
	{
		print_space_decimal(ap, &precision, *len, f);
		if ((f->precision && f->plus && ap[0] != '-' && ap[0] != '0')\
		|| (ap[0] == '0' && f->plus))
		{
			f->print ? write(1, "+", 1) : 1;
			f->plus = 0;
			(*len)++;
		}
		if (f->space && ap[0] != '-' && !(f->plus) && f->print)
		{
			write(FD, " ", 1);
			f->space = 0;
			(*len)++;
		}
		!(f->precision == 0 && f->dot) ? print_str_decimal(ap, len, f) : 1;
	}
	to_weidth_decimal_next_n_n(ap, len, f);
}

int			to_weidth_decimal_next(char *ap, int *len, flags *f)
{
	if (f->space && (ap[0] != '-' || ap[0] != '0') && \
	(f->type != 'u' || f->type != 'U') && (f->weidth || f->precision) \
	&& (f->weidth <= *len || f->precision >= *len) && !(f->plus))
	{
		write(FD, " ", 1);
		f->space = 0;
	}
	if ((f->precision && f->plus && ap[0] != '-' && ap[0] != '0')\
	|| (ap[0] == '0' && f->plus))
	{
		f->print ? write(1, "+", 1) : 1;
		f->plus = 0;
		(*len)++;
	}
	!(f->precision == 0 && f->dot && ap[0] == '0') ? \
	print_str_decimal(ap, len, f) : 1;
	f->plus && ap[0] != '-' ? (*len)++ : 1;
	f->space && ap[0] != '-' && f->type != 'u' ? (*len)++ : 1;
	if (f->precision == 0 && f->dot && ap[0] == '0')
		return (0);
	return (*len);
}

int			to_weidth_decimal(char *ap, int precision, int *len, flags *f)
{
	if (*len >= f->weidth)
		return (to_weidth_decimal_next(ap, len, f));
	if (*len < f->weidth)
	{
		to_weidth_decimal_n_n(ap, precision, len, f);
		if (f->minus == 1)
		{
			if (f->plus && ap[0] != '-' && (f->type != 'u' || f->type != 'U'))
			{
				write(FD, "+", 1);
				f->plus = 0;
				f->percent = -2;
			}
			to_weidth_decimal_min(ap, precision, len, f);
		}
	}
	return (f->weidth);
}
