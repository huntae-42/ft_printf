/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 17:30:42 by tjung             #+#    #+#             */
/*   Updated: 2020/10/15 18:57:50 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*root;
	t_list	*tmp;

	if (!(lst) || !(f))
		return (NULL);
	root = NULL;
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (!(tmp) || (tmp && !(tmp->content)))
		{
			ft_lstclear(&root, del);
			return (NULL);
		}
		ft_lstadd_back(&root, tmp);
		lst = lst->next;
	}
	return (root);
}
