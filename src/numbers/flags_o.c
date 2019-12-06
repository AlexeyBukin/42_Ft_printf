/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelina <lmelina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 19:23:35 by lmelina           #+#    #+#             */
/*   Updated: 2019/12/06 19:23:48 by lmelina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_insert_o(char *input, int start, int i, int d)
{
	char *num;

	num = ft_itoa_base(d, "01234567");
	input = insert_from_to(input, num, start, i);
	return (input);
}

char	*ft_alternative_insert_o(char *input, int start, int i, int d)
{
	char *num;
	char zero[2];

	zero[0] = '0';
	zero[1] = '\0';
	num = ft_itoa_base(d, "01234567");
	num = ft_strjoin(zero, num);
	input = insert_from_to(input, num, start, i);
	return (input);
}