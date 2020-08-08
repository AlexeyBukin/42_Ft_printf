/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strf.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 16:18:21 by kcharla           #+#    #+#             */
/*   Updated: 2020/08/08 17:26:05 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRF_H
# define FT_STRF_H

# include <math.h>
# include <float.h>
# include <stdarg.h>
# include "libft.h"
# include "ldouble.h"
# include "ft_strf.h"

# define ASCII_UNREADABLE_BEFORE ((t_byte)0x20)
# define ASCII_UNREADABLE_AFTER ((t_byte)0xA0)
# define ASCII_UNREADABLE_DIFF ((t_byte)0x40)
# define ASCII_DEL ((t_byte)0x7F)
# define ASCII_NEWLINE ((t_byte)0x0A)

typedef enum	e_format_cast
{
	CAST_NO,
	CAST_HH,
	CAST_H,
	CAST_L,
	CAST_LL,
	CAST_BIG_L
}				t_format_cast;

typedef enum	e_float_special
{
	F_UNSET,
	F_N0_SPECIAL,
	F_NAN,
	F_INF,
	F_ROUND_NO,
	F_ROUND_YES,
}				t_float_special;

//# define CAST_NO    0
//# define CAST_HH    1
//# define CAST_H     2
//# define CAST_L     3
//# define CAST_LL    4
//# define CAST_BIG_L 5

//# define F_N0_SPECIAL   1
//# define F_NAN          2
//# define F_INF          3
//# define F_ROUND_NO     4
//# define F_ROUND_YES    5

# define NULL_IN_THE_BEGINNING 1
# define NULL_IN_THE_END       2

# define PREC_INTENDED_ZERO -1

# define LEN 0
# define IS_X_BIG 1

#define FT_STRF_TYPE_UNKNOWN '?'

typedef struct	s_strflags
{
	char		type;
	char		plus;
	char		minus;
	char		zero;
	char		space;
	char		sharp;
	int			special;
	int			precision;
	char		dot;
	int			width;
	char		num_sign;
	char		cast;
}				t_strflags;


#define FT_PRECISION_DEFAULT -1
#define FT_PRECISION_FLOAT 6
#define FT_WIDTH_DEFAULT -1

int				ft_strf_is_in_args(int ch);


char			*ft_strf(const char *restrict format, ...);

/*
** resolving
*/

int				ft_strf_resolve(char **source, size_t *pos, t_strflags *flags, va_list arg);
int				ft_strf_resolve_ins(char **source, size_t *pos, size_t parsed_len, char *insertion);
int				ft_strf_resolve_text(char **insertion, t_strflags *flags, va_list arg);
int				ft_strf_resolve_nums(char **source, t_strflags *flags, va_list arg);

int				ft_strf_parse(char *args, t_strflags *flags, size_t *parsed_len);

/*
** flag adjustments
*/

void			ft_strf_adjust(t_strflags *flags);

void			ft_strf_adjust_di(t_strflags *flags);
void			ft_strf_adjust_o(t_strflags *flags);
void			ft_strf_adjust_u(t_strflags *flags);
void			ft_strf_adjust_x(t_strflags *flags);
void			ft_strf_adjust_f(t_strflags *flags);

void			ft_strf_adjust_p(t_strflags *flags);
void			ft_strf_adjust_s(t_strflags *flags);
void			ft_strf_adjust_c(t_strflags *flags);
void			ft_strf_adjust_perc(t_strflags *flags);
void			ft_strf_adjust_unknown(t_strflags *flags);

/*
** casts
*/

int				ft_strf_cast_flag_ull(unsigned long long *d,
						t_strflags *flags, va_list arg);
int				ft_strf_cast_flag_lli(long long *d,
						t_strflags *flags, va_list arg);

/*
** flags
*/

char			*ft_strf_flag_di(va_list arg, t_strflags *flags);
char			*ft_strf_flag_o(va_list arg, t_strflags *flags);
char			*ft_strf_flag_u(va_list arg, t_strflags *flags);
char			*ft_strf_flag_x(va_list arg, t_strflags *flags);
char			*ft_strf_flag_p(va_list arg, t_strflags *flags);

char			*ft_strf_flag_c(va_list arg, t_strflags *flags);
char			*ft_strf_flag_s(va_list arg, t_strflags *flags);
char			*ft_strf_flag_perc(t_strflags *flags);
char			*ft_strf_flag_unknown(t_strflags *flags);

/*
** floats
*/

int				float_is_special(long double num);
char			*float_get_special(t_strflags *flags);
char			*float_get_str(t_strflags *flags, long double d);
char			*ft_strf_flag_f(va_list arg, t_strflags *flags);

/*
** formatting
*/

int				is_flag_num(char type);
//char			*ft_strf_format(char *string, t_strflags *flags);
char			*ft_strf_format_prec(char *string, t_strflags *flags);
char			*ft_strf_format_width(char *string, t_strflags *flags);
char			*ft_strf_format_zero(char *string, t_strflags *flags);

char			*ft_strf_format_di(char *string, t_strflags *flags);











char			*insert_from_to(char *inp, char *ins, size_t from, size_t to);
//t_stg			ft_resolve_arg(char *string, va_list arg, int *flags);
char			*ft_insert_d(va_list arg, int *flags);
char			*ft_insert_o(va_list arg, int *flags);
char			*ft_insert_x(va_list arg, int *flags, int is_x_big);
char			*ft_insert_u(va_list arg, int *flags);
char			*ft_insert_p(va_list arg, int *flags);
char			*ft_insert_s(va_list arg, int *flags);
char			*ft_insert_percentage(int *flags);
char			*ft_insert_c(va_list arg, int *flags);

int				parse_flags(char *args, int len, int *flags);
int				arg_len(char *string);

/*
** flag 'f'
*/

char			*ft_float(va_list arg, int *flags);
char			*bad_way(int *flags, long double num);

char			*ft_before_dot(int *flags, long double num);
char			*ft_after_dot(long double num);

char			*f_after_dot(long double num);
char			*f_after_dot_prec(int *flags, long double num);

char			*f_get_special(int *flags);
int				f_is_special(long double num);

char			*width_format(int *flags, char *str, char sign);
//char			*ft_strf_flag_x(va_list arg, t_strflags *flags);


#endif
