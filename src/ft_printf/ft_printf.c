/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 14:50:35 by kcharla           #+#    #+#             */
/*   Updated: 2020/08/11 01:22:54 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** main ft_printf function
** uses ft_strf functions to format and join all flags except 'c'
** uses 'write' only once, in the end, no buffer
*/

int			ft_printf(const char *restrict format, ...)
{
	t_strflags		sflags;
	va_list			arg;
	char			*res;
	size_t			i;

	res = ft_strdup((char *)format);
	va_start(arg, format);
	i = 0;
	while ((res)[i] != '\0')
	{
		if (res[i] == '%')
		{
			ft_printf_resolve(&res, &i, &sflags, arg);
		}
		else
		{
			i++;
		}
	}
	write(1, res, i);
	ft_free(res);
	va_end(arg);
	return (i);
}
