/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelina <lmelina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 17:39:52 by lmelina           #+#    #+#             */
/*   Updated: 2019/12/09 20:48:44 by lmelina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_insert_c(char *string, va_list arg, int start, int i, int *flags)
{
	char	val;
	char	*character;
	int		pos;

	val = (char) va_arg(arg, int);
	if (flags[WIDTH] == 0)
		flags[WIDTH] = 1;
	if (!(character = (char*)malloc(sizeof(char) * (flags[WIDTH] + 1))))
		return (NULL);
	character[flags[WIDTH]] = '\0';
	ft_memset(character, ' ', flags[WIDTH]);
	if (flags[MINUS] == 1)
		character[0] = val;
	else
		character[flags[WIDTH] - 1] = val;
	return (character);
}