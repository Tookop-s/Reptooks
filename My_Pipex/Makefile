NAME = pipex

LIBFT_DIR = libft

SRCS_DIR = srcs
SRCS = pipex_main.c pipex_utils.c

OBJ_DIR = objs
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

DEPS = $(OBJS:.o=.d)


CC = cc
CFLAGS = -Wall -Werror -Wextra -g3 -Iinclude -fPIE

all: $(NAME)

$(LIBFT_DIR)/libft.a: FORCE
	$(MAKE) -C $(LIBFT_DIR) 

$(NAME): $(OBJS)  $(LIBFT_DIR)/libft.a
	$(CC) $(CFLAGS) -o $@  $^ -lXext -lX11 -lm


$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -MMD -c $< -o $@

FORCE:

clean:
	@echo "Cleaning"
	$(MAKE) clean -sC $(LIBFT_DIR)
	rm -rf $(OBJ_DIR)

fclean: clean
	@echo "Full Cleaning"
	$(MAKE) fclean -sC $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all
	
-include $(DEPS)

.PHONY: clean fclean all re
