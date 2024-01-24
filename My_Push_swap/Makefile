NAME = push_swap
LIBFT_DIR = My_libft

SRCS = push_swap.c push_swap_parsing.c push_swap_utils.c push_swap_opswap.c \
push_swap_opreverse.c push_swap_oprotate.c push_swap_oppush.c

OBJ_DIR = objs
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
DEPS = $(OBJS:.o=.d)

CC := cc
CFLAGS = -Wall -Werror -Wextra -g3 -Iinclude

all: FORCE $(LIBFT_DIR)/libft.a $(NAME)

FORCE:
	$(MAKE) -C $(LIBFT_DIR) -s

$(LIBFT_DIR)/libft.a:
	$(MAKE) -C $(LIBFT_DIR) -s

$(NAME): $(LIBFT_DIR)/libft.a $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT_DIR)/libft.a

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC)  $(CFLAGS) -MMD -c -o $@ $<


clean:
	@echo "Cleaning"
	@$(MAKE) -C $(LIBFT_DIR) clean -s
	rm -rf $(OBJ_DIR)

fclean: clean
	@echo "Full Cleaning"
	$(MAKE) -C $(LIBFT_DIR) fclean -s
	rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: clean fclean all re

