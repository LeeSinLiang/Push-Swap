/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 11:43:18 by codespace         #+#    #+#             */
/*   Updated: 2023/07/16 04:11:59 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*extract_and_ret(char *str, int mode, char *remain_str)
{
	int		index;
	char	*extract;

	index = gnl_ft_strchr(str, '\n');
	if (index != -1 && index != BUFFER_SIZE - 1)
	{
		if (mode == 1 || mode == 2)
		{
			extract = ft_substr(str, index + 1, ft_strlen(str) + 1);
			if (remain_str != NULL && ft_strlen(remain_str) > 0 && mode == 1)
				extract = ft_strjoin(remain_str, extract);
			free(remain_str);
			return (extract);
		}
		else
			return (ft_substr(str, 0, index + 1));
	}
	else if (ft_strlen(str) > 0 && mode == 0)
		return (ft_substr(str, 0, ft_strlen(str) + 1));
	else
	{
		if (mode == 2)
			free(str);
		return (NULL);
	}
}

char	*get_next_line(int fd)
{
	int			read_size;
	char		*buffer;
	static char	*remain[1024];
	char		*buff_all;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (false);
	read_size = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	buff_all = extract_and_ret(remain[fd], 0, remain[fd]);
	remain[fd] = extract_and_ret(remain[fd], 2, remain[fd]);
	while (gnl_ft_strchr(buff_all, '\n') == -1 && read_size != 0)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size <= 0)
			break ;
		buffer[read_size] = '\0';
		buff_all = ft_strjoin(buff_all, extract_and_ret(buffer, 0, remain[fd]));
		remain[fd] = extract_and_ret(buffer, 1, remain[fd]);
	}
	free(buffer);
	return (buff_all);
}
