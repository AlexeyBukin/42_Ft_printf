/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strf_format_zero.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 14:28:26 by kcharla           #+#    #+#             */
/*   Updated: 2020/08/06 14:28:26 by kcharla          ###   ########.fr       */
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
		if (flags->plus == 1 || flags->space == 1)
			len++;
		len = (flags->sharp == 1 && !(flags->num_zero)) ? len + 1 : len;
		if (len < (size_t)flags->width)
			string = ft_strjoin_free(ft_str_spam("0", flags->width - (int)len), string);
	}
	return (string);
}
