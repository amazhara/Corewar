/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocheresh <ocheresh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 21:13:51 by ocheresh          #+#    #+#             */
/*   Updated: 2018/11/07 20:01:32 by ocheresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*fts_lstnew(void const *content, size_t content_size)
{
	t_list *temp;

	temp = NULL;
	temp = (t_list *)malloc(sizeof(t_list));
	if (!(temp))
		return (NULL);
	if (content)
	{
		if ((temp->content = malloc(content_size)) == NULL)
		{
			free(temp);
			return (NULL);
		}
		temp->content = fts_memcpy(temp->content, content, content_size);
	}
	else
		temp->content = NULL;
	temp->content_size = 0;
	if (content)
		temp->content_size = content_size;
	temp->next = NULL;
	return (temp);
}
