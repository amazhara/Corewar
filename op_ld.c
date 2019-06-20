#include "virtual_machine.h"
#include "stdio.h"

void	ld(t_op_inf *inf)
{
	int				move_size;
	unsigned int	num;
	unsigned int	reg_id;

	move_size = (inf->arg_type[0] == 2 ? 4 : 2);
	reg_id = byte_get(inf->pos_read + move_size, 1);
	num = byte_get(inf->pos_read, move_size);
	if (move_size == 2)
		num = byte_get(inf->carr->pos + num % IDX_MOD, 4);
	inf->carr->regs[reg_id] = num;
	if (!inf->carr->regs[reg_id])
		inf->carr->flag = 1;
	else
		inf->carr->flag = 0;
	if (g_vl & (uint)s_operations)
		ft_printf("P %4d | ld %d r%d\n", inf->carr->id, num, reg_id);
}

void	ldi(t_op_inf *inf)
{
	int				args[3];
	int				args_size[2];
	int				args_num[2];

	args_size[0] = memory_option_arg(inf->arg_type[0]);
	args_size[1] = memory_option_arg(inf->arg_type[1]);
	args_num[0] = byte_get(inf->pos_read, args_size[0]);
	args_num[1] = byte_get(inf->pos_read + args_size[0], args_size[1]);
	args[2] = byte_get(inf->pos_read + args_size[0] + args_size[1], 1);
	args[0] = operation_type_ld(inf, 0, args_num[0], 2);
	args[1] = operation_type_ld(inf, 1, args_num[1], 2);
	if (g_vl & (uint)s_operations)
	{
		ft_printf("P %4d | ldi %d %d r%d\n", inf->carr->id, args[0], args[1], args[2]);
		ft_printf("       | -> load from %d + %d = %d (with pc and mod %d)\n", args[0], args[1], args[0] + args[1], inf->carr->pos - g_mem + ((args[0] + args[1]) % IDX_MOD));
	}
	inf->carr->regs[args[2]] = byte_get(inf->carr->pos + (args[0] + args[1]) % IDX_MOD, 4);
}

void	lld(t_op_inf *inf)
{
	int				move_size;
	unsigned int	num;
	unsigned int	reg_id;

	move_size = (inf->arg_type[0] == 2 ? 4 : 2);
	reg_id = byte_get(inf->pos_read + move_size, 1);
	num = byte_get(inf->pos_read, move_size);
	if (move_size == 2)
		num = byte_get(inf->carr->pos + num, 4);
	inf->carr->regs[reg_id] = num;
	if (!inf->carr->regs[reg_id])
		inf->carr->flag = 1;
	else
		inf->carr->flag = 0;
	if (g_vl & (uint)s_operations)
		ft_printf("P %4d | lld %d r%d\n", inf->carr->id, num, reg_id);
}

void	lldi(t_op_inf *inf)
{
	int				args[3];
	int				args_size[2];
	int				args_num[2];

	args_size[0] = memory_option_arg(inf->arg_type[0]);
	args_size[1] = memory_option_arg(inf->arg_type[1]);
	args_num[0] = byte_get(inf->pos_read, args_size[0]);
	args_num[1] = byte_get(inf->pos_read + args_size[0], args_size[1]);
	args[2] = byte_get(inf->pos_read + args_size[0] + args_size[1], 1);
	args[0] = operation_type_ld(inf, 0, args_num[0], 2);
	args[1] = operation_type_ld(inf, 1, args_num[1], 2);
	if (g_vl & (uint)s_operations)
	{
		ft_printf("P %4d | lldi %d %d r%d\n", inf->carr->id, args[0], args[1], args[2]);
		ft_printf("       | -> load from %d + %d = %d (with pc and mod %d)\n", args[0], args[1], args[0] + args[1], inf->carr->pos - g_mem + (args[0] + args[1]));
	}
	inf->carr->regs[args[2]] = byte_get(inf->carr->pos + (args[0] + args[1]), 4);
}