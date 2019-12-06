/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelina <lmelina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 19:26:49 by lmelina           #+#    #+#             */
/*   Updated: 2019/12/06 21:15:24 by lmelina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_resolve_arg(char *string, int i, va_list arg)
{
    int flags[11];
    char *insert;
    char character[2];
    int d;
    int start;

    start = i ++ ;
    ///////////////////флаги//////////////////////////////
	while (string[i] && !(string[i] >= '1' && string[i] <= '9') &&
	string[i] != '.' && !(string[i] == 'd' || string[i] == 'i' ||
	string[i] == 's' || string[i] == 'c' || string[i] == 'x' || string[i] == 'p' ||
	string[i] == 'X' || string[i] == 'o' || string[i] == 'u' || string[i] == '%' ||
	string[i] == 'h' || string[i] == 'l'))
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
        flags[WIDTH] = ft_atoi(&string[i]);
        while (string[i] && (string[i] >= '0' && string[i] <= '9'))
            i++;
    }
    //////////////////////////////////////////////////////

    ///////////////////точность///////////////////////////
    if (string[i] == '.')
    {
        flags[PRECISION] = ft_atoi(&string[++i]);
        if(flags[PRECISION] == 0)
        	flags[PRECISION] = -1;
        while (string[i] && (string[i] >= '0' && string[i] <= '9'))
            i++;
    }
    //////////////////////////////////////////////////////

    ///////////////////модификаторы///////////////////////
    if (string[i] == 'h' && string[i + 1] == 'h')
    {
        flags[HH] = 1;
        while (string[i] && string[i] == 'h')
            i++;
    }
    if (string[i] == 'h')
    {
        flags[H] = 1;
        while (string[i] && string[i] == 'h')
            i++;
    }
    if (string[i] == 'l' && string[i + 1] == 'l')
    {
        flags[LL] = 1;
        while (string[i] && string[i] == 'l')
            i++;
    }
    if (string[i] == 'l')
    {
        flags[L] = 1;
        while (string[i] && string[i] == 'l')
            i++;
    }
    //////////////////////////////////////////////////////

//    printf("Minus flag: %d\n", flags[MINUS]);
//    printf("Plus flag: %d\n", flags[PLUS]);
//    printf("Space flag: %d\n", flags[SPACE]);
//    printf("Sharp flag: %d\n", flags[SHARP]);
//    printf("Zero flag: %d\n", flags[ZERO]);
//    printf("Width size: %d\n", flags[WIDTH]);
//    printf("Precision size: %d\n", flags[PRECISION]);
//    printf("hh flag: %d\n", flags[HH]);
//    printf("h flag: %d\n", flags[H]);
//    printf("ll flag: %d\n", flags[LL]);
//    printf("l flag: %d\n", flags[L]);

    ///////////////////тип преобразования/////////////////
    if (string[i] == 's')
    {
        insert = va_arg(arg, char*);

        //printf("\nstart:string: \'%s\'\ninsert: \'%s\'\n", string, insert);

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
        string = ft_insert_d(string, start, i, d, flags);
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
        string = ft_insert_p(string, start, i, d);
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
    else if (string[i] == 'x' || string [i] == 'X')
    {
        d = va_arg(arg, int);
		string = ft_insert_x(string, start, i, d, flags, string[i] == 'X');
		//ft_putendl("here 3");
        return (string);
    }
    else if (string[i] == 'f')
    {

    }
    else if (string[i] == '%')
    {
    	char *perc;
    	int len;

    	if (!(perc = (char*)malloc(sizeof(char) * 2)))
    		return (NULL);
    	perc[0] = '%';
    	perc[1] = '\0';
		if (flags[WIDTH] > 0 && (int)ft_strlen(perc) < flags[WIDTH])
		{
			len = (int)ft_strlen(perc);
			perc = ft_strjoin_free(ft_str_spam(" ", flags[WIDTH] - len), perc);
		}

		if (flags[MINUS])
		{
			int pos = 0;
			int j = 0;
			while (perc[j] != '\0')
			{
				if (perc[j] != ' ')
				{
					perc[pos] = perc[j];
					perc[j] = ' ';
					pos++;
				}
				j++;
			}
		}

		string = insert_from_to(string, perc, start, i);
        return (string);
    }
    //////////////////////////////////////////////////////////////
    return (string);
}
