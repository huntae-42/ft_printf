/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 22:22:46 by tjung             #+#    #+#             */
/*   Updated: 2020/10/08 14:16:41 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	int		i;
	int		s_len;
	char	tmp;

	s_len = (int)ft_strlen(s);
	tmp = (char)c;
	if (tmp == '\0')
		return ((char *)s + s_len);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == tmp)
			break ;
		i++;
	}
	if (s[i] != '\0')
		return ((char *)s + i);
	return (NULL);
}
