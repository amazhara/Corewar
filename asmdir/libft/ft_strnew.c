/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocheresh <ocheresh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 10:58:17 by ocheresh          #+#    #+#             */
/*   Updated: 2018/11/03 15:53:07 by ocheresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*fts_strnew(size_t size)
{
	char	*res;
	int		i;

	i = 0;
	res = (char *)malloc(sizeof(char) * (size + 1));
	if (res == NULL)
		return (NULL);
	while (i <= (int)size)
	{
		res[i] = '\0';
		i++;
	}
	return (res);
}
