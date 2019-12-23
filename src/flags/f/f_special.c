/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_special.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 17:50:22 by kcharla           #+#    #+#             */
/*   Updated: 2019/12/23 17:50:29 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		f_is_special(long double num)
{
	char					sign;
	unsigned char			bytes[10];

	ft_memcpy(&(bytes[0]), &num, 10);

	sign = ((bytes[9] & 0x80) == 0x00) ? 1 : -1;

	//all ones
	if ((bytes[9] | 0x80) == 0xff && bytes[8] == 0xff)
	{
		if ((bytes[7] | 0x3f) == 0xff) // 11xxxxxx
		{
			return(F_NAN);
		}
		else if ((bytes[7] | 0x3f) == 0x7f) // 01xxxxxx
		{
			return(F_NAN);
		}
		else if((bytes[7] & 0xc0) == 0x00) // 00xxxxxx
		{
			unsigned char res = 0;
			res += (bytes[7] & 0x3f) + bytes[6] + bytes[5] +bytes[4];
			res += bytes[3] + bytes[2] +bytes[1] + bytes[0];
			if (res == 0x00)
				return(F_INF * sign);
			else
				return(F_NAN);
		}
		else    // 10xxxxxx
		{
			unsigned char res = 0;
			res += (bytes[7] & 0x3f) + bytes[6] + bytes[5] +bytes[4];
			res += bytes[3] + bytes[2] +bytes[1] + bytes[0];
			if (res == 0x00)
				return(F_INF * sign);
			else
				return(F_NAN);
		}
	}
	return (F_N0_SPECIAL * sign);
}

char	*f_get_special(int *flags)
{
	char	*res;

	if (flags == NULL)
		return (NULL);
	int special = flags[SPECIAL];
	flags[ZERO] = 0;
	if (special == F_NAN)
	{
		flags[PLUS] = 0;
		flags[SPACE] = 0;
		res = ft_strdup("nan");
	}
	else if (special == F_INF)
	{
		res = ft_strdup("inf");
	}
	else
		return (NULL);

	if (flags[FLAG] == 'F')
	{
		ft_str_up(res);
	}
	return (res);
}
