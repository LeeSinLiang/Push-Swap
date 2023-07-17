/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 11:43:22 by codespace         #+#    #+#             */
/*   Updated: 2023/07/17 10:08:41 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	gnl_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (str == 0)
		return (0);
	while (*str++)
		len++;
	return (len);
}

int	gnl_strchr(char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

size_t	gnl_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = gnl_strlen(src);
	if (size == 0)
		return (src_len);
	i = 0;
	while (i < size - 1 && src[i])
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (src_len);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;

	i = -1;
	str = malloc(sizeof(char) * (gnl_strlen(s1) + gnl_strlen(s2) + 1));
	if (!str)
		return (0);
	if (s1)
	{
		while (s1[++i])
			str[i] = s1[i];
		i = -1;
	}
	if (s2)
	{
		while (s2[++i])
			str[gnl_strlen(s1) + i] = s2[i];
	}
	free(s2);
	str[gnl_strlen(s1) + i] = '\0';
	free(s1);
	return (str);
}

char	*gnl_substr(char *s, unsigned int start, size_t len)
{
	char	*substr;

	if (start > gnl_strlen(s))
	{
		substr = malloc(sizeof(char) * 1);
		substr[0] = '\0';
	}
	else
	{
		if (len > gnl_strlen(s + start))
			len = gnl_strlen(s + start);
		if (len == 0)
			return (NULL);
		substr = malloc(sizeof(char) * (len + 1));
		if (substr == 0)
			return (NULL);
		else
			gnl_strlcpy(substr, s + start, len + 1);
	}
	return (substr);
}
