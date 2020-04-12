#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 判断num是否为素数: 是则返回true, 否则返回false 
bool isPrime(const int num)
{
	if(num < 2)
		return false;
	for(int i = 2; i < (int)sqrt(num) + 1; i++)
		if(num % i == 0)
			return false;
	return true;
}

// 从以start开始，以end结束的数组中查找素数，并保存在primes[]中，以0元素为结尾 
void getPrime(int primes[], const int start, const int end, const int step = 1)
{
	int k = 0;
	for(int i = start; i <= end; i++)
		if(isPrime(i))
		{
			primes[k] = i;
			k++;
		}
	primes[k] = 0;
}

// 在数组nums[]的前n个元素中查找素数，并保存在primes[]中，以0元素为结尾 
void findPrime(const int nums[], const int n, int primes[])
{
	int k = 0;
	for(int i = 0; i < n; i++)
		if(isPrime(nums[i]))
		{
			primes[k] = nums[i];
			k++;
		}
	primes[k] = 0;
}

// 按照前2个函数得到的数组(以0元素结束)输出素数 
void printPrime(const int primes[])
{
	for(int i = 0; primes[i] != 0; i++)
		printf("%d ", primes[i]);
	printf("\n");
}

void test()
{
	printf("Hello bpf!\n");
}
