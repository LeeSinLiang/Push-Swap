/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:08:15 by sinlee            #+#    #+#             */
/*   Updated: 2023/05/05 14:16:15 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name: ft_strjoin
// Prototype: char: *ft_strjoin(char const *s1, char const *s2);
// Parameters:
// s1: The prefix string. s2: The suffix string.
// Return value: The new string. NULL if the allocation fails.
// External functs: malloc
// Description:
// Allocates (with malloc(3)) and returns a new string,
// which is the result of the concatenation of ’s1’ and ’s2’.

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;

	i = -1;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (0);
	while (s1[++i])
		str[i] = s1[i];
	i = -1;
	while (s2[++i])
		str[ft_strlen(s1) + i] = s2[i];
	str[ft_strlen(s1) + i] = '\0';
	return (str);
}

// test ft_strjoin function. check strlcat const
// #include <stdio.h>

// int main()
// {
// 	char *s1 = "tripouille";
// 	char *s2 = "42";
// 	char *s3 = ft_strjoin("", "42");
// 	printf("%s|\n", s3);
// 	printf("%d", strcmp(s3, "42"));
// 	// printf("%s|\n", strjoin("", "42"));
// 	return (0);
// }