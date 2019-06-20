/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazhara <amazhara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 15:20:41 by amazhara          #+#    #+#             */
/*   Updated: 2019/06/20 16:46:34 by amazhara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

void	take_op_arg_types(t_op_inf *inf, t_carrier *carr)
{
	t_op				*op;
	unsigned char		types_byte;

	inf->is_arg = g_op_tab[carr->code_curr].args_type;
	op = &g_op_tab[carr->code_curr];
	if (inf->is_arg)
	{
		types_byte = byte_get(carr->pos + 1, 1);
		inf->arg_type[0] = (types_byte & 0b11000000u) >> 6u;
		inf->arg_type[1] = (types_byte & 0b00110000u) >> 4u;
		inf->arg_type[2] = (types_byte & 0b00001100u) >> 2u;
		if ((!inf->arg_type[0] && !inf->arg_type[1] && !inf->arg_type[2]))
			inf->error = 1;
		if ((inf->arg_type[1] && !op->argv[1]) ||
			(inf->arg_type[2] && !op->argv[2]))
			inf->error = 1;
		if (types_byte & 0b00000011u)
			inf->error = 1;
		inf->skip++;
	}
	else
		inf->arg_type[0] = 2;
}

void	check_args_regs(t_op_inf *inf, t_op *op, int *skip)
{
	int		i;
	int		reg_check;

	i = -1;
	while (++i < op->argc)
	{
		if (!inf->arg_type[i])
			continue;
		if ((inf->arg_type[i] | op->argv[i]) != op->argv[i])
			inf->error = 1;
		else if ((inf->arg_type[i] & 0b00000011u) == 1)
		{
			reg_check = byte_get(inf->pos_read + *skip, 1);
			if (reg_check > REG_NUMBER || reg_check <= 0)
				inf->reg_error = 1;
		}
		*skip += (inf->arg_type[i] == 1 ? 1 : 2);
		if (!op->dir_size && inf->arg_type[i] == 2)
			*skip += 2;
	}
}

void	take_skip_size(t_op_inf *inf, t_carrier *carr)
{
	t_op	*op;
	int		skip;

	skip = 0;
	op = &g_op_tab[carr->code_curr];
	inf->pos_read = carr->pos + 1;
	if (inf->is_arg)
	{
		inf->pos_read++;
		check_args_regs(inf, op, &skip);
	}
	else
		skip = op->dir_size ? 2 : 4;
	inf->skip += skip;
}
