/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocheresh <ocheresh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 12:42:21 by ocheresh          #+#    #+#             */
/*   Updated: 2018/11/06 18:14:16 by ocheresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*fts_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*rdest;
	const char		*rsrc;

	rdest = dest;
	rsrc = src;
	while (n--)
	{
		*rdest++ = *rsrc++;
	}
	return (dest);
}
