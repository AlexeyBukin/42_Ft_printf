/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strf_flag_f_special.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 14:45:12 by kcharla           #+#    #+#             */
/*   Updated: 2020/08/07 14:48:09 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strf.h"

/*
** double treated as 10-bytes
*/

int			float_is_special(long double num)
{
//	char				sign;
	unsigned char		bytes[10];
	unsigned char		res;

	ft_memcpy(&(bytes[0]), &num, 10);
//	sign = ((bytes[9] & 0x80) == 0x00) ? 1 : -1;
	if ((bytes[9] | 0x80) == 0xff && bytes[8] == 0xff)
	{
		if ((bytes[7] | 0x3f) == 0xff)
			return (F_NAN);
		else if ((bytes[7] | 0x3f) == 0x7f)
			return (F_NAN);
		else
		{
			res = (bytes[7] & 0x3f) + bytes[6] + bytes[5] + bytes[4];
			res += bytes[3] + bytes[2] + bytes[1] + bytes[0];
			if (res == 0x00)
				return (F_INF);
			else
				return (F_NAN);
		}
	}
	return (F_N0_SPECIAL);
}

char		*float_get_special(t_strflags *flags)
{
	char				*res;

	if (flags == NULL)
		return (NULL);
	flags->zero = 0;
	if (flags->special == F_NAN)
	{
		flags->plus = 0;
		flags->space = 0;
		res = ft_strdup("nan");
	}
	else if (flags->special == F_INF)
	{
		res = ft_strdup("inf");
	}
	else
		return (NULL);
	if (flags->type == 'F')
	{
		ft_str_up(res);
	}
	return (res);
}
