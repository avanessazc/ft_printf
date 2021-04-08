/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 15:13:13 by ayzapata          #+#    #+#             */
/*   Updated: 2020/01/03 11:29:40 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct		s_flags
{
	int		fw;
	int		fneg;
	int		v_zero;
	int		precision;
	int		fprec;
	int		cvl;
	int		sign;
	int		zeros;
	int		spcs;
	int		i;
	int		n;
}					t_flags;

int					ft_printf(const char *format, ...);
int					ft_converted_value_length(char str, va_list ap);
t_flags				ft_find_flags(t_flags fl, char *str, va_list ap);
int					ft_print_d(t_flags flags, va_list ap);
int					ft_print_u(t_flags fl, va_list ap_cv);
int					ft_print_x(t_flags fl, char str, va_list ap_cv);
int					ft_print_p(t_flags fl, va_list ap_cv);
int					ft_print_c(t_flags fl, va_list ap_cv);
int					ft_print_s(t_flags fl, va_list ap_cv);
int					ft_print_pct(t_flags fl, va_list ap_cv);

#endif
