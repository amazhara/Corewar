/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocheresh <ocheresh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 11:15:50 by ocheresh          #+#    #+#             */
/*   Updated: 2018/10/28 12:35:39 by ocheresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*fts_memset(void *b, int c, size_t len)
{
	char	*res;

	res = b;
	while (len--)
	{
		*res++ = (unsigned char)c;
	}
	return (b);
}
