/* srand(seed): ����������ӣ�������ͬ�����ɵ��������ͬ */
/* rand(): ������������ڴ�֮ǰ��Ҫ��ȷ����������� */ 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void fun_rand()
{
	srand( (unsigned int)time(NULL) );	//ʱ�䲻ͬ���ӾͲ�ͬ 
	for(int i = 0; i < 10; i++)
	printf("%d\n", rand());
}

void run()
{
	fun_rand();
}
