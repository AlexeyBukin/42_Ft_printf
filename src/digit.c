/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelina <lmelina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 16:04:23 by lmelina           #+#    #+#             */
/*   Updated: 2019/11/28 17:02:41 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

#define PRECISION 0
#define PLUS 1
#define MINUS 2
#define ZERO 3
#define SPACE 4
#define WIDTH 5
#define SHARP 6

// INT * flags
// if ((....)) flags[MINUS] = 1;
// a = flags[minus]; flags.minus;

char	*ft_insert_d(char *input, int start, int i, int d)
{
	char *num;

	num = ft_itoa(d);
	input = insert_from_to(input, num, start, i);
	return (input);
}

char	*ft_insert_o(char *input, int start, int i, int d)
{
	char *num;

	num = ft_itoa_base(d, "01234567");
	input = insert_from_to(input, num, start, i);
	return (input);
}

char	*ft_insert_x(char *input, int start, int i, int d)
{
	char *num;

	num = ft_itoa_base(d, "0123456789abcdef");
	input = insert_from_to(input, num, start, i);
	return (input);
}

char	*ft_insert_X(char *input, int start, int i, int d)
{
	char *num;

	num = ft_itoa_base(d, "0123456789ABCDEF");
	input = insert_from_to(input, num, start, i);
	return (input);
}

char	*ft_insert_u(char *input, int start, int i, int d)
{
	char *num;

	num = ft_utoa(d);
	input = insert_from_to(input, num, start, i);
	return (input);
}

char	*ft_resolve_arg(char *string, int i, va_list arg)
{
    int flags[7];
    char *insert;
    char character[2];
    int d;
    int start;

    start = i - 1;
    ///////////////////флаги//////////////////////////////
	while (string[i] && !(string[i] >= '1' &&
	string[i] <= '9') && string[i] != '.' && !(string[i] == 'd' || string[i] == 'i' ||
            string[i] == 's' || string[i] == 'c' || string[i] == 'x' || string[i] == 'X' ||
            string[i] == 'o' || string[i] == 'u' || string[i] == '%'))
	{
	    printf("%c\n", string[i]);
		if (string[i] == '-')
            flags[MINUS] = 1;
		else if (string[i] == '+')
			flags[PLUS] = 1;
        else if (string[i] == ' ')
			flags[SPACE] = 1;
        else if (string[i] == '0')
			flags[ZERO] = 1;
        else if (string[i] == '#')
			flags[SHARP] = 1;
		i++;
	}
    printf("\n");
    printf("%d\n", flags[SPACE]);
    printf("%d\n", flags[MINUS]);
    printf("%d\n", flags[PLUS]);
    printf("%d\n", flags[SHARP]);
    printf("%d\n", flags[ZERO]);

    //////////////////////////////////////////////////////

    ///////////////////ширина/////////////////////////////

    //////////////////////////////////////////////////////

    ///////////////////точность///////////////////////////

    //////////////////////////////////////////////////////

    ///////////////////модификаторы///////////////////////

    //////////////////////////////////////////////////////

    ///////////////////тип преобразования/////////////////
    if (string[i] == 's') {
        insert = va_arg(arg, char*);
        string = insert_from_to(string, insert, start, i);
        return (string);
    } else if (string[i] == 'c') {
        character[0] = (char) va_arg(arg, int);
        character[1] = '\0';
        string = insert_from_to(string, character, start, i);
        return (string);
    } else if (string[i] == 'd' || string[i] == 'i') {
        d = va_arg(arg, int);
        string = ft_insert_d(string, start, i, d);
        return (string);
    } else if (string[i] == 'u') {
        d = va_arg(arg, int);
        string = ft_insert_u(string, start, i, d);
        return (string);
    } else if (string[i] == 'o') {
        d = va_arg(arg, int);
        string = ft_insert_o(string, start, i, d);
        return (string);
    } else if (string[i] == 'x') {
        d = va_arg(arg, int);
        string = ft_insert_x(string, start, i, d);
        return (string);
    } else if (string[i] == 'X') {
        d = va_arg(arg, int);
        string = ft_insert_X(string, start, i, d);
        return (string);
    } else if (string[i] == '%') {
        string = insert_from_to(string, "%", start, i);
        return (string);
    }
    //////////////////////////////////////////////////////////////
    return (string);
}
