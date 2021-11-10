/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaegan <smaegan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:14:26 by smaegan           #+#    #+#             */
/*   Updated: 2021/11/10 17:21:16 by smaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	last[255][BUFFER_SIZE];
	char		*buf;
	char		*str;
	int			red;

	str = NULL;
	if (fd < 0 || fd > 255)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (buf == NULL)
		return (NULL);
	ft_strlcpy(buf, last[fd], BUFFER_SIZE);
	if (*buf != '\0')
		build_res(&str, buf);
	while (ft_strchr(buf, '\n') == NULL)
	{
		red = read(fd, buf, BUFFER_SIZE);
		buf[red] = '\0';
		build_res(&str, buf);
		if (red <= 0)
			break ;
	}
	make_last(last[fd], buf);
	free(buf);
	return (str);
}
