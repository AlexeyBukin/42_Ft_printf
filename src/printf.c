/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelina <lmelina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 14:57:18 by lmelina           #+#    #+#             */
/*   Updated: 2019/12/09 15:41:30 by lmelina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_printf(const char *restrict format, ...)
{
	va_list	arg;
	int 	all_byte;
	int		i;
	char	*string;

	//ft_putendl("");
	//write(1, "", 1);
	i = -1;
	all_byte = 0;
	va_start(arg, format);
	string = (char *)format;

//	while (string[++i] != '\0')
//	{
//		char * res;
//		int len;
//		if (string[i] == '%')
//			res = ft_resolve_arg(string, i, arg);
//
//		len = (int) ft_strlen(res);
//		insert_from_to(string, res, i, i + len);
//		i = i + len - 1;
//	}

	while (string[++i] != '\0')
	{
		if (string[i] == '%')
			string = ft_resolve_arg(string, i, arg);

		//if (i > 20) break;
		//ft_putnbr(i);
		//ft_putendl("");
	}
	all_byte = (int)ft_strlen(string);

	//string = "abc";
	//printf("str = \'%s\'", string);
//	char * stb1 = ft_mtob(string, sizeof(char));
//	ft_putendl(st1);
//	char * st1 = ft_str_div_by_ins(stb1, 4, " ");
//	ft_putendl(st1);

	ft_putstr(string);

	va_end(arg);
	return (all_byte);
}

//int main ()
//{
//    ft_printf("% -+#010.10hd", 123);
//    return 0;
//}
