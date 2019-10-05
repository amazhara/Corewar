/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocheresh <ocheresh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 20:17:39 by ocheresh          #+#    #+#             */
/*   Updated: 2018/11/05 20:27:15 by ocheresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	fts_putendl_fd(char const *s, int fd)
{
	fts_putstr_fd(s, fd);
	fts_putchar_fd('\n', fd);
}
