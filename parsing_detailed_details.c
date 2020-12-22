/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_detailed_details.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 20:35:28 by tjung             #+#    #+#             */
/*   Updated: 2020/11/26 02:07:37 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		input_not_pwc_pcs_value(t_printf *data, char *temp)
{
	int		atoi_result;

	atoi_result = 0;
	if ((atoi_result = ft_atoi(temp)) < 0)
	{
		data->flags |= FLAGS_MINUS;
		data->width_value = (-1) * atoi_result;
		data->pcs_value = -2;
	}
	else
		data->pcs_value = ft_atoi(temp);
}

void		input_not_wwc_pcs_value(t_printf *data, int fs, int tp, int *i)
{
	if (data->fmt[fs + *i] == '.')
		get_pcs_value(data, fs, tp, i);
	else
		wv_detailed_options(data, fs, tp, i);
}
