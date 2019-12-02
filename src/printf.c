/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelina <lmelina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 14:57:18 by lmelina           #+#    #+#             */
/*   Updated: 2019/11/28 21:01:28 by lmelina          ###   ########.fr       */
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
	{
		if (string[i] == '%' && string[i + 1] != '%')
			string = ft_resolve_arg(string, ++i, arg);
		if (string[i] == '%' && string[i + 1] == '%')
		{
			string = ft_resolve_arg(string, ++i, arg);
			i--;
		}
	}
	ft_putstr(string);
	all_byte = (int)ft_strlen(string);
	va_end(arg);
	return (all_byte);
}

int main ()
{
    printf("%%%u\n", 01023);
	ft_printf("%%%u", 01023);
	return 0;
}
