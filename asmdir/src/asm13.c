/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm13.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <ikhrypko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 16:45:07 by ikhrypko          #+#    #+#             */
/*   Updated: 2019/06/21 19:12:22 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void				byte_indirect_lab(char *str, t_asm *file)
{
	int size;

	init_size(&size, str, file);
	if (size >= 0)
	{
		file->tp = cw_invert_endian2(size);
		write(file->fd, &file->tp, T_IND);
	}
	else
	{
		size = convert(size);
		size = cw_invert_endian2(size);
		write(file->fd, &size, 2);
	}
}

void				byte_indirect(char *str, t_asm *file)
{
	int size;

	size = fts_atoi(str);
	if (size >= 0)
	{
		file->tp = cw_invert_endian2(size);
		write(file->fd, &file->tp, 2);
	}
	else
	{
		size = convert(size);
		size = cw_invert_endian2(size);
		write(file->fd, &size, 2);
	}
}

void				byte_regist(char *str, t_asm *file)
{
	file->tp = fts_atoi(&str[1]);
	write(file->fd, &file->tp, 1);
}

void				parse_args_byte(char *str, int k, t_asm *file)
{
	if (is_registr(str) > 0)
		byte_regist(str, file);
	if (is_direct(str) > 0)
		byte_direct(str, file, k);
	if (is_direct_label(str, 0) > 0)
		byte_direct_label(str, file, k);
	if (is_indirect(str) > 0)
	{
		if (is_indirect_label(str) > 0)
			byte_indirect_lab(str, file);
		else
			byte_indirect(str, file);
	}
}

void				args_to_byte(char *str, int k, t_asm *file, int i)
{
	int count_of_arg;

	count_of_arg = file->instruct[k][0] - 48;
	while (count_of_arg != 0)
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		parse_args_byte(&str[i], k, file);
		i += is_registr(&str[i]) + is_direct(&str[i]);
		i += is_indirect(&str[i]) + is_direct_label(&str[i], 0);
		i += is_separator(&str[i]);
		count_of_arg--;
	}
}
