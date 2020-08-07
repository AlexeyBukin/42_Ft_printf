/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strf_flag_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 14:10:00 by kcharla           #+#    #+#             */
/*   Updated: 2020/08/07 14:17:29 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strf.h"

char		*ft_strf_flag_p(va_list arg, t_strflags *flags)
{
	unsigned long long	d;
	char				*res;

	if (flags == NULL)
		return (NULL);
	d = (unsigned long long)va_arg(arg, unsigned long long);
	ft_strf_adjust_p(flags);
	if (flags->precision == 0 && d == 0)
		res = ft_strdup("");
	else
		res = ft_ulltoa_base(d, BASE16L);
	res = ft_strf_format_prec(res, flags);
	res = ft_strjoin_free(ft_strdup("0x"), res);
	res = ft_strf_format_zero(res, flags);
	res = ft_strf_format_width(res, flags);
	return (res);
}
