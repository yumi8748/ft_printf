/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:27:43 by yu-chen           #+#    #+#             */
/*   Updated: 2023/11/20 17:59:47 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*cpy;

	if (lst == NULL)
		return (NULL);
	res = ft_lstnew(f(lst->content));
	if (res == NULL)
		return (NULL);
	cpy = res;
	lst = lst->next;
	while (lst)
	{
		cpy->next = ft_lstnew(f(lst->content));
		if (cpy->next == NULL)
		{
			ft_lstclear(&res, del);
			return (NULL);
		}
		cpy = cpy->next;
		lst = lst->next;
	}
	cpy->next = NULL;
	return (res);
}
