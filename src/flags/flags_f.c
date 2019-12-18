/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:40:37 by kcharla           #+#    #+#             */
/*   Updated: 2019/12/04 20:49:25 by lmelina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#define alt         0 // dot always exist
//#define f_or_F      1
//#define shift       2 //which side shift, 0 is right
//#define sign        3 //0 : not enter +
//#define zero        4 //to fill with 0
//#define w1          5 //width before dot
//#define w2          6 //width after dot
//#define error       7
//#define flags_num   8

#include "printf.h"

int		f_parse_flags(char *args, int *flags)
{
	int		dot_pass;
	int 	i;

	i = 0;
	if (args == NULL || flags == NULL)
		return (-1);
	while (args[i] != 0)
	{
		if (args[i] == '.' && dot_pass == 0)
			dot_pass = 1;
		else if (args[i] == '0' && dot_pass == 0)
			flags[ZERO] = 1;
		else if (args[i] > '0' && args[i] <= '9')
		{
			if (dot_pass == 0)
				flags[WIDTH] = ft_atoi(&(args[i]));
			else
				flags[PRECISION] = ft_atoi(&(args[i]));
			while (args[i] >= '0' && args[i] <= '9')
				i++;
			continue ;
		}
		i++;
	}
	return (0);
}

int		is_special(double num)
{
	(void)num;
	return (0);
}

char *get_special(int *flags, double num)
{
	(void)num;
	(void)flags;
	return (NULL);
}

char	*bad_afterdot(long double num)
{
	int		i;
	char	b;
	char	a[360];

	ft_bzero(a, 360);
	i = 0;
	//printf("num is %Lf\n\n", num);

	if (num == 0)
		return (ft_strdup(""));
	while (num > 0)
	{
		num = num * 10;
		b = (char) num;
		num -= b;
		a[i] = b + '0';
		i++;
	}
	return (ft_strdup(a));
}

char	*bad_way(int *flags, long double num)
{
	char			sign;
	int				len;
	long long		bdot;
	char			*bdot_a;

	sign = 1;
	if (num < 0)
	{
		num *= -1;
		sign = -1;
	}
	bdot = (long long int) num;
	bdot_a = ft_lltoa(bdot);
	if (bdot_a == NULL || flags == NULL)
		return (NULL);

	num -= bdot;

	if (sign < 0)
		bdot_a = ft_strjoin_free(ft_strdup("-"), bdot_a);
	else
		if (flags[PLUS] == 1)
			bdot_a = ft_strjoin_free(ft_strdup("+"), bdot_a);

	//	if (flags[PLUS] && sign == ' ')
	//	bdot_a = ft_strjoin_free(ft_strdup("+"), bdot_a);
	//else
	//	bdot_a = ft_strjoin_free(ft_strdup("+"), bdot_a);

	char *after_dot = bad_afterdot(num);
	len = (int) ft_strlen(after_dot);
	if (flags[PRECISION] > len)
		after_dot = ft_strjoin_free(after_dot, ft_str_spam("0", flags[PRECISION] - len));

	if (after_dot == NULL)
		return (NULL);

	int b = flags[PRECISION];

	//printf("b is %d [%c], adot is \'%s\'\n", b, after_dot[b], after_dot);

	if (after_dot[b] >= '5')
	{
		after_dot[b - 1]++;
	}

//	b--;
//	int was_rounded = 1;
//	while (b > 1 && was_rounded)
//	{
//		was_rounded = 0;
//		if (after_dot[b] >= '5' && after_dot[b - 1] >= '9')
//		{
//			was_rounded = 1;
//			after_dot[b - 1]++;
//		}
//		b--;
//	}
//	if (after_dot[0] > '9')
//	{
//		flags[SPECIAL] = SPECIAL_ROUND_BIGGER;
//		after_dot[0] = '0';
//	}

	//printf("b is %d [%c], adot is \'%s\'\n", b, after_dot[b], after_dot);

	b = 1;
	while (b < flags[PRECISION])
	{
		if (after_dot[b] > '9')
			after_dot[b] = '0';
		b++;
	}

	after_dot[flags[PRECISION]] = '\0';

	bdot_a = ft_strjoin_free(bdot_a, ft_strdup("."));
	bdot_a = ft_strjoin_free(bdot_a, after_dot);

	return (bdot_a);
}


char	*ft_float(va_list arg, int *flags)
{
	long double	num;
	size_t	len;
	char	*res;

	if (flags[CAST] == CAST_BIG_L)
		num = va_arg(arg, long double);
	else
		num = (long double) va_arg(arg, double);
	if ((flags[SPECIAL] = is_special(num)) > 0)
		return (get_special(flags, num));

	if (flags[PRECISION] == 0)
		flags[PRECISION] = 6;
	if (flags[PRECISION] == -1)
		flags[PRECISION] = 0;

	res = bad_way(flags, num);

	len = ft_strlen(res);
	if ((int) len < flags[WIDTH])
	{
		if (flags[MINUS] == 0)
			res = ft_strjoin_free(ft_str_spam((flags[ZERO] ? "0" : " "), flags[WIDTH] - len), res);
		else
			res = ft_strjoin_free(res, ft_str_spam(" ", flags[WIDTH] - len));
	}
	return (res);
}
