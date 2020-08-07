/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strf_flag_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 13:18:50 by kcharla           #+#    #+#             */
/*   Updated: 2020/08/07 15:02:19 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strf.h"

char		*ft_strf_flag_x(va_list arg, t_strflags *flags)
{
	char				*res;
	unsigned long long	d;

	if (flags == NULL || ft_strf_flag_cast_ull(&d, flags, arg))
		return (NULL);
	ft_strf_adjust_x(flags);
	flags->num_sign = (char)(d);
	if (flags->precision == 0 && d == 0)
		res = ft_strdup("");
	else
		res = (flags->type == 'X') ?
				ft_ulltoa_base(d, BASE16U) : ft_ulltoa_base(d, BASE16L);
	res = ft_strf_format_prec(res, flags);
	res = ft_strf_format_zero(res, flags);
	if (flags->sharp == 1 && d != 0)
		res = ft_strjoin_free(ft_strdup(
				(flags->type == 'X') ? "0X" : "0x"), res);
	res = ft_strf_format_width(res, flags);
	return (res);
}
