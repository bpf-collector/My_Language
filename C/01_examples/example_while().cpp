// example_while()
#include <stdio.h>

/* Çó 1+2+3+...+100 */
int Sum(int start,int end)
{
	int sum = 0,i = start;
	while(i <= end)
	{
		sum += i;
		i++;
	}
	return sum;
}
int main()
{
	int start,end;
	printf("\tThis application is counting the sum of a series of numbers.\n");
	printf("Please enter the start and end(divide with ','): ");
	scanf("%d,%d",&start,&end);
	printf("Sum = %d\n",Sum(start,end));
	return 0;
}
