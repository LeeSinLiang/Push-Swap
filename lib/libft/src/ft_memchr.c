/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:32:44 by sinlee            #+#    #+#             */
/*   Updated: 2023/05/03 18:34:32 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	index;

	index = 0;
	while (index < n)
	{
		if (((unsigned char *)s)[index] == (unsigned char)c)
			return (((unsigned char *)s) + index);
		index++;
	}
	return (NULL);
}

// #include <stdio.h>

// int main()
// {
// 	char s[] = {0, 1, 2, 3, 4, 5};

// 	printf("%s\n", ft_memchr(s, 0, 0));
// 	printf("%s\n", memchr(s, 0, 0));
// 	printf("---------------------\n");
// 	printf("%s\n", ft_memchr(s, 2, 3));
// 	printf("%s\n", memchr(s, 2, 3));
// 	printf("---------------------\n");
// 	printf("%s\n", ft_memchr(s, 2+256, 3));
// 	printf("%s\n", memchr(s, 2+256, 3));
// }