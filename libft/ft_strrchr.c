/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 22:23:12 by tjung             #+#    #+#             */
/*   Updated: 2020/10/08 14:50:41 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	char	*tmp;
	int		i;
	int		len;

	len = ft_strlen(s);
	if ((char)c == '\0')
		return ((char *)s + len);
	tmp = (char *)s;
	i = 0;
	while (s[i] != '\0')
	{
		if (tmp[(len - 1) - i] == (char)c)
			break ;
		i++;
	}
	if (s[i] != '\0')
		return ((char *)s + ((len - 1) - i));
	return (NULL);
}
