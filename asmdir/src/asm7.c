/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm7.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <ikhrypko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 16:43:06 by ikhrypko          #+#    #+#             */
/*   Updated: 2019/06/21 19:26:00 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int					check_arg_instr(char *str, char *instr, int numb_arg)
{
	int i;
	int k;
	int c;

	i = 0;
	k = 0;
	i += is_instr(str);
	c = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	while (k != numb_arg)
	{
		if ((++c) && is_registr(&str[i]) > 0 && instr[c] != 49)
			return (0);
		if ((++c) && (is_direct(&str[i]) > 0
			|| is_direct_label(&str[i], 0) > 0) && instr[c] != 49)
			return (0);
		if ((++c) && is_indirect(&str[i]) > 0 && instr[c] != 49)
			return (0);
		i += is_registr(&str[i]) + is_direct(&str[i]);
		i += is_indirect(&str[i]) + is_direct_label(&str[i], 0);
		i += is_separator(&str[i]);
		k++;
	}
	return (1);
}

int					fts_cstr_new(char const *s, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			counter++;
		while (s[i] != c && s[i])
		{
			if (s[i] == COMMENT_CHAR || s[i] == ALT_COMMENT_CHAR)
				return (counter);
			i++;
		}
	}
	return (counter);
}

int					check_instr(char *str, char instruct[16][12])
{
	int i;
	int k;
	int c;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	k = is_instr_2(&str[i]);
	if (k < 0)
		return (ft_printf("%s\n", "Error_instruction"));
	c = fts_cstr_new(&str[i], SEPARATOR_CHAR);
	if (c != (instruct[k][0] - 48))
		return (ft_printf("%s\n", "Wrong number of arguments"));
	if (check_arg_instr(&str[i], instruct[k], instruct[k][0] - 48) == 1)
		return (-1);
	else
		return (ft_printf("%s\n", "Wrong arguments"));
	return (-1);
}

void				init_tabl(char tabl[10][9])
{
	fts_strcpy(tabl[0], "12eeee0e0");
	fts_strcpy(tabl[1], "e2eeee1e0");
	fts_strcpy(tabl[2], "ee3e56e8e");
	fts_strcpy(tabl[3], "eee4ee7e9");
	fts_strcpy(tabl[4], "ee3e56e8e");
	fts_strcpy(tabl[5], "eee4ee7e9");
	fts_strcpy(tabl[6], "eee4ee7e9");
	fts_strcpy(tabl[7], "eeeeeeee9");
	fts_strcpy(tabl[8], "eee4ee7e9");
	fts_strcpy(tabl[9], "000000000");
}

void				init_instruct(char instruct[16][12])
{
	fts_strcpy(instruct[0], "1010222222n4");
	fts_strcpy(instruct[1], "2011100222y4");
	fts_strcpy(instruct[2], "2100101222y4");
	fts_strcpy(instruct[3], "3100100100y4");
	fts_strcpy(instruct[4], "3100100100y4");
	fts_strcpy(instruct[5], "3111111100y4");
	fts_strcpy(instruct[6], "3111111100y4");
	fts_strcpy(instruct[7], "3111111100y4");
	fts_strcpy(instruct[8], "1010222222n2");
	fts_strcpy(instruct[9], "3111110122y2");
	fts_strcpy(instruct[10], "3100111110y2");
	fts_strcpy(instruct[11], "1010222222n2");
	fts_strcpy(instruct[12], "2011100222y4");
	fts_strcpy(instruct[13], "3111110122y2");
	fts_strcpy(instruct[14], "1010222222n2");
	fts_strcpy(instruct[15], "1100222222y4");
}
