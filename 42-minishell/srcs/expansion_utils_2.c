/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:57:54 by anferre           #+#    #+#             */
/*   Updated: 2024/07/03 18:29:18 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_dstr_tolower(char **str, char **tmp)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		tmp[i] = ft_strdup(str[i]);
		if (!tmp[i])
			return (NULL);
		while (str[i][j] && str[i][j] != '\0')
		{
			if (str[i][j] >= 'A' && str[i][j] <= 'Z')
				tmp[i][j] += 32;
			j++;
		}
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
}

int	ft_isupper(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			return (1);
		i++;
	}
	return (0);
}

//get the current working directory allocate size and if the buffer is too small
//it reallocates the buffer with a bigger size until SIZE_MAX
char	*get_current_dir_name(void)
{
	size_t	size;
	char	*buf;

	size = 100;
	while (1)
	{
		buf = malloc(size);
		if (!buf)
			return (NULL);
		if (getcwd(buf, size))
			return (buf);
		free(buf);
		if (errno != ERANGE)
			return (NULL);
		if (size > SIZE_MAX / 2)
			return (NULL);
		size *= 2;
	}
}

char	**ft_trim_asterisk(char **cmd, char **tmp, int j)
{
	char	**new_cmd;
	int		i;
	int		l;

	i = -1;
	l = -1;
	new_cmd = malloc(sizeof(char *) * (ft_strlen_2d((const char **)cmd) + \
	ft_strlen_2d((const char **)tmp)));
	if (!new_cmd)
		return (NULL);
	while (cmd[++i])
	{
		if (i != j)
			new_cmd[++l] = cmd[i];
	}
	i = -1;
	while (tmp[++i])
	{
		new_cmd[++l] = tmp[i];
		i++;
	}
	return (new_cmd[++l] = NULL, free(tmp), new_cmd);
}
