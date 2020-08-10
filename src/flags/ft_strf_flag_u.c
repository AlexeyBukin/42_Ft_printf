/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strf_flag_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 13:59:02 by kcharla           #+#    #+#             */
/*   Updated: 2020/08/07 14:06:37 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strf.h"

char		*ft_strf_flag_u(va_list arg, t_strflags *flags)
{
	char				*res;
	unsigned long long	d;

	if (flags == NULL || ft_strf_cast_flag_ull(&d, flags, arg))
		return (NULL);
	ft_strf_adjust_u(flags);
	if (flags->precision == 0 && d == 0)
		res = ft_strdup("");
	else
		res = ft_ulltoa(d);
	res = ft_strf_format_prec(res, flags);
	res = ft_strf_format_zero(res, flags);
	res = ft_strf_format_width(res, flags);
	return (res);
}
