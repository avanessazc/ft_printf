/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 15:03:54 by ayzapata          #+#    #+#             */
/*   Updated: 2020/01/02 16:47:46 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		case_2(t_flags fl, char str, unsigned int ap_cv_nb)
{
	int		n;

	n = 0;
	if (fl.fneg == 0)
	{
		if (fl.v_zero == 1)
		{
			fl.zeros = ((fl.fw - fl.cvl) < 0) ?
										0 : (fl.fw - fl.cvl);
			n = ft_putnbr_hexa_fd(ap_cv_nb, 1, str)
									+ ft_putchar_fd('0', 1, fl.zeros);
		}
		else
			n = ft_putchar_fd(' ', 1, fl.spcs)
									+ ft_putnbr_hexa_fd(ap_cv_nb, 1, str);
	}
	else
		n = ft_putnbr_hexa_fd(ap_cv_nb, 1, str)
									+ ft_putchar_fd(' ', 1, fl.spcs);
	return (n);
}

static int		case_5(t_flags fl, char str, unsigned int ap_cv_nb)
{
	int		n;

	n = 0;
	ft_putchar_fd('-', 1, fl.sign);
	n = ft_putchar_fd('0', 1, fl.zeros) + ft_putnbr_hexa_fd(ap_cv_nb, 1, str)
										+ ft_putchar_fd(' ', 1, fl.spcs);
	return (n);
}

static int		case_6(t_flags fl, char str, unsigned int ap_cv_nb, int prec)
{
	int		n;

	n = 0;
	if ((fl.fprec == 0 || prec < 0) && fl.v_zero == 1)
	{
		fl.zeros = ((fl.fw - fl.cvl) < 0) ? 0 : (fl.fw - fl.cvl);
		ft_putchar_fd('-', 1, fl.sign);
		n = ft_putchar_fd('0', 1, fl.zeros)
									+ ft_putnbr_hexa_fd(ap_cv_nb, 1, str);
	}
	else
	{
		n = ft_putchar_fd(' ', 1, fl.spcs);
		ft_putchar_fd('-', 1, fl.sign);
		n = n + ft_putchar_fd('0', 1, fl.zeros)
									+ ft_putnbr_hexa_fd(ap_cv_nb, 1, str);
	}
	return (n);
}

static int		cases(t_flags fl, char str, unsigned int ap_cv_nb, int prec)
{
	int		n;

	n = 0;
	if (fl.fw == 0 && prec < 0 && fl.fprec == 1 && ap_cv_nb == 0)
		n = ft_putnbr_hexa_fd(ap_cv_nb, 1, str);
	else if (prec < 0 && fl.fprec == 1 && ap_cv_nb == 0)
		n = case_2(fl, str, ap_cv_nb);
	else if (fl.fw == 0 && fl.precision == 0
										&& fl.fprec == 1 && ap_cv_nb == 0)
		n = ft_putchar_fd(' ', 1, fl.spcs);
	else if (fl.precision == 0 && fl.fprec == 1 && ap_cv_nb == 0)
		n = ft_putchar_fd(' ', 1, fl.spcs + 1);
	else if (fl.fneg == 1)
		n = case_5(fl, str, ap_cv_nb);
	else
		n = case_6(fl, str, ap_cv_nb, prec);
	return (n);
}

int				ft_print_x(t_flags fl, char str, va_list ap_cv)
{
	unsigned int		ap_cv_nb;
	int					n;
	int					prec;

	n = 0;
	ap_cv_nb = va_arg(ap_cv, int);
	prec = fl.precision;
	fl.precision = (fl.precision < 0) ? 0 : fl.precision;
	if (ap_cv_nb < 0)
		fl.sign = 1;
	fl.zeros = ((fl.precision - (fl.cvl - fl.sign)) < 0) ?
						0 : (fl.precision - (fl.cvl - fl.sign));
	fl.spcs = ((fl.fw - fl.zeros - fl.cvl) < 0) ?
						0 : (fl.fw - fl.zeros - fl.cvl);
	n = cases(fl, str, ap_cv_nb, prec);
	return (n);
}
