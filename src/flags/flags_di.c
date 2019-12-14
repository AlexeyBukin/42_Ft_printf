/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelina <lmelina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 19:23:35 by lmelina           #+#    #+#             */
/*   Updated: 2019/12/14 23:10:15 by lmelina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_insert_d(int d, int *flags)
{
	char	*num;
	int		len;

	//TODO normal ft_ulltoa();
	num = ft_utoa(ft_abs(d));

	if (flags[PRECISION] == -1 && d == 0)
	{
		num = ft_strdup("");
	}
	else
		num = ft_utoa(ft_abs(d));

//	printf("\n%d:\'%s\'\n", 345674567, num);

	len = (int)ft_strlen(num);
	if (flags[PRECISION] > len)
		num = ft_strjoin_free(ft_str_spam("0", flags[PRECISION] - ft_strlen(num)), num);

//	printf("\n%d:\'%s\'\n", 2, num);

	if (flags[ZERO] == 1 && flags[PRECISION] == 0 && flags[MINUS] == 0)
	{
		len = (int)ft_strlen(num);
		if (flags[PLUS] == 1 || flags[SPACE] == 1 || d < 0)
			len ++;
		if (flags[WIDTH] > len)
			num = ft_strjoin_free(ft_str_spam("0", flags[WIDTH] - len), num);
	}

//	printf("\n%d:\'%s\'\n", 3, num);

	if (d < 0)
		num = ft_strjoin_free(ft_strdup("-"), num);

	if (flags[PLUS] == 1 && d >= 0)
		num = ft_strjoin_free(ft_strdup("+"), num);

	if (flags[SPACE] == 1 && flags[PLUS] == 0 && d >= 0)
		num = ft_strjoin_free(ft_strdup(" "), num);

//	printf("\n%d:\'%s\'\n", 4, num);

	if (flags[WIDTH] > 0 && (int)ft_strlen(num) < flags[WIDTH])
	{
		len = (int)ft_strlen(num);
		if (flags[MINUS] == 0)
		{
			num = ft_strjoin_free(ft_str_spam(" ", flags[WIDTH] - len), num);
		}
		else
		{
			num = ft_strjoin_free(num, ft_str_spam(" ", flags[WIDTH] - len));
		}
	}
//	printf("\n%d:\'%s\'\n", 5, num);
	return (num);
}