
#define RED_TEXT "\x1B[31m"
#define GREEN_TEXT "\x1B[32m"
#define RESET_COLOR "\x1B[0m"

#include <unistd.h>
#include <stdio.h>
#include "ft_printf.h"

void	ft_check(int me, int func)
{
	if ( me == func)
		printf(GREEN_TEXT " OK\n" RESET_COLOR);
	else
		printf(RED_TEXT " KO\n" RESET_COLOR);
}

int main()
{
	char 	c = 'A';
	char	*s = "kilo";
	void	*ptr = NULL;
	int		i = -42;
	unsigned int j = 42;
	int ctme;
	int ctfunc;

	printf("%%c = ");
	fflush(stdout);

	printf(" --> ");
	ctme = printf("%c", c);
	ctfunc = ft_printf("%c", c);
	ft_check(ctme, ctfunc);
	
	printf("%%s = ");
	fflush(stdout);

	printf(" --> ");
	ctme = printf("%s", s);
	ctfunc = ft_printf("%s", s);
	ft_check(ctme, ctfunc);

	printf("%%p = ");
	fflush(stdout);

	printf(" --> ");
	ctme = printf("%p", ptr);
	ctfunc = ft_printf("%p", ptr);
	ft_check(ctme, ctfunc);

	printf("%%d = ");
	fflush(stdout);

	printf(" --> ");
	ctme = printf("%d", i);
	ctfunc = ft_printf("%d", i);
	ft_check(ctme, ctfunc);

	printf("%%i = ");
	fflush(stdout);

	printf(" --> ");
	ctme = printf("%i", i);
	ctfunc = ft_printf("%i", i);
	ft_check(ctme, ctfunc);

	printf("%%u = ");
	fflush(stdout);

	printf(" --> ");
	ctme = printf("%u", j);
	ctfunc = ft_printf("%u", j);
	ft_check(ctme, ctfunc);

	printf("%%x = ");
	fflush(stdout);

	printf(" --> ");
	ctme = printf("%x", j);
	ctfunc = ft_printf("%x", j);
	ft_check(ctme, ctfunc);

	printf("%%X = ");
	fflush(stdout);

	printf(" --> ");
	ctme = printf("%X", j);
	ctfunc = ft_printf("%X", j);
	ft_check(ctme, ctfunc);

	printf("%% = ");
	fflush(stdout);

	printf(" --> ");
	ctme = printf("%%");
	ctfunc = ft_printf("%%");
	ft_check(ctme, ctfunc);

	return (0);
}

