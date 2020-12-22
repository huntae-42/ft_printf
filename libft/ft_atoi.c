/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 22:24:24 by tjung             #+#    #+#             */
/*   Updated: 2020/11/18 16:50:22 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		pass_blank(const char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
			break ;
		i++;
	}
	return (i);
}

static int		check_sign(const char *str, int *sign)
{
	int		cnt;
	int		i;

	cnt = 0;
	i = pass_blank(str);
	while (str[i] != '\0')
	{
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				*sign = -1;
			cnt++;
		}
		else if (str[i] >= '0' && str[i] <= '9')
			break ;
		i++;
	}
	return (cnt);
}

static int		check_long(const char *str)
{
	int		i;
	int		cnt;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			break ;
		i++;
	}
	cnt = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			break ;
		cnt++;
		i++;
	}
	return (cnt);
}

static int		over_result(int sign)
{
	if (sign > 0)
		return (-1);
	else
		return (0);
}

int				ft_atoi(const char *str)
{
	int		total;
	int		sign;
	int		i;

	if (str[0] == '\0')
		return (0);
	sign = 1;
	if (check_sign(str, &sign) > 1)
		return (0);
	total = 0;
	i = pass_blank(str);
	while (str[i] != '\0')
	{
		if (!(str[i] == '+' || str[i] == '-') &&
				!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		if (str[i] >= '0' && str[i] <= '9')
			total = (total * 10) + (str[i] - '0');
		if (!(str[i + 1] >= '0' && str[i + 1] <= '9'))
			break ;
		i++;
	}
	if (check_long(str) > 18)
		return (over_result(sign));
	return (sign * total);
}
