/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 14:57:18 by lmelina           #+#    #+#             */
/*   Updated: 2020/08/08 16:54:12 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strf.h"

int			ft_printf_resolve_c(char **insertion, t_strflags *flags, va_list arg)
{
	if (insertion == NULL || flags == NULL)
		return (-1);
	if (flags->type != 'c')
		return (0);

	return (1);
}

int			ft_printf_resolve_c_ins(char **source, size_t *pos, size_t parsed_len, char *insertion)
{
	size_t		src_len;
	size_t		ins_len;
	char		*res;

	if (source == NULL || pos == NULL)
		return (-1);
	src_len = (*pos + ft_strlen(&((*source)[*pos])));
	ins_len = ft_strlen(insertion);
	res = (char*)ft_memalloc(src_len + ins_len);
	if (res == NULL)
		return (-1);
	ft_strncpy(res, *source, *pos);
	ft_strcat(res, insertion);
	ft_strcat(res, &((*source)[*pos + parsed_len]));
	free(*source);
	free(insertion);
	*pos += ins_len;
	*source = res;
	return (0);
}

int			ft_printf_resolve(char **source, size_t *pos, t_strflags *flags, va_list arg)
{
	char			*insertion;
	size_t			parsed_len;
	int				res;

	if (source == NULL || pos == NULL || flags == NULL)
		return (-1);
	if (ft_strf_parse(&((*source)[*pos]), flags, &parsed_len))
		return (-1);
	ft_strf_adjust(flags);
	(void)res;
	if ((res = ft_printf_resolve_c(&insertion, flags, arg)))
		return ((res > 0) ? ft_printf_resolve_c_ins(source, pos, parsed_len, insertion) : -1);
	(void)res;
	if ((res = ft_strf_resolve_nums(&insertion, flags, arg)))
		return ((res > 0) ? ft_strf_resolve_ins(source, pos, parsed_len, insertion) : -1);
	if ((res = ft_strf_resolve_text(&insertion, flags, arg)))
		return ((res > 0) ? ft_strf_resolve_ins(source, pos, parsed_len, insertion) : -1);
	return (-1);
}
