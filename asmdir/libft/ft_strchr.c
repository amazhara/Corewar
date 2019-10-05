/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocheresh <ocheresh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 12:50:34 by ocheresh          #+#    #+#             */
/*   Updated: 2018/11/03 12:33:14 by ocheresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*fts_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)(&s[i]));
		i++;
	}
	if (!((unsigned char)c))
		return ((char *)(&s[i]));
	return (0);
}
