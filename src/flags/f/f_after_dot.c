/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_after_dot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 17:50:27 by kcharla           #+#    #+#             */
/*   Updated: 2019/12/23 17:50:29 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*f_after_dot_prec(int *flags, char *after_dot)
{
	int len = (int) ft_strlen(after_dot);
	if (flags[PRECISION] >= len)
		after_dot = ft_strjoin_free(after_dot,
									ft_str_spam("0", flags[PRECISION] - len + 3));
	//ft_putendl("lmao not prec");

	int b = flags[PRECISION];
	//printf("\n\na  \"%s\"\n", after_dot);
	if (after_dot[b] == '4' && len > flags[PRECISION])
	{
		int i = 1;
		while (b + i < len && after_dot[b + i] == '9')
			i++;
		if (after_dot[b + i] >= '5' && after_dot[b + i] <= '9' && i > 8)
			after_dot[b - 1]++;
	}
	//printf("a\"%s\"\n", after_dot);
	//ft_putnbr(b);
	//printf("b is \"%c%c[%c]%c\"\n", after_dot[b - 2], after_dot[b - 1], after_dot[b], after_dot[b + 1]);
	//b++;
	//printf("b is %d", (int) b);
	//printf("\n\nspam is \"%s\"\n", ft_str_spam("0.", 10));
	//printf("adot is \"%s\"\n", after_dot);
	if (after_dot[b] >= '5' && len > flags[PRECISION])
	{
		//b--;
		after_dot[b - 1]++;
	}
	b = b - (b >= 1);
	//printf("adot is \"%s\"\n\n", after_dot);
	//printf("b is \"%c%c[%c]%c\"\n", after_dot[b - 2], after_dot[b - 1], after_dot[b], after_dot[b + 1]);

//	if (after_dot[b] >= '5')
//	{
//		after_dot[b - 1]++;
//	}
//	b--;
	//printf("b is \"%c%c[%c]%c\"\n", after_dot[b - 2], after_dot[b - 1], after_dot[b], after_dot[b + 1]);
	flags[SPECIAL] = F_ROUND_NO;

	while (after_dot[b] > '9')
	{
//		ft_putnbr(b);
//		ft_putendl("");
		after_dot[b] = '0';
		if(b > 0)
		{
			after_dot[--b]++;
		}
		else
		{
			flags[SPECIAL] = F_ROUND_YES;
			break ;
		}
	}

	b = 1;
	while (b < flags[PRECISION])
	{
		if (after_dot[b] > '9')
			after_dot[b] = '0';
		b++;
	}

	b = flags[PRECISION];
	if (b == 0)
		b = 3;

	after_dot[b] = '\0';

	return (after_dot);
}

char	*f_after_dot(long double num)
{
	int		i;
	char	b;
	char	a[5000];

	ft_bzero(a, 5000);
	i = 0;
	if (num == 0)
		return (ft_strdup(""));
	while (num > 0 && i < 5000)
	{
		num = num * 10;
		b = (char) num;
		num -= b;
		a[i] = b + '0';
		i++;
	}
	return (ft_strdup(a));
}