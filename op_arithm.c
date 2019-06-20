/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_arithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazhara <amazhara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 15:20:41 by amazhara          #+#    #+#             */
/*   Updated: 2019/06/20 16:27:52 by amazhara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

void	add(t_op_inf *inf)
{
	int				reg;
	t_carrier		*carr;

	carr = inf->carr;
	reg = byte_get(inf->pos_read + 2, 1);
	carr->regs[reg] = carr->regs[byte_get(inf->pos_read, 1)]
					+ carr->regs[byte_get(inf->pos_read + 1, 1)];
	if (g_vl & (uint)s_operations)
		ft_printf("P %4d | add r%d r%d r%d\n", inf->carr->id,
			byte_get(inf->pos_read, 1), byte_get(inf->pos_read + 1, 1), reg);
	carr->flag = 0;
	if (!carr->regs[reg])
		carr->flag = 1;
}

void	sub(t_op_inf *inf)
{
	int				reg;
	t_carrier		*carr;

	carr = inf->carr;
	reg = byte_get(inf->pos_read + 2, 1);
	carr->regs[reg] = carr->regs[byte_get(inf->pos_read, 1)]
					- carr->regs[byte_get(inf->pos_read + 1, 1)];
	if (g_vl & (uint)s_operations)
		ft_printf("P %4d | sub r%d r%d r%d\n", inf->carr->id,
			byte_get(inf->pos_read, 1), byte_get(inf->pos_read + 1, 1), reg);
	carr->flag = 0;
	if (!carr->regs[reg])
		carr->flag = 1;
}

void	byte_and(t_op_inf *inf)
{
	int				args[3];
	int				args_size[2];
	int				args_num[2];

	args_size[0] = byte_option_arg(inf->arg_type[0]);
	args_size[1] = byte_option_arg(inf->arg_type[1]);
	args_num[0] = byte_get(inf->pos_read, args_size[0]);
	args_num[1] = byte_get(inf->pos_read + args_size[0], args_size[1]);
	args[2] = byte_get(inf->pos_read + args_size[0]
				+ args_size[1], byte_option_arg(inf->arg_type[2]));
	args[0] = operation_type(inf, 0, args_num[0], 4);
	args[1] = operation_type(inf, 1, args_num[1], 4);
	inf->carr->regs[args[2]] = args[0] & args[1];
	inf->carr->flag = 0;
	if (g_vl & (uint)s_operations)
		ft_printf("P %4d | and %d %d r%d\n",
			inf->carr->id, args[0], args[1], args[2]);
	if (!inf->carr->regs[args[2]])
		inf->carr->flag = 1;
}

void	byte_or(t_op_inf *inf)
{
	int				args[3];
	int				args_size[2];
	int				args_num[2];

	args_size[0] = byte_option_arg(inf->arg_type[0]);
	args_size[1] = byte_option_arg(inf->arg_type[1]);
	args_num[0] = byte_get(inf->pos_read, args_size[0]);
	args_num[1] = byte_get(inf->pos_read + args_size[0], args_size[1]);
	args[2] = byte_get(inf->pos_read + args_size[0]
				+ args_size[1], byte_option_arg(inf->arg_type[2]));
	args[0] = operation_type(inf, 0, args_num[0], 4);
	args[1] = operation_type(inf, 1, args_num[1], 4);
	inf->carr->regs[args[2]] = args[0] | args[1];
	inf->carr->flag = 0;
	if (g_vl & (uint)s_operations)
		ft_printf("P %4d | or %d %d r%d\n",
			inf->carr->id, args[0], args[1], args[2]);
	if (!inf->carr->regs[args[2]])
		inf->carr->flag = 1;
}

void	byte_xor(t_op_inf *inf)
{
	int				args[3];
	int				args_size[2];
	int				args_num[2];

	args_size[0] = byte_option_arg(inf->arg_type[0]);
	args_size[1] = byte_option_arg(inf->arg_type[1]);
	args_num[0] = byte_get(inf->pos_read, args_size[0]);
	args_num[1] = byte_get(inf->pos_read + args_size[0], args_size[1]);
	args[2] = byte_get(inf->pos_read + args_size[0]
				+ args_size[1], byte_option_arg(inf->arg_type[2]));
	args[0] = operation_type(inf, 0, args_num[0], 4);
	args[1] = operation_type(inf, 1, args_num[1], 4);
	inf->carr->regs[args[2]] = args[0] ^ args[1];
	inf->carr->flag = 0;
	if (g_vl & (uint)s_operations)
		ft_printf("P %4d | xor %d %d r%d\n",
			inf->carr->id, args[0], args[1], args[2]);
	if (!inf->carr->regs[args[2]])
		inf->carr->flag = 1;
}
