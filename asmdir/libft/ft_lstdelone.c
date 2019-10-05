/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocheresh <ocheresh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 20:09:44 by ocheresh          #+#    #+#             */
/*   Updated: 2018/11/07 20:48:53 by ocheresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	fts_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (alst && del && *alst)
	{
		(*del)(alst[0]->content, alst[0]->content_size);
		free(*alst);
		*alst = NULL;
	}
}
