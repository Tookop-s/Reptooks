NAME = get_next_line.a

SRCS = get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

CC = cc

AR = ar rcs

CFLAGS = -Wall -Wextra -Werror -g


all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^
# $@ refers to the target 'NAME', $^ refers to all of the prerequisites 'OBJS'

.c.o:
	$(CC)  $(CFLAGS) -c -o $@ $< 
# -c: Instructs the compiler to generate object files without linking.
# $<: Automatic variable representing the first prerequisite (the source file, in this case).
# -o $@: Specifies the output file (the target), in this case, the object file being built.
# patern rule

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all


.PHONY: clean fclean all re
