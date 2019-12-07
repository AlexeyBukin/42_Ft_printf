/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_perc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelina <lmelina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 17:09:48 by lmelina           #+#    #+#             */
/*   Updated: 2019/12/07 17:11:42 by lmelina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char *ft_insert_percentage(char *string, int start, int i, int *flags)
{
	char *perc;
	int len;

	if (!(perc = (char*)malloc(sizeof(char) * 2)))
		return (NULL);
	perc[0] = '%';
	perc[1] = '\0';
	if (flags[WIDTH] > 0 && (int)ft_strlen(perc) < flags[WIDTH])
	{
		len = (int)ft_strlen(perc);
		perc = ft_strjoin_free(ft_str_spam(" ", flags[WIDTH] - len), perc);
	}

	if (flags[MINUS])
	{
		int pos = 0;
		int j = 0;
		while (perc[j] != '\0')
		{
			if (perc[j] != ' ')
			{
				perc[pos] = perc[j];
				perc[j] = ' ';
				pos++;
			}
			j++;
		}
	}

	string = insert_from_to(string, perc, start, i);
	return (string);
}