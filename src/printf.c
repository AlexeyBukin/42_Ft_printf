/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelina <lmelina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 14:57:18 by lmelina           #+#    #+#             */
/*   Updated: 2019/12/16 17:45:05 by lmelina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_printf(const char *restrict format, ...)
{
	va_list	arg;
	int 	all_byte;
	int		i;
	char	*string;
	t_stg	resolved;
	int		flags[FLAGS_LEN];

	i = -1;
	va_start(arg, format);
	string = (char *)format;
	all_byte = 0;
	while (string[++i] != '\0')
	{
		if (string[i] == '%')
		{
			resolved = ft_resolve_arg(&(string[i + 1]), arg, flags);
			if (resolved.taken > 0)
			{
				if (flags[C_GOT_NULL] == NULL_IN_THE_BEGINNING)
				{
					write(1, "", 1);
					all_byte ++;
				}
				int len = (int) ft_strlen(resolved.string);
				all_byte += len;
				write(1, resolved.string, len);

				if (flags[C_GOT_NULL] == NULL_IN_THE_END)
				{
					write(1, "", 1);
					all_byte ++;
				}
				i += resolved.taken;
			}
		}
		else
		{
			all_byte++;
			write(1, &(string[i]), 1);
		}
	}
	va_end(arg);
	return (all_byte);
}
