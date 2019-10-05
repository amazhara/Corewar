/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carrier.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazhara <amazhara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 15:20:41 by amazhara          #+#    #+#             */
/*   Updated: 2019/06/20 17:07:49 by amazhara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

void		carrier_current_code(t_carrier *carr)
{
	if (g_mem - carr->pos < MEM_SIZE)
		carr->code_curr = *carr->pos;
	if (carr->code_curr < 17 && carr->code_curr > 0)
		carr->cycles_to_exec = g_op_tab[carr->code_curr].cycles_to_exec;
	else
		carr->cycles_to_exec = 0;
}

void		carriers_new_code(void)
{
	ssize_t		i;

	i = -1;
	while (++i < g_carriers->len)
	{
		if (g_carriers->carr[i]->dead)
			continue;
		if (g_carriers->carr[i]->cycles_to_exec <= 0)
			carrier_current_code(g_carriers->carr[i]);
	}
}

t_carrier	*carrier_place(int champ_id, unsigned char *pos)
{
	t_carrier	*carr;

	carr = ft_memalloc(sizeof(t_carrier));
	carr->id = g_carr_num++;
	carr->champ_id = -champ_id;
	carr->pos = pos;
	carrier_current_code(carr);
	return (carr);
}
