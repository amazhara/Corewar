/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocheresh <ocheresh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 14:22:00 by ocheresh          #+#    #+#             */
/*   Updated: 2018/11/10 14:22:02 by ocheresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	fts_lstadd_end(t_list **begin_list, t_list *new)
{
	t_list	*temp;

	if (begin_list && new && *begin_list)
	{
		temp = *begin_list;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}
