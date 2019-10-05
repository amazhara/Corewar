/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocheresh <ocheresh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 19:36:57 by ocheresh          #+#    #+#             */
/*   Updated: 2018/11/08 19:36:59 by ocheresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	fts_lstadd(t_list **alst, t_list *new)
{
	t_list *t;

	if (alst && new)
	{
		t = new;
		t->next = *alst;
		*alst = t;
	}
}
