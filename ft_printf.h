/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 16:31:58 by tjung             #+#    #+#             */
/*   Updated: 2020/11/27 17:00:13 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define FLAGS_MINUS 1
# define FLAGS_ZERO 2
# define FLAGS_HASH 4
# define FLAGS_BLANK 8
# define FLAGS_PLUS 16

# define WIDTH_WCC 1

# define PRECISION_DOT 1
# define PRECISION_WCC 2

typedef struct		s_printf
{
	char			type;
	unsigned char	flags;
	unsigned char	width;
	unsigned char	precision;
	int				width_value;
	int				pcs_value;
	int				base;
	int				ret;
	int				di_sign;
	char			*itoa_s;
	va_list			ap;
	char			*fmt;
}					t_printf;

void				init_data(t_printf *data);
int					free_data(t_printf *data);
int					ft_printf(const char *format, ...);

int					searching_type(t_printf *data, int fs);
void				set_options(t_printf *data, int fs, int tp);
int					parsing_data(t_printf *data, int fs);

void				get_flags(t_printf *data, int fs, int tp);
void				get_width_op(t_printf *data, int fs, int tp);
void				get_precision_op(t_printf *data, int fs, int tp);
void				get_wp_values(t_printf *data, int fs, int tp);

void				wv_detailed_check_wildcard(t_printf *data);
void				pv_detailed_check_wildcard(t_printf *data);
void				get_pcs_value(t_printf *data, int fs, int tp, int *i);
void				input_not_pwc_pcs_value(t_printf *data, char *temp);
void				input_not_wwc_pcs_value(t_printf *data,
												int fs, int tp, int *i);
void				wv_detailed_options(t_printf *data, int fs, int tp, int *i);

int					how_many_digits_uint(unsigned int n, int base);
int					how_many_digits_ulong(unsigned long n);
void				itoa_details(unsigned int *n, int *digits,
													t_printf *data, char *s);
char				*itoa_ui_base(unsigned int n, int digits, t_printf *data);
char				*itoa_pointer(unsigned long n, int digits);

void				handle_specifier(t_printf *data);

void				get_char_values(t_printf *data);
void				check_and_print_c(t_printf *data, char c);

void				get_string_values(t_printf *data);
void				if_minus_conditions(t_printf *data, char *s, int *i);
void				if_unminus_conditions(t_printf *data,
											char *s, int *i, int *len);
void				if_pcs_dot_print_details(t_printf *data, char *s, int *i);
void				check_and_print_s(t_printf *data, char *s);

void				get_pointer_values(t_printf *data);
void				print_hexa_notation(t_printf *data);
void				if_minus_pointer(t_printf *data, char *s, int *i, int *j);
void				check_hash_and_set(t_printf *data, int *flag);
void				if_unminus_pointer(t_printf *data, char *s, int *i, int *j);
void				pcs_value_over_j_p(t_printf *data, int *k, int *j);
void				pcs_value_under_j_p(t_printf *data, int *j);
void				check_and_print_p(t_printf *data, char *s);

void				get_int_values(t_printf *data);
void				print_sign_conditions(t_printf *data, int *cnt);
void				if_minus_di(t_printf *data, char *s, int *i, int *j);
void				if_unminus_di(t_printf *data, char *s, int *i, int *j);
void				unminus_di_details(t_printf *data,
											int *k, int *cnt, int *j);
void				pcs_value_over_j_di(t_printf *data,
											int *k, int *cnt, int *j);
void				pcs_value_under_j_di(t_printf *data, int *cnt, int *j);
void				check_and_print_di(t_printf *data, char *s);

void				get_uint_values(t_printf *data);
void				if_minus_ui(t_printf *data, char *s, int *i, int *j);
void				if_ui_pcs_dot_print_details(t_printf *data,
													char *s, int *i, int *j);
void				if_unminus_ui(t_printf *data, char *s, int *i, int *j);
void				check_and_print_ui(t_printf *data, char *s);

void				get_hexa_values(t_printf *data);
void				if_minus_hexa(t_printf *data, char *s, int *i, int *j);
void				if_unminus_hexa(t_printf *data, char *s, int *i, int *j);
void				unminus_hexa_details(t_printf *data,
											int *k, int *flag, int *j);
void				pcs_value_over_j(t_printf *data, int *k, int *flag, int *j);
void				pcs_value_under_j(t_printf *data, int *flag, int *j);
void				check_and_print_hexa(t_printf *data, char *s);

#endif
