/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <ikhrypko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 15:56:11 by amazhara          #+#    #+#             */
/*   Updated: 2019/06/21 20:56:39 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

int	main(int ac, char **av)
{
	if (ac == 1)
		usage();
	parse(av + 1, ac - 1);
	mem_init();
	if (g_vis)
		main_cycle_v();
	else
		main_cycle();
}
