/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:42:31 by anferre           #+#    #+#             */
/*   Updated: 2023/11/23 11:13:52 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

//Outputs the string ’s’ to the given file descriptor
// #include <stdio.h>
// #include <fcntl.h>
// #include <unistd.h>
// int main()
// {
// 	int fileDescriptor = open("test.txt", O_WRONLY);
// 	char *s = "Hello World !";
// 	ft_putstr_fd(s, fileDescriptor);
// 	close(fileDescriptor);
// 	return (0);
// }