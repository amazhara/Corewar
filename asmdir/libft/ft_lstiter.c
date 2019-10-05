/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocheresh <ocheresh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 19:44:06 by ocheresh          #+#    #+#             */
/*   Updated: 2018/11/08 19:44:08 by ocheresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	fts_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list *t;

	if (lst && f)
	{
		t = lst;
		while (t->next)
		{
			(*f)(t);
			t = t->next;
		}
		(*f)(t);
	}
}
