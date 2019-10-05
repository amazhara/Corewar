/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bar.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <ikhrypko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 21:12:27 by amazhara          #+#    #+#             */
/*   Updated: 2019/06/21 20:43:20 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"
#include "vis.h"

void	show_champs(void)
{
	int	i;

	i = -1;
	while (++i < g_champs_count)
	{
		wattron(g_wis.win, A_BOLD);
		mvwprintw(g_wis.win,
				17 + (i * 2),
				215,
				"Player -%d : ", g_champs[i]->id);
		wattron(g_wis.win, COLOR_PAIR(i + 1));
		wprintw(g_wis.win, "%s", g_champs[i]->name);
		wattroff(g_wis.win, COLOR_PAIR(i + 1));
		wattroff(g_wis.win, A_BOLD);
	}
}

void	info(void)
{
	wattron(g_wis.win, A_BOLD);
	if (g_wis.run)
	{
		wattron(g_wis.win, COLOR_PAIR(1));
		mvwprintw(g_wis.win, 3, 215, "%s", RUN);
		wattroff(g_wis.win, COLOR_PAIR(1));
	}
	else
	{
		wattron(g_wis.win, COLOR_PAIR(3));
		mvwprintw(g_wis.win, 3, 215, "%s", PAUSE);
		wattroff(g_wis.win, COLOR_PAIR(3));
	}
	mvwprintw(g_wis.win, 5, 215, "Cycles : %-10zd", g_cycles);
	mvwprintw(g_wis.win, 7, 215, "Process : %-10zd", g_carriers->len);
	mvwprintw(g_wis.win, 9, 215, "Cycle to die : %-10d", g_cycles_die);
	mvwprintw(g_wis.win, 11, 215, "CYCLE_DELTA : %-10zd", CYCLE_DELTA);
	mvwprintw(g_wis.win, 13, 215, "NBR_LIVE : %-10zd", NBR_LIVE);
	mvwprintw(g_wis.win, 15, 215, "MAX_CHECKS : %-10zd", g_checks_count);
	show_champs();
	wattroff(g_wis.win, A_BOLD);
}

void	buttons(void)
{
	if (g_wis.button == SPACE)
	{
		if (g_wis.run)
			g_wis.run = 0;
		else
			g_wis.run = 1;
	}
}
