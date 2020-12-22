/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 22:23:35 by tjung             #+#    #+#             */
/*   Updated: 2020/10/09 18:17:24 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	haystack_len;
	size_t	needle_len;

	needle_len = ft_strlen(needle);
	if (len == 0 && needle_len > 0)
		return (NULL);
	if (needle_len == 0)
		return ((char *)haystack);
	haystack_len = ft_strlen(haystack);
	if (haystack_len < needle_len)
		return (NULL);
	i = 0;
	while (i <= len - needle_len)
	{
		if (ft_strncmp(haystack + i, needle, needle_len) == 0)
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
