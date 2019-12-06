/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelina <lmelina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 21:01:49 by lmelina           #+#    #+#             */
/*   Updated: 2019/11/27 12:51:09 by lmelina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_utoa_base(unsigned int value, char *base)
{
	int					count;
	unsigned int		tmp;
	char				*res;
	unsigned int		base_length;

	base_length = ft_strlen(base);
	count = 1;
	tmp = value;
	while (tmp >= base_length && (tmp /= base_length))
		++count;
	tmp = value;
	if (!(res = (char*)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	res[count] = '\0';
	while (tmp >= base_length)
	{
		--count;
		res[count] = base[tmp % base_length];
		tmp /= base_length;
	}
	res[--count] = base[tmp % base_length];
	return (res);
}
