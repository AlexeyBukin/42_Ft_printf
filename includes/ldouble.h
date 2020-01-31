/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldouble.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 15:18:08 by kcharla           #+#    #+#             */
/*   Updated: 2020/01/31 17:43:18 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LDOUBLE_H
# define LDOUBLE_H

typedef struct			s_mantissa
{
	unsigned char byte0;
	unsigned char byte1;
	unsigned char byte2;
	unsigned char byte3;
	unsigned char byte4;
	unsigned char byte5;
	unsigned char byte6;
	unsigned char byte7;
}						t_mantissa;

typedef struct			s_ldouble_10
{
	unsigned long long	mantissa;
	unsigned int		exponent : 15;
	unsigned int		sign : 1;
}						t_ldouble_10;

typedef union			u_ldouble_10
{
	long double		num;
	t_ldouble_10	parts;
	t_mantissa		bytes;
}						t_ldouble_10_u;

#endif
