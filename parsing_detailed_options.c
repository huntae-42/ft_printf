/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_detailed_options.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:20:41 by tjung             #+#    #+#             */
/*   Updated: 2020/11/26 02:06:50 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		wv_detailed_check_wildcard(t_printf *data)
{
	int		temp;

	temp = va_arg(data->ap, int);
	if (temp < 0)
	{
		data->flags |= FLAGS_MINUS;
		temp *= -1;
	}
	data->width_value = temp;
}

void		pv_detailed_check_wildcard(t_printf *data)
{
	int		temp;

	temp = va_arg(data->ap, int);
	if (temp < 0)
	{
		data->precision = data->precision - (PRECISION_DOT + PRECISION_WCC);
		data->pcs_value = -1;
	}
	else
		data->pcs_value = temp;
}

void		pass_zero(t_printf *data, int fs, int *i, int *start)
{
	while (data->fmt[fs + *i] == '0')
		++(*i);
	*start = *i;
}

void		get_pcs_value(t_printf *data, int fs, int tp, int *i)
{
	char	*temp;
	int		start;

	++(*i);
	if (data->precision & PRECISION_DOT)
	{
		if (data->fmt[fs + *i] == '*' && data->fmt[fs + *i - 1] == '.')
			pv_detailed_check_wildcard(data);
		else
		{
			pass_zero(data, fs, i, &start);
			while (fs + *i < tp)
			{
				if (!(ft_strchr("0123456789", data->fmt[fs + *i])))
					break ;
				++(*i);
			}
			temp = ft_substr(data->fmt, fs + start, *i - start);
			input_not_pwc_pcs_value(data, temp);
			if (temp)
				free(temp);
			temp = NULL;
			--(*i);
		}
	}
}

void		wv_detailed_options(t_printf *data, int fs, int tp, int *i)
{
	char	*temp;
	int		start;

	temp = NULL;
	start = 0;
	if (ft_strchr("123456789", data->fmt[fs + *i]))
	{
		start = (*i)++;
		while (fs + *i < tp)
		{
			if (!(ft_strchr("0123456789", data->fmt[fs + *i])))
				break ;
			(*i)++;
		}
		temp = ft_substr(data->fmt, fs + start, *i - start);
		data->width_value = ft_atoi(temp);
		if (temp)
			free(temp);
		temp = NULL;
		(*i)--;
	}
}
