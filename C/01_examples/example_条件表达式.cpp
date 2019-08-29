// example_条件表达式 
#include <stdio.h>
int max1(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}
int max2(int a,int b)
{
	return (a>b ? a:b);
}
int main()
{
	int a,b;
	printf("This application is to output the bigger one of two nummbers that are input.\n");
	printf("Please enter 2 numbers(divide with space):");
	scanf("%d %d",&a,&b);
	printf("Max1 = %d\n",max1(a,b));
	printf("Max2 = %d\n",max2(a,b));
	return 0;
}
