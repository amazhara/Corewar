/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm8.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <ikhrypko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 16:43:31 by ikhrypko          #+#    #+#             */
/*   Updated: 2019/06/21 21:01:09 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int					mal_int(int ret, int ind, t_asm *file)
{
	file->mal[0] = ret;
	file->mal[1] = ind;
	return (0);
}

void				size_instr(char *str, t_asm *file, int size, int i)
{
	int k;
	int count_of_arg;

	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	k = is_instr_2(&str[i]);
	count_of_arg = file->instruct[k][0] - 48;
	i += is_instruct(&str[i]);
	while (count_of_arg != 0)
	{
		if (is_registr(&str[i]) > 0)
			size++;
		if (is_direct(&str[i]) > 0 || is_direct_label(&str[i], 0) > 0)
			size += file->instruct[k][11] - 48;
		if (is_indirect(&str[i]) > 0)
			size += 2;
		i += is_registr(&str[i]) + is_direct(&str[i])
		+ is_indirect(&str[i]) + is_direct_label(&str[i], 0);
		i += is_separator(&str[i]);
		count_of_arg--;
	}
	if (file->instruct[k][10] == 'y')
		size++;
	file->size += size;
}

int					is_indirect_label(char *str)
{
	int i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[i] && str[i] == LABEL_CHAR)
	{
		i++;
		if (char_label(str[i], LABEL_CHARS) == 0)
			return (0);
		while (str[i] && (str[i] != ' '
			&& str[i] != '\t' && str[i] != SEPARATOR_CHAR))
		{
			if (char_label(str[i], LABEL_CHARS) == 0)
				return (0);
			i++;
		}
		return (i);
	}
	return (0);
}

int					check_label_direct(t_asm *file, char *str)
{
	int i;
	int k;
	int z;

	i = 0;
	k = -1;
	z = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[i] && str[i] == DIRECT_CHAR && str[i + 1] == LABEL_CHAR)
		i += 2;
	else if (str[i] && str[i] == LABEL_CHAR)
		i++;
	z = i;
	while (str[i] && char_label(str[i], LABEL_CHARS) > 0)
		i++;
	i != z ? i = i - z : 0;
	while (file->lab[++k].name)
		if (ft_strncmp(&str[z], file->lab[k].name, i) == 0)
			if (ft_strncmp(&str[z], file->lab[k].name,
				fts_strlen(file->lab[k].name)) == 0)
				return (0);
	return (10);
}

char				*str_to_correct(char *str)
{
	int		i;
	int		t;
	char	*res;

	i = 0;
	t = 0;
	while (str[i] && char_label(str[i], LABEL_CHARS) > 0)
		i++;
	res = (char*)malloc(sizeof(char) * (i + 1));
	while (t < i)
	{
		res[t] = str[t];
		t++;
	}
	res[t] = '\0';
	return (res);
}
