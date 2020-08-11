/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strf_flag_f.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 14:21:53 by kcharla           #+#    #+#             */
/*   Updated: 2020/08/11 23:44:55 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strf.h"

/*
** bd - before dot
** ad - after dot
*/

char		*ft_strf_flag_f_fast_mantissa(double d)
{
	int		i;
	char	c;
	char	a[FT_FLOAT_FAST_PREC];

	i = 0;
	while (d > 0.0 && i < FT_FLOAT_FAST_PREC - 1)
	{
		d *= 10;
		c = (char)d;
		a[i] = (char)(c + '0');
		d -= (double)c;
		i++;
	}
	a[i] = '\0';
	return (ft_strdup(a));
}

char		*ft_strf_flag_f_fast(double d)
{
	char				*ad;
	char				*bd;

	d *= (d < 0) ? (-1) : 1;
	bd = ft_ulltoa((unsigned long long)d);
	ad = ft_strf_flag_f_fast_mantissa(
			d - (double)((unsigned long long)d));
	bd = ft_strjoin_free(bd, ft_strdup("."));
	bd = ft_strjoin_free(bd, ad);
	bd = ft_strf_flag_f_round(bd);
	return (bd);
}
