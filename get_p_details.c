/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_p_details.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 19:47:22 by tjung             #+#    #+#             */
/*   Updated: 2020/11/26 02:57:38 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		pcs_value_over_j_p(t_printf *data, int *k, int *j)
{
	while (data->pcs_value + 2 + *k < data->width_value)
	{
		write(1, " ", 1);
		data->ret++;
		(*k)++;
	}
	print_hexa_notation(data);
	while (*j < data->pcs_value)
	{
		write(1, "0", 1);
		data->ret++;
		(*j)++;
	}
}

void		pcs_value_under_j_p(t_printf *data, int *j)
{
	if ((data->flags & FLAGS_ZERO) && !(data->precision & PRECISION_DOT))
	{
		print_hexa_notation(data);
		while (*j < (data->width_value - 2))
		{
			write(1, "0", 1);
			data->ret++;
			(*j)++;
		}
	}
	else
	{
		while (*j < (data->width_value - 2))
		{
			write(1, " ", 1);
			data->ret++;
			(*j)++;
		}
		print_hexa_notation(data);
	}
}
