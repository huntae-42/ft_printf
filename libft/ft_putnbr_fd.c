/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 22:54:25 by tjung             #+#    #+#             */
/*   Updated: 2020/10/14 03:48:40 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_digit(int n)
{
	int		len;

	if (n == 0)
		return (1);
	len = 0;
	while (n)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

void			ft_putnbr_fd(int n, int fd)
{
	char	tmp[get_digit(n) + 1];
	int		i;
	int		len;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = n * (-1);
	}
	len = get_digit(n);
	tmp[len] = '\0';
	while (len)
	{
		tmp[len - 1] = '0' + (n % 10);
		n = n / 10;
		len--;
	}
	i = -1;
	while (tmp[++i])
		write(fd, &tmp[i], 1);
}
