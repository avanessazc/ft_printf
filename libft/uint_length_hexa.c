/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint_length_hexa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 13:48:39 by ayzapata          #+#    #+#             */
/*   Updated: 2019/12/13 14:48:53 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		uint_length_hexa(unsigned int n)
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
	while (nbr >= 16)
	{
		nbr = nbr / 16;
		i++;
	}
	return (i);
}
