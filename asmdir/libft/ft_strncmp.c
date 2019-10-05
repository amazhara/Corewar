/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocheresh <ocheresh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 15:32:57 by ocheresh          #+#    #+#             */
/*   Updated: 2018/11/06 19:12:08 by ocheresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	fts_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	while ((unsigned char)s1[i] && (unsigned char)s2[i] && i < n)
	{
		if ((unsigned char)s1[i] > (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if ((unsigned char)s1[i] < (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if ((unsigned char)s1[i] && (unsigned char)s2[i] == '\0' && i != n)
		return (1);
	else if ((unsigned char)s2[i] && (unsigned char)s1[i] == '\0' && i != n)
		return (-1);
	return (0);
}
