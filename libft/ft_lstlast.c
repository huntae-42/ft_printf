/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 17:17:17 by tjung             #+#    #+#             */
/*   Updated: 2020/10/14 17:25:47 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstlast(t_list *lst)
{
	int		size;

	if (lst == NULL)
		return (NULL);
	size = ft_lstsize(lst);
	while (--size)
		lst = lst->next;
	return (lst);
}
