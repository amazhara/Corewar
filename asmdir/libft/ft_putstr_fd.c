/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocheresh <ocheresh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 20:11:51 by ocheresh          #+#    #+#             */
/*   Updated: 2018/11/05 20:16:21 by ocheresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	fts_putstr_fd(char const *s, int fd)
{
	int i;

	i = 0;
	if (s)
		while (s[i])
		{
			fts_putchar_fd(s[i], fd);
			i++;
		}
}
