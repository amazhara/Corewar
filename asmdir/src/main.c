/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <ikhrypko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 18:00:22 by ocheresh          #+#    #+#             */
/*   Updated: 2019/06/21 19:25:27 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void				join_size(t_asm *file)
{
	file->size = cw_invert_endian(file->size);
	write(file->fd, &file->size, sizeof(int));
}

void				join_name(t_asm *file, t_header *head)
{
	int i;

	i = fts_strlen(head->prog_name);
	write(file->fd, &head->prog_name[0], i);
	while (i != PROG_NAME_LENGTH)
	{
		write(file->fd, "\0", 1);
		i++;
	}
	write(file->fd, "\0\0\0\0", 4);
}

void				all_to_code(t_asm *file, t_header *head, int i)
{
	file->fd = open(file->name, O_TRUNC | O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	file->tp = cw_invert_endian(COREWAR_EXEC_MAGIC);
	write(file->fd, &file->tp, sizeof(file->tp));
	join_name(file, head);
	join_size(file);
	join_comment(file, head);
	byte_code(file, i);
	ft_printf("%s%s\n", "Writing output program to ", file->name);
}

int					main(int argc, char const *argv[])
{
	t_asm		file;
	t_header	head;
	int			i;
	int			fd;

	file.numb_str = 1;
	file.numb_colum = 0;
	file.indx = 0;
	file.size = 0;
	file.result = NULL;
	file.temp = NULL;
	fd = 0;
	init_instruct(file.instruct);
	init_tabl(file.tabl);
	i = 0;
	if (check_name(argc, argv[1], &file) == 0)
		if (read_file(&file, argv[1]) == 0)
			if (find_name_comment(&file, &head, &i) == 0)
				if (fin_check_lab(&file, &i) == 0)
					if (check_any_instruct(&file.str_file[i]) == 0)
						all_to_code(&file, &head, i);
	return (0);
}
