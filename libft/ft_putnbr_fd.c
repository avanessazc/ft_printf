/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 10:51:31 by ayzapata          #+#    #+#             */
/*   Updated: 2019/12/30 14:22:40 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_length_int(int n)
{
	int		i;
	int		nbr;

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

int				ft_putnbr_fd(int n, int fd)
{
	int		nbr;
	int		x;

	nbr = n;
	x = 0;
	if (n == -2147483648)
	{
		write(fd, "2147483648", 10);
		return (11);
	}
	else
	{
		if (n < 0)
			nbr = n * -1;
		if (nbr >= 10)
		{
			ft_putnbr_fd(nbr / 10, fd);
			ft_putchar_fd((nbr % 10) + '0', fd, 1);
		}
		else
			ft_putchar_fd((nbr % 10) + '0', fd, 1);
	}
	x = count_length_int(n);
	return (x);
}
