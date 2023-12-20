# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anferre <anferre@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/20 10:47:22 by anferre           #+#    #+#              #
#    Updated: 2023/12/20 12:36:28 by anferre          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf_utils.c ft_printf_types.c ft_printf.c 

OBJS = $(SRCS:.c=.o)

CC = cc -g

AR = ar rc

CFLAGS = -Wall -Wextra -Werror 

$(NAME): $(OBJS)
	@make -C ./libft
# $(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	$(AR) $@ $^
	chmod +x $(NAME)

all: $(NAME)

clean:
	@make clean -C ./libft
	rm -f $(OBJS)

fclean: clean
	@make fclean -C ./libft
	rm -f $(NAME)

re: fclean all


.PHONY: clean fclean all re