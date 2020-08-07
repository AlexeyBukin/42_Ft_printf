/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strf_flag_f_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 14:49:15 by kcharla           #+#    #+#             */
/*   Updated: 2020/08/07 14:50:54 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strf.h"

char		*float_get_str(t_strflags *flags, long double d)
{
	(void)flags;
	(void)d;
	return (ft_strdup("0.0"));
}
