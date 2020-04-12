// File: MS_random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void random(int num, int *randList)
{
	// time(NULL):获取系统时间, 返回值为long类型, 单位: 毫秒 
	// 设置种子数, 种子数相同, 生成的随机数相同! 
	srand((unsigned int)time(NULL));
	for(int i = 0; i < num; i++)
		*(randList + i) = rand();
}
