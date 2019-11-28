/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 16:45:50 by kcharla           #+#    #+#             */
/*   Updated: 2019/11/28 16:48:05 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		power_ten(int power)
{
	int		i;

	i = 1;
	while (power > 0)
	{
		i *= 10;
		power--;
	}
	return (i);
}

static char		*do_if_ok(uint8_t len, int n)
{
	char	*res;

	while (n / power_ten(len) / 10 != 0)
		len++;
	len++;
	res = (char*)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	res[len] = '\0';
	while (n != 0)
	{
		res[len - 1] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	return (res);
}

char			*ft_utoa(unsigned int n)
{
	uint8_t	len;
	char	*res;

	if (n != 0)
	{
		len = 0;
		res = do_if_ok(len, n);
	}
	else
	{
		res = (char*)malloc(sizeof(char) * 2);
		if (res == 0)
			return (0);
		res[0] = '0';
		res[1] = '\0';
	}
	return (res);
}
