// File: MS_Fibonacci[ì³²¨ÄÇÆõÊýÁÐ]
#include <stdio.h>

void Fibonacci(int n)
{
	int f1 = 1, f2 = 1;
	for(int i = 1; i <= n; i++) 
	{
		printf("%15d %15d", f1, f2);
		if(i%2==0)
			putchar('\n');
		f1 = f1 + f2;
		f2 = f1 + f2;
	}
}
