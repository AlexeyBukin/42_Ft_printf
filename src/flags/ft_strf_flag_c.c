/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strf_flag_di.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 08:08:02 by kcharla           #+#    #+#             */
/*   Updated: 2020/08/11 10:58:01 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strf.h"

/*
** works as `cat -v` so no '\0' can be inserted as it is
*/

char		*ft_strf_flag_c(va_list arg, t_strflags *flags)
{
	t_byte		val;
	char		*res;

	val = (t_byte)((flags->cast == CAST_L) ? va_arg(arg, unsigned long int) :
			va_arg(arg, unsigned int));
	ft_strf_adjust_c(flags);
	if (val == ASCII_DEL)
		res = ft_strdup("^?");
	else if (val < ASCII_UNREADABLE_BEFORE && val != ASCII_NEWLINE)
	{
		val += ASCII_UNREADABLE_DIFF;
		res = ft_strjoin_free(ft_strdup("^"),
				ft_char_to_str(val));
	}
	else if (val > ASCII_DEL && val < ASCII_UNREADABLE_AFTER)
	{
		val -= ASCII_UNREADABLE_DIFF;
		res = ft_strjoin_free(ft_strdup("M-^"),
				ft_char_to_str(val));
	}
	else
		res = ft_char_to_str(val);
	return (ft_strf_format_width(res, flags));
}
