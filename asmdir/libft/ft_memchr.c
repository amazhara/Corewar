/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocheresh <ocheresh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 14:29:28 by ocheresh          #+#    #+#             */
/*   Updated: 2018/11/03 09:18:11 by ocheresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*fts_memchr(const void *s, int c, size_t n)
{
	unsigned char	*rs;

	rs = (unsigned char *)s;
	while (n--)
	{
		if (*rs == (unsigned char)c)
			return (rs);
		rs++;
	}
	return (NULL);
}
