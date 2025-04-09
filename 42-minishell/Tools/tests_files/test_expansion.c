
#include "minishell.h"
#include <assert.h>

int main(int argc, char **argv, char **envp)
{
	t_node *node;
	int i = 0;

	if (argc && argv && envp)
		;
	node = malloc(sizeof(t_node));
	node->left = NULL;
	node->right = NULL;
	node->operator= NULL;
	node->command = malloc(sizeof(t_command));
	node->command->cmd = malloc(sizeof(char *) * 20);
	node->command->cmd[0] = ft_strdup("echo");
	node->command->cmd[1] = ft_strdup("$VAR1");
	node->command->cmd[2] = ft_strdup("'$USER'");
	node->command->cmd[3] = ft_strdup("$HOME");
	node->command->cmd[4] = ft_strdup("$USER");
	node->command->cmd[5] = ft_strdup("$");
	node->command->cmd[6] = ft_strdup(" $ ");
	node->command->cmd[7] = ft_strdup("  $");
	node->command->cmd[8] = ft_strdup("$DONT_EXIST");
	node->command->cmd[9] = ft_strdup("'$?'");
	node->command->cmd[10] = ft_strdup("$`?");
	node->command->cmd[11] = ft_strdup("$DONT_EXIST hey ");
	node->command->cmd[12] = ft_strdup("hey $DONT_EXIST hey ");
	node->command->cmd[13] = ft_strdup("\"hey $DONT_EXIST hey \"");
	node->command->cmd[14] = NULL;

	/*
	"echo"
	"file1"
	"file2"
	"file3"
	"'$USER'"
	"/home/anferre"
	"anferre"
	"$"
	" $ "
	" $ "
	""
	"'$?'"
	""
	" hey "
	"hey "
	"\"hey hey \""
	*/

	ft_expand(node, envp);
	while (node->command->cmd[i])
	{
		printf("nb : %d = %s  \n", i, node->command->cmd[i] );
		i++;
	}
	return (0);
}