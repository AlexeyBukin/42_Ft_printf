/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelina <lmelina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 14:57:18 by lmelina           #+#    #+#             */
/*   Updated: 2019/11/23 15:24:40 by lmelina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_printf(const char *restrict format, ...)
{
	va_list	arg;
	int 	all_byte;
	int		i;
	char	*string;

	i = -1;
	all_byte = 0;
	va_start(arg, format);
	string = (char *)format;
	while (string[++i] != '\0')
		if (string[i] == '%')
			all_byte += ft_resolve_arg(string, i, arg);
		else
			all_byte += ft_print_dz(string, i);
	va_end(arg);
	return (all_byte);
}
