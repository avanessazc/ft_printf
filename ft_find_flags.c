/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 08:45:07 by ayzapata          #+#    #+#             */
/*   Updated: 2020/01/03 12:15:53 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flags		modify_structure(t_flags fl, int value)
{
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
	return (fl);
}

static t_flags		case_1(char *str, t_flags fl)
{
	int		t;
	char	*tmp;

	t = fl.i - 1;
	while (t >= 0 && ft_strchr("0123456789", str[t]) == 1)
		t--;
	tmp = ft_substr(&str[t + 1], 0, fl.i - t);
	t = ft_atoi(tmp);
	free(tmp);
	if (t == 0)
		fl.v_zero = 1;
	fl.i++;
	return (fl);
}

static t_flags		case_3(char *str, t_flags fl, va_list ap)
{
	fl.fprec = 1;
	fl.i++;
	if (ft_strchr("0123456789", str[fl.i]) == 1)
	{
		fl.precision = ft_atoi(&str[fl.i]);
		while (ft_strchr("0123456789", str[fl.i]) == 1 && str[fl.i] != '\0')
			fl.i++;
	}
	else if (str[fl.i] == '*')
		fl.precision = (str[fl.i++] == '*') ?
								va_arg(ap, int) : fl.precision;
	return (fl);
}

static t_flags		case_4(char *str, t_flags fl, va_list ap)
{
	if (ft_strchr("123456789", str[fl.i]) == 1)
	{
		fl.fw = ft_atoi(&str[fl.i]);
		while (ft_strchr("0123456789", str[fl.i]) == 1 && str[fl.i] != '\0')
			fl.i++;
	}
	else if (str[fl.i] == '*')
		fl.fw = (str[fl.i++] == '*') ? va_arg(ap, int) : fl.fw;
	else
		fl.i++;
	return (fl);
}

t_flags				ft_find_flags(t_flags fl, char *str, va_list ap)
{
	fl = modify_structure(fl, 0);
	while (str[fl.i] != '\0')
	{
		if (str[fl.i] == '0' && fl.fprec != 1)
			fl = case_1(str, fl);
		else if (str[fl.i] == '-')
			fl.fneg = (str[fl.i++] == '-') ? 1 : fl.fneg;
		else if (str[fl.i] == '.')
			fl = case_3(str, fl, ap);
		else if (ft_strchr("123456789*", str[fl.i]) == 1)
			fl = case_4(str, fl, ap);
		else
		{
			fl.i++;
			break ;
		}
	}
	fl.fneg = (fl.fw < 0) ? 1 : fl.fneg;
	fl.fw = (fl.fw < 0) ? (fl.fw * -1) : fl.fw;
	return (fl);
}
