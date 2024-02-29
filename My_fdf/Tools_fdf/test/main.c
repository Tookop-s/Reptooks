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


// static void ft_draw_line(t_coor start, t_coor end, t_data_img *img, int color) 
// {
// 	int x;
//     double slope;

// 	x = start.x;
// 	slope = (end.y - start.y) / (end.x - start.x);
//     while (x <= end.x)
// 	{
// 		int y = start.y + slope * (x - start.x);
// 		ft_mlx_pixel_put(img, x, y, color);
// 		x++;
// 	}
// }
//view asin(tan(M_PI / 6))
// t = cos(b) * j - sin(b) * sin(a) * i + sin(b) * cos(a) * array3d[i][j];
// u = cos(a) * i - sin(a) * array3d[i][j];

// almost
// t = cos(b) * j + sin(b) * sin(a) * i + sin(b) * cos(a) * array3d[i][j];
// u = cos(a) * i - sin(a) * array3d[i][j];

