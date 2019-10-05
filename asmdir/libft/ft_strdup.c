/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocheresh <ocheresh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 09:25:29 by ocheresh          #+#    #+#             */
/*   Updated: 2018/11/03 09:43:06 by ocheresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*fts_strdup(const char *src)
{
	int		i;
	char	*result;

	i = 0;
	if (!(result = (char*)malloc(sizeof(char) * (fts_strlen(src) + 1))))
		return (NULL);
	while (src[i])
	{
		result[i] = src[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
