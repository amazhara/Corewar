/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocheresh <ocheresh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 13:44:36 by ocheresh          #+#    #+#             */
/*   Updated: 2018/11/02 18:11:17 by ocheresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*fts_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*rdest;
	unsigned char	*rsrc;

	rdest = (unsigned char *)dest;
	rsrc = (unsigned char *)src;
	while (n--)
	{
		if (*rsrc == (unsigned char)c)
		{
			*rdest++ = *rsrc++;
			return (rdest);
		}
		*rdest++ = *rsrc++;
	}
	return (NULL);
}
