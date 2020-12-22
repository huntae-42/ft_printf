/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 22:20:49 by tjung             #+#    #+#             */
/*   Updated: 2020/10/09 16:19:53 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;

	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst <= src)
	{
		d = (char *)dst;
		s = (char *)src;
		while (len--)
			*d++ = *s++;
	}
	else
	{
		d = (char *)dst;
		d += len;
		s = (char *)src;
		s += len;
		while (len--)
			*--d = *--s;
	}
	return (dst);
}
