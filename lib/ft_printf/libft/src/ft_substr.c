/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:20:56 by sinlee            #+#    #+#             */
/*   Updated: 2023/05/05 14:54:36 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name: ft_substr
// Prototype:
// char	*ft_substr(char const *s, unsigned int start,
// size_t len);
// Parameters:
// s: The string from which to create the substring. 
// start: The start index of the substring in the string ’s’. 
// len: The maximum length of the substring.
// Return value:
// The substring.
// NULL if the allocation fails.
// External functs:
// malloc
// Description:
// Allocates (with malloc(3)) and returns a substring from the string ’s’. 
// The substring begins at index ’start’ and is of maximum size ’len’.

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;

	if (start > ft_strlen(s))
	{
		substr = malloc(sizeof(char) * 1);
		substr[0] = '\0';
	}
	else
	{
		if (len > ft_strlen(s + start))
			len = ft_strlen(s + start);
		substr = malloc(sizeof(char) * (len + 1));
		if (substr == 0)
			return (NULL);
		else
			ft_strlcpy(substr, s + start, len + 1);
	}
	return (substr);
}

// #include <stdio.h>
// int main()
// {
// 	printf("%s\n", ft_substr("123456789", 2, 5));
// }