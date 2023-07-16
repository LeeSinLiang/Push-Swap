/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 09:54:31 by sinlee            #+#    #+#             */
/*   Updated: 2023/05/05 13:57:44 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// implementation of calloc function

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void		*ptr;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, count * size);
	return ((void *)ptr);
}

// test ft_calloc function

// #include <stdio.h>

// int main()
// {
// 	char *str;
// 	int i;

// 	printf("ft_calloc: %p \n", ft_calloc(SIZE_MAX, SIZE_MAX));
// 	return (0);
// }
