/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazhara <amazhara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 15:20:41 by amazhara          #+#    #+#             */
/*   Updated: 2019/06/20 16:57:00 by amazhara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

int			g_n[4];
int			g_id_big;

void		vis_case(void)
{
	g_dump = -1;
	g_a = 0;
	g_vl = 0;
}

t_champ		*champ_read(char *path)
{
	int			fd;
	t_champ		*res;
	int			tmp;

	if ((fd = open(path, O_RDONLY)) == -1)
		error("Invalid champion\n");
	res = ft_memalloc(sizeof(t_champ));
	ft_read(fd, &tmp, 4);
	if (byte_swap32(tmp) != COREWAR_EXEC_MAGIC)
		error("Magic header not equals!");
	ft_read(fd, &res->name, PROG_NAME_LENGTH);
	ft_read(fd, &tmp, 4);
	if (tmp)
		error("Name not NULL terminated!");
	ft_read(fd, &res->code_size, 4);
	res->code_size = byte_swap32(res->code_size);
	if (res->code_size > CHAMP_MAX_SIZE)
		error("Too large Champion exec code size!");
	ft_read(fd, &res->comment, COMMENT_LENGTH);
	ft_read(fd, &tmp, 4);
	if (tmp)
		error("Name not NULL terminated!");
	if (res->code_size != ft_read(fd, &res->code, res->code_size + 1))
		error("Exec code size not equals!");
	return (res);
}

void		champ_add(t_champ *champ, int id)
{
	g_champs[id] = champ;
	g_champs[id]->id = id + 1;
	g_champs_count++;
	g_n[id] = 1;
	if (g_id_big < id + 1)
		g_id_big = id + 1;
}

void		champ_parse(char **av, int i)
{
	int		n_i;

	n_i = 0;
	while (g_n[n_i])
		n_i++;
	champ_add(champ_read(av[i]), n_i);
}

void		parse(int ac, char **av)
{
	int		i;

	g_dump = -1;
	i = -1;
	while (av[++i])
	{
		if (!ft_strcmp(av[i], "-dump"))
			flag_dump(av, &i);
		else if (!ft_strcmp(av[i], "-v"))
			flag_v(av, &i);
		else if (!ft_strcmp(av[i], "-a"))
			g_a = 1;
		else if (!ft_strcmp(av[i], "-vis"))
			g_vis = 1;
		else if (!ft_strcmp(av[i], "-n"))
			flag_n(av, &i);
		else
			champ_parse(av, i);
		if (g_champs_count > MAX_PLAYERS)
			error("To much champions");
	}
	g_champs_count < g_id_big ? error("Unnecessary -n index") : 0;
	if (g_vis)
		vis_case();
}
