NAME = philosophers

SRCS_DIR = srcs

SRCS = philosopher_main.c \
		philosopher_utils.c 

OBJ_DIR = objs
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

DEPS = $(OBJS:.o=.d) 

CC = cc
CFLAGS = -Wall -Werror -Wextra -g3 -Iincludes -fPIE -pthread

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@  $^

$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -MMD -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) 

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: clean fclean all re 
