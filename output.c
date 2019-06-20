#include "virtual_machine.h"
#include "stdio.h"
# define RED(string) "\e[31m" string "\e[0m"


void		error(char *line)
{
	ft_printf("%s\n", line);
	exit(0);
}

void		champs_introduce()
{
	ssize_t 	i;

	i = -1;
	ft_printf("Introducing contestants...\n");
	while (++i < g_champs_count)
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
		i + 1, g_champs[i]->code_size, g_champs[i]->name, g_champs[i]->comment);
}

void		champ_print(t_champ *champ)
{
	int	i;

	i = -1;
	if (!champ)
		return ;
	ft_printf("name --> %s\ncomment --> %s\n", champ->name, champ->comment);
	ft_printf("code_size --> %zu\ncode --> ", champ->code_size);
	while (++i < champ->code_size)
		ft_printf("%.2x ", champ->code[i]);
	ft_printf("\nid --> %d\n\n", champ->id);
}

void		carrier_print(t_carrier *carr)
{
	ft_printf("\n\n");
	ft_printf("carry ---> ");
	ft_printf("\nstart chemp id--> %d\nflag --> %u\n", carr->champ_id, carr->flag);
	ft_printf("curr code --> %s\nlast live cycle --> %u\ncycles to exec --> %u\n", g_op_tab[carr->code_curr].name, carr->cycles_id, carr->cycles_to_exec);
	ft_printf("bytes to skip --> %u\ncurr pos --> %p\n", carr->skip, carr->pos);
	ft_printf("\n\n");
}

void		mem_print()
{
	int 	i;

	i = -1;

	int f;

	while (++i < 4096)
	{
		f = 0;
		if (i % 64 == 0)
			ft_printf("\n");
		for (int j = 0; j < g_carriers->len; ++j)
			if (g_carriers->carr[j]->pos - g_mem == i)
			{
				ft_printf(RED("%.2x "), g_mem[i]);
				f = 1;
			}
		if (f)
			continue;
		ft_printf("%.2x ", g_mem[i]);
	}
	ft_printf("\n");
}
