/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strf_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 16:47:56 by kcharla           #+#    #+#             */
/*   Updated: 2020/08/06 19:07:04 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strf.h"

void		ft_strflags_init(t_strflags *flags)
{
	if (flags == NULL)
		return ;
	flags->dot = 0;
	flags->precision = -1;
	flags->width = -1;
	flags->plus = 0;
	flags->minus = 0;
	flags->zero = 0;
	flags->space = 0;
	flags->sharp = 0;
	flags->type = '-';
	flags->num_zero = 0;
	flags->cast = CAST_NO;
}

int			ft_strf_parse_cast(char const *args, size_t *pos, t_strflags *flags)
{
	if (args == NULL || pos == NULL || flags == NULL)
		return (-1);
	if (flags->cast != CAST_NO)
		return (-1);
	if (args[*pos] == 'l')
	{
		if (args[*pos + 1] == 'l')
			flags->cast = CAST_LL;
		else
			flags->cast = CAST_L;
	}
	else if (args[*pos] == 'h')
	{
		if (args[*pos + 1] == 'h')
			flags->cast = CAST_HH;
		else
			flags->cast = CAST_H;
	}
	else if (args[*pos] == 'L')
		flags->cast = CAST_BIG_L;
	if (flags->cast == CAST_HH || flags->cast == CAST_LL)
		(*pos)++;
	return (0);
}

int			ft_strf_parse_digits(char *args, size_t *pos, t_strflags *flags)
{
	int			flag_val;

	if (args == NULL || pos == NULL)
		return (-1);
	if (!ft_isdigit(args[*pos]))
		return (0);
	flag_val = ft_atoi(&(args[*pos]));
	while (ft_isdigit(args[*pos]))
		(*pos)++;
	(*pos)--;
	if (flags->dot == 0)
		flags->width = flag_val;
	else if (flags->precision < 0)
		flags->precision = flag_val;
	else
	{
		write (1, "err\n", 4);
		return (-1);
	}
	return (0);
}

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
		flags->dot = 1;
	else if (ft_isdigit(args[*pos]))
		return (ft_strf_parse_digits(args, pos, flags));
	else if (ft_strchr("lhHL", args[*pos]) != NULL)
		return (ft_strf_parse_cast(args, pos, flags));
	return (0);
}

int			ft_strf_parse(char *args, t_strflags *flags, size_t *parsed_len)
{
	size_t		i;

	if (args == NULL || flags == NULL || parsed_len == NULL)
		return (-1);
	ft_strflags_init(flags);
	i = 1;
	while (ft_strf_is_in_args(args[i]) == 1)
	{
		if (ft_strf_parse_elem(args, &i, flags))
		{

			return (-1);
		}
		i++;
	}
	*parsed_len = i + 1;
	if (ft_strf_is_in_args(args[i]) != 2)
		return (-1);
	else
		flags->type = args[i];
	ft_putstr("\ntype: ");
	ft_putchar(flags->type);
	ft_putstr("\nwidth: ");
	ft_putnbr(flags->width);
	ft_putstr("\ndot: ");
	ft_putnbr(flags->dot);
	ft_putstr("\nprec: ");
	ft_putnbr(flags->precision);
	ft_putstr("\nspace: ");
	ft_putnbr(flags->space);
	ft_putstr("\n");
	return (0);
}
