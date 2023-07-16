/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:56:50 by sinlee            #+#    #+#             */
/*   Updated: 2023/04/28 12:02:54 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// implementation of bzero function

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

// test ft_bzero function
// #include <stdio.h>

// int main()
// {
// 	char str[50] = "GeeksForGeeks is for programming geeks.";
// 	printf("\nBefore bzero(): %s\n", str);
// 	ft_bzero(str + 13, 8*sizeof(char));
// 	printf("After bzero():  %s|", str);
// 	char str1[50] = "GeeksForGeeks is for programming geeks.";
// 	printf("\nBefore bzero(): %s\n", str1);
// 	bzero(str1 + 13, 8*sizeof(char));
// 	printf("After bzero():  %s|", str1);
// 	return 0;
// }