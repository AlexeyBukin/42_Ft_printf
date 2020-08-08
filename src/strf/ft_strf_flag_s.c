/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strf_flag_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 17:59:17 by kcharla           #+#    #+#             */
/*   Updated: 2020/08/08 13:28:24 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strf.h"

char		*ft_strf_flag_s(va_list arg, t_strflags *flags)
{
	int 		len;
	char		*insert;

	if (flags == NULL)
		return (NULL);
	if ((insert = va_arg(arg, char*)) != NULL)
		insert = ft_strdup(insert);
	else
		insert = ft_strdup("(null)");
	ft_strf_adjust_s(flags);
	if (flags->precision < (int)ft_strlen(insert) && flags->precision >= 0)
		insert[flags->precision] = '\0';
	insert = ft_strf_format_width(insert, flags);
	insert = ft_strf_format_zero(insert, flags);
	return (insert);
}
