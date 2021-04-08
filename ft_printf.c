/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 16:07:27 by ayzapata          #+#    #+#             */
/*   Updated: 2020/01/03 12:47:30 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <time.h>

static int			print(t_flags fl, char str, va_list ap_cv)
{
	int		n;

	n = 0;
	if (ft_strchr("di", str) == 1)
		n = ft_print_d(fl, ap_cv);
	else if (ft_strchr("u", str) == 1)
		n = ft_print_u(fl, ap_cv);
	else if (ft_strchr("xX", str) == 1)
		n = ft_print_x(fl, str, ap_cv);
	else if (ft_strchr("p", str) == 1)
		n = ft_print_p(fl, ap_cv);
	else if (ft_strchr("c", str) == 1)
		n = ft_print_c(fl, ap_cv);
	else if (ft_strchr("s", str) == 1)
		n = ft_print_s(fl, ap_cv);
	else if (ft_strchr("%", str) == 1)
		n = ft_print_pct(fl, ap_cv);
	return (n);
}

static int			char_not_allowed(int i, t_flags fl, char *format)
{
	int		n;

	n = 0;
	fl.zeros = ((fl.fw - 1) < 0) ? 0 : (fl.fw - 1);
	fl.spcs = ((fl.fw - 1) < 0) ? 0 : (fl.fw - 1);
	if (fl.fneg == 1)
	{
		n = ft_putchar_fd(format[i + fl.i], 1, 1);
		n = n + ft_putchar_fd(' ', 1, fl.spcs);
	}
	else
	{
		if (fl.v_zero == 1)
			n = ft_putchar_fd('0', 1, fl.zeros);
		else
			n = ft_putchar_fd(' ', 1, fl.spcs);
		n = n + ft_putchar_fd(format[i + fl.i], 1, 1);
	}
	return (n);
}

static t_flags		ft_write(t_flags fl, va_list ap, int i, char *format)
{
	va_list		ap_copy;

	fl = ft_find_flags(fl, (char *)&format[i + 1], ap);
	va_copy(ap_copy, ap);
	if (ft_strchr("cspdiuxX%", format[i + fl.i]) == 1)
	{
		fl.cvl = ft_converted_value_length(format[i + fl.i], ap);
		fl.n = fl.n + print(fl, format[i + fl.i], ap_copy);
	}
	else
		fl.n = fl.n + char_not_allowed(i, fl, (char *)format);
	va_end(ap_copy);
	return (fl);
}

static t_flags		create_structure(int value)
{
	t_flags		fl;

	fl.fw = value;
	fl.fneg = value;
	fl.precision = value;
	fl.fprec = value;
	fl.v_zero = value;
	fl.sign = value;
	fl.zeros = value;
	fl.spcs = value;
	fl.cvl = value;
	fl.i = value;
	fl.n = value;
	return (fl);
}

int					ft_printf(const char *format, ...)
{
	int			i;
	va_list		ap;
	t_flags		fl;

	i = 0;
	va_start(ap, format);
	fl = create_structure(0);
	while (format[i] != '\0')
	{
		while (format[i] != '\0' && format[i] != '%')
		{
			write(1, &format[i], 1);
			fl.n++;
			i++;
		}
		if (format[i] == '%')
		{
			if (format[i + 1] != '\0')
				fl = ft_write(fl, ap, i, (char *)format);
			i = i + fl.i + 1;
		}
	}
	va_end(ap);
	return (fl.n);
}
