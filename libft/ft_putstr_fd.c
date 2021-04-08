/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 10:27:49 by ayzapata          #+#    #+#             */
/*   Updated: 2019/12/22 14:13:33 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putstr_fd(char *s, int fd, int l)
{
	int		i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0' && i < l)
	{
		write(fd, &s[i], 1);
		i++;
	}
	return (i);
}
