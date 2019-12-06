/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelina <lmelina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 19:23:35 by lmelina           #+#    #+#             */
/*   Updated: 2019/12/06 19:28:10 by lmelina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"


char	*ft_insert_x(char *input, int start, int i, int d, int *flags)
{
	char	*num;
	int		len;

	num = ft_itoa_base(d, "0123456789abcdef");

	if (flags[ZERO] == 1 && flags[PRECISION] == 0)
	{
		len = (int)ft_strlen(num);
		if (flags[PLUS] == 1 || flags[SPACE] == 1 || d < 0)
			len ++;
		num = ft_strjoin_free(ft_str_spam("0", flags[WIDTH] - len), num);
	}

	if (flags[WIDTH] > 0 && (int)ft_strlen(num) < flags[WIDTH])
	{
		len = (int)ft_strlen(num);
		num = ft_strjoin_free(ft_str_spam(" ", flags[WIDTH] - len), num);
	}

	if (flags[MINUS])
	{
		int pos = 0;
		int j = 0;
		while (num[j] != '\0')
		{
			if (num[j] != ' ')
			{
				num[pos] = num[j];
				num[j] = ' ';
				pos++;
			}
			j++;
		}
	}

	input = insert_from_to(input, num, start, i);
	return (input);
}



char	*ft_alternative_insert_x(char *input, int start, int i, int d, int *flags)
{
	char *num;
	char zero[3];
	int len;

	zero[0] = '0';
	zero[1] = 'x';
	zero[2] = '\0';
	num = ft_itoa_base(d, "0123456789abcdef");

	if (flags[ZERO] == 1 && flags[PRECISION] == 0)
	{
		len = (int)ft_strlen(num);
		if (flags[PLUS] == 1 || flags[SPACE] == 1 || d < 0)
			len ++;
		num = ft_strjoin_free(ft_str_spam("0", flags[WIDTH] - len - 2), num);
	}

	if (flags[WIDTH] > 0 && (int)ft_strlen(num) < flags[WIDTH] - len - 2)
	{
		len = (int)ft_strlen(num);
		num = ft_strjoin_free(ft_str_spam(" ", flags[WIDTH] - len), num);
	}

	if (d != 0)
		num = ft_strjoin(zero, num);

	if (flags[MINUS])
	{
		int pos = 0;
		int j = 0;
		while (num[j] != '\0')
		{
			if (num[j] != ' ')
			{
				num[pos] = num[j];
				num[j] = ' ';
				pos++;
			}
			j++;
		}
	}

	input = insert_from_to(input, num, start, i);
	return (input);
}

char	*ft_insert_upperx(char *input, int start, int i, int d)
{
	char *num;

	num = ft_itoa_base(d, "0123456789ABCDEF");
	input = insert_from_to(input, num, start, i);
	return (input);
}

char	*ft_alternative_insert_upperx(char *input, int start, int i, int d)
{
	char *num;
	char zero[3];

	zero[0] = '0';
	zero[1] = 'X';
	zero[2] = '\0';
	num = ft_itoa_base(d, "0123456789ABCDEF");
	num = ft_strjoin(zero, num);
	input = insert_from_to(input, num, start, i);
	return (input);
}