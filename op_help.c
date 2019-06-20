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

//int		operation_type(t_op_inf *inf, int ind, int args_num, int dir_size)
//{
//	int 			arg_type;
//	unsigned char	*pos;
//
//	pos = inf->carr->pos + 2; //after flags
//
//	dir_size = (dir_size ? 2 : 4); // 4
//
//	pos += (ind ? dir_size : 0);
//
//	arg_type = byte_option_arg(inf->arg_type[ind]);
//
//	ft_printf("type %d\n", arg_type);
//	if (arg_type == 1)
//		return (inf->carr->regs[args_num]);
//	if (arg_type == 2)
//		return (byte_get(inf->carr->pos + args_num % IDX_MOD, 4));
//	if (arg_type == 4)
//	{
//		ft_printf("zashlo %d\n", byte_get(pos, dir_size));
//		return (byte_get(pos, dir_size));
//	}
//	return (0);
//}

int		operation_type_ld(t_op_inf *inf, int ind, int args_num, int dir_size)
{
	unsigned char	*pos;
	int 			type_curr;
	int 			type_old;

	pos = inf->pos_read;
	if (!ind)
		type_curr = byte_option_arg(inf->arg_type[0]);
	else
	{
		type_curr = byte_option_arg(inf->arg_type[ind]);
		type_old =  memory_option_arg(inf->arg_type[ind - 1]);
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
	int 			type_curr;
	int 			type_old;

	pos = inf->pos_read;
	if (!ind)
		type_curr = byte_option_arg(inf->arg_type[0]);
	else
	{
		type_curr = byte_option_arg(inf->arg_type[ind]);
		type_old =  byte_option_arg(inf->arg_type[ind - 1]);
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

void	test(t_op_inf *inf)
{
	ft_printf("Ya test");
	ft_printf("\nA mozhet ty test\nMMMMM?\n");
}
