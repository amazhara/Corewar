/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocheresh <ocheresh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 16:53:40 by ocheresh          #+#    #+#             */
/*   Updated: 2018/11/01 17:01:44 by ocheresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	fts_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
