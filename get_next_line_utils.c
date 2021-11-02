/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaegan <smaegan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:49:39 by smaegan           #+#    #+#             */
/*   Updated: 2021/11/02 20:19:35 by smaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c, int n)
{
	int		i;

	c = c % 128;
	i = 0;
	while (s[i] != c && s[i] != '\0' && i < n)
		i++;
	if (s[i] == c)
		return ((char *)&s[i]);
	else
		return ((void *)0);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (src == NULL || dst == NULL)
		return (0);
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

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	size;
	size_t	dstsize2;

	j = 0;
	i = 0;
	while (dst[i] != '\0' && i < dstsize)
		i++;
	size = i;
	dstsize2 = i;
	while (src[j] != '\0')
		j++;
	size += j;
	if (i == dstsize)
		return (size);
	j = 0;
	while (dstsize - 1 > i && src[j] != '\0' && j < n)
		dst[i++] = src[j++];
	if (dstsize != 0 && dstsize2 <= dstsize)
		dst[i] = '\0';
	return (size);
}

void	change_res_size(char *buf, size_t *res_size)
{
	if (*buf == '\0')
	{
		*res_size = 0;
		return ;
	}
	if (ft_strchr(buf, '\n', BUFFER_SIZE))
		*res_size += ft_strchr(buf, '\n', BUFFER_SIZE) - buf + 1;
	else
		*res_size += BUFFER_SIZE;
}

// char	*ft_strchr(const char *s, int c, int n)
// {
// 	int		i;

// 	c = c % 128;
// 	i = 0;
// 	while (s[i] != c && s[i] != '\0' && i < n)
// 		i++;
// 	if (s[i] == c)
// 		return ((char *)&s[i]);
// 	else
// 		return ((void *)0);
// }

// size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
// {
// 	size_t	i;

// 	if (src == NULL || dst == NULL)
// 		return (0);
// 	i = 0;
// 	while (src[i] != '\0')
// 		i++;
// 	while (dstsize > 1 && *src != '\0')
// 	{
// 		*dst = *src;
// 		dst++;
// 		src++;
// 		dstsize--;
// 	}
// 	if (dstsize != 0)
// 	{
// 		*dst = '\0';
// 	}
// 	return (i);
// }

// size_t	ft_strlcat(char *dst, const char *src, size_t dstsize, size_t n)
// {
// 	size_t	i;
// 	size_t	j;
// 	size_t	size;
// 	size_t	dstsize2;

// 	j = 0;
// 	i = 0;
// 	while (dst[i] != '\0' && i < dstsize)
// 		i++;
// 	size = i;
// 	dstsize2 = i;
// 	while (src[j] != '\0')
// 		j++;
// 	size += j;
// 	if (i == dstsize)
// 		return (size);
// 	j = 0;
// 	while (dstsize - 1 > i && src[j] != '\0' && src[j] != '\n' && j < n)
// 		dst[i++] = src[j++];
// 	if (src[j] == '\n')
// 		dst[i++] = '\n';
// 	if (dstsize != 0 && dstsize2 <= dstsize)
// 		dst[i] = '\0';
// 	return (size);
// }

// void	change_res_size(char *buf, size_t *res_size)
// {
// 	if (*buf == '\0')
// 	{
// 		*res_size = 0;
// 		return ;
// 	}
// 	if (ft_strchr(buf, '\n', BUFFER_SIZE))
// 		*res_size += ft_strchr(buf, '\n', BUFFER_SIZE) - buf + 1;
// 	else
// 		*res_size += BUFFER_SIZE;
// }

// void	build_res(char **res, char *buf, size_t *res_size, int i)
// {
// 	char	*temp;
// 	int		n_place;

// 	if (i == 0)
// 	{
// 		if (ft_strchr(buf, '\n', BUFFER_SIZE) == NULL)
// 			n_place = BUFFER_SIZE;
// 		else
// 			n_place = (ft_strchr(buf, '\n', BUFFER_SIZE) - buf + 1);
// 		while (n_place < BUFFER_SIZE)
// 			buf[i++] = buf[n_place++];
// 		while (i < n_place && *buf != '\0')
// 			buf[i++] = '\0';
// 		change_res_size(buf, res_size);
// 	}
// 	else
// 	{
// 		temp = *res;
// 		*res = malloc(*res_size + 1);
// 		ft_strlcpy(*res, temp, *res_size + 1);
// 		if (temp != NULL)
// 			free(temp);
// 		ft_strlcat(*res, buf, *res_size + 1, BUFFER_SIZE);
// 	}
// }

void	build_res(char **res, char *buf, size_t *res_size, int i)
{
	char	*temp;
	int		n_place;

	if (ft_strchr(buf, '\n', BUFFER_SIZE) == NULL)
		n_place = BUFFER_SIZE;
	else
		n_place = (ft_strchr(buf, '\n', BUFFER_SIZE) - buf + 1);
	if (i == 0)
	{
		while (n_place < BUFFER_SIZE)
			buf[i++] = buf[n_place++];
		while (i < n_place && *buf != '\0')
			buf[i++] = '\0';
		change_res_size(buf, res_size);
		if (*res_size != 0)
			build_res(res, buf, res_size, 1);
	}
	else
	{
		temp = *res;
		*res = malloc(*res_size + 1);
		ft_strlcpy(*res, temp, *res_size + 1);
		if (temp != NULL)
			free(temp);
		ft_strlcat(*res, buf, *res_size + 1, n_place);
	}
}