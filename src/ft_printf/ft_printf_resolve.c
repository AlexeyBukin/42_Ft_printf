/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 14:57:18 by lmelina           #+#    #+#             */
/*   Updated: 2020/08/11 00:03:47 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strf.h"

int			ft_printf_resolve_c(t_list pos_p, char **source,
				t_strflags *flags, va_list arg)
{
	size_t		src_len;
	size_t		*pos;
	char		*res;
	t_byte		ch;

	pos = pos_p.content;
	if (pos == NULL || flags == NULL || source == NULL)
		return (-1);
	if (flags->type != 'c')
		return (-1);
	ch = (t_byte)((flags->cast == CAST_L) ?
			va_arg(arg, unsigned long int) : va_arg(arg, unsigned int));
	ft_strf_adjust_c(flags);
	src_len = (*pos + ft_strlen(&((*source)[*pos])));
	if ((res = (char*)ft_memalloc(src_len + flags->width + 1)) == NULL)
		return (-1);
	ft_memcpy(res, *source, *pos);
	ft_memset(&(res[*pos]), ' ', flags->width);
	ft_memcpy(&(res[*pos + flags->width]),
			&((*source)[*pos + pos_p.size]), (src_len - *pos - pos_p.size));
	res[(*pos + ((flags->minus == 1) ? 0 : flags->width - 1))] = ch;
	free(*source);
	*pos += (flags->width - 1);
	*source = res;
	return (0);
}

int			ft_printf_resolve(char **src, size_t *pos,
				t_strflags *flags, va_list arg)
{
	char			*ins;
	size_t			pars_len;
	int				res;

	if (src == NULL || pos == NULL || flags == NULL)
		return (-1);
	if (ft_strf_parse(&((*src)[*pos]), flags, &pars_len))
		return (-1);
	ft_strf_adjust(flags);
	if (flags->type == 'c')
	{
		res = ft_printf_resolve_c(
				(t_list){pos, pars_len, NULL},
				src, flags, arg);
		if (res)
			return (-1);
		return (0);
	}
	if ((res = ft_strf_resolve_nums(&ins, flags, arg)))
		return ((res > 0) ? ft_strf_resolve_ins(src, pos, pars_len, ins) : -1);
	if ((res = ft_strf_resolve_text(&ins, flags, arg)))
		return ((res > 0) ? ft_strf_resolve_ins(src, pos, pars_len, ins) : -1);
	return (-1);
}
