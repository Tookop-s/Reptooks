NAME = libftprintf.a
LIBFT_DIR = libft

SRCS = printf_utils.c printf_types.c printf.c

OBJS = $(SRCS:.c=.o)

CC = cc

AR = ar rcs

CFLAGS = -Wall -Wextra -Werror -g


all: $(NAME)

$(NAME): libft $(OBJS)
	$(AR) $@ $^
# $@ refers to the target 'NAME', $^ refers to all of the prerequisites 'OBJS'

.c.o:
	$(CC)  $(CFLAGS) -c -o $@ $< 
# -c: Instructs the compiler to generate object files without linking.
# $<: Automatic variable representing the first prerequisite (the source file, in this case).
# -o $@: Specifies the output file (the target), in this case, the object file being built.
# patern rule

clean:
	@make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

libft:
	@make -C $(LIBFT_DIR)


.PHONY: clean fclean all re libft