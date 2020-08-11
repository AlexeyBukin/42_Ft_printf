/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strf_flag_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 13:59:02 by kcharla           #+#    #+#             */
/*   Updated: 2020/08/11 02:10:09 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strf.h"

char		*ft_strf_flag_u(va_list arg, t_strflags *flags)
{
	char				*res;
	uintmax_t			d;

	if (flags == NULL)
		return (NULL);
	ft_strf_adjust_u(flags);
	if (ft_strf_cast_flag_ull(&d, flags, arg))
		return (NULL);
	if (flags->precision == 0 && d == 0)
		res = ft_strdup("");
	else
		res = ft_ulltoa(d);
	res = ft_strf_format_prec(res, flags);
	res = ft_strf_format_zero(res, flags);
	res = ft_strf_format_width(res, flags);
	return (res);
}
