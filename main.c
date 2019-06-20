#include "virtual_machine.h"

int main(int ac, char **av)
{
	parse(ac - 1, av + 1);
	mem_init();
	if (g_ivan)
	{
		g_vl = 0;
		g_dump = -1;
	}
	main_cycle();
//	mem_print();
//	system("leaks -q Corewar");
//	mem_print();
}
