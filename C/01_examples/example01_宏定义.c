#include <stdio.h>
/* �궨�� */

// ����ֵ 
#define MAX 1024
// ���庯�� 
#define fun(x, y) x+y*2

void test()
{
	printf("MAX = %d\n", MAX);
	printf("fun(2, 2) = %d\n", fun(2, 2));
	printf("fun(2, 1 + 1) = %d\n", fun(2, 1 + 1));
}

void run()
{
	test();
}
