/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 21:37:42 by kcharla           #+#    #+#             */
/*   Updated: 2020/08/11 08:30:34 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static uintmax_t		uintmax_power_ten(int power)
{
	uintmax_t	i;

	i = 1;
	while (power > 0)
	{
		i *= 10;
		power--;
	}
	return (i);
}

char					*ft_itoa_max(t_uintmax n)
{
	int		len;
	char	*res;

	if (n == 0)
		return (ft_strdup("0"));
	len = 0;
	while ((n / uintmax_power_ten(len)) != 0)
		len++;
	if ((res = (char*)ft_memalloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	res[len] = '\0';
	while (n != 0)
	{
		res[--len] = (char)('0' + (n % 10));
		n = n / 10;
	}
	return (res);
}
