/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:53:31 by sinlee            #+#    #+#             */
/*   Updated: 2023/07/16 04:11:51 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

size_t				ft_strlen(const char *str);
char				*ft_substr(char *s, unsigned int start, size_t len);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
int					gnl_ft_strchr(char *s, char c);
int					ft_find_newline_pos(char *str);
char				*get_next_line(int fd);
void				print_debug(char *str);
char				*ft_strjoin(char *s1, char *s2);

#endif