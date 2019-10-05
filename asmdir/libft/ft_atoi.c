/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <ikhrypko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 15:55:05 by ocheresh          #+#    #+#             */
/*   Updated: 2019/06/21 16:54:51 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	fts_atoi(const char *nptr)
{
	int					i;
	unsigned long int	res;
	int					z;

	i = 0;
	z = 1;
	res = 0;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\v' ||
		nptr[i] == '\f' || nptr[i] == '\r' || nptr[i] == '\n')
		i++;
	if (nptr[i] == '-')
		z = -1;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = (res * 10) + (nptr[i] - '0');
		if (res >= 9223372036854775807 && z == 1)
			return (-1);
		if (res > 9223372036854775807 && z == -1)
			return (0);
		i++;
	}
	return (int)(res * z);
}
