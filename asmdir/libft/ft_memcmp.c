/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocheresh <ocheresh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 15:36:30 by ocheresh          #+#    #+#             */
/*   Updated: 2018/11/03 09:26:11 by ocheresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	fts_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*rs1;
	unsigned char	*rs2;

	rs1 = (unsigned char *)s1;
	rs2 = (unsigned char *)s2;
	while (n--)
	{
		if (*rs1 > *rs2)
			return (*rs1 - *rs2);
		else if (*rs1 < *rs2)
			return (*rs1 - *rs2);
		rs2++;
		rs1++;
	}
	return (0);
}
