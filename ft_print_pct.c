/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 14:46:37 by ayzapata          #+#    #+#             */
/*   Updated: 2020/01/02 14:47:59 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_pct(t_flags fl, va_list ap_cv)
{
	int		ap_cv_nb;
	int		n;

	n = 0;
	ap_cv_nb = va_arg(ap_cv, int);
	fl.zeros = ((fl.fw - 1) < 0) ? 0 : (fl.fw - 1);
	fl.spcs = ((fl.fw - 1) < 0) ? 0 : (fl.fw - 1);
	if (fl.fneg == 1)
		n = ft_putchar_fd('%', 1, 1) + ft_putchar_fd(' ', 1, fl.spcs);
	else
	{
		if (fl.v_zero == 1)
			n = ft_putchar_fd('0', 1, fl.zeros) + ft_putchar_fd('%', 1, 1);
		else
			n = ft_putchar_fd(' ', 1, fl.spcs) + ft_putchar_fd('%', 1, 1);
	}
	return (n);
}
