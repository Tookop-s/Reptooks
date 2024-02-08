NAME = push_swap
NAME_BONUS = checker
LIBFT_DIR = My_libft

SRCS = push_swap.c push_swap_sort.c push_swap_sort_a.c push_swap_sort_utils.c

SRCS_SHARED = push_swap_opreverse.c push_swap_oprotate.c push_swap_oppush.c push_swap_opswap.c\
push_swap_utils.c push_swap_parsing.c push_swap_parsing_utils.c

SRCS_BONUS = push_swap_checker.c push_swap_checker_utils1.c push_swap_checker_utils2.c

SRCS_A = $(SRCS) $(SRCS_SHARED)
SRCS_B = $(SRCS_SHARED) $(SRCS_BONUS)

OBJ_DIR = objs
OBJ_DIR_BONUS = obj_bonus
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS_A:.c=.o))
OBJS_BONUS = $(addprefix $(OBJ_DIR_BONUS)/, $(SRCS_B:.c=.o))

DEPS = $(OBJS:.o=.d)
DEPS_BONUS = $(OBJS_BONUS:.o=.d)

CC := cc
CFLAGS = -Wall -Werror -Wextra -g3 -Iinclude

all: FORCE $(NAME)

$(LIBFT_DIR)/libft.a: FORCE
	$(MAKE) -C $(LIBFT_DIR) -s

$(NAME): $(LIBFT_DIR)/libft.a $(OBJS)
	$(CC) -o $@ $^ $(LIBFT_DIR)/libft.a $(CFLAGS)

$(NAME_BONUS): $(LIBFT_DIR)/libft.a $(OBJS_BONUS)
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

bonus: $(NAME_BONUS)
	

-include $(DEPS)
-include $(DEPS_BONUS)

.PHONY: clean fclean all re bonus
