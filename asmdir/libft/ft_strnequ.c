/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocheresh <ocheresh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 13:51:41 by ocheresh          #+#    #+#             */
/*   Updated: 2018/11/03 16:47:01 by ocheresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	fts_strnequ(char const *s1, char const *s2, size_t n)
{
	int i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (i < (int)n)
	{
		if ((!s1[i] && !s2[i]) && (i > 0))
			return (1);
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}
