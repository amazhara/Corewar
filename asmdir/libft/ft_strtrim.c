/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocheresh <ocheresh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 17:58:04 by ocheresh          #+#    #+#             */
/*   Updated: 2018/11/06 20:49:02 by ocheresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*fts_strtrim(char const *s)
{
	char	*res;
	int		i;
	int		f;
	int		counter;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	counter = 0;
	f = fts_strlen(s);
	while (s[--f] && (s[f] == ' ' || s[f] == '\n' || s[f] == '\t'))
		counter++;
	if (!s[i] && ((res = (char *)malloc(sizeof(char) * (1))) != NULL))
		res[0] = '\0';
	if (s[i] && ((res = (char *)malloc(sizeof(char) * (f - i + 2))) == NULL))
		return (NULL);
	f = 0;
	while (s[i] && i < (int)(fts_strlen(s) - counter))
		res[f++] = s[i++];
	res[f] = '\0';
	return (res);
}
