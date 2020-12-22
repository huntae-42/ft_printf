/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_i_details.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:58:57 by tjung             #+#    #+#             */
/*   Updated: 2020/11/26 02:12:44 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		unminus_di_details(t_printf *data, int *k, int *cnt, int *j)
{
	int		zero;

	zero = 0;
	if (data->pcs_value > *j)
		pcs_value_over_j_di(data, k, cnt, j);
	else
	{
		if (*j == 1 && data->itoa_s[0] == '0' && data->pcs_value == 0
									&& (data->precision & PRECISION_DOT))
			pcs_value_under_j_di(data, cnt, &zero);
		else
			pcs_value_under_j_di(data, cnt, j);
	}
}

void		pcs_value_over_j_di(t_printf *data, int *k, int *cnt, int *j)
{
	while (data->pcs_value + *cnt + (*k)++ < data->width_value)
	{
		write(1, " ", 1);
		data->ret++;
	}
	print_sign_conditions(data, cnt);
	while ((*j)++ < data->pcs_value)
	{
		write(1, "0", 1);
		data->ret++;
	}
}

void		pcs_value_under_j_di(t_printf *data, int *cnt, int *j)
{
	if ((data->flags & FLAGS_ZERO) && !(data->precision & PRECISION_DOT))
	{
		print_sign_conditions(data, cnt);
		while ((*j)++ < (data->width_value - *cnt))
		{
			write(1, "0", 1);
			data->ret++;
		}
	}
	else
	{
		while ((*j)++ < (data->width_value - *cnt))
		{
			write(1, " ", 1);
			data->ret++;
		}
		print_sign_conditions(data, cnt);
	}
}
