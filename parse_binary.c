/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_binary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazhara <amazhara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 15:20:41 by amazhara          #+#    #+#             */
/*   Updated: 2019/06/20 17:06:34 by amazhara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

int16_t		byte_swap16(uint32_t number)
{
	uint16_t	res;
	uint8_t		*tmp;

	tmp = (uint8_t*)&number;
	res = 0;
	res |= tmp[0] << 8;
	res |= tmp[1];
	return (res);
}

int			byte_swap32(uint32_t number)
{
	uint32_t	res;
	uint8_t		*tmp;

	tmp = (uint8_t*)&number;
	res = 0;
	res |= tmp[0] << 24;
	res |= tmp[1] << 16;
	res |= tmp[2] << 8;
	res |= tmp[3];
	return (res);
}

uint		byte_get(void *src, size_t size)
{
	uint	res;
	int		skip;
	char	*tmp;
	int		i;

	res = 0;
	skip = 0;
	src = g_mem + jump_pos((unsigned char*)src - g_mem);
	if (size == 1)
		skip = 3;
	else if (size == 2)
		skip = 2;
	tmp = (char*)&res + skip;
	i = -1;
	while (++i < size)
	{
		if ((unsigned char*)src >= g_mem + MEM_SIZE)
			src = g_mem;
		tmp[i] = *(char*)src++;
	}
	if (size == 2)
		return (byte_swap16(res >> 16));
	return (byte_swap32(res));
}
