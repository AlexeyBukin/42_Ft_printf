/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelina <lmelina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 15:23:49 by lmelina           #+#    #+#             */
/*   Updated: 2019/12/20 19:45:52 by lmelina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_insert_s(va_list arg, int *flags)
{
	int len = 0;
	char *insert;
	char *res;

	insert = va_arg(arg, char*);
	if (insert != NULL)
		insert = ft_strdup(insert);
//	printf("0 = \'%s\'\n", insert);

	if (insert == NULL)
	{
		if (flags[PRECISION] == -1)
		{
			res = ft_strdup("");
		}
		else
			res = ft_strdup("(null)");
		if (flags[PRECISION] < 6 && flags[PRECISION] != 0)
			res[flags[PRECISION]] = '\0';
	}
	else
	{
//		printf("1 = \'%s\'\n", insert);
		len = (int) ft_strlen(insert);
		if (flags[PRECISION] < len && flags[PRECISION] != 0)
			insert[flags[PRECISION]] = '\0';
		if (flags[PRECISION] == -1)
		{
			res = ft_strdup("");
		}
		else
			res = ft_strdup(insert);
//		printf(" = \'%s\'\n", res);
//		if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
//			return (NULL);
//		if (flags[PRECISION])
//			res = ft_strncpy(res, insert, flags[PRECISION]);
//		else
//			res = ft_strcpy(res, insert);
	}

//	printf("1 = \'%s\'\n", res);

	//ft_putendl(res);

//	printf("1 = \'%s\'\n", res);

//	len = (int)ft_strlen(res);
//	if (flags[PRECISION] > len)
//		res = ft_strjoin_free(ft_str_spam("0", flags[PRECISION] - ft_strlen(res)), res);

	if (flags[ZERO] == 1 && flags[PRECISION] == 0 && flags[MINUS] == 0)
	{
		len = (int)ft_strlen(res);
		if (flags[PLUS] == 1 || flags[SPACE] == 1)
			len ++;
		if (len < flags[WIDTH])
			res = ft_strjoin_free(ft_str_spam("0", flags[WIDTH] - len), res);
	}

//	printf("2 = \'%s\'\n", res);


	if (flags[WIDTH] > 0 && (len = (int)ft_strlen(res)) < flags[WIDTH])
	{
		if (flags[MINUS] == 1)
		{
			res = ft_strjoin_free(res, ft_str_spam(" ", flags[WIDTH] - len));
		}
		else
		{
			res = ft_strjoin_free(ft_str_spam(" ", flags[WIDTH] - len), res);
		}
	}

//	printf("3 = \'%s\'\n", res);

	return (res);
}