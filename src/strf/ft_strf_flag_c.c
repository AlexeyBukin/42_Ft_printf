/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strf_flag_di.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 08:08:02 by kcharla           #+#    #+#             */
/*   Updated: 2020/08/08 16:29:01 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strf.h"

/*
** works as `cat -v`
*/

char		*ft_strf_flag_c(va_list arg, t_strflags *flags)
{
	t_byte		val;
	char		*res;

	if (flags->cast == CAST_L)
		val = (t_byte)va_arg(arg, unsigned long int);
	else
		val = (t_byte)va_arg(arg, unsigned int);
	ft_strf_adjust_c(flags);
	if (val == ASCII_DEL)
	{
		res = ft_strdup("^?");
	}
	else if (val < ASCII_UNREADABLE_BEFORE && val != ASCII_NEWLINE)
	{
		val += ASCII_UNREADABLE_DIFF;
		res = ft_strdup("^");
		res = ft_strjoin_free(res,
				ft_char_to_str(val));
	}
	else if (val > ASCII_DEL && val < ASCII_UNREADABLE_AFTER)
	{
		val -= ASCII_UNREADABLE_DIFF;
		res = ft_strdup("M-^");
		res = ft_strjoin_free(res,
									ft_char_to_str(val));
	}
	else
		res = ft_char_to_str(val);
	res = ft_strf_format_width(res, flags);
	return (res);
}

//char		*ft_strf_flag_c(va_list arg, t_strflags *flags)
//{
//	char		val;
//	char		*character;
//
//	if (flags->cast == CAST_L)
//		val = (char)va_arg(arg, long int);
//	else
//		val = (char)va_arg(arg, int);
//	ft_strf_adjust_c(flags);
//	flags->width = (val == 0) ? 1 : flags->width;
////	if (val != 0)
//	{
//		character = ft_char_to_str(val);
//		character = ft_strf_format_width(character, flags);
//	}
////	else
////	{
////		character = ft_strdup("");
////	}
//	return (character);
//}
////
//char		*ft_strf_flag_di(va_list arg, t_strflags *flags)
//{
//	char			*res;
//	long long int	d;
//
//	if (flags == NULL || ft_strf_flag_di_cast(&d, flags, arg))
//		return (NULL);
//	flags->num_sign = (char)d;
//	res = (flags->precision == 0 && d == 0)
//			? ft_strdup("") : ft_ulltoa(ft_absl(d));
//	ft_strf_adjust_di(flags);
//	res = ft_strf_format_prec(res, flags);
//	res = ft_strf_format_zero(res, flags);
//	if (d < 0)
//		res = ft_strjoin_free(ft_strdup("-"), res);
//	if (flags->plus == 1 && d >= 0)
//		res = ft_strjoin_free(ft_strdup("+"), res);
//	if (flags->space == 1 && flags->plus == 0 && d >= 0)
//		res = ft_strjoin_free(ft_strdup(" "), res);
//	res = ft_strf_format_width(res, flags);
//	return (res);
//}
