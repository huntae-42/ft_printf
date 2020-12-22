/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 21:01:45 by tjung             #+#    #+#             */
/*   Updated: 2020/11/25 19:59:40 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			searching_type(t_printf *data, int fs)
{
	char	*type;
	int		i;

	i = 1;
	while (data->fmt[fs + i] != '\0')
	{
		if ((type = ft_strchr("cspdiuxX%", data->fmt[fs + i])))
		{
			data->type = *type;
			if (data->type == 'd' || data->type == 'i' || data->type == 'u')
				data->base = 10;
			else if (data->type == 'x' || data->type == 'X')
				data->base = 16;
			return (fs + i);
		}
		i++;
	}
	return (-1);
}

void		set_options(t_printf *data, int fs, int tp)
{
	get_flags(data, fs, tp);
	get_width_op(data, fs, tp);
	get_precision_op(data, fs, tp);
	get_wp_values(data, fs, tp);
}

void		clear_options(t_printf *data)
{
	data->type = 0;
	data->flags = 0;
	data->width = 0;
	data->precision = 0;
	data->base = 0;
	data->width_value = 0;
	data->pcs_value = 0;
	data->di_sign = 0;
	data->itoa_s = NULL;
}

int			parsing_data(t_printf *data, int fs)
{
	int		type_idx;

	if ((type_idx = searching_type(data, fs)) == -1)
		return (-1);
	set_options(data, fs, type_idx);
	handle_specifier(data);
	clear_options(data);
	return (type_idx);
}
