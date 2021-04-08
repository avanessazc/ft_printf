/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ull_length_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 13:49:52 by ayzapata          #+#    #+#             */
/*   Updated: 2019/12/13 13:51:33 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ull_length_hexa(unsigned long long n)
{
	int						i;
	unsigned long long		nbr;

	i = 1;
	nbr = n;
	if (nbr < 0)
	{
		i++;
		nbr = nbr * -1;
	}
	while (nbr >= 16)
	{
		nbr = nbr / 16;
		i++;
	}
	return (i);
}
