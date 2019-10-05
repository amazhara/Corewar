/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm10.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <ikhrypko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 16:44:09 by ikhrypko          #+#    #+#             */
/*   Updated: 2019/06/21 19:11:57 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int					compare_str(char *res, t_asm *file)
{
	file->indx = 0;
	compare(res, file->tabl[0], file);
	file->indx += file->mal[1];
	while (file->mal[0] > 0 && file->mal[0] != 9)
	{
		compare(&res[file->indx], file->tabl[file->mal[0]], file);
		file->indx += file->mal[1];
	}
	if (file->mal[0] < 0)
	{
		ft_printf("%s %03d %s ", "Error in string number [",
			file->numb_str, "] ");
		return (error_string(file->mal[1]));
	}
	return (0);
}

int					compare_labels(t_asm *file, char *str, int t)
{
	int i;

	i = 0;
	while (i < t)
	{
		if (fts_strcmp(file->lab[i].name, str) == 0)
		{
			fts_strdel(&str);
			return (10);
		}
		i++;
	}
	fts_strdel(&str);
	return (0);
}

void				count_labels(char *str, t_asm *file, int t)
{
	char	*res;
	char	*line;
	int		k;

	line = NULL;
	res = fts_strdup(str);
	while (gnl(&res, &line) > 0)
		if (is_label(line) > 0)
			t++;
	file->lab = (t_label*)malloc(sizeof(t_label) * (t + 1));
	fts_strdel(&res);
	res = fts_strdup(str);
	t = 0;
	k = 0;
	while (gnl(&res, &line) > 0)
		if ((k = is_label(line)) > 0)
			if (compare_labels(file, fts_strndup(line, k), t) == 0)
			{
				file->lab[t].size = -1;
				file->lab[t++].name = fts_strndup(line, k);
			}
	file->lab[t].name = NULL;
	fts_strdel(&res);
	fts_strdel(&line);
}

int					fin_check_lab(t_asm *file, int *i)
{
	char *res;
	char *line;

	res = NULL;
	line = NULL;
	count_labels(file->str_file, file, 0);
	res = fts_strdup(&file->str_file[*i]);
	file->numb_str--;
	while (gnl(&res, &line) > 0)
	{
		obnul_colum_str(file, '\n');
		if (compare_str(line, file) != 0)
		{
			fts_strdel(&res);
			fts_strdel(&line);
			return (10);
		}
	}
	fts_strdel(&res);
	fts_strdel(&line);
	return (0);
}

char				*parser_to_code_type_2(char *str)
{
	if (fts_strncmp("1011", str, 4) == 0)
		return ("b");
	if (fts_strncmp("1100", str, 4) == 0)
		return ("c");
	if (fts_strncmp("1101", str, 4) == 0)
		return ("d");
	if (fts_strncmp("1110", str, 4) == 0)
		return ("e");
	if (fts_strncmp("1111", str, 4) == 0)
		return ("f");
	return ("0");
}
