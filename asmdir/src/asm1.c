/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <ikhrypko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 16:39:53 by ikhrypko          #+#    #+#             */
/*   Updated: 2019/06/21 19:21:32 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char				*fts_strndup(char *str, int k)
{
	char	*res;
	int		i;
	int		r;

	i = 0;
	r = 0;
	res = (char*)malloc(sizeof(char) * (k + 1));
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	while (str[i] && i < k && r < k)
		res[r++] = str[i++];
	res[r - 1] = '\0';
	return (res);
}

char				*fts_sjoin(char *s1, char *s2, int t)
{
	int		i;
	int		i2;
	int		k;
	int		k2;
	char	*res;

	k2 = fts_strlen(s1);
	k = k2 + fts_strlen(s2);
	res = (char *)malloc(sizeof(char) * (k + 1));
	i = -1;
	i2 = 0;
	while (++i < k2)
		res[i] = s1[i];
	while (i < k)
		res[i++] = s2[i2++];
	res[i] = '\0';
	if ((t == 1 || t == 3) && (k2 != 0))
		fts_strdel(&(s1));
	if ((t == 2 || t == 3) && (fts_strlen(s2) != 0))
		fts_strdel(&(s2));
	return (res);
}

long long int		fts_latoi(const char *nptr)
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
	return (long long int)(res * z);
}

int					check_name(int argc, const char *str, t_asm *file)
{
	int i;
	int t;

	i = 0;
	t = -1;
	if (argc != 2)
		return (ft_printf("%s\n", "Not correct number of argc."));
	while (str[i] && str[i] != '.')
		i++;
	if (str[i] == '\0' || fts_strcmp(&str[i], ".s") != 0)
		return (ft_printf("%s\n", "Bad name of argc."));
	file->name = (char*)malloc(sizeof(char) * (i + 1));
	while (++t < i)
		file->name[t] = str[t];
	file->name[t] = '\0';
	file->name = fts_sjoin(file->name, ".cor", 1);
	return (0);
}

int					read_file(t_asm *file, const char *argv)
{
	int		fd;
	int		t;
	char	buf[2];
	char	*str;
	char	*error;

	fd = open(argv, O_RDONLY);
	file->str_file = NULL;
	error = "Syntax error - unexpected end of input (Perhaps, you forgot ";
	if (fd == -1)
		return (ft_printf("%s\n", "Wrong file. Please check."));
	while ((t = read(fd, buf, 1)) > 0)
	{
		buf[t] = '\0';
		file->str_file = fts_sjoin(file->str_file, buf, 1);
	}
	t = fts_strlen(file->str_file) - 1;
	if (t < 0)
		return (ft_printf("%s\n", "Empty file."));
	str = file->str_file;
	while (str[t] && (str[t] == ' ' || str[t] == '\t'))
		t--;
	if (str[t] != '\n')
		return (ft_printf("%s%s\n", error, "to end with a newline ?)"));
	return (0);
}
