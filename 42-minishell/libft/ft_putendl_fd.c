/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:18:59 by gchamore          #+#    #+#             */
/*   Updated: 2023/11/17 11:35:46 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			write(fd, &s[i], 1);
			i++;
		}
		write(fd, "\n", 1);
	}
}

//	La fonction ft_putendl_fd écrit la chaîne de caractères s 
//	suivie d'un caractère de fin de ligne ('\n') dans le
//	descripteur de fichier spécifié par fd.

// #include <fcntl.h>
// int	main(void)
// {
// 	int fd1;

// 	fd1 = open("test.txt", O_WRONLY | O_CREAT, 0640);
// 	if (fd1 == -1)
// 		return (1);
// 	ft_putendl_fd("okoksalut", fd1);
// }