/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocheresh <ocheresh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 13:20:38 by ocheresh          #+#    #+#             */
/*   Updated: 2018/11/03 12:59:34 by ocheresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*fts_strstr(const char *str, const char *str2)
{
	int		i;
	int		k;
	char	*res;

	i = 0;
	k = 0;
	if (fts_strlen((char *)str2) == 0)
		return ((char *)&str[i]);
	res = 0;
	while (str[i])
	{
		if (str[i] == str2[k])
		{
			res = (char *)&str[i];
			while (str2[k])
				if (str[i++] != str2[k++])
					res = 0;
			if (str2[k] == '\0' && res != 0)
				return (res);
			i = i - k;
			k = 0;
		}
		i++;
	}
	return (res);
}
