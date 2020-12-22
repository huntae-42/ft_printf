/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_c_values.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 20:04:50 by tjung             #+#    #+#             */
/*   Updated: 2020/11/25 21:47:57 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		get_char_values(t_printf *data)
{
	char	c;

	if (data->type == '%')
		c = '%';
	else
		c = (char)va_arg(data->ap, int);
	check_and_print_c(data, c);
}

void		check_and_print_c(t_printf *data, char c)
{
	if (data->flags & FLAGS_MINUS)
	{
		write(1, &c, 1);
		data->ret++;
		while (data->width_value > 1)
		{
			write(1, " ", 1);
			data->ret++;
			data->width_value--;
		}
	}
	else
	{
		while (data->width_value > 1)
		{
			if (data->flags & FLAGS_ZERO)
				write(1, "0", 1);
			else
				write(1, " ", 1);
			data->ret++;
			data->width_value--;
		}
		write(1, &c, 1);
		data->ret++;
	}
}
