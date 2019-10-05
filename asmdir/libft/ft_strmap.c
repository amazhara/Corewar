/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocheresh <ocheresh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 13:01:41 by ocheresh          #+#    #+#             */
/*   Updated: 2018/11/06 18:25:07 by ocheresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*fts_strmap(char const *s, char (*f)(char))
{
	int		t;
	char	*res;

	t = 0;
	if (!s || !f)
		return (NULL);
	while (s[t])
		t++;
	res = (char *)malloc(sizeof(char) * (t + 1));
	if (res == NULL)
		return (NULL);
	t = 0;
	while (s[t])
	{
		res[t] = (*f)(s[t]);
		t++;
	}
	res[t] = '\0';
	return (res);
}
