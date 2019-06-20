/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbosity_levels.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazhara <amazhara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 15:21:28 by amazhara          #+#    #+#             */
/*   Updated: 2019/06/20 17:11:02 by amazhara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

void	show_lives(int id)
{
	if (!(g_vl & s_lives))
		return ;
	ft_printf("Player %d (%s) is said to be alive\n", id,
		g_champs[id - 1]->name);
}

void	show_cycles(void)
{
	if (!(g_vl & s_cycles))
		return ;
	ft_printf("It is now cycle %u\n", g_cycles);
}

void	show_deaths(t_carrier *carr)
{
	if (!(g_vl & s_deaths))
		return ;
	ft_printf("Process %u hasn't lived for %u cycles (CTD %d)\n",
		carr->id, g_cycles - carr->cycles_id, g_cycles_die);
}

void	show_pc_movements(int size, int begin)
{
	int i;

	i = -1;
	if (!(g_vl & s_pc_movements))
		return ;
	ft_printf("ADV %u (0x%.4x -> 0x%.4x) ", size, begin, begin + size);
	begin = jump_pos(begin);
	while (++i < size)
	{
		if (begin + i == MEM_SIZE)
			begin = -i;
		ft_printf("%.2x ", g_mem[begin + i]);
	}
	ft_printf("\n");
}
