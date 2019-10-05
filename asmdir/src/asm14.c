/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm14.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <ikhrypko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 16:45:23 by ikhrypko          #+#    #+#             */
/*   Updated: 2019/06/21 19:14:40 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void				str_to_byte(char *str, t_asm *file)
{
	int i;
	int k;

	i = 0;
	i += is_label(str);
	if (is_instruct(&str[i]) > 0)
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		k = is_instr_2(&str[i]);
		file->tp = is_instr_2(&str[i]) + 1;
		write(file->fd, &file->tp, 1);
		i += is_instruct(&str[i]);
		type_of_arg(&str[i], file, 0, k);
		args_to_byte(&str[i], k, file, 0);
		i = is_label(str);
		size_instr(&str[i], file, 1, 0);
	}
}

int					propusk_comment(char *str)
{
	int i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
		i++;
	if (str[i] == COMMENT_CHAR || str[i] == ALT_COMMENT_CHAR)
	{
		while (str[i] && str[i] != '\n')
			i++;
		return (i);
	}
	return (i);
}

int					check_any_instruct(char *str)
{
	int i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
		i++;
	while (propusk_comment(&str[i]) > 0)
		i += propusk_comment(&str[i]);
	if (is_label(&str[i]) > 0 || is_instruct(&str[i]) > 0)
		return (0);
	ft_printf("%s\n", "Please put any instruction.");
	return (10);
}

int					byte_code(t_asm *file, int i)
{
	char	*res;
	char	*line;
	int		t;

	line = NULL;
	file->size = 0;
	res = fts_strdup(&file->str_file[i]);
	file->result = NULL;
	t = 1;
	while (gnl(&res, &line) > 0)
		str_to_byte(line, file);
	fts_strdel(&res);
	fts_strdel(&line);
	return (0);
}

void				join_comment(t_asm *file, t_header *head)
{
	int i;

	i = fts_strlen(head->comment);
	write(file->fd, &head->comment[0], i);
	while (i != COMMENT_LENGTH)
	{
		write(file->fd, "\0", 1);
		i++;
	}
	write(file->fd, "\0\0\0\0", 4);
}
