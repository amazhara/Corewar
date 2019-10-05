/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocheresh <ocheresh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 14:30:25 by ocheresh          #+#    #+#             */
/*   Updated: 2018/11/10 14:31:11 by ocheresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	fts_listsize(t_list *lst)
{
	int		i;
	t_list	*t;

	i = 0;
	if (lst)
	{
		t = lst;
		i = 1;
		while (t->next)
		{
			i++;
			t = t->next;
		}
	}
	return (i);
}
