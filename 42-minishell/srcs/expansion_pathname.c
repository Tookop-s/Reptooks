/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_pathname.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:40:42 by anferre           #+#    #+#             */
/*   Updated: 2024/07/04 14:17:46 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// function that retreive the file name from the path and check if the file
//name is a regular file
char	**ft_expand_asterisk(char *arg, char *path, int all, char **dtmp)
{
	DIR				*dir;

	dir = opendir(path);
	if (!dir)
		return (perror("opendir"), NULL);
	dtmp = ft_test_entry(dir, arg, all);
	if (!dtmp)
	{
		dtmp = ft_add_file_name(dtmp, arg);
		if (dtmp == NULL)
			return (closedir(dir), NULL);
	}
	return (closedir(dir), dtmp);
}

//a function that checks if there is an asterisk outside of the quotes
//if there is, it returns 1
int	ft_asterisk_in_quotes(char *str)
{
	int		i;
	int		squote;
	int		dquote;


	i = 0;
	squote = 0;
	dquote = 0;
	while (str[i])
	{
		if (str[i] == '\'' && dquote == 0)
			squote = (squote + 1) % 2;
		if (str[i] == '\"' && squote == 0)
			dquote = (dquote + 1) % 2;
		if (str[i] == '*' && squote == 0 && dquote == 0)
			return (1);
		i++;
	}
	return (0);
}

//expand the pathname of the command
// iterate through the different nodes and commands in the tree
char	**ft_pathname_expansion(char *arg)
{
	int		i;
	char	*path;
	char	*asterisk;
	char	**dtmp;

	i = 0;
	dtmp = NULL;
	path = get_current_dir_name();
	if (path == NULL)
		return (NULL);
	asterisk = ft_strrchr(arg, '*');
	if (arg[0] == '*' && arg[1] == '\0')
	{
		dtmp = ft_expand_asterisk(arg, path, 1, dtmp);
		if (dtmp == NULL)
			return (free(path), NULL);
			return (free(path), NULL);
	}
	else if (asterisk != NULL)
	{
		dtmp = ft_expand_asterisk(arg, path, 0, dtmp);
		if (dtmp == NULL)
			return (free(path), NULL);
	}
	return (free(path), dtmp);
}
