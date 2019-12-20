/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelina <lmelina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 19:23:35 by lmelina           #+#    #+#             */
/*   Updated: 2019/12/20 22:26:19 by lmelina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"


char	*ft_insert_x(va_list arg, int *flags, int is_x_big)
{
	char				*num;
	int					len;
	unsigned long long	d;

	if (flags[CAST] == CAST_NO)
	{
		d = (unsigned int) va_arg(arg, int);
	}
	else if (flags[CAST] == CAST_HH)
	{
		d = (unsigned char) va_arg(arg, int);
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
	if (flags[PRECISION] == -1 && d == 0)
	{
		num = ft_strdup("");
	}
	else
		num = is_x_big ? ft_ulltoa_base(d, BASE16U) : ft_ulltoa_base(d, BASE16L);
	len = (int)ft_strlen(num);
	if (flags[PRECISION] > len)
		num = ft_strjoin_free(ft_str_spam("0", flags[PRECISION] - ft_strlen(num)), num);
	if (flags[ZERO] == 1 && flags[PRECISION] == 0 && flags[MINUS] == 0)
	{

		len = (int)ft_strlen(num);
		if (flags[PLUS] == 1 || flags[SPACE] == 1)
			len++;
		len = (flags[SHARP] == 1 && d != 0) ? len + 2 : len;
		if (len < flags[WIDTH])
			num = ft_strjoin_free(ft_str_spam("0", flags[WIDTH] - len), num);
	}
	if (flags[SHARP] == 1 && d != 0)
	{
		if (is_x_big == 1)
			num = ft_strjoin_free(ft_strdup("0X"), num);
		else
			num = ft_strjoin_free(ft_strdup("0x"), num);
	}
	if (flags[WIDTH] > 0 && (len = (int)ft_strlen(num)) < flags[WIDTH])
	{
		if (flags[MINUS] == 1)
		{
			num = ft_strjoin_free(num, ft_str_spam(" ", flags[WIDTH] - len));
		}
		else
		{
			num = ft_strjoin_free(ft_str_spam(" ", flags[WIDTH] - len), num);
		}
	}
	free(num);
	return (num);
}
