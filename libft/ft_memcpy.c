/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 22:20:01 by tjung             #+#    #+#             */
/*   Updated: 2020/10/10 16:26:01 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*d;
	const char	*s = src;

	if (dst == NULL && src == NULL)
		return (NULL);
	d = dst;
	while (n--)
		*d++ = *s++;
	return (dst);
}
