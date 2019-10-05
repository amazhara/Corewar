/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <ikhrypko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 16:18:30 by amazhara          #+#    #+#             */
/*   Updated: 2019/06/21 18:49:15 by ikhrypko         ###   ########.fr       */
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

void		usage(void)
{
	ft_printf("Usage: ./corewar [-a (-dump) <num> -v <num>"\
							" ] [-vis] [-n <num>] <champion.cor> <...>\n");
	ft_printf("    %-11s : Print output from \"aff\" (Default is off)\n", "-a");
	ft_printf("    %-11s : Dump memory (32 octets per line)"\
							" after <num> cycles and exit\n", "-dump <num>");
	ft_printf("    %-11s : Verbosity levels\n", "-v  <num>");
	ft_printf("            %9s : Show lives\n", "1 ");
	ft_printf("            %9s : Show cycles\n", "2 ");
	ft_printf("            %9s : Show operations\n", "4 ");
	ft_printf("            %9s : Show deaths\n", "8 ");
	ft_printf("            %9s : Show PC movements\n", "16");
	ft_printf("    %-11s : Run visualisation\n", "-vis");
	ft_printf("    %-11s : Set <num> of the next player\n", "-n    <num>");
	exit(0);
}
