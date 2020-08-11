/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strf_parse_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 17:39:46 by kcharla           #+#    #+#             */
/*   Updated: 2020/08/11 02:16:39 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strf.h"

void		ft_strflags_init(t_strflags *flags)
{
	if (flags == NULL)
		return ;
	flags->dot = 0;
	flags->precision = FT_PRECISION_DEFAULT;
	flags->width = FT_WIDTH_DEFAULT;
	flags->plus = 0;
	flags->minus = 0;
	flags->zero = 0;
	flags->space = 0;
	flags->sharp = 0;
	flags->type = '-';
	flags->special = F_UNSET;
	flags->cast = CAST_NO;
}

int			ft_strf_is_known_flag(int ch)
{
	if (ft_strchr("scp%diouUxXfF", ch))
		return (1);
	return (0);
}

int			ft_strf_is_parsable(int ch)
{
	if (ft_strchr(".1234567890-+ #Llhjzt", ch) && ch != '\0')
		return (1);
	return (0);
}
