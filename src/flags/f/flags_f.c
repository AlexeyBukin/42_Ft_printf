/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:40:37 by kcharla           #+#    #+#             */
/*   Updated: 2019/12/23 23:32:31 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char		*bad_way(int *flags, long double num)
{
	char				*after_dot;
	char				sign;
	unsigned long long	bdot;
	char				*bdot_a;

	sign = 1;
	if (num < 0)
	{
		num *= -1;
		sign = -1;
	}
	bdot = (long long int)num;
	num -= bdot;
	char *after_dot_num = f_after_dot(num);
	after_dot = f_after_dot_prec(flags, after_dot_num);
	free(after_dot_num);
	if (after_dot == NULL)
		return (NULL);
	if (flags[PRECISION] == 0)
	{
		if (after_dot[0] == '5')
		{
			if ((bdot % 2) == 1 || ft_strlen(after_dot) > 1)
			{
				bdot++;
			}
		}
		if (after_dot[0] > '5' && after_dot[0] <= '9')
			bdot++;
	}
	else if (flags[SPECIAL] == F_ROUND_YES)
		bdot++;
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

char		*ft_float(va_list arg, int *flags)
{
	char			sign;
	char			*res;
	long double		num;

	if (flags == NULL)
		return (NULL);
	if (flags[CAST] == CAST_BIG_L)
		num = va_arg(arg, long double);
	else
		num = (long double)va_arg(arg, double);
	if (flags[PRECISION] == 0)
		flags[PRECISION] = 6;
	if (flags[PRECISION] == -1)
		flags[PRECISION] = 0;
	sign = 1;
	if ((flags[SPECIAL] = f_is_special(num)) < 0)
	{
		sign = -1;
		flags[SPECIAL] *= -1;
	}
	if (flags[SPECIAL] == F_N0_SPECIAL)
		res = bad_way(flags, num);
	else
		res = f_get_special(flags);
	return (width_format(flags, res, sign));
}
