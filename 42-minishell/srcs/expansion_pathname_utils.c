/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_pathname_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:22:44 by anferre           #+#    #+#             */
/*   Updated: 2024/07/03 18:27:02 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_extract_asterisk(char *tmp_og, int i, char *file_name, int *len)
{
	int		start;
	char	*og_cmd;
	char	*tmp;

	while (tmp_og[i] && tmp_og[i] == '*')
		i++;
	start = i;
	while (tmp_og[i] && tmp_og[i] != '*')
		i++;
	*len = i - start;
	tmp = ft_substr(tmp_og, start, *len);
	if (tmp == NULL)
		return (0);
	og_cmd = ft_strnstr(file_name, tmp, ft_strlen(file_name));
	return (free(tmp), og_cmd);
}

int	ft_test_file_name(char *file_name, char *og_name)
{
	char	*tmp_og;
	int		i;
	int		len;

	i = 0;
	if (ft_strchr(og_name, '\'') || ft_strchr(og_name, '\"'))
	{
		tmp_og = ft_remove_quotes(og_name);
		if (tmp_og == NULL)
			return (0);
	}
	else
		tmp_og = og_name;
	og_name = ft_extract_asterisk(tmp_og, i, file_name, &len);
	if (og_name != NULL)
	{
		if (tmp_og[i] != '\0')
			return (ft_test_file_name(og_name + len, tmp_og + i));
		else if (tmp_og[i] == '\0')
			return (1);
	}
	return (0);
}

char	**ft_copy_file_name(char **cmd, char *file, char **new_cmd, size_t len)
{
	int		j;

	j = 0;
	while (cmd && j < (int)len - 1)
	{
		new_cmd[j] = cmd[j];
		j++;
	}
	if (!cmd)
	{
		new_cmd[0] = ft_strdup(file);
		if (!new_cmd[0])
			return (free(cmd), NULL);
		new_cmd[1] = NULL;
	}
	else
	{
		new_cmd[j] = ft_strdup(file);
		if (!new_cmd[j])
			return (free(cmd), NULL);
		new_cmd[j + 1] = NULL;
	}
	return (free(cmd), new_cmd);
}

char	**ft_add_file_name(char **cmd, char *file)
{
	char	**new_cmd;
	size_t	len;

	if (!cmd)
		len = 1;
	else
		len = ft_strlen_2d((const char **)cmd) + 1;
	new_cmd = malloc(sizeof(char *) * (len + 1));
	if (!new_cmd)
		return (free(cmd), NULL);
	new_cmd = ft_copy_file_name(cmd, file, new_cmd, len);
	if (!new_cmd)
		return (NULL);
	return (new_cmd);
}

char	**ft_test_entry(DIR *dir, char *arg, int all)
{
	struct dirent	*entry;
	char			*tmp;
	char			**dtmp;

	entry = readdir(dir);
	dtmp = NULL;
	tmp = NULL;
	while (entry != NULL)
	{
		if (!(entry->d_name[0] == '.' && arg[0] != '.'))
		{
			if (all == 1 || ft_test_file_name(entry->d_name, arg))
			{
				tmp = ft_strdup(entry->d_name);
				if (tmp == NULL)
					return (NULL);
				dtmp = ft_add_file_name(dtmp, tmp);
				if (dtmp == NULL)
					return (free(tmp), NULL);
			}
		}
		entry = readdir(dir);
	}
	return (free(tmp), dtmp);
}
