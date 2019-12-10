/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_mem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelina <lmelina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:30:58 by lmelina           #+#    #+#             */
/*   Updated: 2019/12/10 16:30:58 by lmelina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		*ft_insert_mem(void *memory, void *insertion, size_t index, size_t inslen, size_t memlen)
{
	uint8_t	*result;
	uint8_t	*mem;
	uint8_t	*insert;

	mem = (uint8_t*) memory;
	insert = (uint8_t*) insertion;
	result = (uint8_t*) malloc (sizeof(uint8_t) * (inslen + memlen));
	if (result == NULL)
		return (NULL);
	int i = 0;
	while (i < (int) index)
	{
		result[i] = mem[i];
		i++;
	}
	while (i < (int) (index + inslen))
	{
		result[i] = insert[i - index];
		i++;
	}
	while (i < (int) (memlen + inslen))
	{
		result[i] = mem[i - inslen];
		i++;
	}
	return (result);
}
