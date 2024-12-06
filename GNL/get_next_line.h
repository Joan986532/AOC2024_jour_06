/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:41:19 by jnauroy           #+#    #+#             */
/*   Updated: 2024/11/15 18:52:15 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 131
# endif

char	*get_next_line(int fd);
char	*ft_write_right(char *buffer);
char	*ft_write_left(char *string);
int		ft_free(char *buffer, char *temp, char *string, char *sentence);
char	*ft_read_buffer(int fd, char *buffer, char *string);
size_t	ft_strlen(char *str);
char	*ft_strchr(const char *string, int c);
char	*ft_strjoin(char *s1, char *s2);

#endif
