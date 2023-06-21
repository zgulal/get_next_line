/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgulal <zgulal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:41:17 by zgulal            #+#    #+#             */
/*   Updated: 2023/03/15 15:02:58 by zgulal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*read_function(char *s, int fd)
{
	char	*s1;
	int		read_count;

	read_count = 1;
	s1 = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!s1)
		return (NULL);
	while (ft_fnl(s) && read_count > 0)
	{
		read_count = read(fd, s1, BUFFER_SIZE);
		if (read_count < 0)
		{
			free(s);
			free(s1);
			return (0);
		}
		s1[read_count] = '\0';
		s = ft_strjoin(s, s1);
	}
	free (s1);
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(buffer[fd]);
		return (NULL);
	}
	buffer[fd] = read_function(buffer[fd], fd);
	if (!buffer[fd])
		return (NULL);
	line = read_line(buffer[fd]);
	buffer[fd] = get_buffer(buffer[fd]);
	return (line);
}
