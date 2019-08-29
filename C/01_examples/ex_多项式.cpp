// 求多项式 1 -1/2 +1/3 -1/4 +... +1/99 -1/100
#include <stdio.h>
double poly()
{
	int sign = 1;
	double deno = 2.0, sum, tmp;
	for(sum = 1.0; deno <= 100; deno++)
	{
		sign = -sign;
		tmp = sign/deno;
		sum += tmp;
	}
	return sum;
} 
int main()
{
	printf("The applicaton is to calculate the value of a polynomial.\n");
	printf("sum = %f\n", poly());
	return 0;
}
