/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <ikhrypko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 18:33:31 by ocheresh          #+#    #+#             */
/*   Updated: 2019/06/21 19:54:09 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dasm.h"

int		parse_read_direct(t_dasm *file, int k, LLI *res, char **mp_minus)
{
	int		temp2;
	char	*temp_minus;

	temp2 = 0;
	temp_minus = *mp_minus;
	while (k != 0)
	{
		read(file->fd_ent, &temp2, 1);
		if (k == 4)
			*res += (long long int)temp2 * 65536 * 256;
		if (k == 3)
			*res += (long long int)temp2 * 65536;
		if (k == 2)
			*res += temp2 * 256;
		if (k < 4)
			temp_minus = fts_sjoin(temp_minus, bynar_from_int(temp2), 3);
		k--;
	}
	*mp_minus = temp_minus;
	return (temp2);
}

void	read_direct(t_dasm *file, int *count, int temp)
{
	int				k;
	long long int	res;
	int				temp2;
	char			*temp_minus;

	temp_minus = NULL;
	res = 0;
	k = file->instruct[temp - 1][11] - 48;
	temp2 = parse_read_direct(file, k, &res, &temp_minus);
	if (fts_strncmp(temp_minus, "1111", 4) == 0)
		if ((k = minus_bynar(&temp_minus)) < 0)
			temp2 = k;
	res = res + temp2;
	fts_putchar_fd(DIRECT_CHAR, file->fd_ext);
	fts_putnbr_fd2(res, file->fd_ext);
	(*count)--;
	if (*count != 0)
		fts_putstr_fd(", ", file->fd_ext);
	fts_strdel(&temp_minus);
}

void	read_indirect(t_dasm *file, int *count)
{
	long long int	res;
	int				temp2;
	char			*temp_minus;
	int				k;

	temp_minus = NULL;
	res = 0;
	temp2 = parse_read_direct(file, 2, &res, &temp_minus);
	if (fts_strncmp(temp_minus, "1111", 4) == 0)
		if ((k = minus_bynar(&temp_minus)) < 0)
			temp2 = k;
	res = res + temp2;
	fts_putnbr_fd2(res, file->fd_ext);
	(*count)--;
	if (*count != 0)
		fts_putstr_fd(", ", file->fd_ext);
	fts_strdel(&temp_minus);
}

int		parse_read_no_arg(t_dasm *file, int k, int *temp2, char **mp_minus)
{
	int		res;
	char	*temp_minus;

	temp_minus = *mp_minus;
	res = 0;
	while (k != 0)
	{
		read(file->fd_ent, temp2, 1);
		if (k == 3)
			res += *temp2 * 65536;
		if (k == 2)
			res += *temp2 * 256;
		if (k < 3)
			temp_minus = fts_sjoin(temp_minus, bynar_from_int(*temp2), 3);
		k--;
	}
	*mp_minus = temp_minus;
	return (res);
}

void	read_no_arg_instr(t_dasm *file, int temp, int temp2)
{
	int		k;
	int		res;
	int		minus;
	char	*temp_minus;

	temp_minus = NULL;
	res = 0;
	minus = 0;
	k = file->instruct[temp - 1][11] - 48;
	res = parse_read_no_arg(file, k, &temp2, &temp_minus);
	fts_putchar_fd(DIRECT_CHAR, file->fd_ext);
	if (fts_strncmp(temp_minus, "1111", 4) == 0)
	{
		if ((k = minus_bynar(&temp_minus)) < 0)
			fts_putnbr_fd(k, file->fd_ext);
	}
	else
	{
		res = res + temp2;
		fts_putnbr_fd(res, file->fd_ext);
	}
	fts_strdel(&temp_minus);
}
