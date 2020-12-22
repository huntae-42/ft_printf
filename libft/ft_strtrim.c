/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 19:03:39 by tjung             #+#    #+#             */
/*   Updated: 2020/10/14 03:51:58 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		get_back_len(char const *s1, char const *set, size_t idx)
{
	size_t	i;
	size_t	j;
	size_t	flag;
	size_t	cnt;

	cnt = 0;
	i = idx;
	while (i)
	{
		flag = 0;
		j = 0;
		while (set[j])
		{
			if (s1[i - 1] == set[j])
				flag = 1;
			j++;
		}
		if (flag == 1)
			cnt++;
		else
			break ;
		i--;
	}
	return (cnt);
}

static size_t		get_front_len(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	flag;
	size_t	cnt;

	cnt = 0;
	i = 0;
	while (s1[i])
	{
		flag = 0;
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				flag = 1;
			j++;
		}
		if (flag == 1)
			cnt++;
		else
			break ;
		i++;
	}
	return (cnt);
}

char				*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	int		new_len;
	size_t	front_trim;
	size_t	back_trim;
	size_t	i;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL || ft_strlen(set) == 0)
		return (ft_strdup(s1));
	front_trim = get_front_len(s1, set);
	back_trim = get_back_len(s1, set, ft_strlen(s1));
	new_len = ft_strlen(s1) - (front_trim + back_trim);
	if (new_len < 0)
		return (ft_strdup(""));
	else
	{
		if ((new = (char *)malloc(sizeof(char) * new_len + 1)) == NULL)
			return (NULL);
		i = -1;
		while (++i < (size_t)new_len)
			new[i] = s1[front_trim + i];
		new[new_len] = '\0';
		return (new);
	}
}
