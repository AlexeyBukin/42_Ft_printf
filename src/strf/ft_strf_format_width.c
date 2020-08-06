/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strf_format_width.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 14:29:40 by kcharla           #+#    #+#             */
/*   Updated: 2020/08/06 14:29:41 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strf.h"

char		*ft_strf_format_width(char *string, t_strflags *flags)
{
	size_t		len;

	len = ft_strlen(string);
	if (!(flags->width > 0 && len < (size_t)flags->width))
		return (string);
	len = flags->width - len;
	if (flags->minus == 1)
		string = ft_strjoin_free(string, ft_str_spam(" ", len));
	else
		string = ft_strjoin_free(ft_str_spam(" ", len), string);
	return (string);
}
