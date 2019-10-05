/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <ikhrypko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 17:47:05 by ikhrypko          #+#    #+#             */
/*   Updated: 2019/06/21 18:56:39 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_read(int fd, void *buff, size_t size)
{
	ssize_t read_size;
	ssize_t res_size;

	res_size = 0;
	while (size)
	{
		read_size = read(fd, buff + res_size, size);
		if (read_size < 1)
			return (!read_size ? res_size : -1);
		res_size += read_size;
		size -= res_size;
	}
	return (res_size);
}
