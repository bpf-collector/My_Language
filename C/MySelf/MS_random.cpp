/*
 * @Author: bpf
 * @Date: 2019-09-13 15:49:56
 * @LastEditTime: 2019-09-27 20:26:46
 * @Description: Get random number
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void random(int num, int *randList)
{
	/**
	* @description: Get random number
	* @param {num} set acount of random numbers
	* @return: list of random numbers
	*/
	// time(NULL):��ȡϵͳʱ��, ����ֵΪlong����, ��λ: ���� 
	// ����������, ��������ͬ, ���ɵ��������ͬ! 
	srand((unsigned int)time(NULL));
	for(int i = 0; i < num; i++)
		*(randList + i) = rand();
}
