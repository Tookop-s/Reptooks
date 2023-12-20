NAME = libft.a

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c \
ft_substr.c ft_tolower.c ft_toupper.c 


SRCS_BONUS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

CC = cc

AR = ar rc

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
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

bonus: $(NAME) $(OBJS_BONUS)
	$(AR) $(NAME) -o $^

.PHONY: clean fclean all re bonus
