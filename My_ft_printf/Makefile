# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anferre <anferre@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/20 10:47:22 by anferre           #+#    #+#              #
#    Updated: 2024/01/03 17:16:42 by anferre          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf_utils.c ft_printf.c ft_printf_types_c_s_p.c \
ft_printf_types_d_i_u.c ft_printf_types_x_X_%.c

OBJS = $(SRCS:.c=.o)

CC = cc

AR = ar rcs

CFLAGS = -Wall -Wextra -Werror -g

$(NAME): $(OBJS)
	$(AR) $@ $^

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all


.PHONY: clean fclean all re