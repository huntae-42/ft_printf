/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 20:45:18 by tjung             #+#    #+#             */
/*   Updated: 2020/11/20 17:01:55 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			how_many_digits_uint(unsigned int n, int base)
{
	int		digits;

	digits = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= base;
		digits++;
	}
	return (digits);
}

int			how_many_digits_ulong(unsigned long n)
{
	int		digits;

	digits = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 16;
		digits++;
	}
	return (digits);
}

void		itoa_details(unsigned int *n, int *digits, t_printf *data, char *s)
{
	unsigned int	remainder;

	while (*digits > -1)
	{
		remainder = *n % data->base;
		if (data->base == 10)
			s[*digits] = remainder + 48;
		else if (data->base == 16)
		{
			if (remainder >= 0 && remainder <= 9)
				s[*digits] = remainder + 48;
			else
			{
				if (data->type == 'x')
					s[*digits] = remainder + 87;
				else if (data->type == 'X')
					s[*digits] = remainder + 55;
			}
		}
		*n /= data->base;
		--(*digits);
	}
}

char		*itoa_ui_base(unsigned int n, int digits, t_printf *data)
{
	char	*trfs;

	if (!(trfs = (char *)malloc(sizeof(char) * digits + 1)))
		return (NULL);
	trfs[digits--] = '\0';
	itoa_details(&n, &digits, data, trfs);
	return (trfs);
}

char		*itoa_pointer(unsigned long n, int digits)
{
	char			*trfs;
	unsigned long	remainder;

	if (!(trfs = (char *)malloc(sizeof(char) * digits + 1)))
		return (NULL);
	trfs[digits--] = '\0';
	while (digits > -1)
	{
		remainder = n % 16;
		if (remainder >= 0 && remainder <= 9)
			trfs[digits] = remainder + 48;
		else
			trfs[digits] = remainder + 87;
		n /= 16;
		--digits;
	}
	return (trfs);
}
