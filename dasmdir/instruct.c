/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <ikhrypko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 18:23:36 by ocheresh          #+#    #+#             */
/*   Updated: 2019/06/21 19:53:56 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dasm.h"

int		is_instruct2(int t, t_dasm *file)
{
	if (t == 8)
		return (write(file->fd_ext, "xor ", 4));
	else if (t == 9)
		return (write(file->fd_ext, "zjmp ", 5));
	else if (t == 10)
		return (write(file->fd_ext, "ldi ", 4));
	else if (t == 11)
		return (write(file->fd_ext, "sti ", 4));
	else if (t == 12)
		return (write(file->fd_ext, "fork ", 5));
	else if (t == 13)
		return (write(file->fd_ext, "lld ", 4));
	else if (t == 14)
		return (write(file->fd_ext, "lldi ", 5));
	else if (t == 15)
		return (write(file->fd_ext, "lfork ", 6));
	else if (t == 16)
		return (write(file->fd_ext, "aff ", 4));
	return (0);
}

int		is_instruct(int t, t_dasm *file)
{
	if (t == 1)
		return (write(file->fd_ext, "live ", 5));
	else if (t == 2)
		return (write(file->fd_ext, "ld ", 3));
	else if (t == 3)
		return (write(file->fd_ext, "st ", 3));
	else if (t == 4)
		return (write(file->fd_ext, "add ", 4));
	else if (t == 5)
		return (write(file->fd_ext, "sub ", 4));
	else if (t == 6)
		return (write(file->fd_ext, "and ", 4));
	else if (t == 7)
		return (write(file->fd_ext, "or ", 3));
	return (is_instruct2(t, file));
}

void	init_instruct(char instruct[16][12])
{
	fts_strcpy(instruct[0], "1010222222n4");
	fts_strcpy(instruct[1], "2011100222y4");
	fts_strcpy(instruct[2], "2100101222y4");
	fts_strcpy(instruct[3], "3100100100y4");
	fts_strcpy(instruct[4], "3100100100y4");
	fts_strcpy(instruct[5], "3111111100y4");
	fts_strcpy(instruct[6], "3111111100y4");
	fts_strcpy(instruct[7], "3111111100y4");
	fts_strcpy(instruct[8], "1010222222n2");
	fts_strcpy(instruct[9], "3111110122y2");
	fts_strcpy(instruct[10], "3100111110y2");
	fts_strcpy(instruct[11], "1010222222n2");
	fts_strcpy(instruct[12], "2101100222y4");
	fts_strcpy(instruct[13], "3111110122y2");
	fts_strcpy(instruct[14], "1010222222n2");
	fts_strcpy(instruct[15], "1100222222y4");
}
