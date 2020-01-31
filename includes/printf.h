/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelina <lmelina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 15:00:26 by lmelina           #+#    #+#             */
/*   Updated: 2020/01/31 11:34:43 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

/*
** TODO delete stdio.h
*/

# include <stdio.h>

# include <math.h>
# include <float.h>
# include <stdarg.h>
# include "libft.h"

#define CAST_NO    0
#define CAST_HH    1
#define CAST_H     2
#define CAST_L     3
#define CAST_LL    4
#define CAST_BIG_L 5

#define F_N0_SPECIAL   1
#define F_NAN          2
#define F_INF          3
#define F_ROUND_NO     4
#define F_ROUND_YES    5

#define NULL_IN_THE_BEGINNING 1
#define NULL_IN_THE_END       2

#define PREC_INTENDED_ZERO -1

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
#define SPECIAL    10
#define FLAGS_LEN  11

typedef struct	s_stg
{
	char			*string;
	int				taken;
}				t_stg;

int			ft_printf(const char *restrict format, ...);

char		*insert_from_to(char *inp, char *ins, size_t from, size_t to);
char		*insert_from_to2(char *res, char *input, size_t to, int i);
t_stg		ft_resolve_arg(char *string, va_list arg, int * flags);
char		*ft_insert_d(va_list arg, int *flags);
char	    *ft_insert_o(va_list arg, int *flags);
char		*ft_insert_x(va_list arg, int *flags, int is_x_big);
char	    *ft_insert_u(va_list arg, int *flags);
char	    *ft_insert_p(va_list arg, int *flags);
char		*ft_insert_s(va_list arg, int *flags);
char		*ft_insert_percentage(int *flags);
char		*ft_insert_c(va_list arg, int *flags);

void		*ft_insert_mem(void *string, void *insertion, size_t index, size_t ilen, size_t mlen);

int			parse_flags(char *args, int len, int *flags);
int			arg_len(char *string);

/*
** flag 'f'
*/

typedef struct ldouble_10_s
{
	unsigned long long mantissa;
	unsigned int       exponent : 15;
	unsigned int       sign     : 1;
}              ldouble_10_t;

typedef struct mantissa_s
{
	unsigned char byte0;
	unsigned char byte1;
	unsigned char byte2;
	unsigned char byte3;
	unsigned char byte4;
	unsigned char byte5;
	unsigned char byte6;
	unsigned char byte7;
}              mantissa_t;

union ldouble_10_u
{
	long double 	num;
	ldouble_10_t	parts;
	mantissa_t		bytes;
};

char		*ft_float(va_list arg, int *flags);
char		*bad_way(int *flags, long double num);

char			*ldouble_from_bits(long double num);
char			*ft_before_dot(int *flags, long double num);

unsigned char	bits_rev(unsigned char input);
void			*mem_rev(void *pointer_v, size_t count);
char			*ft_str_dup_rev(const char *s);

char		*f_after_dot(long double num);
char		*f_after_dot_prec(int *flags, long double num);

char		*f_get_special(int *flags);
int			f_is_special(long double num);

char		*width_format(int *flags, char *str, char sign);



#endif
