/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_p_values.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 21:23:02 by tjung             #+#    #+#             */
/*   Updated: 2020/11/26 03:17:39 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		get_pointer_values(t_printf *data)
{
	void	*p;
	int		n;
	char	*s;

	p = va_arg(data->ap, void *);
	n = how_many_digits_ulong((unsigned long)p);
	s = itoa_pointer((unsigned long)p, n);
	check_and_print_p(data, s);
	if (s)
		free(s);
	s = NULL;
}

void		print_hexa_notation(t_printf *data)
{
	if (data->type == 'X')
		write(1, "0X", 2);
	else
		write(1, "0x", 2);
	data->ret += 2;
}

void		if_minus_pointer(t_printf *data, char *s, int *i, int *j)
{
	int		k;

	k = 0;
	print_hexa_notation(data);
	while (*j + k < data->pcs_value)
	{
		write(1, "0", 1);
		data->ret++;
		k++;
	}
	if_ui_pcs_dot_print_details(data, s, i, j);
	while (*i + 2 + k < data->width_value)
	{
		write(1, " ", 1);
		data->ret++;
		(*i)++;
	}
}

void		if_unminus_pointer(t_printf *data, char *s, int *i, int *j)
{
	int		k;
	int		zero;

	k = 0;
	zero = 0;
	if (data->pcs_value > *j)
		pcs_value_over_j_p(data, &k, j);
	else
	{
		if (*j == 1 && s[0] == '0' && data->pcs_value == 0
						&& (data->precision & PRECISION_DOT))
			pcs_value_under_j_p(data, &zero);
		else
			pcs_value_under_j_p(data, j);
	}
	if_ui_pcs_dot_print_details(data, s, i, j);
}

void		check_and_print_p(t_printf *data, char *s)
{
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(s);
	if (data->flags & FLAGS_MINUS)
		if_minus_pointer(data, s, &i, &j);
	else
		if_unminus_pointer(data, s, &i, &j);
}
