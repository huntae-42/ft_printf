/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_i_values.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 22:36:58 by tjung             #+#    #+#             */
/*   Updated: 2020/11/26 02:11:47 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		get_int_values(t_printf *data)
{
	int				di;
	unsigned int	udi;
	int				n;
	char			*s;

	data->di_sign = 1;
	di = va_arg(data->ap, int);
	if (di < 0)
	{
		udi = (-1) * di;
		data->di_sign = -1;
	}
	else
		udi = di;
	n = how_many_digits_uint(udi, 10);
	s = itoa_ui_base(udi, n, data);
	data->itoa_s = s;
	check_and_print_di(data, s);
	if (s)
		free(s);
	s = NULL;
}

void		print_sign_conditions(t_printf *data, int *cnt)
{
	if (data->di_sign == -1)
	{
		write(1, "-", 1);
		data->ret++;
		*cnt = 1;
	}
	else
	{
		if (data->flags & FLAGS_PLUS)
		{
			write(1, "+", 1);
			data->ret++;
			*cnt = 1;
		}
		else if (data->flags & FLAGS_BLANK)
		{
			write(1, " ", 1);
			data->ret++;
			*cnt = 1;
		}
	}
}

void		if_minus_di(t_printf *data, char *s, int *i, int *j)
{
	int		sign_cnt;
	int		k;

	sign_cnt = 0;
	k = 0;
	print_sign_conditions(data, &sign_cnt);
	while (*j + k < data->pcs_value)
	{
		write(1, "0", 1);
		data->ret++;
		k++;
	}
	if_ui_pcs_dot_print_details(data, s, i, j);
	while (sign_cnt + k + (*i)++ < data->width_value)
	{
		write(1, " ", 1);
		data->ret++;
	}
}

void		if_unminus_di(t_printf *data, char *s, int *i, int *j)
{
	int		sign_cnt;
	int		k;

	sign_cnt = 0;
	k = 0;
	if ((data->di_sign == -1)
			|| (data->flags & FLAGS_PLUS) || (data->flags & FLAGS_BLANK))
		sign_cnt = 1;
	unminus_di_details(data, &k, &sign_cnt, j);
	if_ui_pcs_dot_print_details(data, s, i, j);
}

void		check_and_print_di(t_printf *data, char *s)
{
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(s);
	if (data->flags & FLAGS_MINUS)
		if_minus_di(data, s, &i, &j);
	else
		if_unminus_di(data, s, &i, &j);
}
