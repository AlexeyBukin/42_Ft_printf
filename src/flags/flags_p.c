/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelina <lmelina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 19:23:35 by lmelina           #+#    #+#             */
/*   Updated: 2019/12/10 18:53:40 by lmelina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_insert_p(int d)
{
	char *num;
	char *zero;
	char *ffff;

	zero = "0x";
	ffff = "7fff";
	num = ft_itoa_base(d, BASE16L); //"0123456789abcdef"
	num = ft_strjoin(ffff, num);
	num = ft_strjoin(zero, num);
	return (num);
}