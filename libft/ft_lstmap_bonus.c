/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:48:16 by ayzapata          #+#    #+#             */
/*   Updated: 2019/11/15 16:24:55 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*first_elem_nl;
	t_list	*tmp;

	if (lst == NULL)
		return (NULL);
	if (!(new_lst = ft_lstnew(f(lst->content))))
		return (NULL);
	first_elem_nl = new_lst;
	lst = lst->next;
	while (lst != NULL)
	{
		tmp = new_lst;
		if (!(new_lst = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&first_elem_nl, del);
			return (0);
		}
		tmp->next = new_lst;
		lst = lst->next;
	}
	tmp = new_lst;
	tmp->next = NULL;
	return (first_elem_nl);
}
