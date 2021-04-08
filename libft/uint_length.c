/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint_length.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 13:48:39 by ayzapata          #+#    #+#             */
/*   Updated: 2019/12/13 14:55:22 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		uint_length(unsigned int n)
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
