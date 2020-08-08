/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 14:57:18 by lmelina           #+#    #+#             */
/*   Updated: 2020/08/08 17:32:54 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strf.h"

int			ft_strf_resolve_text(char **insertion, t_strflags *flags, va_list arg)
{
	if (insertion == NULL || flags == NULL)
		return (-1);
	if (flags->type == 's')
		*insertion = ft_strf_flag_s(arg, flags);
	else if (flags->type == 'c')
		*insertion = ft_strf_flag_c(arg, flags);
	else if (flags->type == '%')
		*insertion = ft_strf_flag_perc(flags);
//	t for tint: colorful output
//	else if (flags->type == 't')
//		string = ft_insert_percentage(flags);
	else if (flags->type == FT_STRF_TYPE_UNKNOWN)
		*insertion = ft_strf_flag_unknown(flags);
	else
		return (0);
	if (*insertion == NULL)
		return (-1);
	return (1);
}

// TODO add binary ('b') flag
// TODO add tinted ('t') flag

int			ft_strf_resolve_nums(char **source, t_strflags *flags, va_list arg)
{
	if (source == NULL || flags == NULL)
		return (-1);
	if (flags->type == 'd' || flags->type == 'i')
		*source = ft_strf_flag_di(arg, flags);
	else if (flags->type == 'u')
		*source = ft_strf_flag_u(arg, flags);
	else if (flags->type == 'p')
		*source = ft_strf_flag_p(arg, flags);
	else if (flags->type == 'o')
		*source = ft_strf_flag_o(arg, flags);
	else if (flags->type == 'x' || flags->type == 'X')
		*source = ft_strf_flag_x(arg, flags);
	else if (flags->type == 'f' || flags->type == 'F')
		*source = ft_strf_flag_f(arg, flags);
	else
		return (0);
	if (*source == NULL)
		return (-1);
	return (1);
}

/*
** TODO ft_free replace
*/

int			ft_strf_resolve_ins(char **source, size_t *pos, size_t parsed_len, char *insertion)
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

int			ft_strf_resolve(char **source, size_t *pos, t_strflags *flags, va_list arg)
{
	char			*insertion;
	size_t			parsed_len;
	int				res;

	if (source == NULL || pos == NULL || flags == NULL)
		return (-1);
	if (ft_strf_parse(&((*source)[*pos]), flags, &parsed_len))
	{
		return (-1);
	}
	ft_strf_adjust(flags);
	if ((res = ft_strf_resolve_nums(&insertion, flags, arg)))
	{
//		write (1, "lol\n", 4);
//		ft_putendl(insertion);
		return ((res > 0) ? ft_strf_resolve_ins(source, pos, parsed_len, insertion) : -1);
	}
//	if ((res = ft_strf_resolve_float(&insertion, flags, arg)))
//		return ((res > 0) ? ft_strf_resolve_ins(source, pos, parsed_len, insertion) : -1);
	if ((res = ft_strf_resolve_text(&insertion, flags, arg)))
		return ((res > 0) ? ft_strf_resolve_ins(source, pos, parsed_len, insertion) : -1);

//	ft_putendl("next one is:");
//	ft_putendl(&((*source)[*pos]));

	return (-1);
}