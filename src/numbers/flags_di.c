/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelina <lmelina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 19:23:35 by lmelina           #+#    #+#             */
/*   Updated: 2019/12/09 15:20:42 by lmelina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_insert_d(char *input, int start, int i, int d, int *flags)
{
	char	*num;
	int		len;
	int here = 1;

	//TODO normal ft_ulltoa();
	num = ft_utoa(ft_abs(d));

	if (flags[PRECISION] > 0)
		num = ft_strjoin_free(ft_str_spam("0", flags[PRECISION] - ft_strlen(num)), num);

	if (flags[ZERO] == 1 && flags[PRECISION] == 0)
	{
		len = (int)ft_strlen(num);
		if (flags[PLUS] == 1 || flags[SPACE] == 1 || d < 0)
			len ++;
		num = ft_strjoin_free(ft_str_spam("0", flags[WIDTH] - len), num);
	}

	if (d < 0)
		num = ft_strjoin_free(ft_strdup("-"), num);

	if (flags[PLUS] == 1 && d >= 0)
		num = ft_strjoin_free(ft_strdup("+"), num);

	if (flags[SPACE] == 1 && flags[PLUS] == 0 && d >= 0)
		num = ft_strjoin_free(ft_strdup(" "), num);

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

	input = insert_from_to(input, num, start, i);

	return (input);
}