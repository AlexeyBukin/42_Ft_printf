/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelina <lmelina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 19:23:35 by lmelina           #+#    #+#             */
/*   Updated: 2019/12/14 22:59:26 by lmelina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_insert_o(int d, int *flags)
{
	char	*num;
	int		len;

	//num = ft_itoa_base(d, BASE8);
	/////////
	if (flags[PRECISION] == -1 && d == 0 && flags[SHARP] == 0)
	{
		num = ft_strdup("");
	}
	else
		num = ft_utoa_base(d, BASE8);

	//printf("\n%d:\'%s\'\n", 1, num);

	len = (int)ft_strlen(num);
	if (flags[PRECISION] > len)
		num = ft_strjoin_free(ft_str_spam("0", flags[PRECISION] - len), num);

	//printf("%d:\'%s\'\n", 2, num);

	if (flags[ZERO] == 1 && flags[PRECISION] == 0 && flags[MINUS] == 0)
	{
		len = (int)ft_strlen(num);
		if (flags[PLUS] == 1 || flags[SPACE] == 1 || d < 0)
			len++;
		len = (flags[SHARP] == 1) ? len + 1 : len;
		num = ft_strjoin_free(ft_str_spam("0", flags[WIDTH] - len), num);
	}

	//printf("%d:\'%s\'\n", 3, num);

	if (flags[SHARP] == 1 && d != 0)
		num = ft_strjoin_free(ft_strdup("0"), num);

	//printf("%d:\'%s\'\n", 4, num);

	if (flags[WIDTH] > 0 && (len = (int)ft_strlen(num)) < flags[WIDTH])
	{
		//len = (int)ft_strlen(num);
		if (flags[MINUS] == 1)
		{
			num = ft_strjoin_free(num, ft_str_spam(" ", flags[WIDTH] - len));
		}
		else
		{
			num = ft_strjoin_free(ft_str_spam(" ", flags[WIDTH] - len), num);
		}
	}
	/////////
	//input = insert_from_to(input, num, start, i);
	return (num);
}
