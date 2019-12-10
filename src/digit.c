/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelina <lmelina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 19:26:49 by lmelina           #+#    #+#             */
/*   Updated: 2019/12/10 21:52:03 by lmelina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_stg	ft_resolve_arg(char *string, int i, va_list arg, int *flags)
{
    int d;
    int start = 0;
	int fff;

	fff = -1;
	while (++fff < FLAGS_LEN)
		flags[fff] = 0;
	//printf("\n\n\nstring = \'%s\'\n\n\n", string);
	int len = arg_len(string);
	if (parse_flags(string, len, flags) < 0)
		return ((t_stg) {NULL, -1});

	//if (flags[FLAG] == FLAG_DI)
//    start = i++;
//    ///////////////////флаги//////////////////////////////
//	while (string[i] && !(string[i] >= '1' && string[i] <= '9') &&
//	string[i] != '.' && !(string[i] == 'd' || string[i] == 'i' ||
//	string[i] == 's' || string[i] == 'c' || string[i] == 'x' || string[i] == 'p' ||
//	string[i] == 'X' || string[i] == 'o' || string[i] == 'u' || string[i] == '%' ||
//	string[i] == 'h' || string[i] == 'l'))
//	{
//		if (string[i] == '-')
//            flags[MINUS] = 1;
//		else if (string[i] == '+')
//			flags[PLUS] = 1;
//        else if (string[i] == ' ')
//			flags[SPACE] = 1;
//        else if (string[i] == '0')
//			flags[ZERO] = 1;
//        else if (string[i] == '#')
//			flags[SHARP] = 1;
//		i++;
//	}
//    //////////////////////////////////////////////////////
//
//    ///////////////////ширина/////////////////////////////
//    if (string[i] >= '1' && string[i] <= '9')
//    {
//        flags[WIDTH] = ft_atoi(&string[i]);
//        while (string[i] && (string[i] >= '0' && string[i] <= '9'))
//            i++;
//    }
//    //////////////////////////////////////////////////////
//
//    ///////////////////точность///////////////////////////
//    if (string[i] == '.')
//    {
//    	if (string[++i] && (string[i] >= '0' && string[i] <= '9'))
//    		flags[PRECISION] = ft_atoi(&string[i]);
//    	else
//			while (string[i] && !(string[i] >= '0' && string[i] <= '9'))
//			{
//				if (string[i] == '-')
//					flags[MINUS] = 1;
//				else if (string[i] == '+')
//					flags[PLUS] = 1;
//				else if (string[i] == ' ')
//					flags[SPACE] = 1;
//				else if (string[i] == '#')
//					flags[SHARP] = 1;
//				i++;
//			}
//		flags[PRECISION] = ft_atoi(&string[i]);
//        if(flags[PRECISION] == 0)
//        	flags[PRECISION] = -1;
//        while (string[i] && (string[i] >= '0' && string[i] <= '9'))
//            i++;
//    }
//    //////////////////////////////////////////////////////
//
//    ///////////////////модификаторы///////////////////////
//    if (string[i] == 'h' && string[i + 1] == 'h')
//    {
//        flags[HH] = 1;
//		flags[H] = 0;
//		flags[LL] = 0;
//		flags[L] = 0;
//		while (string[i] && string[i] == 'h')
//            i++;
//    }
//    if (string[i] == 'h')
//    {
//        flags[H] = 1;
//		flags[HH] = 0;
//		flags[LL] = 0;
//		flags[L] = 0;
//        while (string[i] && string[i] == 'h')
//            i++;
//    }
//    if (string[i] == 'l' && string[i + 1] == 'l')
//    {
//        flags[LL] = 1;
//		flags[HH] = 0;
//		flags[H] = 0;
//		flags[L] = 0;
//        while (string[i] && string[i] == 'l')
//            i++;
//    }
//    if (string[i] == 'l')
//    {
//        flags[L] = 1;
//		flags[HH] = 0;
//		flags[H] = 0;
//		flags[LL] = 0;
//        while (string[i] && string[i] == 'l')
//            i++;
//    }
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
		return ((t_stg) {string, len});
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
    return ((t_stg) {string, i - start});
}
