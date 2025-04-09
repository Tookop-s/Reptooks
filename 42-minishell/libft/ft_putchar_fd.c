/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:13:40 by gchamore          #+#    #+#             */
/*   Updated: 2023/11/14 16:09:19 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// #include <fcntl.h>
// int	main(void)
// {
// 	int fd1;

// 	fd1 = open("test.txt", O_WRONLY | O_CREAT, 0640);
// 	if (fd1 == -1)
// 		return (1);
// 	ft_putchar_fd('O', fd1);
// }