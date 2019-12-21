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

char	*width_format(int *flags, char *str, char sign)
{
	int len;
	int w;

	if (str == NULL)
		return (NULL);

	len = (int)ft_strlen(str);
	w = flags[WIDTH] - (sign < 0 || flags[PLUS] == 1 || flags[SPACE] == 1);

	//printf ("w = %d, len = %d, str = \'%s\'\n", w, len, bdot_a);
	if (len < w)
	{
		if (flags[MINUS] == 0)
		{
			if (flags[ZERO] == 1)
				str = ft_strjoin_free(ft_str_spam("0", w - len), str);
		}
		else
			str = ft_strjoin_free(str, ft_str_spam(" ", w - len));
	}
	if (flags[SPACE] == 1 && sign > 0 && flags[PLUS] == 0)
		str = ft_strjoin_free(ft_strdup(" "), str);

	if (sign < 0)
		str = ft_strjoin_free(ft_strdup("-"), str);
	else if (flags[PLUS] == 1)
		str = ft_strjoin_free(ft_strdup("+"), str);

	if (len < w && flags[MINUS] == 0 && flags[ZERO] == 0)
		str = ft_strjoin_free(ft_str_spam(" ", w - len), str);

	return (str);
}

int		is_special(long double num)
{
	char					sign;
	unsigned char			bytes[10];

	ft_memcpy(&(bytes[0]), &num, 10);

	sign = ((bytes[9] & 0x80) == 0x00) ? 1 : -1;

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
				return(F_INF * sign);
			else
				return(F_NAN);
		}
		else    // 10xxxxxx
		{
			unsigned char res = 0;
			res += (bytes[7] & 0x3f) + bytes[6] + bytes[5] +bytes[4];
			res += bytes[3] + bytes[2] +bytes[1] + bytes[0];
			if (res == 0x00)
				return(F_INF * sign);
			else
				return(F_NAN);
		}
	}
	return (F_N0_SPECIAL * sign);
}

char	*get_special(int *flags)
{
	char	*res;

	if (flags == NULL)
		return (NULL);
	int special = flags[SPECIAL];
	flags[ZERO] = 0;
	if (special == F_NAN)
	{
		flags[PLUS] = 0;
		flags[SPACE] = 0;
		res = ft_strdup("nan");
	}
	else if (special == F_INF)
	{
		res = ft_strdup("inf");
	}
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
	while (num > 0 && i < 5000)
	{
		//ft_putnbr(i);
		//ft_putendl("");
		num = num * 10;
		b = (char) num;
		num -= b;
		a[i] = b + '0';
		i++;
	}
	return (ft_strdup(a));
}

char	*bad_afterdot_prec(int *flags, char *after_dot)
{
	int len = (int) ft_strlen(after_dot);
	if (flags[PRECISION] > len)
		after_dot = ft_strjoin_free(after_dot,
				ft_str_spam("0", flags[PRECISION] - len));
	//ft_putendl("lmao not prec");

	int b = flags[PRECISION];
	//ft_putnbr(b);
	if (after_dot[b] >= '5')
	{
		after_dot[--b]++;
	}

	flags[SPECIAL] = F_ROUND_NO;
	while (after_dot[b] > '9')
	{
		after_dot[b] = '0';
		if(b > 0)
			after_dot[--b]++;
		else
		{
			flags[SPECIAL] = F_ROUND_YES;
		}
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

	after_dot[b] = '\0';

	return (after_dot);
}

char	*bad_way(int *flags, long double num)
{
	char				sign;
	unsigned long long	bdot;
	char				*bdot_a;

	sign = 1;
	if (num < 0)
	{
		num *= -1;
		sign = -1;
	}
	bdot = (long long int) num;
	num -= bdot;

	//ft_putendl("lmao not epic bruh");
	char *after_dot = bad_afterdot(num);
	//ft_putendl("lmao not epic");
	after_dot = bad_afterdot_prec(flags, after_dot);

	if (after_dot == NULL)
		return (NULL);


	if (flags[PRECISION] == 0)
		bdot += (after_dot[0] >= '5');
	else if (flags[SPECIAL] == F_ROUND_YES)
		bdot ++;

	bdot_a = ft_ulltoa(bdot);
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

	return (bdot_a);
}

char	*ft_float(va_list arg, int *flags)
{
	char			sign;
	char			*res;
	long double		num;

	if (flags == NULL)
		return (NULL);
	if (flags[CAST] == CAST_BIG_L)
		num = va_arg(arg, long double);
	else
		num = (long double) va_arg(arg, double);

	if (flags[PRECISION] == 0)
		flags[PRECISION] = 6;
	if (flags[PRECISION] == -1)
		flags[PRECISION] = 0;

	//ft_putendl("lmao");
	sign = 1;
	if ((flags[SPECIAL] = is_special(num)) < 0)
	{
		sign = -1;
		flags[SPECIAL] *= -1;
	}
	//ft_putendl("lmao");
	if (flags[SPECIAL] == F_N0_SPECIAL)
	{
		//ft_putendl("lmao here");
		res = bad_way(flags, num);
	}
	else
	{
		res = get_special(flags);
	}
	//ft_putendl("lmao not epic");
	return (width_format(flags, res, sign));
}
