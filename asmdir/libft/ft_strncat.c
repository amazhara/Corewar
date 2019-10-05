/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocheresh <ocheresh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 11:37:00 by ocheresh          #+#    #+#             */
/*   Updated: 2018/11/03 10:45:17 by ocheresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*fts_strncat(char *dest, const char *src, size_t n)
{
	size_t i;
	size_t t;

	i = 0;
	t = 0;
	while (dest[i])
		i++;
	while (t < n && src[t])
	{
		dest[i + t] = src[t];
		t++;
	}
	dest[i + t] = '\0';
	return (dest);
}
