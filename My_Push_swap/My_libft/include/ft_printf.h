/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:46:32 by anferre           #+#    #+#             */
/*   Updated: 2024/01/15 14:29:22 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

int		ft_printf(const char *s, ...);
int		ft_putnbr(int nb, int *count);
int		ft_putnbr_unsigned(unsigned int nb, int *count);
int		ft_putnbr_base(unsigned int nb, char *base, int *count);
void	ft_simplechar(char c, int *count);
void	ft_string(char *str, int *count);
void	ft_ptr(void *ptr, int *count);
void	ft_decimal(int j, int *count);
void	ft_int(int j, int *count);
void	ft_unsigneddeci(unsigned int u, int *count);
void	ft_lowerhex(unsigned int h, int *count);
void	ft_upperhex(unsigned int h, int *count);
void	ft_percent(int *count);
void	ft_putchar(char c);

#endif