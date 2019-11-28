/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 20:20:34 by kcharla           #+#    #+#             */
/*   Updated: 2019/11/06 19:51:18 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*res;

	if (s1 == 0 || s2 == 0)
		return (0);
	res = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (res == 0)
	{
		return (0);
	}
	res = ft_strcpy(res, s1);
	res = ft_strcat(res, s2);
	free(s1);
	free(s2);
	return (res);
}
