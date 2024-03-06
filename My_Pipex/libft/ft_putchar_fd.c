/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:50:33 by anferre           #+#    #+#             */
/*   Updated: 2023/11/20 17:44:13 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

//Outputs the character ’c’ to the given filedescriptor
// #include <stdio.h>
// #include <fcntl.h>
// #include <unistd.h>
// int main()
// {
// 	int fileDescriptor = open("test.txt", O_WRONLY);
// 	char c = '9';
// 	ft_putchar_fd(c, fileDescriptor);
// 	close(fileDescriptor);
// 	return (0);
// }