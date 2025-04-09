/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:22:47 by gchamore          #+#    #+#             */
/*   Updated: 2023/11/17 11:36:51 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	nb2;

	nb2 = n;
	if (nb2 < 0)
	{
		ft_putchar_fd('-', fd);
		nb2 = nb2 * -1;
	}
	if (nb2 > 9)
	{
		ft_putnbr_fd((nb2 / 10), fd);
	}
	ft_putchar_fd((nb2 % 10) + '0', fd);
}

//	La fonction ft_putnbr_fd écrit l'entier n dans le
//	descripteur de fichier spécifié par fd.

// #include <fcntl.h>
// int	main(void)
// {
// 	int fd1;

// 	fd1 = open("test.txt", O_WRONLY | O_CREAT, 0640);
// 	if (fd1 == -1)
// 		return (1);
// 	ft_putnbr_fd(-16647, fd1);
// }
