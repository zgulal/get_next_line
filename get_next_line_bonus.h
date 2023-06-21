/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgulal <zgulal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:40:59 by zgulal            #+#    #+#             */
/*   Updated: 2023/03/07 17:00:46 by zgulal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

int		ft_fnl(char *str);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*read_function(char *s, int fd);
char	*read_line(char *buffer);
char	*get_buffer(char *buffer);
char	*get_next_line(int fd);
char	*ft_substr(const char *s, unsigned int start, size_t len);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

#endif