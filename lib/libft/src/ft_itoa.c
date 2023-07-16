/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:04:49 by sinlee            #+#    #+#             */
/*   Updated: 2023/05/03 14:14:49 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// implement ft_itoa function: convert int to string

#include "libft.h"

static int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;

	len = ft_len(n);
	str = (char *)malloc((len + 1) * 1);
	if (!str)
		return (0);
	str[len] = '\0';
	len--;
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		str[0] = '-';
	while (n != 0)
	{
		str[len] = ft_abs(n % 10) + '0';
		n /= 10;
		len--;
	}
	return (str);
}

// #include <stdio.h>
// int	main(int argc, char **argv)
// {
// 	if (argc == 2)
// 	{
// 		printf("%s\n", ft_itoa(atoi(argv[1])));
// 	}
// 	return (0);
// }
