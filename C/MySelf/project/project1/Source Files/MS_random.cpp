// File: MS_random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void random(int num, int *randList)
{
	// time(NULL):��ȡϵͳʱ��, ����ֵΪlong����, ��λ: ���� 
	// ����������, ��������ͬ, ���ɵ��������ͬ! 
	srand((unsigned int)time(NULL));
	for(int i = 0; i < num; i++)
		*(randList + i) = rand();
}
