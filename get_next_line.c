/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaegan <smaegan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:17:35 by smaegan           #+#    #+#             */
/*   Updated: 2021/10/30 19:31:34 by smaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE];
	char		*temp;
	char		*res;
	size_t		res_size;
	int			bytes_read;

	res = NULL;
	res_size = 0;
	temp = malloc(BUFFER_SIZE + 1);
	build_res(&res, buf, &res_size, 0);
	while (ft_strchr(buf, '\n', BUFFER_SIZE) == NULL)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		ft_strlcpy(temp, buf, BUFFER_SIZE + 1);
		if (bytes_read == 0 || bytes_read == -1)
			break ;
		change_res_size(temp, &res_size);
		build_res(&res, temp, &res_size, 1);
		if (ft_strchr(buf, '\n', BUFFER_SIZE))
			break ;
	}
	free(temp);
	return (res);
}

int	main(int argc, char **argv)
{
	int	i;
	int	fd;

	i = 1;
	if (i > argc)
		return (-1);
	i = 0;
	fd = 100;//open("./t.txt", O_RDONLY);
	while (i < 4)
	{
		printf("%s", get_next_line(fd));
		i++;
	}
	close(fd);
}
