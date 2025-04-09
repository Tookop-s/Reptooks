/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:11:34 by gchamore          #+#    #+#             */
/*   Updated: 2023/11/15 17:22:33 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
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
	}
}

// #include <fcntl.h>
// int	main(void)
// {
// 	int fd1;

// 	fd1 = open("test.txt", O_WRONLY | O_CREAT, 0640);
// 	if (fd1 == -1)
// 		return (1);
// 	ft_putstr_fd("okoksalut", fd1);
// }