/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:32:27 by ayzapata          #+#    #+#             */
/*   Updated: 2019/12/12 14:47:31 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strchr(const char *s, char c)
{
	char	*tmp_s;
	int		i;

	tmp_s = (char *)s;
	i = 0;
	while (tmp_s[i] != '\0' && tmp_s[i] != c)
	{
		i++;
	}
	if (tmp_s[i] == c)
	{
		return (1);
	}
	return (0);
}
