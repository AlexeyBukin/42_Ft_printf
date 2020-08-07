/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strf_flag_di.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 08:08:02 by kcharla           #+#    #+#             */
/*   Updated: 2020/08/07 08:56:33 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strf.h"

int			ft_strf_flag_di_cast(long long *d, t_strflags *flags, va_list arg)
{
	if (flags == NULL || d == NULL)
		return (-1);
	if (flags->cast == CAST_NO)
		*d = va_arg(arg, int);
	else if (flags->cast == CAST_HH)
		*d = (char)va_arg(arg, int);
	else if (flags->cast == CAST_H)
		*d = (short)va_arg(arg, int);
	else if (flags->cast == CAST_L)
		*d = va_arg(arg, long int);
	else if (flags->cast == CAST_LL)
		*d = va_arg(arg, long long int);
	else
		return (-1);
	return (0);
}

char		*ft_strf_flag_di(va_list arg, t_strflags *flags)
{
	char			*res;
	long long int	d;

	if (flags == NULL || ft_strf_flag_di_cast(&d, flags, arg))
		return (NULL);
	res = (flags->precision == 0 && d == 0)
			? ft_strdup("") : ft_ulltoa(ft_absl(d));
	ft_strf_adjust_di(flags);
	res = ft_strf_format_prec(res, flags);
	res = ft_strf_format_zero(res, flags);
	if (d < 0)
		res = ft_strjoin_free(ft_strdup("-"), res);
	if (flags->plus == 1 && d >= 0)
		res = ft_strjoin_free(ft_strdup("+"), res);
	if (flags->space == 1 && flags->plus == 0 && d >= 0)
		res = ft_strjoin_free(ft_strdup(" "), res);
	res = ft_strf_format_width(res, flags);
	return (res);
}
