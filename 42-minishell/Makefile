# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anferre <anferre@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/30 13:03:12 by gchamore          #+#    #+#              #
#    Updated: 2024/07/04 13:48:43 by anferre          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc

VALGRIND = valgrind

CFLAGS = -Wall -Wextra -Werror -g3 -I./headers/

RM = rm -rf

SRCS_DIR = srcs

SRCS_MINISHELL = $(addprefix $(SRCS_DIR)/, \
	main.c 									\
	prompt.c 								\
	lexing.c 								\
	lexing_tokens.c							\
	init.c 									\
	grammar_check.c 						\
	grammar.c								\
	grammar_syntax.c						\
	parsing.c 								\
	expansion.c 							\
	expansion_expand.c						\
	expansion_expand_utils.c				\
	expansion_utils_2.c						\
	expansion_utils.c						\
	expansion_ifs.c							\
	expansion_pathname.c					\
	expansion_pathname_utils.c				\
	destroy.c								\
	destroy_2.c			 					\
	destroy_mini.c	 						\
	parsing.c \
	parsing_operator.c \
	parsing_command.c \
	parsing_utils.c \
	exec.c \
	built_in_1.c \
	built_in_2.c \
	built_in_3.c \
	built_in_4.c \
	exec_utils.c \
	exec_built_in.c \
	exec_cmd.c \
	exec_redir.c \
	pipex_mini.c \
	pipex_mini_utils.c \
	pipex_mini_exec.c \
	pipex_mini_exec_utils.c \
	here_doc.c \
	here_doc_utils.c \
	signaux.c \
	)

OBJ_DIR = objs

OBJS_MINISHELL = $(patsubst $(SRCS_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS_MINISHELL))

DEPS = $(OBJS_MINISHELL:.o=.d)

all: first_header $(NAME) second_header

$(NAME): $(OBJS_MINISHELL)
	$(MAKE) -sC ./libft
	$(CC) $(CFLAGS) -o $@ $^ libft/libft.a -lreadline

$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(@D)
	$(CC)  $(CFLAGS) -MMD -c -o $@ $<

bonus: $(NAME)

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS_MINISHELL) $(DEPS) $(OBJ_DIR)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re



info: header

first_header:
	@echo "\n $$FIRST_HEADER \n"

define FIRST_HEADER

