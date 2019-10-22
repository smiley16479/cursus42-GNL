/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adtheus <adtheus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:32:17 by adtheus           #+#    #+#             */
/*   Updated: 2019/10/22 19:38:50 by adtheus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 32

int recover_old_data(int fd, char **line)
{

	return (0);
}

int GNL_pos(char *str, size_t len)
{
	size_t n;

	n = 0;
	while (n < len && (str[n] != '\n' || str[n] != EOF))
		n++;
	return (str[n] == '\n' ? n : 0);
}

char	**alloc_line_data(size_t len, char *str, char **line, int fd)
{
	static	size_t	s_len;
	size_t			i;
	size_t			l;
	char			*tmp_str;

	// printf("%d", *tmp_str);
	while ((l = read(fd, str, BUFFER_SIZE)))
	{
		()
		if (!s_len)
			free(*line);	
		s_len += GNL_pos(str, len);
		if (!(tmp_str = malloc(sizeof(*tmp_str) * s_len + 1)))
			return (NULL);
		i = 0;
		while (*line[i])
		{
			tmp_str[i] = *line[i];
			i++;
		}
		while (len + i < s_len)
		{
			tmp_str[i] = *(str++);
			i++;
		}	
	}	
	*line = tmp_str;
	return (tmp_str);
}

int get_next_line(int fd, char **line)
{
	size_t		n;
	size_t		l;
	static char	str[BUFFER_SIZE];

	while((l = read(fd, str, BUFFER_SIZE)) && (*line = alloc(l, str, line, fd)) /*&& write(1, str, BUFFER_SIZE)*/)
	{
		n = 0;
		while (str[n] != '\n')
		{
			str[n];
			n++;
		}
		return (n);
	}

	return (0);
}