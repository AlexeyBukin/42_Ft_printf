/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strf_flag_e.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebulwer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 18:37:08 by ebulwer           #+#    #+#             */
/*   Updated: 2020/10/27 18:37:14 by ebulwer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char 				*float_flag_e(t_strflags *flags, long double d)
{
	char			*res;
	int 			sign;
	char 			*exp;
	int 			counter;
	char 			*count;

	sign = d < 0 ? -1 : 1;
	d *= sign;
	counter = 0;
	while (d < 10 && d > 1)
	{
		counter += (d > 1) ? 1 : -1;
		d *= (d > 1) ? 0.1 : 10;
	}
	res = float_get_str(flags, d); // проблема тут
	res = ft_strfloat__fformat(flags, res, sign);
	exp = ft_strdup("e+");
	exp[0] = flags->type;
	exp[1] = counter >= 0 ? '+' : '-';
	counter *= counter >= 0 ? 1 : -1;
	count = ft_itoa(counter);
	if (ft_strlen(count) < 2)
		count = ft_strjoin_free(ft_strdup("0"), count);
	exp = ft_strjoin_free(exp, count);
	res = ft_strjoin_free(res, exp);
	return (res);
	/*
	// exp - e+
	// count - power
	// res - 0.
	*/
}

char 				*ft_strf_flag_e(va_list arg, t_strflags *flags)
{


	long double		d;
	char 			*res;

	if (flags == NULL || ft_strf_flag_f_cast(&d, flags, arg))
		return (NULL);
	flags->cast = CAST_BIG_L;
	if (ft_strf_flag_f_cast(&d, flags, arg))
		return (NULL);
	ft_strf_adjust_f(flags);
	flags->special = float_is_special(d);
	if (flags->special != F_N0_SPECIAL)
	{
		res = float_get_special(flags);
	}
	else
	{
		res = float_flag_e(flags, d);
	}
	return (res);
}
