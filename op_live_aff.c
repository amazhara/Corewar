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
	if (data <= -1 && data >= -g_champs_count)
	{
		g_last_live = g_champs[-data - 1];
		show_lives(-data);
	}
}

void	aff(t_op_inf *inf)
{
	int 	reg;

	reg = inf->carr->regs[byte_get(inf->pos_read, 1)];
	if (g_a) // Need to parse
		ft_printf("%c", (char)reg);
}
