/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_options.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:47:04 by tjung             #+#    #+#             */
/*   Updated: 2020/11/26 05:04:50 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		get_flags(t_printf *data, int fs, int tp)
{
	int		i;

	i = 1;
	while (fs + i < tp)
	{
		if (ft_strchr("123456789", data->fmt[fs + i]))
			while (fs + i < tp)
			{
				if (!(ft_strchr("0123456789", data->fmt[fs + i])))
					break ;
				++i;
			}
		if (data->fmt[fs + i] == '-')
			data->flags |= FLAGS_MINUS;
		else if ((data->fmt[fs + i] == '0') && !(data->fmt[fs + i - 1] == '.'))
			data->flags |= FLAGS_ZERO;
		else if (data->fmt[fs + i] == '#')
			data->flags |= FLAGS_HASH;
		else if (data->fmt[fs + i] == ' ')
			data->flags |= FLAGS_BLANK;
		else if (data->fmt[fs + i] == '+')
			data->flags |= FLAGS_PLUS;
		++i;
	}
}

void		get_width_op(t_printf *data, int fs, int tp)
{
	int		i;

	i = 1;
	while (fs + i < tp)
	{
		if (data->fmt[fs + i - 1] != '.')
			if (data->fmt[fs + i] == '*')
				data->width |= WIDTH_WCC;
		++i;
	}
}

void		get_precision_op(t_printf *data, int fs, int tp)
{
	int		i;

	i = 1;
	while (fs + i < tp)
	{
		if (data->fmt[fs + i] == '.')
		{
			data->precision |= PRECISION_DOT;
			if (data->fmt[fs + i + 1] == '*')
				data->precision |= PRECISION_WCC;
		}
		++i;
	}
}

void		get_wp_values(t_printf *data, int fs, int tp)
{
	int		i;

	i = 1;
	while (fs + i < tp)
	{
		if (data->width & WIDTH_WCC)
		{
			if (data->fmt[fs + i] == '*' && data->fmt[fs + i - 1] != '.')
				wv_detailed_check_wildcard(data);
			else if (data->fmt[fs + i] == '.')
			{
				get_pcs_value(data, fs, tp, &i);
				if (data->pcs_value == -2)
					break ;
			}
		}
		else
		{
			input_not_wwc_pcs_value(data, fs, tp, &i);
			if (data->pcs_value == -2)
				break ;
		}
		i++;
	}
}
