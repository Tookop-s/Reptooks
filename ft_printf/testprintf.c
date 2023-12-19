
#include <unistd.h>
#include <stdio.h>


int main()
{
	char 	c = '\0';
	char	*s = NULL;
	void	*ptr = NULL;
	int		i = 0;
	unsigned int j = 1;


	if (ft_printf("c = %c\n", c) == printf("c = %c\n", c))
	
	else
	
	if (ft_printf("s = %s\n", s) == printf("s = %s\n", s))
	
	if (ft_printf("p = %p\n", ptr) == printf("p = %p\n", ptr))
	
	if (ft_printf("d = %d\n", i) == printf("d = %d\n", i))
	
	if (ft_printf("i = %i\n", i) == printf("i = %i\n", i))
	
	if (ft_printf("u = %u\n", j) == printf("u = %u\n", j))
	
	if (ft_printf("x = %x\n", j) == printf("x = %x\n", j))
	
	if (ft_printf("X = %X\n", j) == printf("X = %X\n", j))
	
	if (ft_printf("%% = %%\n") == printf("%% = %%\n"))
	
	return (0);
}