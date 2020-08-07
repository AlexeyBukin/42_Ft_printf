/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strf_flag_f.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 14:21:53 by kcharla           #+#    #+#             */
/*   Updated: 2020/08/07 14:56:52 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strf.h"

static int			ft_strf_flag_f_cast(long double *d, t_strflags *flags, va_list arg)
{
	if (flags == NULL || d == NULL)
		return (-1);
	if (flags->cast == CAST_BIG_L)
		*d = (long double)va_arg(arg, long double);
	else
		*d = (long double)va_arg(arg, double);
	return (0);
}

char	*ft_strf_float_format(t_strflags *flags, char *str, char sign)
{
	int		len;
	int		w;

	if (str == NULL || flags == NULL)
		return (NULL);
	len = (int)ft_strlen(str);
	w = flags->width - (sign < 0 || flags->plus == 1 || flags->space == 1);
	if (len < w)
	{
		if (flags->minus == 0 && flags->zero == 1)
			str = ft_strjoin_free(ft_str_spam("0", w - len), str);
		else if (flags->minus == 1)
			str = ft_strjoin_free(str, ft_str_spam(" ", w - len));
	}
	if (flags->space == 1 && sign > 0 && flags->plus == 0)
		str = ft_strjoin_free(ft_strdup(" "), str);
	if (sign < 0)
		str = ft_strjoin_free(ft_strdup("-"), str);
	else if (flags->plus == 1)
		str = ft_strjoin_free(ft_strdup("+"), str);
	if (len < w && flags->minus == 0 && flags->zero == 0)
		str = ft_strjoin_free(ft_str_spam(" ", w - len), str);
	return (str);
}

char		*ft_strf_flag_f(va_list arg, t_strflags *flags)
{
	long double			d;
	char				*res;

	if (flags == NULL || ft_strf_flag_f_cast(&d, flags, arg))
		return (NULL);
	ft_strf_adjust_f(flags);
	if (flags->precision == FT_PRECISION_DEFAULT)
		flags->precision = FT_PRECISION_FLOAT;
	flags->special = float_is_special(d);
	res = (flags->special == F_N0_SPECIAL) ? float_get_str(flags, d) : float_get_special(flags);
	res = ft_strf_float_format(flags, res, (d < 0) ? -1 : 1);
	return (res);
}
