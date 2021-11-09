/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaegan <smaegan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:14:26 by smaegan           #+#    #+#             */
/*   Updated: 2021/11/09 19:58:27 by smaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	last[BUFFER_SIZE];
	char		*buf;
	char		*str;
	size_t		len;
	int			red;

	red = -2;
	len = 0;
	str = NULL;
	buf = malloc(BUFFER_SIZE + 1);
	if (buf == NULL)
		return (NULL);
	ft_strlcpy(buf, last, BUFFER_SIZE);
	while (ft_strchr(buf, '\n') == NULL)
	{
		red = read(fd, buf, BUFFER_SIZE);
		buf[red] = '\0';
		if (red <= 0)
			break ;
		build_res(&str, buf);
	}
	if (ft_strchr(buf, '\n') != NULL)
		make_last(last, buf);
	free(buf);
	return (str);
}
