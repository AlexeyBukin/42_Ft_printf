/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelina <lmelina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 19:23:35 by lmelina           #+#    #+#             */
/*   Updated: 2019/12/09 16:09:49 by lmelina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_insert_u(char *input, int start, int i, int d, int *flags)
{
	char	*num;
	int		len;

	num = ft_utoa(d);

	if (flags[PRECISION] > 0)
		num = ft_strjoin_free(ft_str_spam("0", flags[PRECISION] - ft_strlen(num)), num);

	if (flags[ZERO] == 1 && flags[PRECISION] == 0)
	{
		len = (int)ft_strlen(num);
		if (flags[PLUS] == 1 || flags[SPACE] == 1 || d < 0)
			len ++;
		//TODO зачем нужно в этом месте +1 к len, чтобы работал 175 тест
		num = ft_strjoin_free(ft_str_spam("0", flags[WIDTH] - len + 1), num);
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

	input = insert_from_to(input, num, start, i);
	return (input);
}