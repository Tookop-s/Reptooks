/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:48:35 by anferre           #+#    #+#             */
/*   Updated: 2023/11/20 17:44:15 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	unsigned int	i;

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
//Outputs the string ’s’ to the given file descriptor followed by a newline.
// #include <stdio.h>
// #include <fcntl.h>
// #include <unistd.h>
//  int main()
// {
// 	int fileDescriptor = open("test.txt", O_WRONLY);
// 	char *s = "Hello World !";
// 	ft_putendl_fd(s, fileDescriptor);
// 	close(fileDescriptor);
// 	return (0);
// }