⠀⠀⠀⠀⠀⠀⠀⠀⠀⡴⠞⠉⢉⣭⣿⣿⠿⣳⣤⠴⠖⠛⣛⣿⣿⡷⠖⣶⣤⡀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⣼⠁⢀⣶⢻⡟⠿⠋⣴⠿⢻⣧⡴⠟⠋⠿⠛⠠⠾⢛⣵⣿⠀⠀⠀⠀
⣼⣿⡿⢶⣄⠀⢀⡇⢀⡿⠁⠈⠀⠀⣀⣉⣀⠘⣿⠀⠀⣀⣀⠀⠀⠀⠛⡹⠋⠀⠀⠀⠀
⣭⣤⡈⢑⣼⣻⣿⣧⡌⠁⠀⢀⣴⠟⠋⠉⠉⠛⣿⣴⠟⠋⠙⠻⣦⡰⣞⠁⢀⣤⣦⣤⠀
⠀⠀⣰⢫⣾⠋⣽⠟⠑⠛⢠⡟⠁⠀⠀⠀⠀⠀⠈⢻⡄⠀⠀⠀⠘⣷⡈⠻⣍⠤⢤⣌⣀
⢀⡞⣡⡌⠁⠀⠀⠀⠀⢀⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⢿⡀⠀⠀⠀⠸⣇⠀⢾⣷⢤⣬⣉
⡞⣼⣿⣤⣄⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀⣿⠀⠸⣿⣇⠈⠻
⢰⣿⡿⢹⠃⠀⣠⠤⠶⣼⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀⣿⠀⠀⣿⠛⡄⠀
⠈⠉⠁⠀⠀⠀⡟⡀⠀⠈⡗⠲⠶⠦⢤⣤⣤⣄⣀⣀⣸⣧⣤⣤⠤⠤⣿⣀⡀⠉⣼⡇⠀
⣿⣴⣴⡆⠀⠀⠻⣄⠀⠀⠡⠀⠀⠀⠈⠛⠋⠀⠀⠀⡈⠀⠻⠟⠀⢀⠋⠉⠙⢷⡿⡇⠀
⣻⡿⠏⠁⠀⠀⢠⡟⠀⠀⠀⠣⡀⠀⠀⠀⠀⠀⢀⣄⠀⠀⠀⠀⢀⠈⠀⢀⣀⡾⣴⠃⠀
⢿⠛⠀⠀⠀⠀⢸⠁⠀⠀⠀⠀⠈⠢⠄⣀⠠⠼⣁⠀⡱⠤⠤⠐⠁⠀⠀⣸⠋⢻⡟⠀⠀
⠈⢧⣀⣤⣶⡄⠘⣆⠀⠀⠀⠀⠀⠀⠀⢀⣤⠖⠛⠻⣄⠀⠀⠀⢀⣠⡾⠋⢀⡞⠀⠀⠀
⠀⠀⠻⣿⣿⡇⠀⠈⠓⢦⣤⣤⣤⡤⠞⠉⠀⠀⠀⠀⠈⠛⠒⠚⢩⡅⣠⡴⠋⠀⠀⠀⠀
⠀⠀⠀⠈⠻⢧⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⣻⠿⠋⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠉⠓⠶⣤⣄⣀⡀⠀⠀⠀⠀⠀⢀⣀⣠⡴⠖⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀

endef
export FIRST_HEADER

second_header:
	@echo "\n$$SECOND_HEADER \n"

define SECOND_HEADER
██████████████████████████████████████████████████████████████████████
█▌                                                                  ▐█
█▌                                                                  ▐█
█▌  ██╗  ██╗██████╗     ██████╗  ██████╗ ██████╗ ███╗   ██╗         ▐█
█▌  ██║  ██║╚════██╗    ██╔══██╗██╔═══██╗██╔══██╗████╗  ██║         ▐█
█▌  ███████║ █████╔╝    ██████╔╝██║   ██║██████╔╝██╔██╗ ██║         ▐█
█▌  ╚════██║██╔═══╝     ██╔══██╗██║   ██║██╔══██╗██║╚██╗██║         ▐█
█▌       ██║███████╗    ██████╔╝╚██████╔╝██║  ██║██║ ╚████║         ▐█
█▌       ╚═╝╚══════╝    ╚═════╝  ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═══╝         ▐█
█▌                                                                  ▐█
█▌  ████████╗ ██████╗      ██████╗ ██████╗ ██████╗ ███████╗    ██╗  ▐█
█▌  ╚══██╔══╝██╔═══██╗    ██╔════╝██╔═══██╗██╔══██╗██╔════╝    ██║  ▐█
█▌     ██║   ██║   ██║    ██║     ██║   ██║██║  ██║█████╗      ██║  ▐█
█▌     ██║   ██║   ██║    ██║     ██║   ██║██║  ██║██╔══╝      ╚═╝  ▐█
█▌     ██║   ╚██████╔╝    ╚██████╗╚██████╔╝██████╔╝███████╗    ██╗  ▐█
█▌     ╚═╝    ╚═════╝      ╚═════╝ ╚═════╝ ╚═════╝ ╚══════╝    ╚═╝  ▐█
█▌                                                                  ▐█
█▌                                                                  ▐█
█▌                                                                  ▐█
██████████████████████████████████████████████████████████████████████
endef
export SECOND_HEADER

header:
	@echo "$$FIRST_HEADER"
	@echo "$$SECOND_HEADER"