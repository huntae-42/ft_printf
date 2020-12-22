/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 15:27:22 by tjung             #+#    #+#             */
/*   Updated: 2020/10/15 18:52:43 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!(lst) || !(new))
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	ft_lstlast(*lst)->next = new;
	new->next = NULL;
}
