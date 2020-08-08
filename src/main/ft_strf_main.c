/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:52:05 by kcharla           #+#    #+#             */
/*   Updated: 2020/08/08 18:55:02 by kcharla          ###   ########.fr       */
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

#define STR "|%-20f|%3.5i|%20s|%c|%c|%- 3.3%|%b|"
#define ARGS -1.0, 228, "asdfghjkl", '\n', 159, 160, 3

int		main(void)
{
	{
		double a = 0;
		(void)a;
		printf("gg_printf: "STR"\n", ARGS);
		printf("%s", ft_strf("ft_printf: "STR"\n", ARGS));
	}
	return (0);
}
