/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:40:37 by kcharla           #+#    #+#             */
/*   Updated: 2019/11/28 21:35:36 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Flags used in floats
*/

#define alt         0 // dot always exist
#define f_or_F      1
#define shift       2 //which side shift, 0 is right
#define sign        3 //0 : not enter +
#define zero        4 //to fill with 0
#define w1          5 //width before dot
#define w2          6 //width after dot
#define error       7
#define flags_num   8

#include "printf.h"

char	*ft_float(char *flags_str, double num);

int main()
{
	printf("%-+10.3f\n", (double)-10.1);
	printf("%#.0f\n", (double)10);

	//double num = 1.5;
//
//	printf("exponent of %f = %d, %016x\n\n", num, 5, get_exponent(num));
//	unsigned long long a = 0x3ff0000000000000;
//
//	ft_memcpy(&num, &a, 8);
//	printf("%f\n", num);
//	print_double_as_binary(num);
//
//	a = 0x3ff1000000000000;
//	ft_memcpy(&num, &a, 8);
//	printf("%f\n", num);
//	print_double_as_binary(num);
//
//	a = 0x0000000000000000;
//	ft_memcpy(&num, &a, 8);
//	a = 0x3ff0001000010001;
//	ft_memcpy(&num, (&a), 8);
//	printf("%f\n", num);
//	print_double_as_binary(num);
}

int		parse_flags(char *args, int *flags)
{
	int		dot_pass;
	int 	i;

	i = 0;
	stage = 0;
	if (args == NULL || flags == NULL)
		return (-1);
	while (args[i] != 0)
	{
		if (args[i] == '.' && dot_pass == 0)
			dot_pass = 1;
		else if (args[i] == '0')
			flags[zero] = 1;
		else if (args[i] > '0' && args[i] <= '9')
		{
			if (dot_pass == 0)
				flags[w1] = ft_atoi(&(args[i]));
			else
				flags[w2] = ft_atoi(&(args[i]));
		}
		i++;
	}
	//flags[]
	return (0);
}

static char		*try_special(int *flags, double num)
{
	(void)num;
	(void)flags;
	return (NULL);
}

char	*ft_float(char *flags_str, double num)
{
	char	*res;
	int		flags[flags_num];

	if (parse_flags(flags_str, flags) < 0)
		return (NULL);
	res = try_special(flags, num);
	if (flags[error] < 0) //error
		return (NULL);
	if (res == NULL) //not denormilized or infinity
	{
		//res = long_calcs();
	}
	return (res);
}

int get_exponent(double d)
{
	(void) d;
	return (1);
}

void	print_double_as_binary(double d)
{
	char * stb1 = ft_mtob(&d, sizeof(double));
	char * st1 = ft_str_div_by_ins(stb1, 4, " ");
	char * st21 = ft_str_div_by_ins(st1, 10, "   ");
	ft_putendl(st21);
}

