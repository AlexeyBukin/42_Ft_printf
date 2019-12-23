/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelina <lmelina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 14:57:18 by lmelina           #+#    #+#             */
/*   Updated: 2019/12/21 23:36:32 by kcharla          ###   ########.fr       */
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

	char *buf = string;
	size_t  buf_len = 0;

	while (string[++i] != '\0')
	{
		if (string[i] == '%')
		{
			//NEW starts
			//printf("writing \'%.*s\'", (int) buf_len, buf);
			//printf("writing \'%.*s\', len = %d\n\n", (int) buf_len, buf, (int) buf_len);
			write(1, buf, buf_len);
			buf_len = 0;
			// NEW ends

			resolved = ft_resolve_arg(&(string[i + 1]), arg, flags);
			if (resolved.taken > 0)
			{
				if (flags[C_GOT_NULL] == NULL_IN_THE_BEGINNING)
				{
					write(1, "", 1);
					all_byte ++;
				}
				printf("resolved = \'%s\'\n", resolved.string);
				int len = (int) ft_strlen(resolved.string);
				all_byte += len;
				write(1, resolved.string, len);

				free(resolved.string);

				if (flags[C_GOT_NULL] == NULL_IN_THE_END)
				{
					write(1, "", 1);
					all_byte ++;
				}
				i += resolved.taken;
			}
			//free(resolved.string);


		}
		else
		{
			if (buf_len == 0)
			{
				buf = &(string[i]);
			}
			buf_len ++;

			if (string[i] == '\n')
			{
				write(1, buf, buf_len);
				buf_len = 0;
			}
			all_byte++;
		}
	}

	//printf("writing \'%.*s\'", (int) buf_len, buf);
	write(1, buf, buf_len);

	va_end(arg);
	return (all_byte);
}
