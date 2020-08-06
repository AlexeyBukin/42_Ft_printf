/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strf_flag_perc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 18:03:29 by kcharla           #+#    #+#             */
/*   Updated: 2020/08/06 18:04:54 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strf.h"

char		*ft_strf_flag_perc(t_strflags *flags)
{
	if (flags == NULL)
		return (NULL);
	ft_strf_adjust_perc(flags);
	return (ft_strf_format(ft_strdup("%"), flags));
}
