/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgulal <zgulal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:41:34 by zgulal            #+#    #+#             */
/*   Updated: 2023/03/16 19:01:28 by zgulal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_fnl(char *str)
{
	if (!str)
		return (1);
	while (*str)
	{
		if (*str == '\n')
			return (0);
		str++;
	}
	return (1);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*result;

	if (!s)
		return (0);
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	result = malloc(sizeof(char) * len + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < len && s[i])
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = 0;
	return (result);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
	{
		s1 = malloc(sizeof(char) + 1);
		s1[0] = '\0';
	}
	new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	while (s1[i])
		new[j++] = s1[i++];
	i = 0;
	while (s2[i])
		new[j++] = s2[i++];
	free (s1);
	new[j] = 0;
	return (new);
}

char	*read_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	line = ft_substr(buffer, 0, i + 1);
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_buffer(char *buffer)
{
	char	*new_buffer;
	int		i;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (0);
	}
	if (buffer[i] == '\n')
		i++;
	new_buffer = ft_substr(buffer, i, ft_strlen(buffer) - i);
	free (buffer);
	return (new_buffer);
}
