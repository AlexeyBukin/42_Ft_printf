/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:52:05 by kcharla           #+#    #+#             */
/*   Updated: 2020/08/11 12:42:05 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** #define STR "%15.f|%15.1f|%15.2f|%15.5f|%15.12f"
** #define ARGS 999.99999, 999.99999, 999.99999, 999.99999, 999.99999
** -------------
** #define STR "|%.19f|%.19f|"
** #define ARGS 1.025978542436587568678, -1.025978542436587568678
**
** printf("gg_printf: \'"STR"\'\n", ARGS);
*/

#include "ft_printf.h"
#include <stdio.h>
#include <math.h>
#include <limits.h>


#define INPUT "{%f}_%c|||", -9999910.52, 0
//#define INPUT "%jd, %jd", -9223372036854775808, 9223372036854775807
//#define INPUT "%3d, %i, %zd, %zhd, %jhd", -1, 2, -1, 4294967296, 9223372036854775807
//#define INPUT "|%-.8d|%30.5s|%12c|", -1245, "wanna check some leaks?", 0
//#define STR "|%-.8d|%30.5s|%12c|"
//#define ARGS -1245, "wanna check some leaks?", 0
//#define ARGS -1245, "wanna check some leaks?", 0
//#define ARGS -1245.02 * 10000000000L * 1000000000000L * 200000000000000L

int		main(void)
{
	{
		int ft = 0;
		int gg = 0;
//		ft_putstr("\'");
//		ft_putstr(ft_itoa_max(10000));
//		ft_putendl("\'");
//		t_intmax a = -9223372036854775808;
//		t_intmax b = -9223372036854775807;
//		t_intmax c = 9223372036854775807;
//		t_uintmax d = 9223372036854775808;
//		t_uintmax e = 9223372036854775809;
//		printf("%s\n", ft_mtob(&a, sizeof(t_intmax)));
//		printf("%s\n", ft_mtob(&b, sizeof(t_intmax)));
//		printf("%s\n", ft_mtob(&c, sizeof(t_intmax)));
//		printf("%s\n", ft_mtob(&d, sizeof(t_uintmax)));
//		printf("%s\n\n\n", ft_mtob(&e, sizeof(t_uintmax)));
//		ft = ft_printf("% hZ%");
//		printf("\n");
//		gg = printf("% hZ%");
		ft_putstr("ft_printf: \'");
		ft = ft_printf(INPUT);
		ft_putstr("\'\n");
		printf("gg_printf: \'");
		gg = printf(INPUT);
		printf("\'\n");
		printf("\nft: %3i\ngg: %3i\n", ft, gg);
	}
	return (0);
}
