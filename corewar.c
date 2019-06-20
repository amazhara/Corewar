#include <stdio.h>
#include "virtual_machine.h"

int 		g_delete_count;
int			g_check_time;

void	end_game()
{
	ft_printf("Contestant %d, \"%s\", has won !\n", g_last_live->id, g_last_live->name);
	exit(0);
}

void	check()
{
	ssize_t i;

	i = g_carriers->len;
	g_checks_count++;
	while (i--)
		if (g_cycles - g_carriers->carr[i]->cycles_id >= g_cycles_die || g_cycles_die <= 0)
		{
			if (g_carriers->carr[i]->dead)
				continue;
			g_carriers->carr[i]->dead = 1;
			show_deaths(g_carriers->carr[i]);
			g_delete_count++;
		}
	if (g_delete_count == g_carriers->len || g_cycles_die <= 0)
		end_game();
	if (g_lives_count >= NBR_LIVE || MAX_CHECKS == g_checks_count)
	{
		g_cycles_die -= CYCLE_DELTA;
		g_checks_count = 0;
		if (g_vl & 2u)
			ft_printf("Cycle to die is now %d\n", g_cycles_die);
	}
	g_lives_count = 0;
	g_check_time = 0;
}

void	code_execute(t_carrier *carr)
{
	t_op_inf	inf;

	ft_bzero(&inf, sizeof(t_op_inf));
	if (carr->code_curr > 0 && carr->code_curr <= 16)
	{
		take_op_arg_types(&inf, carr);
		take_skip_size(&inf, carr);
		inf.carr = carr;
		if (!inf.error && !inf.reg_error)
			g_op_tab[carr->code_curr].exec(&inf);
		if (!inf.is_zjmp)
			show_pc_movements(inf.skip + 1, inf.carr->pos - g_mem);
		carr->pos = g_mem + mem_pos(carr->pos - g_mem + inf.skip);
	}
	carr->pos += 1;
	if (carr->pos - g_mem >= MEM_SIZE)
		carr->pos = g_mem;
	if (inf.is_zjmp)
		carr->pos = inf.zjmp_pos;
}

void	main_cycle()
{
	ssize_t i;

	g_cycles_die = CYCLE_TO_DIE;
	dump();
	while ( 1 )
	{
		i = g_carriers->len;
		g_cycles++;
		g_check_time++;
		show_cycles();
		while (i--)
		{
			if (g_carriers->carr[i]->dead)
				continue;
			if (g_carriers->carr[i]->cycles_to_exec == 0)
				carrier_current_code(g_carriers->carr[i]);
			if (g_carriers->carr[i]->cycles_to_exec > 0)
				g_carriers->carr[i]->cycles_to_exec--;
			if (g_carriers->carr[i]->cycles_to_exec == 0)
				code_execute(g_carriers->carr[i]);
		}
//		ft_printf("num ---> %d\n", g_carr_num);
		dump();
		if ((g_check_time == g_cycles_die) || g_cycles_die <= 0)
			check();
	}
}
