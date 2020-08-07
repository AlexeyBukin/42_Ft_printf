/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strf_format_zero.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 14:28:26 by kcharla           #+#    #+#             */
/*   Updated: 2020/08/07 15:39:57 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strf.h"

char		*ft_strf_format_zero(char *string, t_strflags *flags)
{
	size_t		len;

	if (ft_strchr("diouxXfF%", flags->type) == NULL)
		return (string);
	if (flags->zero == 1 && flags->precision == FT_PRECISION_DEFAULT && flags->minus == 0)
	{
		len = ft_strlen(string);
		if (flags->plus == 1 || flags->space == 1 || flags->num_sign < 0)
			len++;
		if (flags->sharp == 1 && (flags->num_sign != 0))
			len += (flags->type == 'x' || flags->type == 'X') ? 2 : 1;
		if ((int)len < flags->width)
			string = ft_strjoin_free(ft_str_spam("0", flags->width - (int)len), string);
	}
	return (string);
}
