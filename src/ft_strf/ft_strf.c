/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 14:57:18 by lmelina           #+#    #+#             */
/*   Updated: 2020/08/12 21:40:10 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strf.h"

/*
** main ft_strf function
** concatenates all flags and format to one string
** returns (NULL) on error
*/

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
