/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazhara <amazhara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 15:56:11 by amazhara          #+#    #+#             */
/*   Updated: 2019/06/21 13:37:36 by amazhara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

int	main(int ac, char **av)
{
	(void)ac;
	parse(av + 1);
	mem_init();
	if (g_vis)
		main_cycle_v();
	else
		main_cycle();
}
