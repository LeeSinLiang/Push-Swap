/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:33:21 by sinlee            #+#    #+#             */
/*   Updated: 2023/05/05 14:29:22 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// implements ft_putnbr_fd function: output integer to file descriptor

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	*str;

	str = ft_itoa(n);
	write(fd, str, ft_strlen(str));
	free(str);
}
// void	ft_putnbr_fd(int n, int fd)
// {
// 	write(fd, ft_itoa(n), ft_strlen(ft_itoa(n)));
// }
