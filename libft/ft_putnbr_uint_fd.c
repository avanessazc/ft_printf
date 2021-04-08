/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_uint_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 10:51:31 by ayzapata          #+#    #+#             */
/*   Updated: 2020/01/02 16:43:45 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			count_length_int(unsigned int n)
{
	int					i;
	unsigned int		nbr;

	i = 1;
	nbr = n;
	if (nbr < 0)
	{
		i++;
		nbr = nbr * -1;
	}
	while (nbr >= 10)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

unsigned int		ft_putnbr_uint_fd(unsigned int n, int fd)
{
	unsigned int		nbr;
	int					x;

	nbr = n;
	x = 0;
	if (nbr >= 10)
	{
		ft_putnbr_uint_fd(nbr / 10, fd);
		ft_putchar_fd((nbr % 10) + '0', fd, 1);
	}
	else
		ft_putchar_fd((nbr % 10) + '0', fd, 1);
	x = count_length_int(n);
	return (x);
}
