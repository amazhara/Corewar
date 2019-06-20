#include "virtual_machine.h"

int		operation_type_sti(t_op_inf *inf, int ind, int args_num)
{
	int 			arg_type;
	unsigned char	*pos;

	pos = inf->carr->pos + 3;
	pos += (ind ? 2 : 0);
	arg_type = byte_option_arg(inf->arg_type[ind + 1]);
	if (arg_type == 1)
		return (inf->carr->regs[args_num]);
	if (arg_type == 2)
		return (byte_get(inf->carr->pos + args_num % IDX_MOD, 4));
	if (arg_type == 4)
		return (byte_get(pos, 2));
	return (0);
}

void	st(t_op_inf *inf)
{
	int				move_size;
	int 			byte;
	int				reg_id;
	short			arg_2;

	move_size = (inf->arg_type[1] == 1 ? 1 : 2);
	reg_id = byte_get(inf->pos_read, 1);
	arg_2 = byte_get(inf->pos_read + 1, move_size);
	if (move_size == 1)
		inf->carr->regs[arg_2] = inf->carr->regs[reg_id];
	else
	{
		byte = byte_swap32(inf->carr->regs[reg_id]);
		mem_add(inf->carr->pos, arg_2 % IDX_MOD, &byte, 4);
	}
	if (g_vl & (uint)s_operations)
		ft_printf("P %4d | st r%d %hd\n", inf->carr->id, reg_id, arg_2);
}

void	sti(t_op_inf *inf)
{
	int				args[3];
	int				args_size[2];
	int				args_num[2];
	int				byte;

	args_size[0] = memory_option_arg(inf->arg_type[1]);
	args_size[1] = memory_option_arg(inf->arg_type[2]);
	args_num[0] = byte_get(inf->pos_read + 1, args_size[0]);
	args_num[1] = byte_get(inf->pos_read + args_size[0] + 1, args_size[1]);
	args[2] = byte_get(inf->pos_read, 1);
	args[0] = operation_type_sti(inf, 0, args_num[0]);
	args[1] = operation_type_sti(inf, 1, args_num[1]);
	if (g_vl & (uint)s_operations)
	{
		ft_printf("P %4d | sti r%d %d %d\n", inf->carr->id, args[2], args[0], args[1]);
		ft_printf("       | -> store to %d + %d = %d (with pc and mod %d)\n", args[0], args[1], args[0] + args[1], inf->carr->pos - g_mem + ((args[0] + args[1]) % IDX_MOD));
	}
	byte = byte_swap32(inf->carr->regs[args[2]]);
	mem_add(inf->carr->pos, (args[0] + args[1]) % IDX_MOD, &byte, 4);
}
