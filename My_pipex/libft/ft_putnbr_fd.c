/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:52:44 by anferre           #+#    #+#             */
/*   Updated: 2023/11/20 17:44:18 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	nb;

	nb = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
	}
	ft_putchar_fd(nb % 10 + '0', fd);
}

//Outputs the integer ’n’ to the given file descriptor.
// #include <stdio.h>
// #include <fcntl.h>
// #include <unistd.h>
//  int main()
// {
// 	int fileDescriptor = open("test.txt", O_WRONLY);
// 	int nbr = -245;
// 	ft_putnbr_fd(nbr, fileDescriptor);
// 	close(fileDescriptor);
// 	return (0);
// }