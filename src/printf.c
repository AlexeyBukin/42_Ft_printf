/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelina <lmelina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 14:57:18 by lmelina           #+#    #+#             */
/*   Updated: 2020/01/31 19:46:32 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	after_taking(int *flags, int *all_byte, t_stg resolved, int *i)
{
	int		len;

	if (i == NULL || flags == NULL || all_byte == NULL)
		return ;
	if (resolved.taken > 0)
	{
		if (flags[C_GOT_NULL] == NULL_IN_THE_BEGINNING)
		{
			write(1, "", 1);
			(*all_byte)++;
		}
		len = (int) ft_strlen(resolved.string);
		(*all_byte) += len;
		write(1, resolved.string, len);
		free(resolved.string);
		if (flags[C_GOT_NULL] == NULL_IN_THE_END)
		{
			write(1, "", 1);
			(*all_byte)++;
		}
		*i += resolved.taken;
	}
}

void	write_from_buf(char *buf, int *buf_len)
{
	if (buf == NULL || buf_len == NULL)
		return;
	write(1, buf, buf_len);
	buf_len = 0;
}

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
			write_from_buf(buf, &buf_len);
			write(1, buf, buf_len);
			buf_len = 0;

			resolved = ft_resolve_arg(&(string[i + 1]), arg, flags);
			after_taking(flags, &all_byte, resolved, &i);
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
	write(1, buf, buf_len);
	va_end(arg);
	return (all_byte);
}
