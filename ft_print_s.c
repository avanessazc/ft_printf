/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 12:13:09 by ayzapata          #+#    #+#             */
/*   Updated: 2019/12/30 11:13:19 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		case_2(t_flags fl, char *ap_cv_nb)
{
	int		n;

	n = 0;
	if (fl.v_zero == 1)
		n = ft_putchar_fd('0', 1, fl.spcs)
									+ ft_putstr_fd(ap_cv_nb, 1, fl.zeros);
	else
		n = ft_putchar_fd(' ', 1, fl.spcs)
									+ ft_putstr_fd(ap_cv_nb, 1, fl.zeros);
	return (n);
}

static int		case_3(t_flags fl, char *ap_cv_nb)
{
	int		n;

	n = 0;
	fl.spcs = ((fl.fw - fl.cvl) < 0) ? 0 : (fl.fw - fl.cvl);
	if (fl.fneg == 1)
		n = ft_putstr_fd(ap_cv_nb, 1, ft_strlen(ap_cv_nb))
									+ ft_putchar_fd(' ', 1, fl.spcs);
	else
	{
		if (fl.v_zero == 1)
			n = ft_putchar_fd('0', 1, fl.spcs)
						+ ft_putstr_fd(ap_cv_nb, 1, ft_strlen(ap_cv_nb));
		else
			n = ft_putchar_fd(' ', 1, fl.spcs)
						+ ft_putstr_fd(ap_cv_nb, 1, ft_strlen(ap_cv_nb));
	}
	return (n);
}

int				ft_print_s(t_flags fl, va_list ap_cv)
{
	char	*ap_cv_nb;
	int		n;
	int		prec;

	n = 0;
	ap_cv_nb = (char *)va_arg(ap_cv, char*);
	if (!ap_cv_nb)
		ap_cv_nb = "(null)\0";
	prec = fl.precision;
	fl.precision = (fl.precision < 0) ? 0 : fl.precision;
	fl.zeros = (fl.precision < fl.cvl) ? fl.precision : fl.cvl;
	fl.spcs = ((fl.fw - fl.zeros) < 0) ? 0 : (fl.fw - fl.zeros);
	if (fl.fneg == 1 && fl.fprec == 1 && prec >= 0)
		n = ft_putstr_fd(ap_cv_nb, 1, fl.zeros)
										+ ft_putchar_fd(' ', 1, fl.spcs);
	else if (fl.fneg == 0 && fl.fprec == 1 && prec >= 0)
		n = case_2(fl, ap_cv_nb);
	else
		n = case_3(fl, ap_cv_nb);
	return (n);
}
