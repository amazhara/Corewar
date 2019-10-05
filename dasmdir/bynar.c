/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bynar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <ikhrypko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 18:30:36 by ocheresh          #+#    #+#             */
/*   Updated: 2019/06/21 19:54:11 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dasm.h"

char	*bynar_from_int(int t)
{
	int		k;
	int		count;
	char	*str;
	int		v;

	k = t;
	count = 1;
	v = 8;
	while ((t = (t / 2)) > 0)
		count++;
	str = (char*)malloc(sizeof(char) * (8 + 1));
	str[8] = '\0';
	count--;
	v--;
	while (count >= 0 && v >= 0)
	{
		str[v] = (k % 2) + 48;
		k = k / 2;
		count--;
		v--;
	}
	while (v >= 0)
		str[v--] = 48;
	return (str);
}

int		int_from_bynar(char **t_str)
{
	char	*str;
	int		i;
	int		k;
	int		res;

	str = *t_str;
	k = 1;
	i = fts_strlen(str);
	res = 0;
	if (i == 16)
	{
		while (i >= 8)
		{
			i--;
			if (str[i] == '1')
				res += k;
			k = k * 2;
		}
		res = res * (-1);
	}
	return (res);
}

int		minus_bynar(char **t_str)
{
	int		i;
	int		end;
	char	*str;

	i = -1;
	str = *t_str;
	end = fts_strlen(str) - 1;
	if (str[end] == '1')
		str[end] = '0';
	else
	{
		while (str[end] && str[end] == '0')
			str[end--] = '1';
		if (str[end])
			str[end] = '0';
	}
	while (str[++i])
		if (str[i] == '0')
			str[i] = '1';
		else
			str[i] = '0';
	*t_str = str;
	return (int_from_bynar(t_str));
}

void	fts_putnbr_fd2(long long int n, int fd)
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
		fts_putnbr_fd2(((temp - (temp % 10)) / 10), fd);
	fts_putchar_fd(((temp % 10) + 48), fd);
}

void	read_registr(t_dasm *file, int *count)
{
	int	temp2;

	temp2 = 0;
	read(file->fd_ent, &temp2, 1);
	fts_putchar_fd(LABEL_CHARS[17], file->fd_ext);
	fts_putnbr_fd(temp2, file->fd_ext);
	(*count)--;
	if (*count != 0)
		fts_putstr_fd(", ", file->fd_ext);
}
