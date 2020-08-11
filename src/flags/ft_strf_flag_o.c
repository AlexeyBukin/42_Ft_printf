/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strf_flag_o.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 13:50:49 by kcharla           #+#    #+#             */
/*   Updated: 2020/08/11 10:38:50 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strf.h"

char		*ft_strf_flag_o(va_list arg, t_strflags *flags)
{
	char				*res;
	t_uintmax			d;

	if (flags == NULL || ft_strf_cast_flag_ull(&d, flags, arg))
		return (NULL);
	ft_strf_adjust_o(flags);
	flags->num_sign = (char)(d);
	if (flags->precision == 0 && d == 0 && flags->sharp == 0)
		res = ft_strdup("");
	else
		res = ft_ulltoa_base(d, BASE8);
	if (flags->sharp == 1 && d != 0)
		res = ft_strjoin_free(ft_strdup("0"), res);
	res = ft_strf_format_prec(res, flags);
	res = ft_strf_format_zero(res, flags);
	res = ft_strf_format_width(res, flags);
	return (res);
}
