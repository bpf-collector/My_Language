/*
 * @Description: judge is a prime number or not
 * @Author: bpf
 * @Date: 2019-09-13 15:49:56
 * @LastEditTime: 2019-09-27 20:06:30
 * @LastEditors: Please set LastEditors
 */
// FIle: MS_prime
#include <math.h>

bool prime(int num)
{
	int i = 2;
	for(; i <= sqrt(num); i++)
		if(num % i == 0)
			break;
	if(i <= sqrt(num))
		return false;
	else
		return true;
}
