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

#include "printf.h"

int		is_special(long double num)
{
	unsigned char			sign;
	unsigned char			bytes[10];
	unsigned long long int	bits;
	unsigned int			expo;

	//num *= -1;
	//printf("\nmtob_1\n\'%s\'\n", ft_mtob(&num, 10));

	ft_memcpy(&(bytes[0]), &num, 10);
	//all ones
	if ((bytes[9] | 0x80) == 0xff && bytes[8] == 0xff)
	{
		if ((bytes[7] | 0x3f) == 0xff) // 11xxxxxx
		{
			return(F_NAN);
		}
		else if ((bytes[7] | 0x3f) == 0x7f) // 01xxxxxx
		{
			return(F_NAN);
		}
		else if((bytes[7] & 0xc0) == 0x00) // 00xxxxxx
		{
			unsigned char res = 0;
			res += (bytes[7] & 0x3f) + bytes[6] + bytes[5] +bytes[4];
			res += bytes[3] + bytes[2] +bytes[1] + bytes[0];
			if (res == 0x00)
				return(((bytes[9] & 0x80) == 0) ? F_INF_POS : F_INF_NEG);
			else
				return(F_NAN);
		}
		else    // 10xxxxxx
		{
			unsigned char res = 0;
			res += (bytes[7] & 0x3f) + bytes[6] + bytes[5] +bytes[4];
			res += bytes[3] + bytes[2] +bytes[1] + bytes[0];
			if (res == 0x00)
				return(((bytes[9] & 0x80) == 0) ? F_INF_POS : F_INF_NEG);
			else
				return(F_NAN);
		}
	}
	return (0);
}

char	*get_special(int *flags)
{
	char	*res;

	if (flags == NULL)
		return (NULL);
	int special = flags[SPECIAL];
	if (special == F_NAN)
		res = ft_strdup("nan");
	else if (special == F_INF_POS)
	{
		if (flags[PLUS] == 1)
			res = ft_strdup("+inf");
		else if (flags[SPACE] == 1)
			res = ft_strdup(" inf");
		else
			res = ft_strdup("inf");
	}
	else if (special == F_INF_NEG)
		res = ft_strdup("-inf");
	else
		return (NULL);

	if (flags[FLAG] == 'F')
	{
		ft_str_up(res);
	}
	return (res);
}

char	*bad_afterdot(long double num)
{
	int		i;
	char	b;
	char	a[5000];

	ft_bzero(a, 5000);
	i = 0;
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

char *bad_afterdot_prec(int *flags, char *after_dot)
{
	int len = (int) ft_strlen(after_dot);
	if (flags[PRECISION] > len)
		after_dot = ft_strjoin_free(after_dot, ft_str_spam("0", flags[PRECISION] - len));
	int b = flags[PRECISION];

	if (after_dot[b] >= '5')// || (after_dot[b] == '5' && sign == 1))
	{
		after_dot[--b]++;
	}

	while (after_dot[b] > '9')
	{
		after_dot[b] = '0';
		if(b > 0)
			after_dot[--b]++;
//		else
//		{
//			flags[SPECIAL] = SPECIAL_ROUND_BIGGER;
//			//printf("special!\n");
//		}

	}

	b = 1;
	while (b < flags[PRECISION])
	{
		if (after_dot[b] > '9')
			after_dot[b] = '0';
		b++;
	}

	b = flags[PRECISION];
	if (b == 0)
		b++;


	//printf("\nb is %d [%c%c%c], adot is \'%.13s\'\n", b, after_dot[b-1], after_dot[b], after_dot[b+1], after_dot);

	after_dot[b] = '\0';

	return (after_dot);
//	printf("\nb is %d [%c%c%c], adot is \'%.13s\'\n", b, after_dot[b-1], after_dot[b], after_dot[b+1], after_dot);

}

char	*bad_way(int *flags, long double num)
{
	char			sign;
	long long		bdot;
	char			*bdot_a;

	sign = 1;
	if (num < 0)
	{
		num *= -1;
		sign = -1;
	}
	bdot = (long long int) num;
	num -= bdot;

	char *after_dot = bad_afterdot(num);

	after_dot = bad_afterdot_prec(flags, after_dot);

	if (after_dot == NULL)
		return (NULL);

	if (flags[PRECISION] == 0)
		bdot += (after_dot[0] >= '5');

	bdot_a = ft_lltoa(bdot);
	if (bdot_a == NULL || flags == NULL)
		return (NULL);

	if (flags[PRECISION] != 0 || flags[SHARP] == 1)
	{
		bdot_a = ft_strjoin_free(bdot_a, ft_strdup("."));
	}

	if (flags[PRECISION] != 0)
	{
		bdot_a = ft_strjoin_free(bdot_a, after_dot);
	}

	//ft_putstr("1111\n");
	////  FUN PART !!

	int len = (int)ft_strlen(bdot_a);
	int w = flags[WIDTH] - (sign < 0 || flags[PLUS] == 1 || flags[SPACE] == 1);

	//printf ("w = %d, len = %d, str = \'%s\'\n", w, len, bdot_a);
	if (len < w)
	{
		if (flags[MINUS] == 0)
		{
			if (flags[ZERO] == 1)
				bdot_a = ft_strjoin_free(ft_str_spam("0", w - len), bdot_a);
		}
		else
			bdot_a = ft_strjoin_free(bdot_a, ft_str_spam(" ", w - len));
	}
	if (flags[SPACE] == 1 && sign > 0 && flags[PLUS] == 0)
		bdot_a = ft_strjoin_free(ft_strdup(" "), bdot_a);

	if (sign < 0)
		bdot_a = ft_strjoin_free(ft_strdup("-"), bdot_a);
	else if (flags[PLUS] == 1)
		bdot_a = ft_strjoin_free(ft_strdup("+"), bdot_a);

	if (len < w && flags[MINUS] == 0 && flags[ZERO] == 0)
		bdot_a = ft_strjoin_free(ft_str_spam(" ", w - len), bdot_a);

	return (bdot_a);
}

char	*ft_float(va_list arg, int *flags)
{
	long double	num;
	int			special;

	if (flags == NULL)
		return (NULL);
	if (flags[CAST] == CAST_BIG_L)
		num = va_arg(arg, long double);
	else
		num = (long double) va_arg(arg, double);

	if ((flags[SPECIAL] = is_special(num)) > 0)
	{
		char * s = get_special(flags);
		//printf("\n\ns is \'%s\'\n\n", s);
		return (s);
	}


	if (flags[PRECISION] == 0)
		flags[PRECISION] = 6;
	if (flags[PRECISION] == -1)
		flags[PRECISION] = 0;

	return (bad_way(flags, num));
}
