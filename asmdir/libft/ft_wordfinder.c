/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordfinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocheresh <ocheresh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 12:02:48 by ocheresh          #+#    #+#             */
/*   Updated: 2018/11/17 12:02:49 by ocheresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*fts_wordfinder(char const *s, char c)
{
	int		i;
	int		count;
	char	*res;
	int		t;

	i = 0;
	t = 0;
	count = 0;
	while (s[i] == c)
		i++;
	while (s[i++] != c && s[i])
		count++;
	res = (char *)malloc(sizeof(char) * (count + 1));
	i = i - count - 1;
	while (s[i] && s[i] != c)
		res[t++] = s[i++];
	res[t] = '\0';
	return (res);
}
