/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocheresh <ocheresh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 20:28:31 by ocheresh          #+#    #+#             */
/*   Updated: 2018/11/05 20:36:08 by ocheresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	fts_putnbr_fd(int n, int fd)
{
	long long int	temp;

	temp = n;
	if (n < 0)
		fts_putchar_fd('-', fd);
	if (temp < 0)
		temp = temp * (-1);
	if ((temp % 10) == 0)
		if ((temp - (temp % 10)) == 0)
			fts_putchar_fd('0', fd);
	if (n == 0)
		return ;
	if (((temp - (temp % 10)) / 10) != 0)
		fts_putnbr_fd(((temp - (temp % 10)) / 10), fd);
	fts_putchar_fd(((temp % 10) + 48), fd);
}
