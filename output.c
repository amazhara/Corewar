/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazhara <amazhara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 16:18:30 by amazhara          #+#    #+#             */
/*   Updated: 2019/06/20 16:54:22 by amazhara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

void		error(char *line)
{
	ft_printf("%s\n", line);
	exit(0);
}

void		champs_introduce(void)
{
	ssize_t		i;

	i = -1;
	ft_printf("Introducing contestants...\n");
	while (++i < g_champs_count)
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
		i + 1, g_champs[i]->code_size, g_champs[i]->name, g_champs[i]->comment);
}
