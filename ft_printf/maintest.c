
#include "ft_printf.h"


char	ft_strchr(const char *str, char c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c && str[i + 1])
			return (str[i + 1]);
		i++;
	}
	return (0);
}

int	ft_strpercent(const char *str)
{
	int		i;
	int		ct;

	i = 0;
	ct = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] && str[i + 1] != '%')
			ct++;
		i++;
	}
	return (ct);
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putnbr(int nb, int *count)
{
	long nb2;

	nb2 = nb;
	if (nb2 < 0)
	{
		ft_putchar('-');
		nb2 *= -1;
		(*count)++;
	}
	if (nb2 > 9)
		ft_putnbr(nb2 / 10, count);
	ft_putchar((nb2 % 10) + '0');
	(*count)++;
	return (*count);
}

int ft_putnbr_base(int nb, char *base, int *count)
{
	long	nb2;
	int		baselen;
	
	nb2 = nb;
	baselen = 16;
	if (nb2 < 0)
	{
		ft_putchar('-');
		nb2 *= -1;
		(*count)++;
	}
	if (nb2 >= 16)
		ft_putnbr_base(nb2 / baselen, base, count);
	ft_putchar(base[nb2 % baselen]);
	(*count)++;
	return (*count);	
}

char	*ft_reversestr(char *str)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	char			temp;

	i = 0;
	j = 0;
	while(str[i])
		i++;
	k = i - 1;
	while (j < k)
	{
		temp = str[k];
		str[k] = str[j];
		str[j] = temp;
		j++;
		k--;
	}
	return (str);
}

void	ft_simplechar(char c, int *count)
{
	ft_putchar(c);
	(*count)++;
}

void	ft_string(char *str, int *count)
{
	unsigned int	i;

	if (!str)
	{
		write(1,"(null)", 6);
		*count += 6;
		return ;
	}
	i = ft_strlen(str);
	write(1, str, i);
	*count += i;
}

void	ft_ptr(void *ptr, int *count)
{
	char			addressstr[20];
	unsigned long	address;
	char			digit;
	unsigned int	i;

	i = 0;
	if (!ptr)
	{
		write(1,"(nil)", 5);
		*count += 5;
		return ;
	}
	address = (unsigned long)ptr;
	while (address > 0)
	{
		digit = address % 16;
		if (digit < 10)
			digit += '0';
		else
			digit = digit - 10 + 'a';
		addressstr[i] = digit;
		i++;
		address /= 16;
	}
	addressstr[i++] = 'x';
	addressstr[i++] = '0';
	ft_reversestr(addressstr);
	write(1, addressstr, i);
	*count += ft_strlen(addressstr);
}

void	ft_decimal(int j, int *count)
{
	*count = ft_putnbr(j, count);
}

void	ft_int(int j, int *count)
{
	*count = ft_putnbr(j, count);
}

void	ft_unsigneddeci(unsigned int u, int *count)
{
	*count = ft_putnbr(u, count);
	
}

void	ft_lowerhex(unsigned int h, int *count)
{
	char	*base;

	base = "0123456789abcdef";
	*count = ft_putnbr_base(h, base, count);
}

void	ft_upperhex(unsigned int h, int *count)
{
	char	*base;

	base = "0123456789ABCDEF";
	*count = ft_putnbr_base(h, base, count);
}

void	ft_percent(int *count)
{
	ft_putchar('%');
	(*count)++;
}

int ft_printf(const char *s, ...)
{
	int		i;
	char	c;
	int 	count;
	int		*ct;
	va_list args;

	i = 0;
	count = 0;
	va_start(args, s);
	c = ft_strchr(s, '%');
	ct = &count;
	while(s[i])
	{
		while(s[i] != '%' && s[i])
		{
			ft_putchar(s[i]);
			i++;
			count++;
		}
		if (s[i] == '%')
			i += 2;
		if (c == 'c')
			ft_simplechar((char)va_arg(args, int), ct);
		else if (c == 's')
			ft_string(va_arg(args, char *), ct);
		else if (c == 'p')
			ft_ptr(va_arg(args, char *), ct);
		else if (c == 'd')
			ft_decimal(va_arg(args, int), ct);
		else if (c == 'i')
			ft_int(va_arg(args, int), ct);
		else if (c == 'u')
			ft_unsigneddeci(va_arg(args, unsigned int), ct);
		else if (c == 'x')
			ft_lowerhex(va_arg(args, unsigned int), ct);
		else if (c == 'X')
			ft_upperhex(va_arg(args, unsigned int), ct);
		else if (c == '%')
			ft_percent(ct);
		if (s[i])
			c = ft_strchr(&s[i], '%');
	}
	va_end(args);
	return (*ct);
}
#include <stdio.h>

int main()
{
	int ct;

	ct = ft_printf("%c%c%c*", '\0', '1', 1);
	printf("\n%d\n", ct);
	
	return (0);
}