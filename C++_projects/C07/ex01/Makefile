# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anferre <anferre@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/12 09:49:54 by gchamore          #+#    #+#              #
#    Updated: 2024/11/28 16:55:58 by anferre          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Iter

CXX = c++

INCLUDE_DIR = -IFormat -IHeaders
CFLAGSX = -Wall -Wextra -Werror -Wno-conversion -g3 -std=c++98 $(INCLUDE_DIR)

RM = rm -rf

SRCS_DIR = srcs
SRCS_FILES = main.cpp
SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))

OBJ_DIR = objs

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:$(SRCS_DIR)/%.cpp=%.o))

DEPS = $(OBJS:.o=.d)

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

