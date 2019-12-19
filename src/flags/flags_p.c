/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelina <lmelina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 19:23:35 by lmelina           #+#    #+#             */
/*   Updated: 2019/12/19 23:37:39 by lmelina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_insert_p(va_list arg, int *flags)
{
	unsigned long long d;
	char				*num;
	char				*zero;
	char				*ffff;
	int 				len;

	if (flags[CAST] == CAST_NO)
	{
		d = (unsigned int) va_arg(arg, int);
	}
	else if (flags[CAST] == CAST_HH)
	{
		d = (unsigned char) va_arg(arg, int);
		//printf("\nd:\'%hhd\'\n", (char)d);
	}
	else if (flags[CAST] == CAST_H)
	{
		d = (unsigned short) va_arg(arg, int);
	}
	else if (flags[CAST] == CAST_L)
	{
		d = (unsigned long) va_arg(arg, long int);
	}
	else if (flags[CAST] == CAST_LL)
	{
		d = (unsigned long long) va_arg(arg, long long int);
	}
	else
	{
		return (NULL);
	}
	zero = "0x";
	ffff = "7fff";
	num = ft_ulltoa_base(d, BASE16L); //"0123456789abcdef"
	if (d)
		num = ft_strjoin(ffff, num);
	num = ft_strjoin(zero, num);
	if (flags[WIDTH] > 0 && (int)ft_strlen(num) < flags[WIDTH])
	{
		len = (int)ft_strlen(num);
		num = ft_strjoin_free(ft_str_spam(" ", flags[WIDTH] - len), num);
	}
	return (num);
}