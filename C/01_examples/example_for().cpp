// example_for()
#include <stdio.h>

/* Çó 1+2+3+...+100 */
int Sum(int start,int end)
{
	int sum = 0,i = start;
	for(int i = start;i<=end;i++)
		sum += i;
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
