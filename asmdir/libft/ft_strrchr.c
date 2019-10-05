/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocheresh <ocheresh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 13:07:27 by ocheresh          #+#    #+#             */
/*   Updated: 2018/11/03 12:35:55 by ocheresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*fts_strrchr(const char *s, int c)
{
	int		i;
	char	*res;

	res = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			res = (char *)&s[i];
		i++;
	}
	if (!((unsigned char)c))
		return ((char *)&s[i]);
	return (res);
}
