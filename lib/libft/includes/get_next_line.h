/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:53:31 by sinlee            #+#    #+#             */
/*   Updated: 2023/07/17 10:25:19 by sinlee           ###   ########.fr       */
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

size_t				gnl_strlen(const char *str);
char				*gnl_substr(char *s, unsigned int start, size_t len);
size_t				gnl_strlcpy(char *dest, const char *src, size_t size);
int					gnl_strchr(char *s, char c);
char				*get_next_line(int fd);
char				*gnl_strjoin(char *s1, char *s2);

#endif