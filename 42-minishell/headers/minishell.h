/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:58:37 by gchamore          #+#    #+#             */
/*   Updated: 2024/07/04 14:15:36 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <limits.h>
# include <errno.h>
# include <dirent.h>
# include <stdint.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft.h"
# include <sys/wait.h>
# include <signal.h>
# include <fcntl.h>

extern volatile sig_atomic_t	g_got_signal;

typedef enum e_exit_code
{
	NO_EXIT = -1,
	EXIT_SUCCEED = 0,
	EXIT_FAILED = 1,
}	t_exit_code;

typedef enum e_bool
{
	false = 0,
	true = 1
}	t_bool;

typedef enum e_priority_tree
{
	wrong = -1,
	prio_and_or = 1,
	prio_piped = 2,
	prio_parrenthesis = 3,
	prio_cmds = 4,
}	t_priority_tree;

typedef enum e_token_type
{
	none = -1,
	token_pipe = 3,
	token_or = 1,
	token_left_par = 9,
	token_right_par = 8,
	token_word = 0,
	token_and_and = 2,
	token_left_dir = 4,
	token_right_dir = 5,
	token_here_doc = 6,
	token_dright_dir = 7,
	token_newline = 10,
}	t_token_type;

typedef struct s_command
{
	char			**cmd;
	char			*path;
	char			**redir_dest;
	int				**redir_type;
}	t_command;

typedef struct s_token
{
	t_token_type	type;
	t_priority_tree	priority;
	int				*used;
	char			*input;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;

typedef struct s_og_cmd
{
	t_token			*token;
	struct s_og_cmd	*next;
}	t_og_cmd;

typedef struct s_node
{
	t_token			*operator;
	t_command		*command;
	struct s_node	*left;
	struct s_node	*right;
}	t_node;

typedef struct s_cmd
{
	int				nb_cmd;
	int				std_fd[2];
	int				p_fd[2][2];
	int				h_d_fd;
	int				*i;
	pid_t			*child;
	t_node			*node;
}	t_cmd;

typedef struct s_heredoc
{
	char			**heredoc_paths;
	char			*here_doc_file;
	int				heredoc_fd;
}				t_heredoc;

typedef struct s_pipeline
{
	t_command			*command;
	struct s_pipeline	*next;
}	t_pipeline;

typedef struct s_mini
{
	char			**env;
	char			*line;
	int				is_pipe;
	int				last_exit;
	int				nb_node;
	int				stdin_copy;
	int				stdout_copy;
	t_command		*command;
	t_token			*token;
	t_og_cmd		*og_cmd;
	t_node			**node;
	t_cmd			*cmd;
	t_heredoc		*heredoc;
}	t_mini;

int			ft_prompt(t_mini *mini);
char		*ft_strdup(char *str1);
char		*ft_substr(char *s, unsigned int start, size_t len);
void		*ft_lexing(char *input, t_mini *mini);
size_t		ft_locate_token(char *input, t_token *token, int i);

//////////////////////  EXPANSION  //////////////////////

/*grammar*/
void		ft_syntax_error(t_token *token, t_token *next);
void		*ft_grammar(t_og_cmd *head_c, t_mini *mini);
int 		ft_islogic(t_token *token);
int			ft_isredir(t_token *token);
int 		ft_ispar(t_token *token);
int			ft_token_error(t_token *token);
t_token		*ft_syntax(t_token *tokens, t_token *prev, int *par_count);

/*expansion*/
char		*get_current_dir_name(void);
char		*ft_remove_quotes(char *str);
char		**ft_add_args(char **cmd, char **tmp);
char		**ft_trim_arg(char **cmd, int i);
char		**ft_sort_cmd(char **cmd, int index);
char		**ft_dstr_tolower(char **str,char **tmp);
char		**ft_add_file_name(char **cmd, char *file);
char		**ft_search_dol(char *cmd, t_mini *mini, t_bool *expand);
char		**ft_split_word(char *cmd);
char		**ft_trim_asterisk(char **cmd, char **tmp, int j);
char		**ft_test_entry(DIR *dir, char *arg, int all);
char		**ft_swap_cmd(char **cmd, char **tmp_cmd, t_bool swapped, int i);
char		**ft_update_tmp(char **tmp, char **tmp_ifs, int *j, int *k);
char		**ft_pathname_expansion(char *cmd);
char		*get_current_dir_name(void);
char		*ft_handle_dollar(char *cm, t_mini *mini, t_bool *expand);
char		*ft_expand_var(char *str, t_mini *mini, int is_exit_status, t_bool *expand);
char		*ft_get_in_env( char *cmd, char **env);
char		*ft_trim_dol_quotes(char *cmd, int j);
void		*ft_expand(t_node *node, t_mini *mini);
int			ft_dol_in_quotes(char *str);
int			ft_asterisk_in_quotes(char *str);
size_t		ft_strlen_var(char *cmd, int *start);

//////////////////////  INIT  //////////////////////

// init.c
void		*ft_build_env(char **env);
t_mini		*ft_init(char **env);
int			init_signal_handler(void);

//////////////////////  SIGNAUX  //////////////////////

// signaux.c
void		handle_signal(int signal);
void		handle_eof(t_mini *mini, char *input);

//////////////////////  HERE_DOC  //////////////////////

// here_doc.c
int			ft_here_doc(char *lim, t_mini *mini, int j);
int			create_heredoc_file(t_mini *mini);
int			ft_get_input(char *lim, int fd, t_mini *mini);
void		ft_add_new_heredoc_path(t_mini *mini, int j);
void		ft_unlink_fds(t_mini *mini);

// here_doc_utils.c
void		handle_hd_child_process(char *lim, int fd, struct \
				sigaction sa_child, t_mini *mini);
