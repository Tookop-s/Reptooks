/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_ifs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:54:41 by anferre           #+#    #+#             */
/*   Updated: 2024/07/03 15:07:24 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//split the command by the IFS
char	**ft_ifs_split(char *str, char *ifs, int count)
{
	char	**tmp;
	int		j;
	int		i;
	int		start;
	int		end;

	tmp = malloc(sizeof(char *) * (count + 1));
	if (!tmp)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		start = i;
		while (str[i] && !ft_strchr(ifs, str[i]))
			i++;
		end = i;
		tmp[j] = ft_substr(str, start, end - start);
		j++;
		while (str[i] && ft_strchr(ifs, str[i]))
			i++;
	}
	tmp[j] = NULL;
	return (tmp);
}

//count the number of words in the command by the IFS
void	ft_count_w(char *cmd, char *ifs, int *count)
{
	int	check;
	int	j;

	j = 0;
	*count = 0;
	check = 1;
	while (cmd && cmd[j])
	{
		if (ft_strchr(ifs, cmd[j]))
			check = 1;
		else if (check == 1)
		{
			(*count)++;
			check = 0;
		}
		j++;
	}
}

//recover the ifs and count the number of words in the command
char	**ft_split_word(char *cmd)
{
	char	*ifs;
	int		*count;
	char	**tmp;

	count = malloc(sizeof(int));
	if (!count)
		return (free(cmd), NULL);
	ifs = getenv("IFS");
	if (!ifs)
		ifs = " \t\n";
	ft_count_w(cmd, ifs, count);
	if (*count == 0 || *count == 1)
		return (free(count), NULL);
	tmp = ft_ifs_split(cmd, ifs, *count);
	if (!tmp)
		return (free(count), free(cmd), NULL);
	return (free(count), free(cmd), tmp);
}
