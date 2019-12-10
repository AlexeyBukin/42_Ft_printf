/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelina <lmelina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 19:23:35 by lmelina           #+#    #+#             */
/*   Updated: 2019/12/10 18:51:09 by lmelina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"


char	*ft_insert_x(int d, int *flags, int is_x_big)
{
	char	*num;
	int		len;

	if (flags[PRECISION] == -1 && d == 0)
	{
		num = ft_strdup("");
	}
	else
		num = is_x_big ? ft_utoa_base(d, BASE16U) : ft_utoa_base(d, BASE16L);

	if (flags[ZERO] == 1 && flags[PRECISION] == 0 && flags[MINUS] == 0)
	{
		len = (int)ft_strlen(num);
		if (flags[PLUS] == 1 || flags[SPACE] == 1 || d < 0)
			len ++;
		len = (flags[SHARP] == 1) ? len + 2 : len;
		num = ft_strjoin_free(ft_str_spam("0", flags[WIDTH] - len), num);
	}

	if (flags[SHARP] == 1 && d != 0)
	{
		if (is_x_big == 1)
			num = ft_strjoin_free(ft_strdup("0X"), num);
		else
			num = ft_strjoin_free(ft_strdup("0x"), num);
	}

	if (flags[WIDTH] > 0 && (int)ft_strlen(num) < flags[WIDTH])
	{
		len = (int)ft_strlen(num);
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
