/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm6.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <ikhrypko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 16:42:46 by ikhrypko          #+#    #+#             */
/*   Updated: 2019/06/21 19:24:33 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int					is_comment(char *str)
{
	int i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[i] == '\0')
		return (0);
	if (str[i] == COMMENT_CHAR || str[i] == ALT_COMMENT_CHAR)
	{
		i++;
		while (str[i])
			i++;
		return (i);
	}
	else
		return (0);
}

int					is_end(char *str)
{
	int i;

	i = 0;
	while (str[i] && (str[i] == '\t' || str[i] == ' '))
		i++;
	if (str[i] == '\0')
		return (i + 1);
	return (0);
}

int					gnl(char **res, char **line)
{
	char	*str;
	char	*temp;
	char	*tempres;
	size_t	i;

	i = 0;
	str = *res;
	while (str[i] && str[i] != '\n')
		i++;
	temp = (char*)malloc(sizeof(char) * (i + 1));
	i = (-1);
	while (str[++i] && str[i] != '\n')
		temp[i] = str[i];
	temp[i] = '\0';
	if (*line != NULL)
		fts_strdel(line);
	*line = temp;
	if (str[i] != '\0')
		i++;
	tempres = fts_strdup(&str[i]);
	fts_strdel(res);
	*res = tempres;
	if (i == 0)
		return (0);
	return (1);
}

int					is_instr_2_2(char *str)
{
	if (fts_strncmp(str, "sti", 3) == 0)
		return (10);
	if (fts_strncmp(str, "lld", 3) == 0)
		return (12);
	if (fts_strncmp(str, "aff", 3) == 0)
		return (15);
	if (fts_strncmp(str, "ld", 2) == 0)
		return (1);
	if (fts_strncmp(str, "st", 2) == 0)
		return (2);
	if (fts_strncmp(str, "or", 2) == 0)
		return (6);
	return (-1);
}

int					is_instr_2(char *str)
{
	if (fts_strncmp(str, "lfork", 5) == 0)
		return (14);
	if (fts_strncmp(str, "live", 4) == 0)
		return (0);
	if (fts_strncmp(str, "zjmp", 4) == 0)
		return (8);
	if (fts_strncmp(str, "fork", 4) == 0)
		return (11);
	if (fts_strncmp(str, "lldi", 4) == 0)
		return (13);
	if (fts_strncmp(str, "add", 3) == 0)
		return (3);
	if (fts_strncmp(str, "sub", 3) == 0)
		return (4);
	if (fts_strncmp(str, "and", 3) == 0)
		return (5);
	if (fts_strncmp(str, "xor", 3) == 0)
		return (7);
	if (fts_strncmp(str, "ldi", 3) == 0)
		return (9);
	return (is_instr_2_2(str));
}
