NAME = fdf

LIBFT_DIR = libft
MINILIBX_DIR = minilibx

SRCS = fdf_main.c fdf_utils.c fdf_parsing.c fdf_parsing_utils.c fdf_projection.c fdf_projection_utils.c

OBJ_DIR = objs
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

DEPS = $(OBJS:.o=.d)


GCC = gcc
CFLAGS = -Wall -Werror -Wextra -g3 -Iinclude -fPIE

all: $(NAME)

$(LIBFT_DIR)/libft.a: FORCE
	$(MAKE) -C $(LIBFT_DIR) 

$(MINILIBX_DIR)/libmlx.a: FORCE
	$(MAKE) -C $(MINILIBX_DIR)

$(NAME): $(OBJS)  $(LIBFT_DIR)/libft.a $(MINILIBX_DIR)/libmlx.a
	$(GCC) $(CFLAGS) -o $@  $^ $(MINILIBX_DIR)/libmlx.a -lXext -lX11 -lm


$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(GCC) $(CFLAGS) -MMD -c $< -o $@

FORCE:

clean:
	@echo "Cleaning"
	$(MAKE) clean -sC $(LIBFT_DIR)
	$(MAKE) clean -sC $(MINILIBX_DIR)	
	rm -rf $(OBJ_DIR)

fclean: clean
	@echo "Full Cleaning"
	$(MAKE) fclean -sC $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all
	
-include $(DEPS)

.PHONY: clean fclean all re
