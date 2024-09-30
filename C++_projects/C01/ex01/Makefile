# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anferre <anferre@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/12 09:49:54 by gchamore          #+#    #+#              #
#    Updated: 2024/09/30 13:35:40 by anferre          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = Moar_brainz

CC = c++

CFLAGS = -Wall -Wextra -Werror -g3 -std=c++98

RM = rm -rf

SRCS =  main.cpp Zombie.cpp zombieHorde.cpp

OBJ_DIR = objs

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))

DEPS = $(OBJS:.o=.d)

ifeq ($(DEBUG), true)
	CFLAGS += -DDEBUG=true
else
	CFLAGS += -DDEBUG=false
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CC)  $(CFLAGS) -MMD -c -o $@ $<

debug: 
	$(MAKE) DEBUG=true re

release:
	$(MAKE) DEBUG=false re

clean:
	$(RM) $(OBJS) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re debug release

-include $(DEPS)

