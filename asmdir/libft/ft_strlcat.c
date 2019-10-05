/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocheresh <ocheresh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 11:53:13 by ocheresh          #+#    #+#             */
/*   Updated: 2018/11/03 11:59:57 by ocheresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	fts_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t t;

	i = 0;
	t = 0;
	while (dst[i] && i < size)
		i++;
	if (i == size)
	{
		while (src[t])
			t++;
		return (i + t);
	}
	while ((i + t) < size && src[t])
	{
		dst[i + t] = src[t];
		t++;
	}
	if ((i + t) == size)
		t = t - 1;
	dst[i + t] = '\0';
	t = 0;
	while (src[t])
		t++;
	return (i + t);
}
