/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:46:32 by anferre           #+#    #+#             */
/*   Updated: 2024/01/03 16:19:21 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>

int		ft_strlen(char *str);
int		ft_printf(const char *s, ...);
int		ft_strpercent(const char *str);
int		ft_putnbr(unsigned long nb, int *count);
int		ft_putnbr_base(unsigned long nb, char *base, int *count);
void	ft_simplechar(char c, int *count);
void	ft_string(char *str, int *count);
void	ft_ptr(void *ptr, int *count);
void	ft_decimal(int j, int *count);
void	ft_int(int j, int *count);
void	ft_unsigneddeci(unsigned long u, int *count);
void	ft_lowerhex(unsigned long h, int *count);
void	ft_upperhex(unsigned long h, int *count);
void	ft_percent(int *count);
void 	ft_putchar(char c);

#endif