NAME = get_next_line.a

SRCS = get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

CC = cc

AR = ar rcs

CFLAGS = -Wall -Wextra -Werror -g


all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

.c.o:
	$(CC)  $(CFLAGS) -c -o $@ $< 


clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all


.PHONY: clean fclean all re
