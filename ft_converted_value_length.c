/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converted_value_length.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 10:44:38 by ayzapata          #+#    #+#             */
/*   Updated: 2020/01/02 16:42:18 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		addr_hexa_length(void *str)
{
	char					*base;
	unsigned long long		ptr;
	int						x;

	ptr = (unsigned long long)str;
	base = "0123456789abcdef";
	x = ull_length_hexa(ptr);
	return (x + 2);
}

int				ft_converted_value_length(char str, va_list ap)
{
	int		cv;
	char	*cv_s;

	cv = 0;
	if (str == 'd' || str == 'i')
		cv = int_length(va_arg(ap, int));
	else if (str == 's')
	{
		cv_s = (char *)va_arg(ap, char*);
		cv = (!cv_s) ? ft_strlen("(null)\0") : ft_strlen(cv_s);
	}
	else if (str == 'c')
	{
		cv = va_arg(ap, int);
		cv = 1;
	}
	else if (str == 'u')
		cv = uint_length(va_arg(ap, int));
	else if (str == 'x' || str == 'X')
		cv = uint_length_hexa(va_arg(ap, int));
	else if (str == 'p')
		cv = addr_hexa_length(va_arg(ap, void *));
	return (cv);
}
