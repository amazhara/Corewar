/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocheresh <ocheresh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 10:03:36 by ocheresh          #+#    #+#             */
/*   Updated: 2018/11/02 11:19:39 by ocheresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*fts_memalloc(size_t size)
{
	void	*res;

	if (!(res = (void*)malloc(size)))
		return (0);
	fts_memset(res, 0, size);
	return (res);
}
