/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelina <lmelina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 15:00:26 by lmelina           #+#    #+#             */
/*   Updated: 2019/12/10 21:52:34 by lmelina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

/*
** TODO delete stdio.h
*/

# include <stdio.h>

# include <stdarg.h>
# include "libft.h"

#define CAST_HH    1
#define CAST_H     2
#define CAST_L     3
#define CAST_LL    4
#define CAST_BIG_L 5

//#define FLAG_S     1
//#define FLAG_C     2
//#define FLAG_F     3
//#define FLAG_P     4
//#define FLAG_O     5
//#define FLAG_PERC  6
//#define FLAG_U     7
//#define FLAG_X     8
//#define FLAG_X_BIG 9
//#define FLAG_DI    10

#define NULL_IN_THE_BEGINNING 1
#define NULL_IN_THE_END       2

#define PRECISION  0
#define PLUS       1
#define MINUS      2
#define ZERO       3
#define SPACE      4
#define WIDTH      5
#define SHARP      6
#define CAST       7
#define C_GOT_NULL 8
#define FLAG       9
#define FLAGS_LEN  10

typedef struct	s_stg
{
	char			*string;
	int				taken;
}				t_stg;

int			ft_printf(const char *restrict format, ...);
char		*insert_from_to(char *inp, char *ins, size_t from, size_t to);
char		*insert_from_to2(char *res, char *input, size_t to, int i);
t_stg		ft_resolve_arg(char *string, va_list arg, int * flags);
char		*ft_insert_d(int d, int *flags);
char	    *ft_insert_o(int d, int *flags);
char	    *ft_insert_x(int d, int *flags, int is_x_big);
char	    *ft_insert_u(int d, int *flags);
char	    *ft_insert_p(int d);
char		*ft_insert_s(va_list arg, int *flags);
char		*ft_insert_percentage(int *flags);
char		*ft_insert_c(va_list arg, int *flags);

void		*ft_insert_mem(void *string, void *insertion, size_t index, size_t ilen, size_t mlen);

int			parse_flags(char *args, int len, int *flags);
int			arg_len(char *string);

#endif
