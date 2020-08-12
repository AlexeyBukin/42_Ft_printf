/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strf_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 16:47:56 by kcharla           #+#    #+#             */
/*   Updated: 2020/08/12 21:56:19 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strf.h"

/*
** parses 'source' string starting at 'pos'
** into 'flags' structure
** returns negative integer on error
** returns zero on success
*/

int			ft_strf_parse(char **source, size_t pos, t_strflags *flags)
{
	char		*string;
	size_t		i;

	if (source == NULL || flags == NULL)
		return (-1);
	if ((string = *source) == NULL)
		return (-1);
	string = &(string[pos]);
	ft_strflags_init(flags);
	i = 1;
	while (ft_strf_is_parsable(string[i]))
	{
		if (ft_strf_parse_elem(string, &i, flags))
			return (-1);
		i++;
	}
	if (ft_strf_is_known_flag(string[i]))
		flags->type = string[i++];
	else
		flags->type = FT_STRF_TYPE_UNKNOWN;
	ft_strcpy(string, &(string[i]));
	return (0);
}

/*
** parses one 'cast' element
** updates one field in 'flags' structure
** returns negative integer on error
** returns zero on success
*/

int			ft_strf_parse_cast(char const *args, size_t *pos, t_strflags *flags)
{
	char		cast;

	if (args == NULL || pos == NULL || flags == NULL)
		return (-1);
	if (args[*pos] == 'l')
		cast = (args[*pos + 1] == 'l') ? CAST_LL : CAST_L;
	else if (args[*pos] == 'h')
		cast = (args[*pos + 1] == 'h') ? CAST_HH : CAST_H;
	else if (args[*pos] == 'L')
		cast = CAST_BIG_L;
	else if (args[*pos] == 'j')
		cast = CAST_J;
	else if (args[*pos] == 'z')
		cast = CAST_Z;
	else if (args[*pos] == 't')
		cast = CAST_T;
	if (flags->cast < cast)
		flags->cast = cast;
	if (cast == CAST_HH || cast == CAST_LL)
		(*pos)++;
	return (0);
}

/*
** parses one 'digits' element
** decides if it is width or precision
** fills one field in 'flags' structure
** with parsed element
** returns negative integer on error
** returns zero on success
*/

int			ft_strf_parse_digits(char *args, size_t *pos, t_strflags *flags)
{
	int			flag_val;

	if (args == NULL || pos == NULL)
		return (-1);
	if (flags->dot == 0 && args[*pos] == '0')
	{
		flags->zero = 1;
		return (0);
	}
	if (!ft_isdigit(args[*pos]))
		return (0);
	flag_val = ft_atoi(&(args[*pos]));
	while (ft_isdigit(args[*pos]))
		(*pos)++;
	(*pos)--;
	if (flags->dot == 0)
		flags->width = flag_val;
	else if (flags->precision <= 0)
		flags->precision = flag_val;
	else
		return (-1);
	return (0);
}

/*
** parses one 'element' from 'args' string
** one element means one 'flags' field
** into 'flags' structure
** returns negative integer on error
** returns zero on success
*/

int			ft_strf_parse_elem(char *args, size_t *pos, t_strflags *flags)
{
	if (args == NULL || pos == NULL)
		return (-1);
	if (args[*pos] == '-')
		flags->minus = 1;
	else if (args[*pos] == '+')
		flags->plus = 1;
	else if (args[*pos] == ' ')
		flags->space = 1;
	else if (args[*pos] == '#')
		flags->sharp = 1;
	else if (args[*pos] == '.')
	{
		flags->precision = 0;
		flags->dot = 1;
	}
	else if (ft_isdigit(args[*pos]))
		return (ft_strf_parse_digits(args, pos, flags));
	else if (ft_strchr("lhLjzt", args[*pos]) != NULL)
		return (ft_strf_parse_cast(args, pos, flags));
	return (0);
}
