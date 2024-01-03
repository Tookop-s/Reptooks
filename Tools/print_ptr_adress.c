
#include <string.h>
#include <stdio.h>
#include <unistd.h>

void	ft_putptr(unsigned long address, int *count)
{

	if(address >= 16)
	{
		ft_putptr(address / 16, count);
		ft_putptr(address % 16, count);
	}
	else
	{
		if (address < 10)
			putchar(address + '0');
		else
			putchar(address - 10 + 'a');
		*count += 1;
	}
}
void	ft_ptr(void *ptr, int *count)
{
	
	unsigned long	address;
	unsigned int	i;

	i = 0;
	if (!ptr)
	{
		write(1,"(nil)", 5);
		*count += 5;
		return ;
	}
	address = (unsigned long)ptr;
	write(1, "0x", 2);
	(*count) += 2;
	ft_putptr(address, count);
}

int main ()
{
	char *ptr = "c";
	int 	count;
	int		*ct;

	count = 0;
	ct = &count;
	ft_ptr(ptr, ct);
	printf("\n%d", *ct);
	*ct = printf("\n%p", ptr);
	printf("\n%d", *ct);
}