#include "virtual_machine.h"

int		mem_pos(int move)
{
	if (move >= MEM_SIZE)
		move = move % MEM_SIZE;
	return (move);
}

void	mem_add(unsigned char *carr_pos, int pos, void *bytes, int size)
{
	int 			sum;
	unsigned char	*fill;
	unsigned char	*dest;
	unsigned char	*end;

	int i;

	i = -1;
	fill = bytes;
	sum = carr_pos - g_mem + pos;
	sum = mem_pos(sum);
	if (sum < 0)
		sum += MEM_SIZE;
	dest = g_mem + sum;
	end = g_mem + MEM_SIZE;
	while (++i < size)
	{
		if (dest == end)
			dest = g_mem;
		*dest++ = *fill++;
	}
}


void 	mem_init()
{
	int 		pos;
	int 		i;

	pos = 0;
	i = -1;
	g_carr_num = 1;
	champs_introduce();
	g_carriers = array_new(1, sizeof(t_carriers));
	while (++i < g_champs_count)
	{
		mem_add(g_mem, pos, g_champs[i]->code, g_champs[i]->code_size);
		array_push(g_carriers, carrier_place(i + 1, g_mem + pos));
		g_carriers->carr[i]->regs[1] = -g_champs[i]->id;
		pos += MEM_SIZE / g_champs_count;
	}
	g_last_live = g_champs[g_champs_count - 1];
}
