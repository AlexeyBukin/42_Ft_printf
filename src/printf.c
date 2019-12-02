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

#define h_or_l 1;
#define H_OR_L 2;
#define _OPEN_SYS_ITOA_EXT

//flags[h_or_l]

#include "printf.h"

int		ft_printf(const char *restrict format, ...)
{
	va_list	arg;
	int 	all_byte;
	int		i;
	char	*string;


	//@requires char * insert_from_to(string input, size_t from, size_t to, string insertion);
	//string = do_all_ints(string);
	//string = do_all_floats(string);
	//string = do_all_char_strings(string);

	//last part - %%
	//string = do_all_ints(string);

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
	ft_printf("h");
	return 0;
}
