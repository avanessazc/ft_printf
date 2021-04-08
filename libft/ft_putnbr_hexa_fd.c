/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 10:38:58 by ayzapata          #+#    #+#             */
/*   Updated: 2019/12/22 12:55:37 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_write_nbr_base_uint(unsigned int nbr, int fd, char *base)
{
	if (nbr >= 16)
	{
		ft_write_nbr_base_uint(nbr / 16, fd, base);
	}
	ft_putchar_fd(base[nbr % 16], fd, 1);
}

int				ft_putnbr_hexa_fd(int n, int fd, char conv)
{
	char	*base;
	int		nbr;
	int		j;

	nbr = n;
	j = 0;
	base = NULL;
	if (conv == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	ft_write_nbr_base_uint(nbr, fd, base);
	j = uint_length_hexa(n);
	return (j);
}
