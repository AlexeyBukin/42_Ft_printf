/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelina <lmelina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 15:00:26 by lmelina           #+#    #+#             */
/*   Updated: 2019/11/28 16:56:49 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

//TODO delete stdio.h
#include <stdio.h>

# include <stdarg.h>
# include "libft.h"

int			ft_printf(const char *restrict format, ...);
char		*insert_from_to(char *input, char *insertion, size_t from, size_t to);
char		*insert_from_to2(char *res, char *input, size_t to, int i);
char		*ft_resolve_arg(char *string, int i, va_list arg);
char		*ft_insert_d(char *input, int i, int d);

#endif