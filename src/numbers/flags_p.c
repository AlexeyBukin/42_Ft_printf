/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelina <lmelina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 19:23:35 by lmelina           #+#    #+#             */
/*   Updated: 2019/12/06 19:30:35 by lmelina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_insert_p(char *input, int start, int i, int d)
{
	char *num;
	char zero[3];
	char ffff[5];

	zero[0] = '0';
	zero[1] = 'x';
	zero[2] = '\0';
	ffff[0] = '7';
	ffff[1] = 'f';
	ffff[2] = 'f';
	ffff[3] = 'f';
	ffff[4] = '\0';
	num = ft_itoa_base(d, "0123456789abcdef");
	num = ft_strjoin(ffff, num);
	num = ft_strjoin(zero, num);
	input = insert_from_to(input, num, start, i);
	return (input);
}