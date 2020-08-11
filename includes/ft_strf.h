/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strf.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 16:18:21 by kcharla           #+#    #+#             */
/*   Updated: 2020/08/11 04:50:20 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRF_H
# define FT_STRF_H

# include <math.h>
# include <float.h>
# include <stdarg.h>
# include "libft.h"
# include "ldouble.h"

# define ASCII_UNREADABLE_BEFORE ((t_byte)0x20)
# define ASCII_UNREADABLE_AFTER ((t_byte)0xA0)
# define ASCII_UNREADABLE_DIFF ((t_byte)0x40)
# define ASCII_DEL ((t_byte)0x7F)
# define ASCII_NEWLINE ((t_byte)0x0A)

# define FT_STRF_TYPE_UNKNOWN '?'
# define FT_PRECISION_DEFAULT -1
# define FT_PRECISION_FLOAT 6
# define FT_WIDTH_DEFAULT -1

typedef enum	e_format_cast
{
	CAST_NO,
	CAST_HH,
	CAST_H,
	CAST_L,
	CAST_LL,
	CAST_J,
	CAST_T,
	CAST_Z,
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

char			*ft_strf(const char *restrict format, ...);

/*
** resolving
*/

int				ft_strf_resolve(char **source, size_t *pos, t_strflags *flags, va_list arg);
int				ft_strf_resolve_ins(char **source, size_t *pos, char *insertion);
int				ft_strf_resolve_text(char **insertion, t_strflags *flags, va_list arg);
int				ft_strf_resolve_nums(char **source, t_strflags *flags, va_list arg);

//TODO left only new, delete old
int				ft_strf_parse(char **source, size_t pos, t_strflags *flags);
int				ft_strf_parse_old(char *args, t_strflags *flags, size_t *parsed_len);

void			ft_strflags_init(t_strflags *flags);
int				ft_strf_is_known_flag(int ch);
int				ft_strf_is_parsable(int ch);

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

int				ft_strf_cast_flag_ull(t_uintmax *d,
						t_strflags *flags, va_list arg);
int				ft_strf_cast_flag_lli(t_intmax *d,
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

char			*ft_strf_format_prec(char *string, t_strflags *flags);
char			*ft_strf_format_width(char *string, t_strflags *flags);
char			*ft_strf_format_zero(char *string, t_strflags *flags);








/*
** flag 'f'
*/

//char			*ft_float(va_list arg, int *flags);
//char			*bad_way(int *flags, long double num);
//
//char			*ft_before_dot(int *flags, long double num);
//char			*ft_after_dot(long double num);
//
//char			*f_after_dot(long double num);
//char			*f_after_dot_prec(int *flags, long double num);
//
//char			*f_get_special(int *flags);
//int				f_is_special(long double num);
//
//char			*width_format(int *flags, char *str, char sign);
//char			*ft_strf_flag_x(va_list arg, t_strflags *flags);


#endif
