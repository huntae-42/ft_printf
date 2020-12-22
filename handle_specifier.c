/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_specifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:20:20 by tjung             #+#    #+#             */
/*   Updated: 2020/11/24 22:41:21 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		handle_specifier(t_printf *data)
{
	if (data->type == 'c' || data->type == '%')
		get_char_values(data);
	else if (data->type == 's')
		get_string_values(data);
	else if (data->type == 'p')
		get_pointer_values(data);
	else if (data->type == 'd' || data->type == 'i')
		get_int_values(data);
	else if (data->type == 'u')
		get_uint_values(data);
	else if (data->type == 'x' || data->type == 'X')
		get_hexa_values(data);
}
