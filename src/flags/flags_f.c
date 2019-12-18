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

#define alt         0 // dot always exist
#define f_or_F      1
#define shift       2 //which side shift, 0 is right
#define sign        3 //0 : not enter +
#define zero        4 //to fill with 0
#define w1          5 //width before dot
#define w2          6 //width after dot
#define error       7
#define flags_num   8

#include "printf.h"

//c00har	*ft_float(char *flags_str, double num);
//char	*ft_long_float(char *flags_str, long double num);

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
			flags[zero] = 1;
		else if (args[i] > '0' && args[i] <= '9')
		{
			if (dot_pass == 0)
				flags[w1] = ft_atoi(&(args[i]));
			else
				flags[w2] = ft_atoi(&(args[i]));
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

char *get_special(int *flags, int spec_type, double num)
{
	(void)num;
	(void)flags;
	(void)spec_type;
	return (NULL);
}

char	*bad_afterdot(double num)
{
	int		i;
	char	b;
	char	a[360];

	ft_bzero(a, 360);
	a[0] = '.';
	i = 0;
	while (num > 0)
	{
		i++;
		num = num * 10;
		b = (char) num;
		num -= b;
		a[i] = b + '0';
	}
	return (ft_strdup(a));
}

char	*bad_way(int *flags, double num)
{
	long long		bdot;
	char			*bdot_a;

	bdot = (long long int) num;
	bdot_a = ft_lltoa(bdot);
	if (bdot_a == NULL || flags == NULL)
		return (NULL);

	num -= bdot;
	if (num < 0)
		num *= -1;

	if (flags[sign] == 1 && num >= 0)
		bdot_a = ft_strjoin_free(ft_strdup("+"), bdot_a);
	bdot_a = ft_strjoin_free(bdot_a, bad_afterdot(num));
	return (bdot_a);
}


char	*ft_float(int *flags, double num)
{
	int		special_type;
	size_t	len;
	char	*res;

	if ((special_type = is_special(num)) > 0)
		return (get_special(flags, special_type, num));
	res = bad_way(flags, num);
	if ((int) len < flags[WIDTH])
	{
		if (flags[shift] == 0)
			res = ft_strjoin_free(ft_str_spam((flags[zero] ? "0" : " "), flags[w1] - len), res);
		else
			res = ft_strjoin_free(res, ft_str_spam(" ", flags[w1] - len));
	}
	return (res);
}

//int get_exponent(double d)
//{
//	(void) d;
//	return (1);
//}
//
//void	print_double_as_binary(double d)
//{
//	char * stb1 = ft_mtob(&d, sizeof(double));
//	char * st1 = ft_str_div_by_ins(stb1, 4, " ");
//	char * st21 = ft_str_div_by_ins(st1, 10, "   ");
//	ft_putendl(st21);
//}