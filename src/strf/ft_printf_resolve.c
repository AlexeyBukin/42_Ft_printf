/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 14:57:18 by lmelina           #+#    #+#             */
/*   Updated: 2020/08/09 20:44:31 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strf.h"

int			ft_printf_resolve_c(t_list pos_parsed, char **source, t_strflags *flags, va_list arg)
{
	size_t		*pos;
	size_t		parsed_len;
	char		*res;
	t_byte		ch;

	pos = pos_parsed.content;
	parsed_len = pos_parsed.content_size;
	if (pos == NULL || flags == NULL || source == NULL)
		return (-1);
	if (flags->type != 'c')
		return (-1);
	if ((res = (char*)ft_strnew(1)) == NULL)
		return (-1);
	if (flags->cast == CAST_L)
		ch = (char)va_arg(arg, unsigned long int);
	else
		ch = (char)va_arg(arg, unsigned int);
	ft_strf_adjust_c(flags);

	flags->width = (flags->width <= 0) ? 1 : flags->width;

	size_t		src_len;
	size_t		ins_len;

	src_len = (*pos + ft_strlen(&((*source)[*pos])));

//	ft_putendl("src:");
//	write (1, *source, src_len);
//	ft_putstr("\nsrc_len: ");
//	ft_putnbr((int)src_len);
//	ft_putstr("\n");


	ins_len = (size_t)flags->width;
	res = (char*)ft_memalloc(src_len + ins_len + 1);
	if (res == NULL)
		return (-1);
	ft_memcpy(res, *source, *pos);

//	ft_putendl("res:");
//	write (1, res, *pos);
//	ft_putstr("\nres_len: ");
//	ft_putnbr((int)*pos);
//	ft_putstr("\n");

//	ft_strncpy(res, *source, *pos);
	ft_memset(&(res[*pos]), ' ', ins_len);

//	ft_putendl("res before cat:");
//	write (1, res, *pos + ins_len);
//	ft_putstr("\nres_len: ");
//	ft_putnbr((int)(*pos + ins_len));
//	ft_putstr("\n");

	ft_memcpy(&(res[*pos + ins_len]), &((*source)[*pos + parsed_len]), (src_len - *pos - parsed_len));

//	ft_strcat(res, &((*source)[*pos + parsed_len]));

//	ft_putendl("res after cat:");
//	write (1, res, *pos - parsed_len + ins_len);
//	ft_putstr("\nres_len: ");
//	ft_putnbr((int)(*pos - parsed_len + ins_len));
//	ft_putstr("\n");

	res[(*pos + ((flags->minus == 1) ? 0 : ins_len - 1))] = ch;

//	ft_putendl("here we go:");
//	write (1, &(res[*pos]), ins_len);
//	ft_putendl("\ndone");
//	ft_putendl("full:");
//	write (1, res, src_len - parsed_len + ins_len);
//	ft_putendl("\ndone");
//	ft_putendl("ins:");
//	ft_putnbr((int)ins_len);
//	ft_putendl("\nsrc:");
//	ft_putnbr((int)src_len);
//	ft_putendl("\ndone");


	free(*source);

	*pos += ins_len;
	*source = res;
	return (0);
}

//flags, arg, source, pos, parsed_len

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
//	ft_putstr("resolving at ");
//	ft_putnbr((int)*pos);
//	ft_putendl("");

	if (flags->type == 'c')
	{
//		ft_putstr("full before:\n");
//		write (1, *source, (*pos + ft_strlen(&((*source)[*pos]))));
//		ft_putendl("\ndone");
//		ft_putendl("pos:");
//		ft_putnbr((int)*pos);
//		ft_putendl("\n");

		res = ft_printf_resolve_c(
				(t_list){pos, parsed_len, NULL},
				source,
				flags,
				arg);
		if (res)
			return (-1);

//		ft_putstr("full after:\n");
//		write (1, *source, (*pos + ft_strlen(&((*source)[*pos]))));
//		ft_putendl("\ndone");
//		ft_putendl("pos:");
//		ft_putnbr((int)*pos);
//		ft_putendl("\n");


		return (0);
	}
	if ((res = ft_strf_resolve_nums(&insertion, flags, arg)))
		return ((res > 0) ? ft_strf_resolve_ins(source, pos, parsed_len, insertion) : -1);
	if ((res = ft_strf_resolve_text(&insertion, flags, arg)))
		return ((res > 0) ? ft_strf_resolve_ins(source, pos, parsed_len, insertion) : -1);
	return (-1);
}
