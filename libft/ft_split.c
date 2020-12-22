/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 06:24:29 by tjung             #+#    #+#             */
/*   Updated: 2020/10/18 20:04:03 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		get_size(char const *s, char c)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] != c)
			cnt++;
		while (s[i] != c && s[i + 1])
			i++;
		i++;
	}
	return (cnt);
}

static size_t		get_len(char const *s, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i])
	{
		len++;
		i++;
	}
	return (len);
}

static char			**free_memory(char **memory)
{
	int		i;

	i = 0;
	while (memory[i])
		free(memory[i++]);
	free(memory);
	return (NULL);
}

char				**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	if (!s || !(split = (char **)malloc(sizeof(char *) * (get_size(s, c) + 1))))
		return (NULL);
	while (i < get_size(s, c))
	{
		split[i] = (char *)malloc(sizeof(char) * (get_len(&s[j], c) + 1));
		if (!split[i])
			return (free_memory(split));
		k = 0;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			split[i][k++] = s[j++];
		split[i][k] = '\0';
		i++;
	}
	split[i] = NULL;
	return (split);
}
