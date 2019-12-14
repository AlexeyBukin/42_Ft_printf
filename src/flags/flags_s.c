/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelina <lmelina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 15:23:49 by lmelina           #+#    #+#             */
/*   Updated: 2019/12/13 15:33:42 by lmelina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_insert_s(va_list arg, int *flags)
{
	int len = 0;
	char *insert;
	char *res;

	insert = va_arg(arg, char*);
	if (!insert)
	{
		return (ft_strdup("(null)"));
	}
	len = (int) ft_strlen(insert);
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (flags[PRECISION])
		res = ft_strncpy(res, insert, flags[PRECISION]);
	else
		res = ft_strcpy(res, insert);

	if (flags[WIDTH] > 0 && (int)ft_strlen(res) < flags[WIDTH])
	{
		len = (int)ft_strlen(res);
		res = ft_strjoin_free(ft_str_spam(" ", flags[WIDTH] - len), res);
	}

	if (flags[MINUS] && flags[WIDTH])
	{
		int pos = 0;
		int j = 0;
		while (res[j] != '\0')
		{
			if (res[j] != ' ')
			{
				res[pos] = res[j];
				res[j] = ' ';
				pos++;
			}
			j++;
		}
	}
	return (res);
}