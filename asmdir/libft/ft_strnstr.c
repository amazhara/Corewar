/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocheresh <ocheresh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 15:06:00 by ocheresh          #+#    #+#             */
/*   Updated: 2018/11/06 19:01:28 by ocheresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*fts_strnstr(const char *str, const char *str2, size_t len)
{
	size_t	i;
	size_t	k;
	char	*res;

	i = 0;
	k = 0;
	if (fts_strlen((char *)str2) == 0)
		return ((char *)&str[i]);
	while (str[i] && i < len)
	{
		res = 0;
		if (str[i] == str2[k])
		{
			res = (char *)&str[i];
			while (str2[k] && i < len)
				if (str[i++] != str2[k++])
					res = 0;
			if (str2[k] == '\0' && res != 0)
				return (res);
			i = i - k;
			k = 0;
		}
		i++;
	}
	return (NULL);
}
