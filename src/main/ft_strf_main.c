/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:52:05 by kcharla           #+#    #+#             */
/*   Updated: 2020/08/06 14:57:26 by kcharla          ###   ########.fr       */
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

//gcc src/main/ft_strf_main.c src/ft_srtf_format/*.c libft/libft.a -I libft/includes src/ft_strf.c -I includes

// gcc src/main/ft_strf_main.c src/ft_strf_format/*.c src/ft_strf_resolve.c src/ft_strf_adjust/*.c  libft/libft.a -I libft/includes src/ft_strf.c -I includes
#include "printf.h"
#include "ft_strf.h"
#include <math.h>
#include <limits.h>

#define STR "|%-.8f|"
#define ARGS -1245.02 * 10000000000L * 1000000000000L * 200000000000000L

int		main(void)
{
	{
		double a = 0;
		printf("printf: \'%10.5s\' \'%+020.20d\'\n", "abc", 22);
//		write(1, "ft_strf_1\n", 11);
		printf("\"%s\"\n", ft_strf("-format-s-is-\'%.5s\'-", "abc"));
	}
	return (0);
}
