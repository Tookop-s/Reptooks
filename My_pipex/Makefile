NAME = pipex

LIBFT_DIR = libft

SRCS_DIR = srcs
SRCS_DIR_BONUS = srcs_bonus

SRCS = pipex_main.c pipex_utils_1.c  pipex_exec_utils.c pipex_exec.c pipex_signals.c pipex_utils_2.c

SRCS_BONUS = pipex_main_bonus.c pipex_utils_1_bonus.c  pipex_exec_utils_bonus.c pipex_exec_bonus.c pipex_signals_bonus.c pipex_utils_2_bonus.c

OBJ_DIR = objs
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
OBJS_BONUS = $(addprefix $(OBJ_DIR)/, $(SRCS_BONUS:.c=.o))

DEPS = $(OBJS:.o=.d) $(OBJS_BONUS:.o=.d)

CC = cc
CFLAGS = -Wall -Werror -Wextra -g3 -Iincludes -fPIE

OBJS_USED = $(OBJS)
SRCS_USED = $(SRCS_DIR)

# The variable MAKECMDGOALS contains the list of targets specified on the command line when invoking make.
ifeq ($(MAKECMDGOALS),bonus)
	OBJS_USED = $(OBJS_BONUS)
	SRCS_USED = $(SRCS_DIR_BONUS)
endif

all: $(NAME)

$(LIBFT_DIR)/libft.a: FORCE
	$(MAKE) -C $(LIBFT_DIR) 

$(NAME): $(OBJS_USED) $(LIBFT_DIR)/libft.a
	$(CC) $(CFLAGS) -o $@  $^

$(OBJ_DIR)/%.o: $(SRCS_USED)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -MMD -c $< -o $@

FORCE:

clean:
	echo "Cleaning"
	$(MAKE) clean -sC $(LIBFT_DIR)
	rm -rf $(OBJ_DIR) $(OBJ_DIR_BONUS)

fclean: clean
	echo "Full Cleaning"
	$(MAKE) fclean -sC $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

bonus:$(NAME)
	
-include $(DEPS)
-include $(DEPS_BONUS)

.PHONY: clean fclean all re bonus
