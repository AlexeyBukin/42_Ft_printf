/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelina <lmelina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 19:26:49 by lmelina           #+#    #+#             */
/*   Updated: 2019/12/16 19:27:41 by lmelina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_stg	ft_resolve_arg(char *string, va_list arg, int *flags)
{
	int		len;
    int		d;
   // double	d_d;

	len = arg_len(string);
	if (parse_flags(string, len, flags) < 0)
		return ((t_stg) {NULL, -1});
//	  printf("\n\n\n");
//    printf("Minus flag: %d\n", flags[MINUS]);
//    printf("Plus flag: %d\n", flags[PLUS]);
//    printf("Space flag: %d\n", flags[SPACE]);
//    printf("Sharp flag: %d\n", flags[SHARP]);
//    printf("Zero flag: %d\n", flags[ZERO]);
//    printf("Width size: %d\n", flags[WIDTH]);
//    printf("Precision size: %d\n", flags[PRECISION]);
//    printf("hh flag: %d\n", flags[CAST] == CAST_HH);
//    printf("h flag: %d\n", flags[CAST] == CAST_H);
//    printf("ll flag: %d\n", flags[CAST] == CAST_LL);
//    printf("l flag: %d\n", flags[CAST] == CAST_L);

	if (flags[FLAG] == 's')
    {
        string = ft_insert_s(arg, flags);
    }
    else if (flags[FLAG] == 'c')
    {
    	string = ft_insert_c(arg, flags);
    }
    else if (flags[FLAG] == 'd' || flags[FLAG] == 'i')
    {
        string = ft_insert_d(arg, flags);
    }
    else if (flags[FLAG] == 'u')
    {
        string = ft_insert_u(arg, flags);
    }
    else if (flags[FLAG] == 'p')
    {
    	//TODO delete this
        d = va_arg(arg, int);
        string = ft_insert_p(d);
    }
    else if (flags[FLAG] == 'o')
    {
    	//TODO delete this
        d = va_arg(arg, int);
        string = ft_insert_o(d, flags);
    }
    else if (flags[FLAG] == 'x' || flags[FLAG] == 'X')
    {
		string = ft_insert_x(arg, flags, flags[FLAG] == 'X');
    }
    else if (flags[FLAG] == 'f')
    {
    	//d_d = va_arg(arg, double);
    	string = ft_float(arg, flags);
    }
    else if (flags[FLAG] == '%')
    {
		string = ft_insert_percentage(flags);
    }

	return ((t_stg) {string, len});
}
