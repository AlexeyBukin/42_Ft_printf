/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:40:37 by kcharla           #+#    #+#             */
/*   Updated: 2019/12/10 20:45:45 by lmelina          ###   ########.fr       */
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

char	*ft_float(char *flags_str, double num);
char	*ft_long_float(char *flags_str, long double num);

//int		parse_flags(char *args, int *flags)
//{
//	int		dot_pass;
//	int 	i;
//
//	i = 0;
//	if (args == NULL || flags == NULL)
//		return (-1);
//	while (args[i] != 0)
//	{
//		if (args[i] == '.' && dot_pass == 0)
//			dot_pass = 1;
//		else if (args[i] == '0' && dot_pass == 0)
//			flags[zero] = 1;
//		else if (args[i] > '0' && args[i] <= '9')
//		{
//			if (dot_pass == 0)
//				flags[w1] = ft_atoi(&(args[i]));
//			else
//				flags[w2] = ft_atoi(&(args[i]));
//			while (args[i] >= '0' && args[i] <= '9')
//				i++;
//			continue ;
//		}
//		i++;
//	}
//	return (0);
//}

static char		*try_special(int *flags, double num)
{
	(void)num;
	(void)flags;
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

char	*ft_float(char *flags_str, double num)
{
	size_t	len;
	char	*res;
	int		flags[flags_num];

	int i = 0;
	while (i < flags_num)
		flags[i++] = 0;
//	if (parse_flags(flags_str, flags) < 0)
//		return (NULL);

//	printf("alt    = %d\n", flags[alt]);
//	printf("f_or_F = %d\n", flags[f_or_F]);
//	printf("shift  = %d\n", flags[shift]);
//	printf("sign   = %d\n", flags[sign]);
//	printf("zero   = %d\n", flags[zero]);
//	printf("sign   = %d\n", flags[sign]);
//	printf("w1     = %d\n", flags[w1]);
//	printf("w2     = %d\n", flags[w2]);

	res = try_special(flags, num);
	if (flags[error] < 0)
		return (NULL);
	if (res == NULL)
		res = bad_way(flags, num);
	len = ft_strlen(res);
	if ((int) len < flags[w1])
	{
		res = ft_strjoin_free(ft_str_spam(" ", flags[w1] - len), res);
	}
	return (res);
}

int get_exponent(double d)
{
	(void) d;
	return (1);
}

void	print_double_as_binary(double d)
{
	char * stb1 = ft_mtob(&d, sizeof(double));
	char * st1 = ft_str_div_by_ins(stb1, 4, " ");
	char * st21 = ft_str_div_by_ins(st1, 10, "   ");
	ft_putendl(st21);
}

//int main()
//{
//	print_double_as_binary(0);
//}