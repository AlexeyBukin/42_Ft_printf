/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelina <lmelina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 19:23:35 by lmelina           #+#    #+#             */
/*   Updated: 2019/12/16 20:18:07 by lmelina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_insert_u(va_list arg, int *flags)
{
	unsigned long long	d;
	char				*num;
	int					len;

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


	num = ft_ulltoa(d);


	if (flags[PRECISION] > 0)
		num = ft_strjoin_free(ft_str_spam("0", flags[PRECISION] - ft_strlen(num)), num);

	if (flags[ZERO] == 1 && flags[PRECISION] == 0)
	{
		len = (int)ft_strlen(num);
		if (flags[PLUS] == 1 || flags[SPACE] == 1)
			len++;
		num = ft_strjoin_free(ft_str_spam("0", flags[WIDTH] - len), num);
	}

	if (flags[WIDTH] > 0 && (int)ft_strlen(num) < flags[WIDTH])
	{
		len = (int)ft_strlen(num);
		num = ft_strjoin_free(ft_str_spam(" ", flags[WIDTH] - len), num);
	}

	if (flags[MINUS])
	{
		int pos = 0;
		int j = 0;
		while (num[j] != '\0')
		{
			if (num[j] != ' ')
			{
				num[pos] = num[j];
				num[j] = ' ';
				pos++;
			}
			j++;
		}
	}
	return (num);
}