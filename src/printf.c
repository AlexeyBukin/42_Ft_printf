/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelina <lmelina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 14:57:18 by lmelina           #+#    #+#             */
/*   Updated: 2019/12/09 21:16:07 by lmelina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int add_eol = 1

int		ft_printf(const char *restrict format, ...)
{
	va_list	arg;
	int 	all_byte;
	int		i;
	char	*string;

	i = -1;
	va_start(arg, format);
	string = (char *)format;
	int n = 0;
	while (string[++i] != '\0')
	{
		//printf("\n i = %d, n = %d, c = \'%c\'\n", i, n, string[i - n]);
		if (string[i] == '%')
		{
			t_stg got = ft_resolve_arg(string, i, arg); // {string, how_many_to_skip}
			string = ft_insert_from_to(string, got.pointer, i, i + got.size);
			i += ft_strlen(got.pointer);

			if (got.taken <= 0) //TODO comment '\0' char moment
			{
				if (ft_strlen(got.pointer) == 0)
				{
					got.pointer++;
					ft_insert_mem(string, "\0", i++, 1);
					string = ft_insert_from_to(string, got.pointer, i, i + got.size);
					i += ft_strlen(got.pointer);
				}
				else
					ft_insert_mem(string, "\0", i++, 1);
			}
		}
	}
	write(1, string, i);
	va_end(arg);
	return (all_byte);
}
