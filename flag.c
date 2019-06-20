#include "virtual_machine.h"

void		flag_n(char **av, int *i)
{
	int 	id;

	if (!ft_isnum(av[++*i]))
		error("Wrong -n argument");
	id = ft_atoi(av[*i]);
	if (id > 4 || id <= 0)
		error("Wrong -n argument");
	champ_add(champ_read(av[++*i]), id - 1);
}

void		flag_dump(char **av, int *i)
{
	if (!ft_isnum(av[++*i]))
		error("Wrong -dump argument");
	g_dump = ft_atoi(av[*i]);
}

void		flag_v(char **av, int *i)
{
	if (!ft_isnum(av[++*i]) || (g_vl = ft_atoi(av[*i])) > 31)
		error("Wrong -v argument");
}

void		dump(void)
{
	int	i;
	int j;

	if (g_dump != g_cycles)
		return;
	i = 0;
	while (i < MEM_SIZE)
	{
		ft_printf("0x%.4x : ", i);
		j = -1;
		while (++j < 64)
			ft_printf("%.2x ", g_mem[i + j]);
		ft_printf("\n");
		i += 64;
	}
	exit(0);
}

//
//int	i;
//int	j;
//
//i = 0;
//while (i < MEM_SIZE)
//{
//ft_printf("%.4p : ", i);
//j = 0;
//while (j < print_mode)
//{
//ft_printf("%.2x ", arena[i + j]);
//j++;
//}
//ft_printf("\n");
//i += print_mode;
//}