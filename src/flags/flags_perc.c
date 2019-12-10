/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_perc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelina <lmelina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 17:09:48 by lmelina           #+#    #+#             */
/*   Updated: 2019/12/10 18:54:33 by lmelina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char *ft_insert_percentage(int *flags)
{
	char *perc;
	int len;

	if (!(perc = (char*)malloc(sizeof(char) * 2)))
		return (NULL);
	perc[0] = '%';
	perc[1] = '\0';
	if (flags[WIDTH] > 0 && (len = (int)ft_strlen(perc)) < flags[WIDTH])
	{
		len = (int)ft_strlen(perc);
		if (flags[MINUS] == 1)
		{
			perc = ft_strjoin_free(perc, ft_str_spam(" ", flags[WIDTH] - len));
		}
		else
		{
			perc = ft_strjoin_free(ft_str_spam(" ", flags[WIDTH] - len), perc);
		}
	}
	return (perc);
}
