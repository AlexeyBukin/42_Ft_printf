/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strf_flag_unknown.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 17:26:52 by kcharla           #+#    #+#             */
/*   Updated: 2020/08/08 17:26:52 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strf.h"

char		*ft_strf_flag_unknown(t_strflags *flags)
{
	char		*insert;

	if (flags == NULL)
		return (NULL);
	insert = ft_strdup("");
	ft_strf_adjust_unknown(flags);
	insert = ft_strf_format_width(insert, flags);
	return (insert);
}
