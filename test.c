
#include "get_next_line.h"
# include <stdio.h>
# define BUFFER_SIZE  1

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
	{
		printf("%c\n", src[j]);
		dst[i++] = src[j++];
	}
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

void	ft_bzero(void *s, size_t n)
{
	char	*c;

	c = s;
	while (n > 0)
	{
		*c++ = 0;
		n--;
	}
}

// char	*get_next_line(int fd)
// {
// 	static char	buf[BUFFER_SIZE];
// 	char		*temp;
// 	char		*res;
// 	size_t		res_size;
// 	int			bytes_read;

// 	res = NULL;
// 	temp = malloc(BUFFER_SIZE + 1);
// 	res_size = 0;
// 	build_res(&res, buf, &res_size, 0);
// 	ft_strlcpy(temp, buf, BUFFER_SIZE + 1);
// 	printf("-%s-\n\n--%s", buf, temp);
// 	change_res_size(temp, &res_size);
// 	if (res_size != 0)
// 		build_res(&res, temp, &res_size, 1);
// 	while (ft_strchr(temp, '\n', BUFFER_SIZE) == NULL)
// 	{
// 		ft_bzero(buf, BUFFER_SIZE);
// 		ft_bzero(temp, BUFFER_SIZE);
// 		bytes_read = read(fd, buf, BUFFER_SIZE);
// 		ft_strlcpy(temp, buf, BUFFER_SIZE + 1);
// 		if (bytes_read == 0 || bytes_read == -1)
// 			break ;
// 		change_res_size(temp, &res_size);
// 		build_res(&res, temp, &res_size, 1);
// 		if (ft_strchr(temp, '\n', BUFFER_SIZE))
// 			break ;
// 	}
// 	return (res);
// }

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE];
	char		*res;
	size_t		res_size;
	int			bytes_read;

	res = NULL;
	res_size = 0;
	build_res(&res, buf, &res_size, 0);
	change_res_size(buf, &res_size);
	if (res_size != 0)
		build_res(&res, buf, &res_size, 1);
	while (ft_strchr(buf, '\n', BUFFER_SIZE) == NULL)
	{
		ft_bzero(buf, BUFFER_SIZE);
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == 0 || bytes_read == -1)
			break ;
		change_res_size(buf, &res_size);
		build_res(&res, buf, &res_size, 1);
		if (ft_strchr(buf, '\n', BUFFER_SIZE))
			break ;
	}
	return (res);
}

int	main(int argc, char **argv)
{
	int		i;
	int		fd;
	char	*s1;

	i = 1;
	if (i > argc)
		return (-1);
	i = 0;
	fd = open("./t.txt", O_RDONLY);
	while (i < 3)
	{
		s1 = get_next_line(fd);
		printf("%d) %s", i, s1);
		free(s1);
 		i++;
	}
	close(fd);
}
