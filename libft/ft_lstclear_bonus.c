/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:38:08 by ayzapata          #+#    #+#             */
/*   Updated: 2019/11/15 11:45:18 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*succ;

	tmp = *lst;
	while (tmp != NULL)
	{
		succ = tmp->next;
		del(tmp->content);
		free(tmp);
		tmp = succ;
	}
	*lst = NULL;
}
