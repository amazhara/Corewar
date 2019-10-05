/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <ikhrypko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 16:41:05 by ikhrypko          #+#    #+#             */
/*   Updated: 2019/06/21 16:51:39 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int					is_label(char *str)
{
	int i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[i] && str[i] == LABEL_CHAR)
		return (0);
	while (str[i] && str[i] != LABEL_CHAR)
	{
		if (char_label(str[i], LABEL_CHARS) == 0)
			return (0);
		i++;
	}
	if (str[i] == LABEL_CHAR)
		return (i + 1);
	return (0);
}

int					is_instr(char *str)
{
	if (fts_strncmp(str, "lfork", 5) == 0)
		return (5);
	if (fts_strncmp(str, "lldi", 4) == 0)
		if (str[4] && str[4] != 'r')
			return (4);
	if (fts_strncmp(str, "live", 4) == 0 || fts_strncmp(str, "zjmp", 4) == 0
		|| fts_strncmp(str, "fork", 4) == 0)
		return (4);
	if (fts_strncmp(str, "add", 3) == 0 || fts_strncmp(str, "xor", 3) == 0
		|| fts_strncmp(str, "ldi", 3) == 0 || fts_strncmp(str, "sti", 3) == 0)
		if (str[2] && str[3] != 'r')
			return (3);
	if (fts_strncmp(str, "sub", 3) == 0 || fts_strncmp(str, "and", 3) == 0
		|| fts_strncmp(str, "lld", 3) == 0 || fts_strncmp(str, "aff", 3) == 0)
		return (3);
	if (fts_strncmp(str, "ld", 2) == 0)
		return (2);
	if (fts_strncmp(str, "st", 2) == 0 || fts_strncmp(str, "or", 2) == 0)
		if (str[2] && str[2] != 'r')
			return (2);
	return (0);
}

int					is_instruct(char *str)
{
	int i;
	int k;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	k = is_instr(&str[i]);
	i += k;
	if (str[i] && str[i] == LABEL_CHAR)
		return (0);
	if (k > 0)
		return (i);
	return (0);
}

int					is_registr(char *str)
{
	int i;
	int k;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[i] == 'r')
		i++;
	else
		return (0);
	k = fts_atoi(&str[i]);
	if (k > 0 && k < 10)
		i++;
	if (k > 9 && k <= REG_NUMBER)
		i += 2;
	if (str[i] && (str[i] == ' ' || str[i] == '\t'
		|| str[i] == SEPARATOR_CHAR))
		return (i);
	else if (str[i] == '\0')
		return (i);
	return (0);
}

int					cintl(long long int n)
{
	long long int	temp;
	int				counter;

	counter = 0;
	temp = n;
	if (n < 0)
	{
		temp = temp * (-1);
		counter++;
	}
	while ((temp - (temp % 10)) != 0)
	{
		temp = (temp - (temp % 10)) / 10;
		counter++;
	}
	counter++;
	return (counter);
}
