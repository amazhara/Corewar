/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <ikhrypko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 16:56:53 by ikhrypko          #+#    #+#             */
/*   Updated: 2019/06/21 20:42:12 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

int		get_color(int i)
{
	if (g_b[i].bold && g_b[i].color)
	{
		g_b[i].bold--;
		return (COLOR_PAIR(g_b[i].color) | A_BOLD);
	}
	if (g_b[i].live && g_b[i].color)
	{
		g_b[i].live--;
		return (COLOR_PAIR(g_b[i].color + 8) | A_BOLD);
	}
	return (COLOR_PAIR(g_b[i].color));
}

void	bold_color(unsigned char *carr_pos, int pos, int c, int size)
{
	int i;
	int p;
	int j;

	i = -1;
	p = carr_pos - g_mem;
	j = p + pos;
	if (j < 0)
		j = MEM_SIZE + j;
	while (++i < size)
	{
		j = mem_pos(j);
		g_b[j].color = c;
		g_b[j].bold = 50;
		j++;
	}
}

void	primt_map(void)
{
	int i;
	int x;

	i = -1;
	while (++i < MEM_SIZE)
	{
		x = get_color(i);
		wattron(g_wis.win, x);
		mvwprintw(g_wis.win, IDENT + i / 64,
			IDENT + (i % 64) * 3, "%.2x", g_mem[i]);
		wattroff(g_wis.win, x);
	}
	colors_default();
}

void	ccycle_v(void)
{
	ssize_t	i;

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
	init_carr();
	wrefresh(g_wis.win);
	primt_map();
	if ((g_check_time == g_cycles_die) || g_cycles_die <= 0)
		check();
	usleep(7000);
}

void	main_cycle_v(void)
{
	g_cycles_die = CYCLE_TO_DIE;
	prep();
	init_carr();
	info();
	primt_map();
	while ((g_wis.button = getch()) != ESC)
	{
		wrefresh(g_wis.win);
		buttons();
		info();
		wrefresh(g_wis.win);
		if (g_wis.run)
			ccycle_v();
	}
	endwin();
}
