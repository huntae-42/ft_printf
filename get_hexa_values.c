/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hexa_values.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 22:35:59 by tjung             #+#    #+#             */
/*   Updated: 2020/11/26 03:12:03 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		get_hexa_values(t_printf *data)
{
	unsigned int	h;
	int				n;
	char			*s;

	h = va_arg(data->ap, unsigned int);
	if (h == 0 && (data->flags & FLAGS_HASH))
		data->flags = data->flags - FLAGS_HASH;
	n = how_many_digits_uint(h, 16);
	s = itoa_ui_base(h, n, data);
	data->itoa_s = s;
	check_and_print_hexa(data, s);
	if (s)
		free(s);
	s = NULL;
}

void		check_hash_and_set(t_printf *data, int *flag)
{
	if (data->flags & FLAGS_HASH)
	{
		print_hexa_notation(data);
		*flag = 2;
	}
}

void		if_minus_hexa(t_printf *data, char *s, int *i, int *j)
{
	int		k;
	int		flag;

	k = 0;
	flag = 0;
	check_hash_and_set(data, &flag);
	while (*j + k < data->pcs_value)
	{
		write(1, "0", 1);
		data->ret++;
		k++;
	}
	if_ui_pcs_dot_print_details(data, s, i, j);
	while (flag + k + (*i)++ < data->width_value)
	{
		write(1, " ", 1);
		data->ret++;
	}
}

void		if_unminus_hexa(t_printf *data, char *s, int *i, int *j)
{
	int		k;
	int		flag;

	k = 0;
	flag = 0;
	if (data->flags & FLAGS_HASH)
		flag = 2;
	unminus_hexa_details(data, &k, &flag, j);
	if_ui_pcs_dot_print_details(data, s, i, j);
}

void		check_and_print_hexa(t_printf *data, char *s)
{
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(s);
	if (data->flags & FLAGS_MINUS)
		if_minus_hexa(data, s, &i, &j);
	else
		if_unminus_hexa(data, s, &i, &j);
}
