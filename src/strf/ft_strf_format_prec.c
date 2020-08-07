/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strf_format_prec.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 14:28:09 by kcharla           #+#    #+#             */
/*   Updated: 2020/08/06 17:32:49 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strf.h"

char		*ft_strf_format_prec(char *string, t_strflags *flags)
{
	size_t		len;

	if (string == NULL)
		return (NULL);
	len = ft_strlen(string);
	if (flags->type == 's')
	{
		if ((size_t)flags->precision < len && flags->precision >= 0)
			string[flags->precision] = '\0';
	}
	if (is_flag_num(flags->type))
	{
		if (flags->precision > (int)len)
			string = ft_strjoin_free(ft_str_spam("0", (flags->precision) - (int)len), string);
	}
	return (string);
}
