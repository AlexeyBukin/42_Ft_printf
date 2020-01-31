/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldouble.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 15:18:08 by kcharla           #+#    #+#             */
/*   Updated: 2020/01/31 15:18:35 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LDOUBLE_H
# define LDOUBLE_H

typedef struct ldouble_10_s
{
	unsigned long long mantissa;
	unsigned int       exponent : 15;
	unsigned int       sign     : 1;
}              ldouble_10_t;

typedef struct mantissa_s
{
	unsigned char byte0;
	unsigned char byte1;
	unsigned char byte2;
	unsigned char byte3;
	unsigned char byte4;
	unsigned char byte5;
	unsigned char byte6;
	unsigned char byte7;
}              mantissa_t;

union ldouble_10_u
{
	long double 	num;
	ldouble_10_t	parts;
	mantissa_t		bytes;
};

#endif
