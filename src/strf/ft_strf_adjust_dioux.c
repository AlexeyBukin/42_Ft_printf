/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strf_adjust_dioux.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 14:59:17 by kcharla           #+#    #+#             */
/*   Updated: 2020/08/06 14:59:18 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strf.h"

void		ft_strf_adjust_di(t_strflags *flags)
{
	if (flags == NULL)
		return ;
	flags->sharp = 0;
}

void		ft_strf_adjust_o(t_strflags *flags)
{
	if (flags == NULL)
		return ;
	flags->space = 0;
	flags->plus = 0;
	flags->sharp = 0;
}

void		ft_strf_adjust_u(t_strflags *flags)
{
	if (flags == NULL)
		return ;
	flags->space = 0;
	flags->plus = 0;
	flags->sharp = 0;
}

void		ft_strf_adjust_x(t_strflags *flags)
{
	if (flags == NULL)
		return ;
	flags->space = 0;
	flags->plus = 0;
	flags->sharp = 0;
}
