/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocheresh <ocheresh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 19:51:12 by ocheresh          #+#    #+#             */
/*   Updated: 2018/11/08 19:51:14 by ocheresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*fts_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *res;
	t_list *t;

	res = NULL;
	t = NULL;
	if (lst && f)
	{
		if (!(res = (*f)(lst)))
		{
			free(res);
			return (NULL);
		}
		t = res;
		while (lst->next)
		{
			if (!(res->next = (*f)(lst->next)))
			{
				free(res);
				return (NULL);
			}
			lst = lst->next;
			res = res->next;
		}
	}
	return (t);
}
