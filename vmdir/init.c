/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <ikhrypko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 16:55:11 by ikhrypko          #+#    #+#             */
/*   Updated: 2019/06/21 20:07:08 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

void	colors_init(void)
{
	start_color();
	init_color(GR, GR_NUM, GR_NUM, GR_NUM);
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);
	init_pair(5, COLOR_BLACK, COLOR_GREEN);
	init_pair(6, COLOR_BLACK, COLOR_BLUE);
	init_pair(7, COLOR_BLACK, COLOR_RED);
	init_pair(8, COLOR_BLACK, COLOR_CYAN);
	init_pair(9, COLOR_WHITE, COLOR_GREEN);
	init_pair(10, COLOR_WHITE, COLOR_BLUE);
	init_pair(11, COLOR_WHITE, COLOR_RED);
	init_pair(12, COLOR_WHITE, COLOR_CYAN);
	init_pair(13, GR, 0);
	init_pair(14, GR, GR);
}

void	init_carr(void)
{
	int i;
	int j;

	i = -1;
	while (++i < g_carriers->len)
	{
		if (g_carriers->carr[i]->dead)
			continue;
		if (g_carriers->carr[i]->champ_id == 0)
			return ;
		j = g_carriers->carr[i]->pos - g_mem;
		j = mem_pos(j);
		if (g_b[j].color <= 4 && g_b[j].color >= 1 && !g_b[j].live)
			g_b[j].color += 4;
		else if (g_b[j].color == 13)
			g_b[j].color = 14;
	}
}

void	prep(void)
{
	initscr();
	clear();
	keypad(stdscr, true);
	curs_set(0);
	nodelay(stdscr, true);
	cbreak();
	noecho();
	colors_init();
	g_wis.win = newwin(68, 198, 1, 1);
	g_wis.win = newwin(69, 350, 1, 1);
	wattron(g_wis.win, COLOR_PAIR(14));
	wborder(g_wis.win, '*', '*', '*', '*', '*', '*', '*', '*');
	wattroff(g_wis.win, COLOR_PAIR(14));
}

void	init_color_map(int pos, int c, int size)
{
	int i;

	i = -1;
	while (++i < size)
		g_b[pos++].color = c;
	i = -1;
	while (++i < MEM_SIZE)
		if (!g_b[i].color)
			g_b[i].color = 13;
}

void	colors_default(void)
{
	int i;

	i = -1;
	while (++i < MEM_SIZE)
	{
		if (g_b[i].color >= 5 && g_b[i].color <= 8 && !g_b[i].live)
			g_b[i].color -= 4;
		else if (g_b[i].color >= 9 && g_b[i].color <= 12 && !g_b[i].live)
			g_b[i].color -= 8;
		else if (g_b[i].color == 14 && !g_b[i].live)
			g_b[i].color -= 1;
	}
}
