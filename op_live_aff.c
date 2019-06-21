/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live_aff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazhara <amazhara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 15:20:41 by amazhara          #+#    #+#             */
/*   Updated: 2019/06/20 21:15:24 by amazhara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

void	live(t_op_inf *inf)
{
	int			data;
	t_carrier	*carr;

	carr = inf->carr;
	data = byte_get(inf->pos_read, 4);
	carr->cycles_id = g_cycles;
	g_lives_count++;
	if (g_vl & s_operations)
		ft_printf("P %4d | live %d\n", inf->carr->id, data);
	if (g_vis)
	{
		g_b[mem_pos(inf->carr->pos - g_mem)].live = 50;
		g_b[mem_pos(inf->carr->pos - g_mem)].color = -inf->carr->champ_id;
	}
	if (data <= -1 && data >= -g_champs_count)
	{
		g_last_live = g_champs[-data - 1];
		show_lives(-data);
	}
}

void	aff(t_op_inf *inf)
{
	int		reg;

	reg = inf->carr->regs[byte_get(inf->pos_read, 1)];
	if (g_a)
		ft_printf("Aff: %c\n", reg);
}
