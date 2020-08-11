/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 16:24:56 by kcharla           #+#    #+#             */
/*   Updated: 2020/08/11 00:21:36 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t size)
{
	void	*content_copy;
	t_list	*res;

	res = (t_list*)malloc(sizeof(t_list));
	if (res == 0)
	{
		return (0);
	}
	if (content == 0)
	{
		res->content = 0;
		res->size = 0;
	}
	else
	{
		content_copy = ft_memalloc(size);
		content_copy = ft_memcpy(content_copy, content, size);
		res->content = content_copy;
		res->size = size;
	}
	res->next = 0;
	return (res);
}
