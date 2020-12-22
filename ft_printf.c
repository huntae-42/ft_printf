/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 16:19:53 by tjung             #+#    #+#             */
/*   Updated: 2020/11/25 19:59:21 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		init_data(t_printf *data)
{
	data->type = 0;
	data->flags = 0;
	data->width = 0;
	data->precision = 0;
	data->base = 0;
	data->width_value = 0;
	data->pcs_value = 0;
	data->ret = 0;
	data->di_sign = 0;
	data->itoa_s = NULL;
	data->fmt = NULL;
}

int			free_data(t_printf *data)
{
	int		ret;

	ret = data->ret;
	init_data(data);
	va_end(data->ap);
	free(data);
	data = NULL;
	return (ret);
}

int			ft_printf(const char *format, ...)
{
	t_printf	*data;
	int			i;

	if (!(data = (t_printf *)malloc(sizeof(t_printf))))
		return (-1);
	init_data(data);
	data->fmt = (char *)format;
	va_start(data->ap, format);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			i = parsing_data(data, i);
		else
		{
			write(1, &format[i], 1);
			++data->ret;
		}
		if (i < 0)
			return (free_data(data));
		i++;
	}
	return (free_data(data));
}
