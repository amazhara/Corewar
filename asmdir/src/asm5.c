/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm5.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <ikhrypko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 16:42:31 by ikhrypko          #+#    #+#             */
/*   Updated: 2019/06/21 19:25:12 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int					is_direct(char *str)
{
	int				i;
	long long int	k;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[i] == DIRECT_CHAR)
		i++;
	else
		return (0);
	if ((str[i] < 48 || str[i] > 57) && str[i] != '-')
		return (0);
	k = fts_latoi(&str[i]);
	if (str[i] == '-' && k == 0)
		i++;
	return (i + cintl(k));
}

int					is_indirect_2(char *str, int i)
{
	if (str[i] && ((str[i] > 47 && str[i] < 58) || str[i] == '-'))
	{
		i++;
		while (str[i] && (str[i] >= 48 && str[i] <= 57))
			i++;
		if (str[i] && (str[i] == ' '
			|| str[i] == '\t' || str[i] == SEPARATOR_CHAR))
			return (i);
		if (str[i] == '\0')
			return (i);
	}
	return (0);
}

int					is_indirect(char *str)
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
	return (is_indirect_2(str, i));
}

int					is_separator(char *str)
{
	int i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[i] == SEPARATOR_CHAR)
		return (i + 1);
	return (0);
}

int					is_direct_label(char *s, int i)
{
	while (s[i] && (s[i] == ' ' || s[i] == '\t'))
		i++;
	if (s[i] && s[i + 1] && s[i] == DIRECT_CHAR
		&& s[i + 1] == LABEL_CHAR)
		i += 2;
	else
		return (0);
	if (s[i] == '\0')
		return (0);
	while (s[i] && s[i] != ' ' && s[i] != '\t'
		&& s[i] != SEPARATOR_CHAR)
	{
		if (char_label(s[i], LABEL_CHARS) == 0)
			return (0);
		i++;
	}
	if (s[i] && (s[i] == ' ' || s[i] == '\t'
		|| s[i] == SEPARATOR_CHAR))
		return (i);
	else if (s[i] == '\0')
		return (i);
	return (0);
}
