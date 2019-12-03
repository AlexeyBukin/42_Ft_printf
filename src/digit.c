/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelina <lmelina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 16:04:23 by lmelina           #+#    #+#             */
/*   Updated: 2019/12/03 16:08:09 by kcharla          ###   ########.fr       */
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

char	*ft_insert_d(char *input, int i, int d)
{
	char *num;

	num = ft_itoa(d);
	input = insert_from_to(input, num, i - 1, i);
	return (input);
}

char	*ft_insert_o(char *input, int i, int d)
{
	char *num;

	num = ft_itoa_base(d, "01234567");
	input = insert_from_to(input, num, i - 1, i);
	return (input);
}

char	*ft_insert_x(char *input, int i, int d)
{
	char *num;

	num = ft_itoa_base(d, "0123456789abcdef");
	input = insert_from_to(input, num, i - 1, i);
	return (input);
}

char	*ft_insert_X(char *input, int i, int d)
{
	char *num;

	num = ft_itoa_base(d, "0123456789ABCDEF");
	input = insert_from_to(input, num, i - 1, i);
	return (input);
}

char	*ft_resolve_arg(char *string, int i, va_list arg)
{
	int		flags[7];
	char	*insert;
	char 	character[2];
	int		d;

	///////////////////флаги//////////////////////////////
	if (string[i] == '-')
		flags[MINUS] = 1;
	if (string[i] == '+')
		flags[PLUS] = 1;
	if (string[i] == ' ')
		flags[SPACE] = 1;
	if (string[i] == '0')
		flags[SPACE] = 1;
	if (string[i] == '#')
		flags[SHARP] = 1;
	//////////////////////////////////////////////////////

	///////////////////ширина/////////////////////////////

	//////////////////////////////////////////////////////

	///////////////////точность///////////////////////////

	//////////////////////////////////////////////////////

	///////////////////модификаторы///////////////////////

	//////////////////////////////////////////////////////

	///////////////////тип преобразования/////////////////
	if (string[i] == 's')
	{
		insert = va_arg(arg, char*);
		string = insert_from_to(string, insert, i - 1, i);
		return (string);
	}
	else if (string[i] == 'c')
	{
		character[0] = (char)va_arg(arg, int);
		character[1] = '\0';
		string = insert_from_to(string, character, i - 1, i);
		return (string);
	}
	else if (string[i] == 'd' || string[i] == 'i')
	{
		d = va_arg(arg, int);
		string = ft_insert_d(string, i, d);
		return (string);
	}
	else if (string[i] == 'u')
	{
		d = va_arg(arg, int);
		string = ft_insert_d(string, i, d);
		return (string);
	}
	else if (string[i] == 'o')
	{
		d = va_arg(arg, int);
		string = ft_insert_o(string, i, d);
		return (string);
	}
	else if (string[i] == 'x')
	{
		d = va_arg(arg, int);
		string = ft_insert_x(string, i, d);
		return (string);
	}
	else if (string[i] == 'X')
	{
		d = va_arg(arg, int);
		string = ft_insert_X(string, i, d);
		return (string);
	}
	else if (string[i] == '%')
	{
		string = insert_from_to(string, "%", i - 1, i);
		return (string);
	}
	//////////////////////////////////////////////////////////////
	return (string);
}
