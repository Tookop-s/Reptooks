/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:45:51 by gchamore          #+#    #+#             */
/*   Updated: 2024/06/18 12:58:40 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_split(char **split, unsigned int i)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		free(split[j]);
		j++;
	}
	free(split);
	return ;
}

static int	count_words(const char *str, char c)
{
	int	count_w;
	int	check;

	count_w = 0;
	check = 0;
	while (*str)
	{
		if (*str != c && check == 0)
		{
			check = 1;
			count_w++;
		}
		else if (*str == c)
			check = 0;
		str++;
	}
	return (count_w);
}

static char	*word_dup(const char *str, int start, int end)
{
	char	*word;
	int		i;

	word = (char *)malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**fill_split(char const *s, char c, char **split)
{
	size_t	i;
	size_t	j;
	int		start_or_end;

	i = 0;
	j = 0;
	start_or_end = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && start_or_end < 0)
			start_or_end = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start_or_end >= 0)
		{
			split[j] = word_dup(s, start_or_end, i);
			if (!split[j])
				return (free_split(split, j), NULL);
			start_or_end = -1;
			j++;
		}
		i++;
	}
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	split = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	split = fill_split(s, c, split);
	if (!split)
		return (NULL);
	split[count_words(s, c)] = NULL;
	return (split);
}

//	La fonction ft_split est une fonction du langage C qui
//	divise la chaîne de caractères s en un tableau de
//	chaînes de caractères en utilisant le caractère c comme
//	délimiteur. La dernière chaîne dans le tableau est
//	suivie d'un pointeur nul.

// void free_split_result(char **result) 
// {
//     char **ptr = result;
//     while (*ptr) 
// 	{
//         free(*ptr);
//         ptr++;
//     }
//     free(result);
// }

// int main() 
// {
//     const char *input_string = "This,is,a,test,string";
//     char separator = ',';

//     char **result = ft_split(input_string, separator);

//     if (result == NULL) {
//         fprintf(stderr, "Erreur lors de l'appel à ft_split.\n");
//         return 1;
//     }

//     // Afficher les résultats
//     printf("Chaîne d'entrée: '%s'\n", input_string);
//     printf("Résultat du split:\n");

//     char **ptr = result;
//     while (*ptr) {
//         printf("'%s'\n", *ptr);
//         ptr++;
//     }

//     // Libérer la mémoire allouée
//     free_split_result(result);

//     return 0;
// }