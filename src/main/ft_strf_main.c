/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:52:05 by kcharla           #+#    #+#             */
/*   Updated: 2020/08/09 20:47:58 by kcharla          ###   ########.fr       */
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

// gcc src/main/ft_strf_main.c src/strf/*.c src/strf/float/*.c  libft/libft.a -I libft/includes -I includes

#include "printf.h"
#include "ft_strf.h"
#include <math.h>
#include <limits.h>

#define STR "|.%4s.|-%c-|+%c+|+%4s+|*%c*|"
#define ARGS "ab", 0, 0, "cd", 0

#define COLOR_RED "\033[0;31m"
#define COLOR_RESET "\033[0m"

int		main(void)
{
	{
		double a = 0;
		(void)a;

//		sleep(3);
		ft_printf("ft_printf: "STR"\n", ARGS);
		printf("gg_printf: "STR"\n", ARGS);
//		ft_printf("%s", COLOR_RED);
//		ft_printf("%s\n", "0123456789  12 15 18 21 24 27 30");
//		ft_printf("%s\n", " |  |  |   11 14 17 20 23 26 29");
//		ft_printf("%s\n", " |  |  |  10 13 16 19 22 25 28");
//		ft_printf("%s\n", " |  |  |  |  |  |  |  |  |  |");
//		ft_printf("%s", COLOR_RESET);
//		ft_printf(STR, ARGS);
//		printf("%s", ft_strf("ft_printf: "STR"\n", ARGS));
	}
	return (0);
}
