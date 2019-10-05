/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <ikhrypko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 16:40:16 by ikhrypko          #+#    #+#             */
/*   Updated: 2019/06/21 19:14:55 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int					synt_error(t_asm *file)
{
	return (ft_printf("%s%03d%s%03d%s\n", "Syntax error at token [TOKEN][",
		file->numb_str, ":", (file->numb_colum - 1), "]"));
}

int					obnul_colum_str(t_asm *file, char c)
{
	if (c == '\n')
	{
		file->numb_str++;
		file->numb_colum = 0;
		return (0);
	}
	return (0);
}

int					plus_numb_col(t_asm *file, int *i)
{
	file->numb_colum++;
	(*i)++;
	return ((*i) - 1);
}

void				propusk_tab(char *line, int *i, t_asm *file)
{
	while (line[*i] && (line[*i] == ' ' || line[*i] == '\t'))
		plus_numb_col(file, i);
	if (line[*i] && (line[*i] == COMMENT_CHAR || line[*i] == ALT_COMMENT_CHAR))
		while (line[*i] && line[*i] != '\n')
			plus_numb_col(file, i);
	obnul_colum_str(file, line[*i]);
}

int					put_name(t_asm *file, t_header *head, int i, int t)
{
	char *line;

	line = file->str_file;
	i += 5;
	file->numb_colum += 6;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		plus_numb_col(file, &i);
	if (line[plus_numb_col(file, &i)] != 34)
		return (synt_error(file));
	while (line[i] && line[i] != 34 && t < PROG_NAME_LENGTH)
	{
		obnul_colum_str(file, line[i]);
		head->prog_name[t++] = line[plus_numb_col(file, &i)];
	}
	head->prog_name[t] = '\0';
	if (line[plus_numb_col(file, &i)] != 34 && t < PROG_NAME_LENGTH)
		return (synt_error(file));
	if (t == PROG_NAME_LENGTH)
		return (ft_printf("%s\n", "Champion name too long (Max length 128)"));
	propusk_tab(line, &i, file);
	if (line[plus_numb_col(file, &i)] != '\n')
		return (synt_error(file));
	return (i * (-1));
}
