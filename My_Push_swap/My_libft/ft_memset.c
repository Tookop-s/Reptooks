/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:43:45 by anferre           #+#    #+#             */
/*   Updated: 2023/11/20 17:44:10 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*p;

	p = s;
	while (n)
	{
		*p = (unsigned char) c;
		p++;
		n --;
	}
	return (s);
}

//fills *s for n bytes with c
// int main()
// {
// 	char s[20];
// 	ft_memset(s, 'A', 10);
// 	printf("%s", s);
// 	return (0);
// }
