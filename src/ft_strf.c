/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 14:57:18 by lmelina           #+#    #+#             */
/*   Updated: 2020/08/06 15:03:48 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "ft_strf.h"

/*
** PREC_INTENDED_ZERO == 0
** PREC_DEFAULT == -1
** precision (-1) means it is default
*/



int			is_flag_num(char type)
{
	if (ft_strchr("diouxX", type) != NULL)
		return (1);
	return (0);
}

int			is_in_args(int ch)
{
	if (ch == '\0')
		return (-1);
	if (ft_strchr(".1234567890-+ #Llh", ch) != NULL)
		return (1);
	if (ft_strchr("scp%diouxXfF", ch) != NULL)
		return (2);
	return (0);
}

int			ft_strf_parse_elem(char *args, size_t *pos, t_strflags *flags)
{
	return (0);
}

void		ft_strflags_init(t_strflags *flags)
{
	if (flags == NULL)
		return ;
	flags->precision = 5;
	flags->width = -1;
	flags->minus = 0;
}

int			ft_strf_parse(char *args, t_strflags *flags, size_t *parsed_len)
{
	int			dot_passed;
	size_t		i;

	if (args == NULL || flags == NULL || parsed_len == 0)
		return (-1);
	ft_strflags_init(flags);
	i = 1;
	while (is_in_args(args[i]) == 1)
	{
		if (ft_strf_parse_elem(&(args[i]), &i, flags))
			return (-1);
		i++;
	}
	*parsed_len = i + 1;
	if (is_in_args(args[i]) != 2)
		return (-1);
	else
		flags->type = args[i];
	return (0);
}

char		*ft_strf_flag_s(va_list arg, t_strflags *flags)
{
	char		*insert;

	if (flags == NULL)
		return (NULL);
	if ((insert = va_arg(arg, char*)) != NULL)
		insert = ft_strdup(insert);
	else
		insert = ft_strdup("(null)");
	ft_strf_adjust_s(flags);
	return (ft_strf_format(insert, flags));
}

char		*ft_strf(const char *restrict format, ...)
{
	t_strflags		sflags;
	va_list			arg;
	char			*res;
	size_t			i;

	res = ft_strdup((char *)format);
	va_start(arg, format);
	i = 0;
	while ((res)[i] != '\0')
	{
		if (res[i] == '%')
		{
			if (ft_strf_resolve(&res, &i, &sflags, arg))
			{
				free(res);
				return (NULL);
			}
		}
		i++;
	}
	return (res);
}
