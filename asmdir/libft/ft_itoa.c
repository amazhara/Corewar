/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocheresh <ocheresh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 11:01:46 by ocheresh          #+#    #+#             */
/*   Updated: 2018/11/05 18:45:04 by ocheresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	cint(int n)
{
	long long int	temp;
	int				counter;

	counter = 0;
	temp = n;
	if (n < 0)
	{
		temp = temp * (-1);
		counter++;
	}
	while ((temp - (temp % 10)) != 0)
	{
		temp = (temp - (temp % 10)) / 10;
		counter++;
	}
	counter++;
	return (counter);
}

char		*fts_itoa(int n)
{
	long long int	temp;
	char			*res;
	int				t;

	res = (char *)malloc(sizeof(char) * (cint(n) + 1));
	if (res == NULL)
		return (NULL);
	t = cint(n);
	temp = n;
	if (temp < 0)
		temp = temp * (-1);
	res[t] = '\0';
	t--;
	if (n == 0)
		res[t] = '0';
	while (t >= 0 && n != 0)
	{
		res[t] = ((temp % 10) + 48);
		temp = (temp - (temp % 10)) / 10;
		t--;
	}
	if (n < 0)
		res[0] = '-';
	return (res);
}
