// File: MS_equation
#include <stdio.h>
#include <math.h>

void equation(double a, double b, double c)
{
	if(fabs(a) <= 1e-6)
	{
		// 一次方程  a == 0
		if(fabs(b) <= 1e-6) // 无解 b == 0 
		{
			printf("The equation has no solution.\n");
		}
		else // 一解 b != 0 
			printf("The equation has one root: %.3f", -c/b);
	}
	else
	{
		// 二次方程  a != 0
		double delta = pow(b, 2) - 4*a*c;
		if(delta >= 1e-6) // 二解 delta > 0
		{
			double x1, x2;
			x1 = (-b - sqrt(delta))/(2*a);
			x2 = (-b + sqrt(delta))/(2*a);
			printf("The equation has two roots: %.3f  %.3f\n", x1, x2);
		}
		else if(fabs(delta) <= 1e-6) // 一解 delta == 0 
			printf("The equation has one root:%.3f", -b/(2*a));
		else
		{
			double real, imag;
			real = -b/(2*a);
			imag = sqrt(-delta)/(2*a);
			printf("The equation has two roots: %.3f+%.3fi  %.3f-%.3fi", real, imag, real, imag);
		}
	}
}
