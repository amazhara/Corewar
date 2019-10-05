/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocheresh <ocheresh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 12:17:54 by ocheresh          #+#    #+#             */
/*   Updated: 2018/10/28 12:36:08 by ocheresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	fts_bzero(void *s, size_t n)
{
	char	*res;

	res = s;
	while (n--)
	{
		*res++ = '\0';
	}
}
