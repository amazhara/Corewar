/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocheresh <ocheresh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 19:11:54 by ocheresh          #+#    #+#             */
/*   Updated: 2018/11/05 20:06:22 by ocheresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	fts_putnbr(int n)
{
	long long int	temp;

	temp = n;
	if (n < 0)
		fts_putchar('-');
	if (temp < 0)
		temp = temp * (-1);
	if ((temp % 10) == 0)
		if ((temp - (temp % 10)) == 0)
			fts_putchar('0');
	if (n == 0)
		return ;
	if (((temp - (temp % 10)) / 10) != 0)
		fts_putnbr((temp - (temp % 10)) / 10);
	fts_putchar((temp % 10) + 48);
}
