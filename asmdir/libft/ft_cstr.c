/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocheresh <ocheresh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 12:00:00 by ocheresh          #+#    #+#             */
/*   Updated: 2018/11/17 12:00:05 by ocheresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	fts_cstr(char const *s, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			counter++;
		while (s[i] != c && s[i])
			i++;
	}
	return (counter);
}
