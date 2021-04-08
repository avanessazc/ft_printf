/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 08:46:37 by ayzapata          #+#    #+#             */
/*   Updated: 2019/12/30 14:22:10 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_write_nbr_base(unsigned long long nbr, int fd, char *base)
{
	if (nbr >= 16)
	{
		ft_write_nbr_base(nbr / 16, fd, base);
	}
	ft_putchar_fd(base[nbr % 16], fd, 1);
}

int				ft_putaddr_fd(void *str, int fd)
{
	char					*base;
	unsigned long long		ptr;
	int						x;

	ptr = (unsigned long long)str;
	base = "0123456789abcdef";
	ft_write_nbr_base(ptr, fd, base);
	x = ull_length_hexa(ptr);
	return (x + 2);
}
