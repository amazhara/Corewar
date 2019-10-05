/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm9.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <ikhrypko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 16:43:52 by ikhrypko          #+#    #+#             */
/*   Updated: 2019/06/21 20:32:54 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int					put_size_in_label(t_asm *file, char *str)
{
	int i;
	int t;

	i = 0;
	t = 0;
	while (str[t] && (str[t] == ' ' || str[t] == '\t'))
		t++;
	while (file->lab[i].name)
	{
		file->temp = str_to_correct(&str[t]);
		if (fts_strcmp(file->temp, file->lab[i].name) == 0)
		{
			if (file->lab[i].size == -1)
				file->lab[i].size = file->size;
			fts_strdel(&file->temp);
			return (0);
		}
		fts_strdel(&file->temp);
		i++;
	}
	return (10);
}

int					compare_3(char *str, char *tabl, t_asm *file)
{
	if (is_indirect(str) > 0)
	{
		if (tabl[7] != 101)
		{
			if (is_indirect_label(str) > 0 && check_label_direct(file, str) > 0)
				return (mal_int(-1, 8, file));
			return (mal_int(8, is_indirect(str), file));
		}
		return (mal_int(-1, 8, file));
	}
	else if (is_end(str) > 0)
	{
		if (tabl[8] != 101)
			return (mal_int(9, is_end(str), file));
		return (mal_int(-1, 9, file));
	}
	return (mal_int(-1, 0, file));
}

int					compare_2(char *str, char *tabl, t_asm *file)
{
	if (is_separator(str) > 0 && tabl[3] != 101)
	{
		if (tabl[3] != 101)
			return (mal_int(4, is_separator(str), file));
		return (mal_int(-1, 4, file));
	}
	else if (is_direct_label(str, 0) > 0)
	{
		if (tabl[4] != 101 && check_label_direct(file, str) == 0)
			return (mal_int(5, is_direct_label(str, 0), file));
		return (mal_int(-1, 5, file));
	}
	else if (is_direct(str) > 0)
	{
		if (tabl[5] != 101)
			return (mal_int(6, is_direct(str), file));
		return (mal_int(-1, 6, file));
	}
	else if (is_comment(str) > 0 && tabl[6] != 101)
	{
		if (tabl[6] != 101)
			return (mal_int(7, is_comment(str), file));
		return (mal_int(-1, 7, file));
	}
	return (compare_3(str, tabl, file));
}

int					compare(char *str, char *tabl, t_asm *file)
{
	if (is_label(str) > 0)
	{
		if (tabl[0] != 101 && put_size_in_label(file, str) == 0)
			return (mal_int(1, is_label(str), file));
		file->numb_colum = is_label(str);
		return (mal_int(-1, 1, file));
	}
	else if (is_instruct(str) > 0)
	{
		if (tabl[1] != 101 && (check_instr(str, (file->instruct)) < 0))
		{
			size_instr(str, file, 1, 0);
			return (mal_int(2, is_instruct(str), file));
		}
		file->numb_colum = is_label(str);
		return (mal_int(-1, 2, file));
	}
	else if (is_registr(str) > 0)
	{
		if (tabl[2] != 101)
			return (mal_int(3, is_registr(str), file));
		return (mal_int(-1, 3, file));
	}
	return (compare_2(str, tabl, file));
}

int					error_string(int t)
{
	if (t == 1)
		return (ft_printf("%s\n", "You have problem in label."));
	if (t == 2)
		return (ft_printf("%s\n", "You have problem in instruction."));
	if (t == 3)
		return (ft_printf("%s\n", "You have problem in registr."));
	if (t == 4)
		return (ft_printf("%s\n", "You have problem in separator."));
	if (t == 5)
		return (ft_printf("%s\n", "You have problem in direct label."));
	if (t == 6)
		return (ft_printf("%s\n", "You have problem in direct."));
	if (t == 7)
		return (ft_printf("%s\n", "You have problem in comment."));
	if (t == 8)
		return (ft_printf("%s\n", "You have problem in indirect."));
	if (t == 9)
		return (ft_printf("%s\n", "You have problem with end."));
	return (ft_printf("%s\n", "Please check syntax."));
}
