/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_jump_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazhara <amazhara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 15:20:41 by amazhara          #+#    #+#             */
/*   Updated: 2019/06/20 16:29:15 by amazhara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

int		jump_pos(int pos)
{
	if (pos < 0)
		pos += MEM_SIZE;
	pos %= MEM_SIZE;
	return (pos);
}

void	zjmp(t_op_inf *inf)
{
	t_carrier	*carry;
	int			arg;

	carry = inf->carr;
	arg = byte_get(carry->pos + 1, 2);
	if (carry->flag)
	{
		inf->is_zjmp = 1;
		inf->zjmp_pos = g_mem + jump_pos(carry->pos - g_mem + arg % IDX_MOD);
	}
	if (g_vl & (uint)s_operations)
	{
		ft_printf("P %4d | zjmp %d ", inf->carr->id, arg);
		ft_printf(carry->flag ? "OK\n" : "FAILED\n");
	}
}

void	carrier_fork(t_op_inf *inf)
{
	int			address;
	t_carrier	*carr;

	address = byte_get(inf->pos_read, 2);
	carr = ft_memalloc(sizeof(t_carrier));
	ft_memcpy(carr, inf->carr, sizeof(t_carrier));
	carr->id = g_carr_num++;
	carr->pos = g_mem + jump_pos(carr->pos - g_mem + (address % IDX_MOD));
	carr->cycles_to_exec = 0;
	if (g_vl & s_operations)
		ft_printf("P %4d | fork %d (%d)\n", inf->carr->id, address,
			jump_pos(inf->carr->pos - g_mem + (address % IDX_MOD)));
	array_push(g_carriers, carr);
}

void	carrier_lfork(t_op_inf *inf)
{
	int			address;
	t_carrier	*carr;

	address = byte_get(inf->pos_read, 2);
	carr = ft_memalloc(sizeof(t_carrier));
	ft_memcpy(carr, inf->carr, sizeof(t_carrier));
	carr->id = g_carr_num++;
	carr->pos = g_mem + jump_pos(carr->pos - g_mem + address);
	carr->cycles_to_exec = 0;
	if (g_vl & s_operations)
		ft_printf("P %4d | lfork %d (%d)\n",
			inf->carr->id, address, inf->carr->pos - g_mem + address);
	array_push(g_carriers, carr);
}
