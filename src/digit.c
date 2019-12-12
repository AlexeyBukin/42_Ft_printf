/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelina <lmelina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 19:26:49 by lmelina           #+#    #+#             */
/*   Updated: 2019/12/12 18:06:47 by lmelina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_stg	ft_resolve_arg(char *string, int i, va_list arg, int *flags)
{
	int len;
    int d;

	len = arg_len(string);
	if (parse_flags(string, len, flags) < 0)
		return ((t_stg) {NULL, -1});

    //////////////////////////////////////////////////////

//	printf("\n\n\n");
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

	//printf("\n\n\nALERT! char is %c\n\n\n", (char) flags[FLAG]);
	//printf("\n\n\n");

    ///////////////////тип преобразования/////////////////

	if (flags[FLAG] == 's')
    {
        string = ft_insert_s(arg, flags);
        //return ({string, i - start});
    }
    else if (flags[FLAG] == 'c')
    {
    	string = ft_insert_c(arg, flags);
//		return ((t_stg) {string, i - start});
	//	return ((t_stg) {string, len});
//    	if (string == NULL || flags[WIDTH] <= 0)
//    		return ({NULL, -1});
//    	if (string[0] == '\0' || string[flags[WIDTH] - 1] == '\0')
//		{
//			return ({string, (i - start) * (-1)});
//		}
//		return ({string, i - start});
    }
    else if (flags[FLAG] == 'd' || flags[FLAG] == 'i')
    {
        d = va_arg(arg, int);
        string = ft_insert_d(d, flags);
    }
    else if (flags[FLAG] == 'u')
    {
        d = va_arg(arg, int);
        string = ft_insert_u(d, flags);
    }
    else if (flags[FLAG] == 'p')
    {
        d = va_arg(arg, int);
        string = ft_insert_p(d);
    }
    else if (flags[FLAG] == 'o')
    {
        d = va_arg(arg, int);
        string = ft_insert_o(d, flags);
    }
    else if (flags[FLAG] == 'x' || flags[FLAG] == 'X')
    {
        d = va_arg(arg, int);
		string = ft_insert_x(d, flags, flags[FLAG] == 'X');
    }
    else if (string[i] == 'f')
    {

    }
    else if (string[i] == '%')
    {
		string = ft_insert_percentage(flags);
    }

	//////////////////////////////////////////////////////////////
    return ((t_stg) {string, len});
}
