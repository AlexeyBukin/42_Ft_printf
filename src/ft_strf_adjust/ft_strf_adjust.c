/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strf_adjust.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 14:48:58 by kcharla           #+#    #+#             */
/*   Updated: 2020/08/06 15:12:25 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strf.h"

void		ft_strf_adjust(t_strflags *flags)
{
	if (flags == NULL)
		return ;
	if (flags->plus == 1)
		flags->space = 0;
	if (flags->minus == 1)
		flags->zero = 0;
}
