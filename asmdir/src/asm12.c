/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm12.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <ikhrypko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 16:44:45 by ikhrypko          #+#    #+#             */
/*   Updated: 2019/06/21 19:15:13 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void				sum_type_of_arg(char *str, int *i, char **res)
{
	if (is_registr(&str[*i]) > 0)
		*res = fts_sjoin(*res, "01", 1);
	if (is_direct(&str[*i]) > 0 || is_direct_label(&str[*i], 0) > 0)
		*res = fts_sjoin(*res, "10", 1);
	if (is_indirect(&str[*i]) > 0)
		*res = fts_sjoin(*res, "11", 1);
	*i += is_registr(&str[*i]) + is_direct(&str[*i]);
	*i += is_indirect(&str[*i]) + is_direct_label(&str[*i], 0);
	*i += is_separator(&str[*i]);
}

void				type_of_arg(char *str, t_asm *file, int i, int k)
{
	int			count_of_arg;
	char		*res;

	res = "";
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	count_of_arg = file->instruct[k][0] - 48;
	if (file->instruct[k][10] == 'y')
	{
		while (count_of_arg != 0)
		{
			sum_type_of_arg(str, &i, &res);
			count_of_arg--;
		}
		res = fts_sjoin(res, "00", 1);
		while (fts_strlen(res) % 8 != 0)
			res = fts_sjoin(res, "00", 1);
		print_code_type_arg(res, file);
	}
}

void				init_size(int *size, char *str, t_asm *file)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[i] && str[i] == DIRECT_CHAR
		&& str[i + 1] && str[i + 1] == LABEL_CHAR)
		i += 2;
	else if (str[i] && str[i] == LABEL_CHAR)
		i++;
	while (file->lab[k].name)
	{
		file->temp = str_to_correct(&str[i]);
		if (fts_strcmp(file->lab[k].name, file->temp) == 0)
			*size = (file->lab[k].size - file->size);
		fts_strdel(&file->temp);
		k++;
	}
}

void				byte_direct(char *str, t_asm *file, int k)
{
	int size;

	size = fts_atoi(&str[1]);
	if (size >= 0)
	{
		if (file->instruct[k][11] - 48 == 2)
			file->tp = cw_invert_endian2(size);
		else
			file->tp = cw_invert_endian(size);
		write(file->fd, &file->tp, (file->instruct[k][11] - 48));
	}
	else
	{
		size = convert(size);
		if (file->instruct[k][11] - 48 == 2)
			file->tp = cw_invert_endian2(size);
		else
			file->tp = cw_invert_endian(size);
		write(file->fd, &file->tp, (file->instruct[k][11] - 48));
	}
}

void				byte_direct_label(char *str, t_asm *file, int k)
{
	int size;

	init_size(&size, str, file);
	if (size >= 0)
	{
		if (file->instruct[k][11] - 48 == 2)
			file->tp = cw_invert_endian2(size);
		else
			file->tp = cw_invert_endian(size);
		write(file->fd, &file->tp, (file->instruct[k][11] - 48));
	}
	else
	{
		size = convert(size);
		size = cw_invert_endian2(size);
		write(file->fd, &size, (file->instruct[k][11] - 48));
	}
}
