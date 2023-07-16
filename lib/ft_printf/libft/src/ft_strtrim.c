/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:27:47 by sinlee            #+#    #+#             */
/*   Updated: 2023/05/05 15:11:55 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name: ft_strtrim
// Prototype: char *ft_strtrim(char const *s1, char const *set);
// Parameters:
// s1: The string to be trimmed.
// set: The reference set of characters to trim.
// Return value: The trimmed string. NULL if the allocation fails.
// External functs: malloc
// Description:
// Allocates (with malloc(3)) and returns a copy of ’s1’
// with the characters specified in ’set’ removed
// from the beginning and the end of the string.

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = 0;
	if (set == 0)
		return (ft_strdup((char *)s1));
	if (s1 != 0)
	{
		i = 0;
		j = ft_strlen(s1);
		while (s1[i] && ft_strchr(set, s1[i]))
			i++;
		while (s1[j - 1] && ft_strchr(set, s1[j - 1]) && j > i)
			j--;
		str = (char *)malloc(sizeof(char) * (j - i + 1));
		if (str)
			ft_strlcpy(str, &s1[i], j - i + 1);
	}
	return (str);
}

// test ft_strtrim function

// #include <stdio.h>

// int main(int argc, char **argv)
// {
// 	// printf("%s|\n", ft_strtrim(argv[1], argv[2]));
// 	printf("%s|", ft_strtrim("basic test", " "));
// 	return (0);
// }