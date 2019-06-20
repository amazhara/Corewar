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
