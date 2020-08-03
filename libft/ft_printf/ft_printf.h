/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarsell <dmarsell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 23:08:07 by dmarsell          #+#    #+#             */
/*   Updated: 2020/07/27 23:08:08 by dmarsell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H
#define FD 1

# include <stdlib.h>
# include <unistd.h>
# include "../libft.h"
# include <stdarg.h>

typedef struct			t_flags
{
    int				size;
	int				varsize;
	int				div;
	int				minus;
	int				plus;
	int				space;
	int				zero;
	int				hash;
	int				weidth;					 
	int				precision;				
	int				dot;
	int				star;
	int				print;
	int				percent;
	int				decminus;
	char			*ox;
	char			*len;
	char			type;
}                   	flags;

typedef struct			t_use
{
    int				res;
	int				len;
	char			plus;
	char			space;				
	char			decminus;
}                   	use;

typedef struct			t_print_d
{
	int				weidth;
	int				precision;
	int				len;
}                   	print_d;

typedef struct			t_count_d
{
	int				start;
	int				space;
}                   	count_d;

union					longint_double
{
	long			long_val;
	long double		double_val;
};

void    to_weidth_decimal_n_n(char *ap, int precision, int *len, flags *f);
void	ft_space_bit_next(char *tmp, char *buff, int *res, count_d *count);
void	to_weidth_decimal_min(char *ap, int precision, int *len, flags *f);
void    print_space_decimal(char *ap, int *precision, int len, flags *f);
void    print_space_decimal(char *ap, int *precision, int len, flags *f);
int     to_weidth_decimal(char *ap, int precision, int *len, flags *f);
char	*ft_str_combain(char *entire, char *bufer, char *sign, int p);
void    ft_count_num_ull(unsigned long long n, char *buff, int *res);
void    print_str_decimal_next(char *ap, int *len, flags *f, int i);
int     out_num(const char *format, int size1, int size, int start);
void    ft_count_bit(unsigned long long n, char *buff, int *res);
void    to_weidth_decimal_next_n_n(char *ap, int *len, flags *f);
int		calc_float(flags *f, va_list ap, char *buff, char *str);
void	ft_space_bit(char *tmp, char *buff, int *res, flags *f);
void    ft_count_num_ul(unsigned long n, char *buff, int *res);
void    ft_count_num_ui(unsigned int n, char *buff, int *res);
int     to_weidth_decimal_next(char *ap, int *len, flags *f);
void    l_less_next_n(char *s, flags *f, int l, count_d *rx);
void    l_less_next(char *s, flags *f, int l, count_d *rx);
void    ft_count_num_ll(long long n, char *buff, int *res);
void    print_zero_decimal_next(char *ap, flags *f, int i);
void    print_zero_decimal(char *ap, int *len, flags *f);
void	fill_type(const char *ft, flags *tmp, int start);
void    print_zero_decimal(char *ap, int *len, flags *f);
void    find_weidth(const char *ft, flags *f, int start);
int     count_decimal(flags *f, va_list ap, char *buff);
void	fill_flag(const char *fmt, flags *f, int start);
void    print_str_decimal(char *ap, int *len, flags *f);
int     all_formats(const char *ft, int i, va_list ap);
void	to_null(flags *f, const char *ft, int start);
void    ft_count_num_l(long n, char *buff, int *res);
void    ft_count_num_l(long n, char *buff, int *res);
void	print_hex(long nb, int *pointlen, flags *f);
void    ft_count_num_i(int n, char *buff, int *res);
int    	l_big_next(char *s, flags *f, int l, int x);
void    fill_len(const char *ft, flags *tm, int c);
int    	convert_to_l(unsigned long src, flags *f);
int     how_much_l(unsigned long tmp, flags *f);
int		rn(unsigned long long value, int base);
int     print_char_decimal(flags *f, char *ap);
void	ft_to_string(char (*bufer)[70], int n);
void	ft_putnstr(char *str, int n, int end);
int		to_weidth(char *ap, int c, flags *f);
int     how_much(unsigned int tmp, flags *f);
int     print_address(flags *f, va_list ap);
int		ft_printf(const char *format, ...);
int		ft_round(char (*bufer)[70], int p);
int     print_num_str(char *s, flags *f);
int     l_less(char *s, flags *f, int l);
void    put_zero(int s, int p, flags *f);
int		print_float(flags *f, char *ap);
int     find_le(const char *ft, int st);
int    	l_big(char *s, flags *f, int l);
int     print_ch(flags *f, va_list ap);
void    print_space(int len, flags *f);
int     convert(va_list ap, flags *f);
void    if_hash(char **dst, flags *f);
void	print_space(int c, flags *f);
void	print_zero(int c, flags *f);
void	print_space_float(use *box);
void	print_str(char *ap, int l);
void    put_space(int l, flags *f);
char    do_16_abc(int t, flags *f);
void	ft_decminus(use *box);
void    only_zero(char *s);

#endif
