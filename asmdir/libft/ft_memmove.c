/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocheresh <ocheresh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 14:00:39 by ocheresh          #+#    #+#             */
/*   Updated: 2018/11/03 09:15:24 by ocheresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*fts_memmove(void *dest, const void *src, size_t n)
{
	char	*rdest;
	char	*rsrc;
	size_t	i;

	i = -1;
	rdest = (char *)dest;
	rsrc = (char *)src;
	if (src < dest)
		while ((int)(--n) >= 0)
			*(rdest + n) = *(rsrc + n);
	else
		while (++i < n)
			*(rdest + i) = *(rsrc + i);
	return (dest);
}
