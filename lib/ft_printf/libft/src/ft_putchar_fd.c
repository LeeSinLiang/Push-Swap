/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:29:39 by sinlee            #+#    #+#             */
/*   Updated: 2023/05/03 15:30:17 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// implement putchar_fd function: output character to file descriptor

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
