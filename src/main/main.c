/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:52:05 by kcharla           #+#    #+#             */
/*   Updated: 2020/08/10 21:44:59 by kcharla          ###   ########.fr       */
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

#define STR "%i"
#define ARGS 12345
//#define STR "|%-.8d|%30.5s|%12c|"
//#define ARGS -1245, "wanna check some leaks?", 0
//#define ARGS -1245, "wanna check some leaks?", 0
//#define ARGS -1245.02 * 10000000000L * 1000000000000L * 200000000000000L

int		main(void)
{
	{
		int ft = 0;
		int gg = 0;
		ft = ft_printf("ft_printf: \'"STR"\'\n", ARGS);
		gg = printf("gg_printf: \'"STR"\'\n", ARGS);
		printf("ft: %3i\ngg: %3i\n", ft, gg);
	}
	return (0);
}
