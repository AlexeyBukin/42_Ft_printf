/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strf_flag_f_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 14:49:15 by kcharla           #+#    #+#             */
/*   Updated: 2020/08/11 23:41:40 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strf.h"

char		*float_get_str(t_strflags *flags, long double d)
{
	(void)flags;
//	char 	*raw;
//	char 	*ready;

//	if (d < 1000000000000L && flags->precision < FT_FLOAT_FAST_PREC)
	{
		return (ft_strf_flag_f_fast((double)d));
	}
//	raw = ft_strf_flag_f_fast(d);
//	ready = ft_strf_flag_f_round(raw, flags);
//	return (ready);
}
