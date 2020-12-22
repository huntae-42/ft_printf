# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjung <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/24 18:08:11 by tjung             #+#    #+#              #
#    Updated: 2020/11/26 06:17:30 by tjung            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

LIBFT		= libft
LIBFT_LIB	= libft.a

SRCS		= ./ft_printf.c \
			  ./parsing_data.c \
			  ./parsing_options.c \
			  ./parsing_detailed_options.c \
			  ./parsing_detailed_details.c \
			  ./handle_specifier.c \
			  ./itoa_base.c \
			  ./get_c_values.c \
			  ./get_s_values.c \
			  ./get_p_values.c \
			  ./get_p_details.c \
			  ./get_i_values.c \
			  ./get_i_details.c \
			  ./get_ui_values.c \
			  ./get_hexa_values.c \
			  ./get_hexa_details.c

OBJS		= $(SRCS:.c=.o)

INCS		= .
RM			= rm -rf
LIBC		= ar rcs
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(INCS)

$(NAME) : $(OBJS)
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	$(LIBC) $(NAME) $(OBJS)

all : $(NAME)

bonus : $(NAME)

clean :
	$(RM) $(OBJS)
	make clean -C $(LIBFT)

fclean : clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT)

re : fclean all

.PHONY: all, clean, fclean, re, bonus
