#include <stdio.h>
#include <math.h>

int main (void)
{
	double a = 0.09;
	double b = -0.09;
	double c = 0.99;
	double d = -0.99;

	int a1 = (int)a;
	printf("%d = %lf \n",a1 , a);
	int b1 = (int)b;
	printf("%d = %lf \n",b1 , b);
	int c1 = (int)ceil(c);
	printf("%d = %lf \n",c1 , c);
	int d1 = (int)floor(d);
	printf("%d = %lf \n",d1 , d);
}
