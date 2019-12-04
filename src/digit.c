/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelina <lmelina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 16:04:23 by lmelina           #+#    #+#             */
/*   Updated: 2019/12/04 16:39:13 by lmelina          ###   ########.fr       */
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

char	*ft_alternative_insert_o(char *input, int start, int i, int d)
{
    char *num;
    char zero[2];

    zero[0] = '0';
    zero[1] = '\0';
    num = ft_itoa_base(d, "01234567");
    num = ft_strjoin(zero, num);
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

char	*ft_alternative_insert_x(char *input, int start, int i, int d)
{
    char *num;
    char zero[3];

    zero[0] = '0';
    zero[1] = 'x';
    zero[2] = '\0';
    num = ft_itoa_base(d, "0123456789abcdef");
    num = ft_strjoin(zero, num);
    input = insert_from_to(input, num, start, i);
    return (input);
}

char	*ft_alternative_insert_upperx(char *input, int start, int i, int d)
{
	char *num;
    char zero[3];

    zero[0] = '0';
    zero[1] = 'X';
    zero[2] = '\0';
	num = ft_itoa_base(d, "0123456789ABCDEF");
    num = ft_strjoin(zero, num);
    input = insert_from_to(input, num, start, i);
	return (input);
}

char	*ft_insert_upperx(char *input, int start, int i, int d)
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
    int width = 0;
    int precision = 0;

    start = i - 1;
    ///////////////////флаги//////////////////////////////
	while (string[i] && !(string[i] >= '1' && string[i] <= '9') &&
	string[i] != '.' && !(string[i] == 'd' || string[i] == 'i' ||
	string[i] == 's' || string[i] == 'c' || string[i] == 'x' || string[i] == 'p' ||
	string[i] == 'X' || string[i] == 'o' || string[i] == 'u' || string[i] == '%'))
	{
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
    //////////////////////////////////////////////////////

    ///////////////////ширина/////////////////////////////
    if (string[i] >= '1' && string[i] <= '9')
    {
        width = atoi(&string[i]);
        flags[WIDTH] = 1;
        while (string[i] && (string[i] >= '0' && string[i] <= '9'))
            i++;
    }
    //////////////////////////////////////////////////////

    ///////////////////точность///////////////////////////
    if (string[i] == '.')
    {
        precision = atoi(&string[++i]);
        flags[PRECISION] = 1;
        while (string[i] && (string[i] >= '0' && string[i] <= '9'))
            i++;
    }
    //////////////////////////////////////////////////////

    ///////////////////модификаторы///////////////////////

    //////////////////////////////////////////////////////

//    printf("Minus flag: %d\n", flags[MINUS]);
//    printf("Plus flag: %d\n", flags[PLUS]);
//    printf("Space flag: %d\n", flags[SPACE]);
//    printf("Sharp flag: %d\n", flags[SHARP]);
//    printf("Zero flag: %d\n", flags[ZERO]);
//    printf("Width size: %d\n", width);
//    printf("Precision size: %d\n", precision);

    ///////////////////тип преобразования/////////////////
    if (string[i] == 's')
    {
        insert = va_arg(arg, char*);
        string = insert_from_to(string, insert, start, i);
        return (string);
    }
    else if (string[i] == 'c')
    {
        character[0] = (char) va_arg(arg, int);
        character[1] = '\0';
        string = insert_from_to(string, character, start, i);
        return (string);
    }
    else if (string[i] == 'd' || string[i] == 'i')
    {
        d = va_arg(arg, int);
        string = ft_insert_d(string, start, i, d);
        return (string);
    }
    else if (string[i] == 'u')
    {
        d = va_arg(arg, int);
        string = ft_insert_u(string, start, i, d);
        return (string);
    }
    else if (string[i] == 'p')
    {
        d = va_arg(arg, int);
        string = ft_alternative_insert_x(string, start, i, d);
        return (string);
    }
    else if (string[i] == 'o')
    {
        d = va_arg(arg, int);
        if (flags[SHARP] == 1)
            string = ft_alternative_insert_o(string, start, i, d);
        else
            string = ft_insert_o(string, start, i, d);
        return (string);
    }
    else if (string[i] == 'x')
    {
        d = va_arg(arg, int);
        if (flags[SHARP] == 1)
            string = ft_alternative_insert_x(string, start, i, d);
        else
            string = ft_insert_x(string, start, i, d);
        return (string);
    }
    else if (string[i] == 'X')
    {
        d = va_arg(arg, int);
        if (flags[SHARP] == 1)
            string = ft_alternative_insert_upperx(string, start, i, d);
        else
            string = ft_insert_upperx(string, start, i, d);
        return (string);
    }
    else if (string[i] == '%')
    {
        string = insert_from_to(string, "%", start, i);
        return (string);
    }
    //////////////////////////////////////////////////////////////
    return (string);
}
