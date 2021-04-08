/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 16:19:10 by ayzapata          #+#    #+#             */
/*   Updated: 2019/12/29 12:04:36 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		case_2(t_flags fl, void *ap_cv_nb)
{
	int		n;

	n = 0;
	if (fl.fneg == 0)
	{
		if (fl.v_zero == 1)
		{
			fl.zeros = ((fl.fw - fl.cvl) < 0) ?
										0 : (fl.fw - fl.cvl);
			ft_putstr_fd("0x", 1, 2);
			n = ft_putaddr_fd(ap_cv_nb, 1) + ft_putchar_fd('0', 1, fl.zeros);
		}
		else
		{
			n = ft_putchar_fd(' ', 1, fl.spcs);
			ft_putstr_fd("0x", 1, 2);
			n = n + ft_putaddr_fd(ap_cv_nb, 1);
		}
	}
	else
	{
		ft_putstr_fd("0x", 1, 2);
		n = ft_putaddr_fd(ap_cv_nb, 1) + ft_putchar_fd(' ', 1, fl.spcs);
	}
	return (n);
}

static int		case_6(t_flags fl, void *ap_cv_nb)
{
	int		n;

	n = 0;
	ft_putstr_fd("0x", 1, 2);
	n = ft_putchar_fd('0', 1, fl.zeros)
			+ ft_putaddr_fd(ap_cv_nb, 1) + ft_putchar_fd(' ', 1, fl.spcs);
	return (n);
}

static int		case_7(t_flags fl, void *ap_cv_nb, int prec)
{
	int		n;

	n = 0;
	if ((fl.fprec == 0 || prec < 0) && fl.v_zero == 1)
	{
		fl.zeros = ((fl.fw - fl.cvl) < 0) ? 0 : (fl.fw - fl.cvl);
		ft_putstr_fd("0x", 1, 2);
		n = ft_putchar_fd('0', 1, fl.zeros) + ft_putaddr_fd(ap_cv_nb, 1);
	}
	else
	{
		n = ft_putchar_fd(' ', 1, fl.spcs);
		ft_putstr_fd("0x", 1, 2);
		n = n + ft_putchar_fd('0', 1, fl.zeros) + ft_putaddr_fd(ap_cv_nb, 1);
	}
	return (n);
}

static int		cases(t_flags fl, void *ap_cv_nb, int prec)
{
	int		n;

	n = 0;
	if (fl.fw == 0 && prec < 0 && fl.fprec == 1 && ap_cv_nb == 0)
	{
		ft_putstr_fd("0x", 1, 2);
		n = ft_putaddr_fd(ap_cv_nb, 1);
	}
	else if (prec < 0 && fl.fprec == 1 && ap_cv_nb == 0)
		n = case_2(fl, ap_cv_nb);
	else if (fl.fw == 0 && fl.precision == 0
										&& fl.fprec == 1 && ap_cv_nb == 0)
		n = ft_putstr_fd("0x", 1, 2) + ft_putchar_fd(' ', 1, fl.spcs);
	else if (fl.precision == 0 && fl.fprec == 1
										&& ap_cv_nb == 0 && fl.fneg == 1)
		n = ft_putstr_fd("0x", 1, 2) + ft_putchar_fd(' ', 1, fl.spcs + 1);
	else if (fl.precision == 0 && fl.fprec == 1 && ap_cv_nb == 0)
		n = ft_putchar_fd(' ', 1, fl.spcs + 1) + ft_putstr_fd("0x", 1, 2);
	else if (fl.fneg == 1)
		n = case_6(fl, ap_cv_nb);
	else
		n = case_7(fl, ap_cv_nb, prec);
	return (n);
}

int				ft_print_p(t_flags fl, va_list ap_cv)
{
	void		*ap_cv_nb;
	int			n;
	int			prec;

	n = 0;
	ap_cv_nb = va_arg(ap_cv, void *);
	prec = fl.precision;
	fl.precision = (fl.precision < 0) ? 0 : fl.precision;
	if (ap_cv_nb < 0)
		fl.sign = 1;
	fl.zeros = ((fl.precision - (fl.cvl - fl.sign - 2)) < 0) ?
						0 : (fl.precision - (fl.cvl - fl.sign - 2));
	fl.spcs = ((fl.fw - fl.zeros - fl.cvl) < 0) ?
						0 : (fl.fw - fl.zeros - fl.cvl);
	n = cases(fl, ap_cv_nb, prec);
	return (n);
}
