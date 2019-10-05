/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocheresh <ocheresh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 15:49:27 by ocheresh          #+#    #+#             */
/*   Updated: 2018/11/03 16:51:31 by ocheresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*fts_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		i2;
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	i = fts_strlen(s1) + fts_strlen(s2);
	res = (char *)malloc(sizeof(char) * (i + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	i2 = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[i2])
		res[i++] = s2[i2++];
	res[i] = '\0';
	return (res);
}
