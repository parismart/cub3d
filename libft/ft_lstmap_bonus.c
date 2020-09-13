/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parmarti <parmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 17:08:03 by parmarti          #+#    #+#             */
/*   Updated: 2020/07/08 19:21:20 by parmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*tmp;

	if (!lst)
		return (NULL);
	tmp = ft_lstnew(f(lst->content));
	newlst = tmp;
	lst = lst->next;
	while (lst)
	{
		if (tmp == NULL)
		{
			ft_lstclear(&tmp, del);
			return (NULL);
		}
		tmp->next = ft_lstnew(f(lst->content));
		lst = lst->next;
		tmp = tmp->next;
	}
	return (newlst);
}
