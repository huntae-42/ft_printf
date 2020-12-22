/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ui_values.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 22:37:52 by tjung             #+#    #+#             */
/*   Updated: 2020/11/26 02:14:00 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		get_uint_values(t_printf *data)
{
	unsigned int	u;
	int				n;
	char			*s;

	u = va_arg(data->ap, unsigned int);
	n = how_many_digits_uint(u, 10);
	s = itoa_ui_base(u, n, data);
	check_and_print_ui(data, s);
	if (s)
		free(s);
	s = NULL;
}

void		if_ui_pcs_dot_print_details(t_printf *data, char *s, int *i, int *j)
{
	if (data->precision & PRECISION_DOT)
	{
		while (s[*i] != '\0'
				&& (!(*j == 1 && s[0] == '0' && data->pcs_value == 0)))
		{
			write(1, &s[(*i)++], 1);
			data->ret++;
		}
	}
	else
	{
		while (s[*i] != '\0')
		{
			write(1, &s[(*i)++], 1);
			data->ret++;
		}
	}
}

void		if_minus_ui(t_printf *data, char *s, int *i, int *j)
{
	int		k;

	k = 0;
	while (*j + k < data->pcs_value)
	{
		write(1, "0", 1);
		data->ret++;
		k++;
	}
	if_ui_pcs_dot_print_details(data, s, i, j);
	while (*i + k < data->width_value)
	{
		write(1, " ", 1);
		data->ret++;
		(*i)++;
	}
}

void		if_unminus_ui(t_printf *data, char *s, int *i, int *j)
{
	int		k;
	int		zero1;
	int		zero2;

	k = 0;
	zero1 = 0;
	zero2 = 0;
	if (data->pcs_value > *j)
		pcs_value_over_j(data, &k, &zero1, j);
	else
	{
		if (*j == 1 && s[0] == '0' && data->pcs_value == 0
								&& (data->precision & PRECISION_DOT))
			pcs_value_under_j(data, &zero1, &zero2);
		else
			pcs_value_under_j(data, &zero1, j);
	}
	if_ui_pcs_dot_print_details(data, s, i, j);
}

void		check_and_print_ui(t_printf *data, char *s)
{
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(s);
	if (data->flags & FLAGS_MINUS)
		if_minus_ui(data, s, &i, &j);
	else
		if_unminus_ui(data, s, &i, &j);
}