void		handle_hd_child_signal(int signal);
int			handle_hd_parent_process(pid_t pid, t_mini *mini);
void		handle_input(char *lim, int fd, t_mini *mini);
void		handle_hd_eof(int i, char *lim, t_mini *mini, int fd);

//////////////////////  BUILT-IN  //////////////////////

// built_in_1.c
int			ft_echo(char **args);
int			check_length_and_compare(char *str, t_bool is_neg);
int			ft_pwd(char **args);
int			ft_env(char **args, t_mini *mini, int export);

// built_in_2.c
int			ft_check_var_name(char *var);
char		*add_quotes_to_env_var(char *env_var);
char		**ft_add_quotes(char **env);
void		update_or_add_env_var(t_mini *mini, char *arg, char *tmp);
int			ft_export(char **args, t_mini *mini);

// built_in_3.c
int			ft_is_not_valid(char *str);
t_bool		validate_exit_args(char **args, t_mini *mini);
void		ft_exit(char **args, t_mini *mini, t_bool is_pipe);
char		*ft_get_home(char **env);
int			ft_cd(char **args, t_mini *mini);

// built_in_4.c
char		**ft_rm_var(char **env, int i);
int			ft_unset(char **args, t_mini *mini);

//////////////////////  PARSING  //////////////////////

// parsing.c
void		*ft_parsing(t_og_cmd *head_c, t_mini *mini);
t_node		*build_tree(t_token **token, t_priority_tree priority);
t_node		*handle_current_token(t_token **current, t_priority_tree *priority, \
				t_node **node);

// operator.c
t_node		*ft_create_operator_node(t_token **token, \
			t_priority_tree *priority, t_node **node);
t_node		*handle_and_or_pipe(t_token **token, t_priority_tree *priority,
				t_node **node);
t_node		*handle_parenthesis(t_token **token, t_priority_tree *priority,
				t_node **node);

// command.c
t_node		*ft_create_command_node(t_token *current);
t_node		*handle_command(t_token **token, t_priority_tree *priority,
				t_node **node);
void		ft_count_redir_cmds(t_token *current, int *count,
				int *count_redirections);
int			ft_add_mem_to_redir(t_node *new_node, int count, \
				int count_redirections);
void		ft_fill_cmds_redir(t_node *new_node, t_token *current);

// utils.c
t_token		*ft_give_me_left(t_token *current);
t_token		*ft_pass_parrenthesis(t_token *current);
t_token		*ft_using_parrenthesis(t_token *current);
int			count_cmds(t_og_cmd *head_c);

//////////////////////  EXEC  //////////////////////

// exec.c
int			ft_exec(t_node *node, t_mini *mini);
int			ft_do_operator(t_node *node, int left, t_mini *mini);
int			execute_command(t_node *node, t_mini *mini);
int			do_redir(t_command *command, t_mini *mini);

//exec_cmd.c
int			exec_cmd(char **cmd, t_mini *mini);
int			handle_parent_process(pid_t pid);
void		handle_child_process(char **cmd, char **env, t_mini *mini);
void		ft_child_exec_command(char *prep_cmd, char **cmd, char **env, \
				t_mini *mini);

//exec_built_in.c
int			ft_check_if_built_in(char *cmd);
int			ft_do_built_in(char **cmd, t_mini *mini, t_bool is_pipe);
char		**get_built_in_cmds(void);

//exec_redir.c
int			handle_heredoc(t_command *command, t_mini *mini, int i, int *j);
int			handle_redirections(t_command *command, t_mini *mini, int i, int j);
int			ft_heredoc_redir(char *heredoc_path);
int			ft_left_redir(char *redir_dest);
int			ft_right_redir(char *redir_dest, int append);

//exec_utils.c
char		*ft_check_env(char **env, char *cmd);
char		*ft_find_in_env(char *env, char *cmd);
void		ft_error(char *str1, char *str2, char *str3);

//pipex_mini.c
int			ft_pipex(t_node *node, t_mini *mini);
int			ft_exit_status(int status, t_cmd *cmd, int p_fd[2][2], \
				t_mini *mini);
int			ft_count_cmd(t_node *node);
int			ft_pipex_childs(char **env, t_command *command, t_mini *mini);
int			ft_pipex_parent(t_mini *mini);
int			ft_redirect_pipes(t_mini *mini, int p_fd[2][2]);
int			ft_redir_files(t_command *command, t_mini *mini);
int			ft_input_redir(t_command *command, t_mini *mini, int tmp, int i);
int			ft_open_access_dup(char *str, int flags, int std);
void		ft_error(char *str1, char *str2, char *str3);
void		ft_c_fd(int *pipe_fd1, int *pipe_fd2, int std_fd[2]);
void		ft_free_all_pipex(t_mini *mini);
char 		*ft_prepare_cmd(char **cmd, t_mini *mini, t_bool is_pipe);
char		**ft_copy_dstr(char **str);


//////////////////////  DESTROY  //////////////////////

// destroy.c
void		ft_destroy_token(t_token *token);
void		ft_destroy_og_cmd(t_og_cmd *og_cmd);
void		ft_destroy_node(t_node **node);
void		ft_destroy_command_2(t_command *command);
void		ft_destroy_command(t_command *command);

// destroy_2.c
void		ft_destroy_char_d(char **tab_str);
void		free_token_list(t_token *head);
void		ft_destroy_env(char **env);
void		ft_free_str(char **str);
void		ft_cleanup(t_node *node);

// destroy_mini.c
void		free_mini_d_quit(t_mini *mini, char *input);
void		free_mini_og_cmd(t_mini *mini, char *input);
void		free_mini_loop(t_mini *mini);
void		free_mini(t_mini *mini, char *input);
void		free_mini_childs(t_mini *mini, char *input);

#endif