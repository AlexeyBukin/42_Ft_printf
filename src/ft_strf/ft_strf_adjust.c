/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strf_adjust.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 14:48:58 by kcharla           #+#    #+#             */
/*   Updated: 2020/08/12 22:07:00 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strf.h"

/*
** general adjustment functions
*/

void		ft_strf_adjust(t_strflags *flags)
{
	if (flags == NULL)
		return ;
	if (flags->plus == 1)
		flags->space = 0;
	if (flags->minus == 1)
		flags->zero = 0;
}

void		ft_strf_adjust_unknown(t_strflags *flags)
{
	if (flags == NULL)
		return ;
	flags->width--;
	flags->precision = FT_PRECISION_DEFAULT;
	flags->zero = 0;
	flags->sharp = 0;
	flags->plus = 0;
	flags->space = 0;
}
