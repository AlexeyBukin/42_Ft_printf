/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strf_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 14:24:54 by kcharla           #+#    #+#             */
/*   Updated: 2020/08/07 08:43:32 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strf.h"

char		*ft_strf_format_plus(char *string, t_strflags *flags)
{
	(void)flags;
//	if (is_flag_num(flags->type) || ;
	return (string);
}

char		*ft_strf_format_space(char *string, t_strflags *flags)
{
	(void)flags;
//	if (is_flag_num(flags->type) || ;
	return (string);
}

char		*ft_strf_format_di(char *string, t_strflags *flags)
{
	string = ft_strf_format_prec(string, flags);
	string = ft_strf_format_width(string, flags);
	string = ft_strf_format_zero(string, flags);
	return (string);
}

//TODO leaks


char		*ft_strf_format(char *string, t_strflags *flags)
{
	string = ft_strf_format_prec(string, flags);
	string = ft_strf_format_width(string, flags);
	string = ft_strf_format_zero(string, flags);
	return (string);
}
