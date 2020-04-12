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
	// time(NULL):获取系统时间, 返回值为long类型, 单位: 毫秒 
	// 设置种子数, 种子数相同, 生成的随机数相同! 
	srand((unsigned int)time(NULL));
	for(int i = 0; i < num; i++)
		*(randList + i) = rand();
}
