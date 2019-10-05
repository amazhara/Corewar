/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocheresh <ocheresh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 18:05:51 by ocheresh          #+#    #+#             */
/*   Updated: 2018/11/06 18:26:45 by ocheresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		**fts_strsplit(char const *s, char c)
{
	char	**res;
	int		t;
	int		r;

	if (!s || !c)
		return (NULL);
	if ((res = (char **)malloc(sizeof(char *) * (fts_cstr(s, c) + 1))) == NULL)
		return (NULL);
	t = 0;
	r = 0;
	while (s[t] && r < (fts_cstr(s, c)))
	{
		if (s[t] != c && t == 0)
			res[r++] = fts_wordfinder(&s[t], c);
		if (s[t] == c && s[t])
		{
			res[r++] = fts_wordfinder(&s[t], c);
			while (s[t] == c)
				t++;
		}
		t++;
	}
	res[r] = NULL;
	return (res);
}
