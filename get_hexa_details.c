/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hexa_details.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 18:01:25 by tjung             #+#    #+#             */
/*   Updated: 2020/11/26 02:16:02 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		unminus_hexa_details(t_printf *data, int *k, int *flag, int *j)
{
	int		zero;

	zero = 0;
	if (data->pcs_value > *j)
		pcs_value_over_j(data, k, flag, j);
	else
	{
		if (*j == 1 && data->itoa_s[0] == '0' && data->pcs_value == 0
									&& (data->precision & PRECISION_DOT))
			pcs_value_under_j(data, flag, &zero);
		else
			pcs_value_under_j(data, flag, j);
	}
}

void		pcs_value_over_j(t_printf *data, int *k, int *flag, int *j)
{
	while (data->pcs_value + *flag + (*k)++ < data->width_value)
	{
		write(1, " ", 1);
		data->ret++;
	}
	if (*flag == 2)
		print_hexa_notation(data);
	while (*j < data->pcs_value)
	{
		write(1, "0", 1);
		data->ret++;
		(*j)++;
	}
}

void		pcs_value_under_j(t_printf *data, int *flag, int *j)
{
	if ((data->flags & FLAGS_ZERO) && !(data->precision & PRECISION_DOT))
	{
		if (*flag == 2)
			print_hexa_notation(data);
		while (*j < (data->width_value - *flag))
		{
			write(1, "0", 1);
			data->ret++;
			(*j)++;
		}
	}
	else
	{
		while (*j < (data->width_value - *flag))
		{
			write(1, " ", 1);
			data->ret++;
			(*j)++;
		}
		if (*flag == 2)
			print_hexa_notation(data);
	}
}
