/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm11.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <ikhrypko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 16:44:30 by ikhrypko          #+#    #+#             */
/*   Updated: 2019/06/21 16:50:37 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char				*parser_to_code_type(char *str)
{
	if (fts_strncmp("0000", str, 4) == 0)
		return ("0");
	if (fts_strncmp("0001", str, 4) == 0)
		return ("1");
	if (fts_strncmp("0010", str, 4) == 0)
		return ("2");
	if (fts_strncmp("0011", str, 4) == 0)
		return ("3");
	if (fts_strncmp("0100", str, 4) == 0)
		return ("4");
	if (fts_strncmp("0101", str, 4) == 0)
		return ("5");
	if (fts_strncmp("0110", str, 4) == 0)
		return ("6");
	if (fts_strncmp("0111", str, 4) == 0)
		return ("7");
	if (fts_strncmp("1000", str, 4) == 0)
		return ("8");
	if (fts_strncmp("1001", str, 4) == 0)
		return ("9");
	if (fts_strncmp("1010", str, 4) == 0)
		return ("a");
	return (parser_to_code_type_2(str));
}

int					cw_invert_endian(int x)
{
	x = ((x >> 24) & 0xff) | ((x >> 8) & 0xff00) | ((x << 8) & 0xff0000) |
	((x << 24) & 0xff000000);
	return (x);
}

int					cw_invert_endian2(int x)
{
	x = ((x >> 8) & 0xff) | ((x << 8) & 0xff00);
	return (x);
}

int					convert(int a)
{
	if (a < 0)
		a = ~(-a) + 1;
	return (a);
}

void				print_code_type_arg(char *str, t_asm *file)
{
	int t;
	int k;
	int r;

	t = fts_strlen(str) / 4;
	k = 0;
	r = 0;
	file->tp = 0;
	while (t != 0)
	{
		file->temp = parser_to_code_type(&str[k]);
		if (file->temp[0] >= 48 && file->temp[0] <= 57)
			file->tp = file->temp[0] - 48;
		else
			file->tp = file->temp[0] - 'a' + 10;
		if (t == 2)
			r += file->tp * 16;
		else
			r += file->tp;
		t--;
		k += 4;
	}
	write(file->fd, &r, 1);
	fts_strdel(&str);
}
