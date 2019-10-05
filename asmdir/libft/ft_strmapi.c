/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocheresh <ocheresh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 13:25:28 by ocheresh          #+#    #+#             */
/*   Updated: 2018/11/03 16:42:07 by ocheresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*fts_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	t;

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
		if (!(res[t] = (*f)(t, s[t])))
			return (NULL);
		t++;
	}
	res[t] = '\0';
	return (res);
}
