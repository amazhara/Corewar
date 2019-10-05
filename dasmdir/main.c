/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <ikhrypko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 18:00:22 by ocheresh          #+#    #+#             */
/*   Updated: 2019/06/21 19:56:03 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dasm.h"

char	*fts_sjoin(char *s1, char *s2, int t)
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

int		read_file(t_dasm *file, const char *argv)
{
	file->fd_ent = open(argv, O_RDONLY);
	if (file->fd_ent == -1)
		return (ft_printf("%s\n", "Wrong file. Please check."));
	return (0);
}

int		create_file(t_dasm *file, const char *name_input_file)
{
	int	d;

	d = 0;
	while (name_input_file[d] && name_input_file[d] != '.')
		d++;
	file->temp_str = (char*)malloc(sizeof(char) * fts_strlen(name_input_file));
	file->temp_str = fts_strncpy(file->temp_str, name_input_file, (d + 1));
	file->temp_str = fts_sjoin(file->temp_str, "s", 1);
	ft_printf("%s%s\n", "Writing file: ", file->temp_str);
	file->fd_ext = open(file->temp_str,
		O_TRUNC | O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	fts_strdel(&file->temp_str);
	return (0);
}

int		w_name_comment(t_dasm *file)
{
	int		t;
	int		k;
	char	buf[3];

	k = 0;
	while ((t = read(file->fd_ent, buf, 1)) > 0 && k < 2191)
	{
		buf[t] = '\0';
		if (k > 3 && k <= 131)
			file->name_file = fts_sjoin(file->name_file, buf, 1);
		if (k > 139 && k <= 2192)
			file->str_file = fts_sjoin(file->str_file, buf, 1);
		if (k > 135 && k < 139)
			while (k < 139)
				if (read(file->fd_ent, &file->size, 1) > 0)
					k++;
		k++;
	}
	file->name_file = fts_sjoin(".name \"", file->name_file, 2);
	file->name_file = fts_sjoin(file->name_file, "\"\n", 1);
	write(file->fd_ext, file->name_file, fts_strlen(file->name_file));
	file->str_file = fts_sjoin(".comment \"", file->str_file, 2);
	file->str_file = fts_sjoin(file->str_file, "\"\n\n", 1);
	write(file->fd_ext, file->str_file, fts_strlen(file->str_file));
	return (0);
}

int		main(int argc, char const *argv[])
{
	t_dasm	file;
	int		t;

	file.str_file = "";
	file.name_file = "";
	t = 1;
	init_instruct(file.instruct);
	if (argc == 2)
		if (read_file(&file, argv[1]) == 0)
			if (create_file(&file, argv[1]) == 0)
				if (w_name_comment(&file) == 0)
					while (t != 0)
						t = instruct(&file);
	return (0);
}
