# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anferre <anferre@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/12 09:49:54 by gchamore          #+#    #+#              #
#    Updated: 2024/09/24 14:06:42 by anferre          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = Sed_is_for_losers

CC = c++

CFLAGS = -Wall -Wextra -Werror -g3 -std=c++98 -MMD

RM = rm -rf

SRCS =  main.cpp 

OBJ_DIR = objs

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))

DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CC)  $(CFLAGS)  -c -o $@ $<


clean:
	$(RM) $(OBJS) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)

