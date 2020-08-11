/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strf_flag_perc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 18:03:29 by kcharla           #+#    #+#             */
/*   Updated: 2020/08/10 18:04:18 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strf.h"

char		*ft_strf_flag_perc(t_strflags *flags)
{
	char	*str;

	if (flags == NULL)
		return (NULL);
	ft_strf_adjust_perc(flags);
	str = ft_strdup("%");
	str = ft_strf_format_zero(str, flags);
	str = ft_strf_format_width(str, flags);
	return (str);
}
