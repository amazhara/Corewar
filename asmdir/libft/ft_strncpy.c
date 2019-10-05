/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocheresh <ocheresh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 10:36:58 by ocheresh          #+#    #+#             */
/*   Updated: 2018/11/03 10:41:09 by ocheresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*fts_strncpy(char *dest, const char *src, size_t n)
{
	size_t	t;

	t = 0;
	while (t < n && src[t])
	{
		dest[t] = src[t];
		t++;
	}
	while (t < n)
	{
		dest[t] = '\0';
		t++;
	}
	return (dest);
}
