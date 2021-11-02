/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaegan <smaegan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:36:20 by smaegan           #+#    #+#             */
/*   Updated: 2021/11/02 20:07:01 by smaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
//static size_t	BUFFER_SIZE;

char	*get_next_line(int fd);

//utils
char	*ft_strchr(const char *s, int c, int n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize, size_t n);
void	build_res(char **res, char *buf, size_t *res_size, int i);
void	change_res_size(char *buf, size_t *res_size);

#endif
