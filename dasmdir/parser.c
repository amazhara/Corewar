/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <ikhrypko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 18:27:37 by ocheresh          #+#    #+#             */
/*   Updated: 2019/06/21 19:54:07 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dasm.h"

char	*p_to_code_type_2(char c)
{
	if (c == 'b')
		return ("1011");
	if (c == 'c')
		return ("1100");
	if (c == 'd')
		return ("1101");
	if (c == 'e')
		return ("1110");
	if (c == 'f')
		return ("1111");
	return ("0");
}

char	*p_to_code_type(char c)
{
	if (c == '0')
		return ("0000");
	if (c == '1')
		return ("0001");
	if (c == '2')
		return ("0010");
	if (c == '3')
		return ("0011");
	if (c == '4')
		return ("0100");
	if (c == '5')
		return ("0101");
	if (c == '6')
		return ("0110");
	if (c == '7')
		return ("0111");
	if (c == '8')
		return ("1000");
	if (c == '9')
		return ("1001");
	if (c == 'a')
		return ("1010");
	return (p_to_code_type_2(c));
}

int		parser_to_int_2(char *str)
{
	if (fts_strncmp("1011", str, 4) == 0)
		return (11);
	if (fts_strncmp("1100", str, 4) == 0)
		return (12);
	if (fts_strncmp("1101", str, 4) == 0)
		return (13);
	if (fts_strncmp("1110", str, 4) == 0)
		return (14);
	if (fts_strncmp("1111", str, 4) == 0)
		return (15);
	return (0);
}

int		parser_to_int(char *str)
{
	if (fts_strncmp("0000", str, 4) == 0)
		return (0);
	if (fts_strncmp("0001", str, 4) == 0)
		return (1);
	if (fts_strncmp("0010", str, 4) == 0)
		return (2);
	if (fts_strncmp("0011", str, 4) == 0)
		return (3);
	if (fts_strncmp("0100", str, 4) == 0)
		return (4);
	if (fts_strncmp("0101", str, 4) == 0)
		return (5);
	if (fts_strncmp("0110", str, 4) == 0)
		return (6);
	if (fts_strncmp("0111", str, 4) == 0)
		return (7);
	if (fts_strncmp("1000", str, 4) == 0)
		return (8);
	if (fts_strncmp("1001", str, 4) == 0)
		return (9);
	if (fts_strncmp("1010", str, 4) == 0)
		return (10);
	return (parser_to_int_2(str));
}

char	*fts_itoa_base(long long int n, int base)
{
	long long int	temp;
	char			*res;
	int				size;

	size = 1;
	temp = n;
	while (temp >= (long long int)base && size++)
		temp = temp / base;
	res = (char *)malloc(sizeof(char) * (size + 1));
	res[size] = '\0';
	while (n > 0 && size--)
	{
		temp = n % base;
		if (temp <= 9)
			res[size] = temp + 48;
		else if (temp >= 10 && temp <= 15)
		{
			temp = temp - 10;
			res[size] = temp + 97;
		}
		n = n / base;
	}
	return (res);
}
