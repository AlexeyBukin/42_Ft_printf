/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 16:44:37 by kcharla           #+#    #+#             */
/*   Updated: 2020/08/08 16:56:23 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <math.h>
# include <float.h>
# include <stdarg.h>
# include "libft.h"
# include "ft_strf.h"

int			ft_printf_resolve(char **source, size_t *pos, t_strflags *flags, va_list arg);
int			ft_printf_resolve_c(char **insertion, t_strflags *flags, va_list arg);
int			ft_printf_resolve_c_ins(char **source, size_t *pos, size_t parsed_len, char *insertion);
int			ft_printf(const char *restrict format, ...);

#endif
