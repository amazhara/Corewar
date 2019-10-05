/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocheresh <ocheresh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 11:02:28 by ocheresh          #+#    #+#             */
/*   Updated: 2018/11/06 18:23:04 by ocheresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*fts_strcat(char *dest, const char *src)
{
	int i;
	int t;

	t = fts_strlen(dest);
	i = 0;
	while (src[i])
	{
		dest[t] = src[i];
		t++;
		i++;
	}
	dest[t] = '\0';
	return (dest);
}
