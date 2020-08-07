/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strf_flag_cast.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 14:05:04 by kcharla           #+#    #+#             */
/*   Updated: 2020/08/07 14:05:31 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strf.h"

int			ft_strf_flag_cast_ull(unsigned long long *d, t_strflags *flags, va_list arg)
{
	if (flags == NULL || d == NULL)
		return (-1);
	if (flags->cast == CAST_NO)
		*d = (unsigned int)va_arg(arg, int);
	else if (flags->cast == CAST_HH)
		*d = (unsigned char)va_arg(arg, int);
	else if (flags->cast == CAST_H)
		*d = (unsigned short)va_arg(arg, int);
	else if (flags->cast == CAST_L)
		*d = (unsigned long)va_arg(arg, long int);
	else if (flags->cast == CAST_LL)
		*d = (unsigned long long)va_arg(arg, long long int);
	else
		return (-1);
	return (0);
}