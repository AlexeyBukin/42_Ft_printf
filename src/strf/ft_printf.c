/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 14:57:18 by lmelina           #+#    #+#             */
/*   Updated: 2020/08/08 16:37:30 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
			if (ft_printf_resolve(&res, &i, &sflags, arg))
			{
				free(res);
				return (-1);
			}
		}
		i++;
	}
	write (1, res, i);
	return (i);
}