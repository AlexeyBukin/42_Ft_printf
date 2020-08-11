/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strf_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 14:24:54 by kcharla           #+#    #+#             */
/*   Updated: 2020/08/11 08:46:33 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strf.h"

char		*ft_strf_format_prec(char *string, t_strflags *flags)
{
	int		len;

	if (string == NULL)
		return (NULL);
	len = (int)ft_strlen(string);
	if (flags->precision > len)
		string = ft_strjoin_free(ft_str_spam("0",
				(flags->precision) - len), string);
	return (string);
}

char		*ft_strf_format_width(char *string, t_strflags *flags)
{
	size_t		len;

	len = ft_strlen(string);
	if (!(flags->width > 0 && len < (size_t)flags->width))
		return (string);
	len = flags->width - len;
	if (flags->minus == 1)
		string = ft_strjoin_free(string, ft_str_spam(" ", len));
	else
		string = ft_strjoin_free(ft_str_spam(" ", len), string);
	return (string);
}

char		*ft_strf_format_zero(char *string, t_strflags *flags)
{
	int			len;

	if (flags->zero == 1 && flags->precision == FT_PRECISION_DEFAULT
			&& flags->minus == 0)
	{
		len = (int)ft_strlen(string);
		if (flags->plus == 1 || flags->space == 1 || flags->num_sign < 0)
			len++;
		if (flags->sharp == 1 && (flags->num_sign != 0))
			len += (flags->type == 'x' || flags->type == 'X') ? 2 : 1;
		if (len <= flags->width)
			string = ft_strjoin_free(ft_str_spam("0",
					flags->width - len), string);
	}
	return (string);
}
