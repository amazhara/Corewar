/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazhara <amazhara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 15:48:35 by amazhara          #+#    #+#             */
/*   Updated: 2019/06/20 16:28:45 by amazhara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

int		memory_option_arg(t_arg_type arg_type)
{
	if (arg_type == 1)
		return (1);
	return (2);
}

int		byte_option_arg(t_arg_type arg_type)
{
	if (arg_type == 1)
		return (1);
	if (arg_type == 2)
		return (4);
	if (arg_type == 3)
		return (2);
	return (0);
}

int		operation_type_ld(t_op_inf *inf, int ind, int args_num, int dir_size)
{
	unsigned char	*pos;
	int				type_curr;
	int				type_old;

	pos = inf->pos_read;
	if (!ind)
		type_curr = byte_option_arg(inf->arg_type[0]);
	else
	{
		type_curr = byte_option_arg(inf->arg_type[ind]);
		type_old = memory_option_arg(inf->arg_type[ind - 1]);
		pos += type_old;
	}
	if (type_curr == 1)
		return (inf->carr->regs[args_num]);
	if (type_curr == 2)
		return (byte_get(inf->carr->pos + args_num % IDX_MOD, 4));
	if (type_curr == 4)
		return (byte_get(pos, dir_size));
	return (0);
}

int		operation_type(t_op_inf *inf, int ind, int args_num, int dir_size)
{
	unsigned char	*pos;
	int				type_curr;
	int				type_old;

	pos = inf->pos_read;
	if (!ind)
		type_curr = byte_option_arg(inf->arg_type[0]);
	else
	{
		type_curr = byte_option_arg(inf->arg_type[ind]);
		type_old = byte_option_arg(inf->arg_type[ind - 1]);
		pos += type_old;
	}
	if (type_curr == 1)
		return (inf->carr->regs[args_num]);
	if (type_curr == 2)
		return (byte_get(inf->carr->pos + args_num % IDX_MOD, 4));
	if (type_curr == 4)
		return (byte_get(pos, dir_size));
	return (0);
}
