/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocheresh <ocheresh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 14:58:25 by ocheresh          #+#    #+#             */
/*   Updated: 2018/11/03 16:49:38 by ocheresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*fts_strsub(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*res;

	if (!s)
		return (NULL);
	i = fts_strlen(s);
	if (((int)start + (int)len) > i)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < (int)len)
	{
		if (!(res[i] = s[start]))
			return (0);
		i++;
		start++;
	}
	res[i] = '\0';
	return (res);
}
