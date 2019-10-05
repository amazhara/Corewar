/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <ikhrypko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 18:36:47 by ocheresh          #+#    #+#             */
/*   Updated: 2019/06/21 19:53:54 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dasm.h"

void	arg_instr(t_dasm *file, int temp, int r, int i)
{
	int		count;
	int		temp2;
	char	buf[2];
	char	*str;

	temp2 = 0;
	str = NULL;
	count = file->instruct[temp - 1][0] - 48;
	read(file->fd_ent, &temp2, 1);
	str = fts_itoa_base(temp2, 16);
	while (str[++i])
		file->temp_str = fts_sjoin(file->temp_str, p_to_code_type(str[i]), 1);
	while (file->temp_str[r] && count != 0)
	{
		buf[0] = file->temp_str[r];
		buf[1] = file->temp_str[r + 1];
		if (fts_strncmp(buf, "01", 2) == 0)
			read_registr(file, &count);
		if (fts_strncmp(buf, "10", 2) == 0)
			read_direct(file, &count, temp);
		if (fts_strncmp(buf, "11", 2) == 0)
			read_indirect(file, &count);
		r += 2;
	}
	fts_strdel(&str);
}

int		instruct(t_dasm *file)
{
	int	temp;

	temp = 0;
	read(file->fd_ent, &temp, 1);
	is_instruct(temp, file);
	if (file->instruct[temp - 1][10] == 121)
		arg_instr(file, temp, 0, -1);
	else if (file->instruct[temp - 1][10] == 110)
		read_no_arg_instr(file, temp, 0);
	fts_putchar_fd('\n', file->fd_ext);
	fts_strdel(&file->temp_str);
	return (temp);
}
