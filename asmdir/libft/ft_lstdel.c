/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocheresh <ocheresh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 20:59:19 by ocheresh          #+#    #+#             */
/*   Updated: 2018/11/07 21:24:05 by ocheresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	fts_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *t;

	if (*alst && alst && del)
	{
		t = *alst;
		while (t->next)
		{
			(*del)(t->content, t->content_size);
			t = t->next;
			free(*alst);
			*alst = t;
		}
		(*del)(t->content, t->content_size);
		free(*alst);
		*alst = NULL;
	}
}
