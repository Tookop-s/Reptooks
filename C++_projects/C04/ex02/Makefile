# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anferre <anferre@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/12 09:49:54 by gchamore          #+#    #+#              #
#    Updated: 2024/10/21 14:11:31 by anferre          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = AAnimal

CXX = c++

INCLUDE_DIR = -IFormat -IHeaders
CFLAGSX = -Wall -Wextra -Werror -g3 -std=c++98 $(INCLUDE_DIR)

RM = rm -rf

SRCS_DIR = srcs
SRCS_FILES = AAnimal.cpp Cat.cpp Dog.cpp Brain.cpp main.cpp
SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))

OBJ_DIR = objs

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:$(SRCS_DIR)/%.cpp=%.o))

DEPS = $(OBJS:.o=.d)

ifeq ($(DEBUG), true)
	CFLAGS += -DDEBUG=true
else
	CFLAGS += -DDEBUG=false
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CFLAGSX) -o $@ $^

$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX)  $(CFLAGSX) -MMD -c -o $@ $<

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

