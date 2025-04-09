/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:00:41 by gchamore          #+#    #+#             */
/*   Updated: 2024/07/04 14:19:17 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
// Le processus parent ait les descripteurs de fichiers 3 et 4 ouverts 
// lorsqu'il crée le processus enfant, donc ces descripteurs de fichiers
// sont également ouverts dans le processus enfant.
// Cela ne signifie pas nécessairement qu'il y a une fuite de descripteurs 
// de fichiers, car ces descripteurs de fichiers peuvent être fermés plus 
// tard dans le code.

// ==2083400== FILE DESCRIPTORS: 2 open (0 std) at exit.
// ==2083400== Open file descriptor 4: /dev/pts/0
// ==2083400==    <inherited from parent>
// ==2083400== 
// ==2083400== Open file descriptor 3: /dev/pts/0
// ==2083400==    <inherited from parent>

//  cela indique simplement que ces descripteurs de fichiers étaient ouverts
//  dans le processus parent au moment où le processus s'est terminé,
//  ce qui est normal pour les descripteurs de fichiers associés au terminal.

void	ft_picture(void)
{
	printf("\033[1;32m\n");
	printf("███╗   ███╗██╗███╗   ██╗██╗███████╗██╗  ██╗███████╗██╗     ██╗    \
	\n");
	printf("████╗ ████║██║████╗  ██║██║██╔════╝██║  ██║██╔════╝██║     ██║    \
	\n");
	printf("██╔████╔██║██║██╔██╗ ██║██║███████╗███████║█████╗  ██║     ██║    \
	\n");
	printf("██║╚██╔╝██║██║██║╚██╗██║██║╚════██║██╔══██║██╔══╝  ██║     ██║    \
	\n");
	printf("██║ ╚═╝ ██║██║██║ ╚████║██║███████║██║  ██║███████╗███████╗███████\
	");
	printf("\033[0m\n\n");
	printf("\033[1;33mHey bud ! Welcome to our 42 MINISHELL !\033[0m\n\n");
	ft_printf("\033[5;33m");
	printf("------------------ 🌈 SHELL ZONE BELOW 🌈 ------------------");
	printf("\033[0m\n\n");
}

int	main(int argc, char **argv, char **env)
{
	t_mini	*mini;
	int		status;

	// ft_picture();
	status = 0;
	mini = ft_init(env);
	mini->stdin_copy = dup(STDIN_FILENO);
	mini->stdout_copy = dup(STDOUT_FILENO);
	if (mini->stdin_copy == -1 || mini->stdout_copy == -1)
		return (EXIT_FAILURE);
	if (argc || argv)
		status = ft_prompt(mini);
	if (dup2(mini->stdin_copy, STDIN_FILENO) == -1 || \
	dup2(mini->stdout_copy, STDOUT_FILENO) == -1)
		return (EXIT_FAILURE);
	close(mini->stdin_copy);
	close(mini->stdout_copy);
	free_mini_d_quit(mini, NULL);
	return (status);
}
