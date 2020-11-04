/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 14:57:18 by lmelina           #+#    #+#             */
/*   Updated: 2020/08/12 22:00:39 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strf.h"

/*
** fulfills 'flags' structure and inserts
** formatted flag string into shared 'source' string
** also shifts 'pos' to the end of insertion
** returns non-zero integer on error
** returns zero on success
*/

int			ft_strf_resolve(char **source, size_t *pos,
							   t_strflags *flags, va_list arg)
{
	char			*insertion;
	int				res;

	if (source == NULL || pos == NULL || flags == NULL)
		return (-1);
	if (ft_strf_parse(source, *pos, flags))
		return (-1);
	ft_strf_adjust(flags);
	if ((res = ft_strf_resolve_nums(&insertion, flags, arg)))
		return ((res > 0) ? ft_strf_resolve_ins(source, pos, insertion) : -1);
	if ((res = ft_strf_resolve_text(&insertion, flags, arg)))
		return ((res > 0) ? ft_strf_resolve_ins(source, pos, insertion) : -1);
	return (-1);
}

/*
** TODO add binary flag 'b'
*/

/*
** resolves 'text' flags
** (also will resolve bonus flags in future)
** returns negative integer on error
** returns positive integer on succes
** returns zero if no flag matched
*/

int			ft_strf_resolve_text(char **insertion,
				t_strflags *flags, va_list arg)
{
	if (insertion == NULL || flags == NULL)
		return (-1);
	if (flags->type == 's')
		*insertion = ft_strf_flag_s(arg, flags);
	else if (flags->type == 'c')
		*insertion = ft_strf_flag_c(arg, flags);
	else if (flags->type == '%')
		*insertion = ft_strf_flag_perc(flags);
	else if (flags->type == FT_STRF_TYPE_UNKNOWN)
		*insertion = ft_strf_flag_unknown(flags);
	else
		return (0);
	if (*insertion == NULL)
		return (-1);
	return (1);
}

/*
** resolves 'nums' flags
** (also will resolve bonus flags in future)
** returns negative integer on error
** returns positive integer on succes
** returns zero if no flag matched
*/

int			ft_strf_resolve_nums(char **source, t_strflags *flags, va_list arg)
{
	if (source == NULL || flags == NULL)
		return (-1);
	if (flags->type == 'd' || flags->type == 'i')
		*source = ft_strf_flag_di(arg, flags);
	else if (flags->type == 'u' || flags->type == 'U')
		*source = ft_strf_flag_u(arg, flags);
	else if (flags->type == 'p')
		*source = ft_strf_flag_p(arg, flags);
	else if (flags->type == 'o')
		*source = ft_strf_flag_o(arg, flags);
	else if (flags->type == 'x' || flags->type == 'X')
		*source = ft_strf_flag_x(arg, flags);
	else if (flags->type == 'f' || flags->type == 'F')
		*source = ft_strf_flag_f(arg, flags);
	else if (flags->type == 'e' || flags->type == 'E')
		*source = ft_strf_flag_e(arg, flags);
	else
		return (0);
	if (*source == NULL)
		return (-1);
	return (1);
}

/*
** inserts resolved flag string into 'source' string
** skips (NULL) characters in the middle of string
** returns non-zero on error
** returns zero on success
*/

int			ft_strf_resolve_ins(char **source, size_t *pos, char *insertion)
{
	size_t		src_len;
	size_t		ins_len;
	char		*res;

	if (source == NULL || pos == NULL)
		return (-1);
	src_len = (*pos + ft_strlen(&((*source)[*pos])));
	ins_len = ft_strlen(insertion);
	res = (char*)ft_memalloc(src_len + ins_len + 1);
	if (res == NULL)
		return (-1);
	ft_memcpy(res, *source, *pos);
	ft_memcpy(&(res[*pos]), insertion, ins_len);
	ft_memcpy(&(res[*pos + ins_len]),
			&((*source)[*pos]), (src_len - *pos) < 0 ? 0 : (src_len - *pos));
	ft_free(*source);
	ft_free(insertion);
	*pos += (ins_len);
	*source = res;
	return (0);
}
