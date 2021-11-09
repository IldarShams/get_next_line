/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaegan <smaegan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:13:31 by smaegan           #+#    #+#             */
/*   Updated: 2021/11/09 20:39:27 by smaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	c = c % 128;
	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	if (s[i] == c)
		return ((char *)&s[i]);
	else
		return ((void *)0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size1;
	int		size2;
	char	*rets;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	size1 = 0;
	size2 = 0;
	while (s1[size1] != '\0')
		size1++;
	while (s2[size2] != '\0' && *(s2 + size2 - 1) != '\n')
		size2++;
	rets = malloc(size1 + size2 + 1);
	if (rets == NULL)
		return (NULL);
	while (*s1 != '\0')
		rets[i++] = *s1++;
	while (*s2 != '\0' && *(s2 - 1) != '\n')
		rets[i++] = *s2++;
	rets[i] = '\0';
	return (rets);
}

void	build_res(char **res, char *buf)
{
	char	*temp;

	if (*res == NULL)
	{
		*res = malloc(1);
		*res[0] = '\0';
	}
	temp = ft_strjoin(*res, buf);
	free(*res);
	*res = temp;
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
		i++;
	while (dstsize > 1 && *src != '\0')
	{
		*dst = *src;
		dst++;
		src++;
		dstsize--;
	}
	if (dstsize != 0)
	{
		*dst = '\0';
	}
	return (i);
}

void	make_last(char l[BUFFER_SIZE], char *buf)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_strchr(buf, '\n') == NULL)
	{
		while (i < BUFFER_SIZE)
			l[i++] = '\0';
		return ;
	}
	while (buf[j] != '\n' && buf[j] != '\0' && j < BUFFER_SIZE)
		j++;
	j++;
	while (j < BUFFER_SIZE)
		l[i++] = buf[j++];
	while (i < BUFFER_SIZE)
		l[i++] = '\0';
}
