NAME = push_swap
LIBFT_DIR = libft

SRCS = push_swap.c push_swap_sort.c push_swap_sort_a.c push_swap_sort_utils.c


OBJ_DIR = objs

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS_A:.c=.o))


DEPS = $(OBJS:.o=.d)


CC := cc
CFLAGS = -Wall -Werror -Wextra -g3 -Iinclude

all: FORCE $(NAME)

$(LIBFT_DIR)/libft.a: FORCE
	$(MAKE) -C $(LIBFT_DIR) -s

$(NAME): $(LIBFT_DIR)/libft.a $(OBJS)
	$(CC) -o $@ $^ $(LIBFT_DIR)/libft.a $(CFLAGS)


$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) -MMD -c -o $@ $< $(CFLAGS)

$(OBJ_DIR_BONUS)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) -MMD -c -o $@ $< $(CFLAGS)
	
FORCE:
	 	

clean:
	@echo "Cleaning"
	$(MAKE) -C $(LIBFT_DIR) clean -s
	rm -rf $(OBJ_DIR) $(OBJ_DIR_BONUS)

fclean: clean
	@echo "Full Cleaning"
	$(MAKE) -C $(LIBFT_DIR) fclean -s
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all
	

-include $(DEPS)

.PHONY: clean fclean all re
