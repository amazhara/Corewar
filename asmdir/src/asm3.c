/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <ikhrypko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 16:40:37 by ikhrypko          #+#    #+#             */
/*   Updated: 2019/06/21 19:31:24 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int					put_comment(t_asm *file, t_header *head, int i, int t)
{
	char	*line;
	char	*error;

	error = "Champion comment too long (Max length 2048)";
	line = file->str_file;
	i += 8;
	file->numb_colum += 9;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		plus_numb_col(file, &i);
	if (line[plus_numb_col(file, &i)] != 34)
		return (synt_error(file));
	while (line[i] && line[i] != 34 && t < COMMENT_LENGTH)
	{
		obnul_colum_str(file, line[i]);
		head->comment[t++] = line[plus_numb_col(file, &i)];
	}
	head->comment[t] = '\0';
	if (line[plus_numb_col(file, &i)] != 34 && t < COMMENT_LENGTH)
		return (synt_error(file));
	if (t == COMMENT_LENGTH)
		return (ft_printf("%s\n", error));
	propusk_tab(line, &i, file);
	if (line[plus_numb_col(file, &i)] != '\n')
		return (synt_error(file));
	return (i * (-1));
}

int					put_name_comment(t_asm *file, t_header *head,
	char *str, int *t)
{
	int i;
	int k;

	i = *t;
	if ((k = fts_strncmp(&str[i], NAME_CMD_STRING, 5)) == 0)
	{
		if ((k = put_name(file, head, i, 0)) < 0)
			i = (k * (-1));
		else
			return (2);
	}
	if ((k = fts_strncmp(&str[i], COMMENT_CMD_STRING, 8)) == 0)
	{
		if ((k = put_comment(file, head, i, 0)) < 0)
			i = (k * (-1));
		else
			return (3);
		*t = i;
		return (0);
	}
	return (synt_error(file));
}

int					put_comment_name(t_asm *file, t_header *head,
	char *str, int *t)
{
	int i;
	int k;

	i = *t;
	if ((k = fts_strncmp(&str[i], COMMENT_CMD_STRING, 8)) == 0)
	{
		if ((k = put_comment(file, head, i, 0)) < 0)
			i = (k * (-1));
		else
			return (3);
	}
	if ((k = fts_strncmp(&str[i], NAME_CMD_STRING, 5)) == 0)
	{
		if ((k = put_name(file, head, i, 0)) < 0)
			i = (k * (-1));
		else
			return (2);
		*t = i;
		return (0);
	}
	return (synt_error(file));
}

int					find_name_comment(t_asm *file, t_header *head, int *i)
{
	int		t;
	char	*str;

	str = file->str_file;
	head->magic = 0;
	*i = 0;
	while (str[*i] && (fts_strncmp(&str[*i], NAME_CMD_STRING, 5) != 0
		&& fts_strncmp(&str[*i], COMMENT_CMD_STRING, 8) != 0))
	{
		if (str[*i] == COMMENT_CHAR || str[*i] == ALT_COMMENT_CHAR)
			while (str[*i] && str[*i] != '\n')
				plus_numb_col(file, i);
		obnul_colum_str(file, str[*i]);
		plus_numb_col(file, i);
	}
	if ((t = fts_strncmp(&str[*i], NAME_CMD_STRING, 5)) == 0)
		if (put_name_comment(file, head, str, i) == 0)
			return (0);
	if ((t = fts_strncmp(&str[*i], COMMENT_CMD_STRING, 8)) == 0)
		if (put_comment_name(file, head, str, i) == 0)
			return (0);
	return (ft_printf("%s\n", "No .name or .comment."));
}

int					char_label(char c, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (10);
		i++;
	}
	return (0);
}
