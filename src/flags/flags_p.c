/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelina <lmelina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 19:23:35 by lmelina           #+#    #+#             */
/*   Updated: 2019/12/20 22:16:27 by lmelina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_insert_p(va_list arg, int *flags)
{
	unsigned long long d;
	char				*num;
	char				*zero;
	int 				len;

	d = (unsigned long long) va_arg(arg, long long int);
	zero = "0x";

	//	int *a;
//	ft_memcpy(&a, &d, 8);
//	printf("\nd = %s, size = %d\n", ft_mtob(&d, 8), sizeof(a));
//	printf("\na = %s\n", ft_mtob(&a, 8));
//
//	if (*a == 0)
//	{
//		printf("\nptr points no 0\n");
//	}
	//int *a = (int*) d;
//	if ((*a) == 0)
//	{
//		ffff = "7fff";
//	}

//	if (&d == 0)
//		ffff = "7fff";
//	else

	//printf("\nd = %s\n");
	//printf("\nd =    %s\n", ft_mtob(&d, 8));

	if (flags[PRECISION] == -1 && d == 0)
	{
		num = ft_strdup("");
	}
	else
		num = ft_ulltoa_base(d, BASE16L); //"0123456789abcdef"
	num = ft_strjoin(zero, num);

	len = (int)ft_strlen(num);
	if (flags[PRECISION] > len)
		num = ft_strjoin_free(ft_str_spam("0", flags[PRECISION] - ft_strlen(num)), num);

	if (flags[ZERO] == 1 && flags[PRECISION] == 0)
	{
		len = (int)ft_strlen(num);
		if (flags[PLUS] == 1 || flags[SPACE] == 1)
			len++;
		if (len < flags[WIDTH])
			num = ft_strjoin_free(ft_str_spam("0", flags[WIDTH] - len), num);
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
	return (num);
}