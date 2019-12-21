/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:40:37 by kcharla           #+#    #+#             */
/*   Updated: 2019/12/21 21:25:39 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*width_format(int *flags, char *str, char sign)
{
	int len;
	int w;

	if (str == NULL || flags == NULL)
		return (NULL);

	//printf("str = \'%s\', sign = %hhd\n", str, sign);
	len = (int)ft_strlen(str);
	w = flags[WIDTH] - (sign < 0 || flags[PLUS] == 1 || flags[SPACE] == 1);
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
	{
		str = ft_strjoin_free(ft_strdup("-"), str);
	}
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
	if (flags[PRECISION] >= len)
		after_dot = ft_strjoin_free(after_dot,
				ft_str_spam("0", flags[PRECISION] - len + 3));
	//ft_putendl("lmao not prec");

	int b = flags[PRECISION];
	//printf("\n\na  \"%s\"\n", after_dot);
	if (after_dot[b] == '4' && len > flags[PRECISION])
	{
		int i = 1;
		while (b + i < len && after_dot[b + i] == '9')
			i++;
		if (after_dot[b + i] >= '5' && after_dot[b + i] <= '9' && i > 8)
			after_dot[b - 1]++;
	}
	//printf("a\"%s\"\n", after_dot);
	//ft_putnbr(b);
	//printf("b is \"%c%c[%c]%c\"\n", after_dot[b - 2], after_dot[b - 1], after_dot[b], after_dot[b + 1]);
	//b++;
	//printf("b is %d", (int) b);
	//printf("\n\nspam is \"%s\"\n", ft_str_spam("0.", 10));
	//printf("adot is \"%s\"\n", after_dot);
	if (after_dot[b] >= '5' && len > flags[PRECISION])
	{
		//b--;
		after_dot[b - 1]++;
	}
	b = b - (b >= 1);
	//printf("adot is \"%s\"\n\n", after_dot);
	//printf("b is \"%c%c[%c]%c\"\n", after_dot[b - 2], after_dot[b - 1], after_dot[b], after_dot[b + 1]);

//	if (after_dot[b] >= '5')
//	{
//		after_dot[b - 1]++;
//	}
//	b--;
	//printf("b is \"%c%c[%c]%c\"\n", after_dot[b - 2], after_dot[b - 1], after_dot[b], after_dot[b + 1]);
	flags[SPECIAL] = F_ROUND_NO;

	while (after_dot[b] > '9')
	{
//		ft_putnbr(b);
//		ft_putendl("");
		after_dot[b] = '0';
		if(b > 0)
		{
			after_dot[--b]++;
		}
		else
		{
			flags[SPECIAL] = F_ROUND_YES;
			break ;
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
		b = 3;

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

	//ft_putendl("before bad afterdot");
	char *after_dot_num = bad_afterdot(num);
	//ft_putendl("lmao not epic");
	char * after_dot = bad_afterdot_prec(flags, after_dot_num);

	//free(after_dot_num);
	//printf("adot is \'%s\'\n", after_dot);
	if (after_dot == NULL)
		return (NULL);


	if (flags[PRECISION] == 0)
	{
		//printf("here 1\n");
		if (after_dot[0] == '5')
		{
			//printf("here 2\n");
			if ((bdot % 2) == 1 || ft_strlen(after_dot) > 1)
			{
				//printf("here 3\n");
				bdot++;
			}
		}
//		if ((bdot % 2) == 1 && (after_dot[0] == '5') && ft_strlen(after_dot) > 1)
//			bdot++;
		if (after_dot[0] > '5' && after_dot[0] <= '9')
			bdot++;
	}
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

	sign = 1;
	if ((flags[SPECIAL] = is_special(num)) < 0)
	{
		sign = -1;
		flags[SPECIAL] *= -1;
	}

	if (flags[SPECIAL] == F_N0_SPECIAL)
	{
		res = bad_way(flags, num);
	}
	else
	{
		res = get_special(flags);
	}

	//printf("res = \'%s\'\n", res);
	char * resres = width_format(flags, res, sign);
	//printf("resres = \'%s\'\n", resres);
	return (resres);
	//return (width_format(flags, res, sign));
}
