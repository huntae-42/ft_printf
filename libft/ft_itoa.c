/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 20:46:13 by tjung             #+#    #+#             */
/*   Updated: 2020/10/13 22:00:13 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		get_num_len(int n)
{
	size_t	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		len++;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	char	*i2a;
	size_t	n_len;
	size_t	i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	n_len = get_num_len(n);
	if (!(i2a = (char *)malloc(sizeof(char) * n_len + 1)))
		return (NULL);
	i = 0;
	if (n < 0)
	{
		i2a[i] = '-';
		n = -n;
		i = 1;
	}
	i2a[n_len] = '\0';
	while (i < n_len)
	{
		i2a[n_len - 1] = '0' + (n % 10);
		n = n / 10;
		n_len--;
	}
	return (i2a);
}
