/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:15:38 by sinlee            #+#    #+#             */
/*   Updated: 2023/05/03 18:26:59 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// implementation of strrchr function

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;

	ptr = 0;
	if (c == 0)
		return ((char *)s + ft_strlen(s));
	while (*s)
	{
		if (*s == (char)c)
			ptr = (char *)s;
		s++;
	}
	return (ptr);
}

// test ft_strrchr function

// #include <stdio.h>

// int main(void)
// {
// 	char	*str;
// 	char	*ptr;
// 	char * empty = (char*)calloc(1, 1);

// 	str = "tripouille";
// 	ptr = ft_strrchr(empty, 'V');
// 	printf("%s\n", ptr);
// 	str = "tripouille";
// 	ptr = strrchr(empty, 'V');
// 	printf("%s\n", ptr);
// 	return (0);
// }
