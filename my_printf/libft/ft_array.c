/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazhara <amazhara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 13:43:40 by amazhara          #+#    #+#             */
/*   Updated: 2019/04/25 13:46:17 by amazhara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*array_new(size_t amount, size_t size)
{
	t_array	*res;

	res = malloc(size);
	res->arr = malloc(sizeof(t_array) * amount);
	if (!res->arr)
		exit(0);
	res->len = 0;
	res->max = amount;
	return (res);
}

void	*array_push(void *dst, void *elem)
{
	t_array	*cast;
	t_array	**tmp;

	cast = (t_array*)dst;
	if (cast->len >= cast->max)
	{
		cast->max *= 2;
		tmp = malloc(cast->max * sizeof(t_array*));
		if (!tmp)
			exit(0);
		ft_memcpy(tmp, cast->arr, sizeof(t_array*) * cast->len);
		free(cast->arr);
		cast->arr = (void **)tmp;
	}
	return ((cast->arr[cast->len++] = elem));
}
