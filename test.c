
#include "get_next_line.h"
# include <stdio.h>
# define BUFFER_SIZE  43

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
	while (dstsize - 1 > i && src[j] != '\0' && src[j] != '\n' && j < n)
		dst[i++] = src[j++];
	if (src[j] == '\n')
		dst[i++] = '\n';
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

// void	*ft_memmove(void *dst, const void *src, size_t len)
// {
// 	char	*dst2;
// 	char	*src2;

// 	dst2 = (char *)dst;
// 	src2 = (char *)src;
// 	if (!dst && !src)
// 		return (dst);
// 	if (dst > src)
// 	{
// 		while (len > 0)
// 		{
// 			len--;
// 			dst2[len] = src2[len];
// 		}
// 	}
// 	else
// 	{
// 		while (len > 0)
// 		{
// 			*dst2++ = *src2++;
// 			len--;
// 		}
// 	}
// 	return (dst);
// }

void	build_res(char **res, char *buf, size_t *res_size, int i)
{
	char	*temp;
	int		n_place;

	if (i == 0)
	{
		if (ft_strchr(buf, '\n', BUFFER_SIZE) == NULL)
			n_place = BUFFER_SIZE;
		else
			n_place = (ft_strchr(buf, '\n', BUFFER_SIZE) - buf + 1);
		while (n_place < BUFFER_SIZE)
			buf[i++] = buf[n_place++];
		while (i < n_place)
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
		ft_strlcat(*res, buf, *res_size + 1, BUFFER_SIZE);
	}
}

// char	*start(char *buf2)
// {
// 	char	*temp;
// 	int		i;

// 	if (!*buf2)
// 		return (NULL);
// 	i = 0;
// 	while (buf2[i] != '\n' && i < BUFFER_SIZE)
// 		i++;
// 	temp = malloc(i);
// 	ft_strlcpy(temp, buf2, i);
// 	ft_memmove(buf2, buf2 + i + 1, BUFFER_SIZE - i - 1);
// 	return (temp);
// }

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
	fd = open("./t.txt", O_RDONLY);
	while (i < 1)
	{
		printf("%s", get_next_line(fd));
		i++;
	}
	close(fd);
}
