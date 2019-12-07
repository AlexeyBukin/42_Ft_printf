/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelina <lmelina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 17:39:52 by lmelina           #+#    #+#             */
/*   Updated: 2019/12/07 17:51:23 by lmelina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char *ft_insert_c(char *string, va_list arg, int start, int i, int *flags)
{
	char *character;
	int len;

	if (!(character = (char*)malloc(sizeof(char) * 2)))
		return (NULL);
	character[0] = (char) va_arg(arg, int);
	character[1] = '\0';

	if (flags[WIDTH] > 0 && (int)ft_strlen(character) < flags[WIDTH])
	{
		len = (int)ft_strlen(character);
		character = ft_strjoin_free(ft_str_spam(" ", flags[WIDTH] - len), character);
	}

	if (flags[MINUS])
	{
		int pos = 0;
		int j = 0;
		while (character[j] != '\0')
		{
			if (character[j] != ' ')
			{
				character[pos] = character[j];
				character[j] = ' ';
				pos++;
			}
			j++;
		}
	}

	if (!character[0])
		string = insert_from_to(string, "", start, i);
	else
		string = insert_from_to(string, character, start, i);

	return (string);
}