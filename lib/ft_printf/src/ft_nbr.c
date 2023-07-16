/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:16:41 by sinlee            #+#    #+#             */
/*   Updated: 2023/05/19 14:57:06 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_len(int n, int *len)
{
	char	*nbr;

	nbr = ft_itoa(n);
	ft_putstr_len(nbr, len);
	free(nbr);
}

void	ft_putnbr_u_len(unsigned int n, int *len)
{
	if (n >= 10)
		ft_putnbr_u_len(n / 10, len);
	ft_putchar_len((n % 10) + '0', len);
}

static char	*ft_nbr_base_len(unsigned int nbr, char *base)
{
	unsigned int	length;
	char			*ans;
	int				attr[2];
	char			display[11];

	attr[0] = 0;
	attr[1] = 0;
	ans = malloc(11);
	length = (unsigned int)ft_strlen(base);
	while (nbr >= length)
	{
		display[attr[0]++] = base[(nbr % length)];
		nbr /= length;
	}
	display[attr[0]] = base[nbr];
	while (attr[0] >= 0)
		ans[attr[1]++] = display[attr[0]--];
	ans[attr[1]] = '\0';
	return (ans);
}

void	ft_putnbr_hexa_len(unsigned int nbr, int *len, bool up)
{
	char	*ans;

	if (up == true)
		ans = ft_nbr_base_len(nbr, "0123456789ABCDEF");
	else
		ans = ft_nbr_base_len(nbr, "0123456789abcdef");
	ft_putstr_len(ans, len);
	free(ans);
}

void	ft_putpointer_len(uintptr_t pointer, int *len)
{
	char	ans[25];
	int		i;
	char	*base;

	base = "0123456789abcdef";
	i = 0;
	ft_putstr_len("0x", len);
	if (pointer == 0)
	{
		ft_putchar_len('0', len);
		return ;
	}
	while (pointer != 0)
	{
		ans[i++] = base[pointer % 16];
		pointer /= 16;
	}
	while (i--)
		ft_putchar_len(ans[i], len);
}
