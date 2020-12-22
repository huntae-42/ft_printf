/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_s_values.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 20:03:49 by tjung             #+#    #+#             */
/*   Updated: 2020/11/26 02:09:08 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		get_string_values(t_printf *data)
{
	char	*s;

	s = va_arg(data->ap, char *);
	if (s == NULL)
		s = "(null)";
	check_and_print_s(data, s);
}

void		if_minus_conditions(t_printf *data, char *s, int *i)
{
	if (data->precision & PRECISION_DOT)
		while (*i < data->pcs_value && s[*i] != '\0')
		{
			write(1, &s[(*i)++], 1);
			data->ret++;
		}
	else
		while (s[*i] != '\0')
		{
			write(1, &s[(*i)++], 1);
			data->ret++;
		}
	while (*i < data->width_value)
	{
		write(1, " ", 1);
		data->ret++;
		(*i)++;
	}
}

void		if_pcs_dot_print_details(t_printf *data, char *s, int *i)
{
	if (data->precision & PRECISION_DOT)
		while (*i < data->pcs_value && s[*i] != '\0')
		{
			write(1, &s[(*i)++], 1);
			data->ret++;
		}
	else
		while (s[*i] != '\0')
		{
			write(1, &s[(*i)++], 1);
			data->ret++;
		}
}

void		if_unminus_conditions(t_printf *data, char *s, int *i, int *len)
{
	int		j;

	j = 0;
	while (j < data->pcs_value && s[j] != '\0')
		j++;
	if (!(data->precision & PRECISION_DOT))
		j = *len;
	while (j < data->width_value)
	{
		if (data->flags & FLAGS_ZERO)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		data->ret++;
		j++;
	}
	if_pcs_dot_print_details(data, s, i);
}

void		check_and_print_s(t_printf *data, char *s)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s);
	if (data->flags & FLAGS_MINUS)
		if_minus_conditions(data, s, &i);
	else
		if_unminus_conditions(data, s, &i, &len);
}
