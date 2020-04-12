#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 判断num是否为素数: 是则返回true, 否则返回false 
int isPrime(const int num)
{
	int i = 2;
	if(num < 2)
		return 0;
	while(i <= (int)sqrt(num))
	{
		if(num % i == 0)
			return 0;
		i++;
	}
	return 1;
}

// 从以start开始，以end结束的数组中查找素数，并保存在primes[]中，以0元素为结尾 
void getPrime(int primes[], const int start, const int end, const int step)
{
	int k = 0;
	int i = start;
	while(i <= end)
	{
		if(isPrime(i))
		{
			primes[k] = i;
			k++;
		}
		i++;
	}
	primes[k] = 0;
}
void printPrime(const int primes[]);
// 在数组nums[]的前n个元素中查找素数，并保存在primes[]中，以0元素为结尾 
void findPrime(const int nums[], const int n, int primes[])
{
	printf("C: nums: ");
	printPrime(nums);
	int k = 0, i = 0;
	while(i < n)
	{
		if(isPrime(nums[i]))
		{
			primes[k] = nums[i];
			k++;
		}
		i++;
	}
	primes[k] = 0;
	printf("C: primes: ");
	printPrime(primes);
}

// 按照前2个函数得到的数组(以0元素结束)输出素数 
void printPrime(const int primes[])
{
	int i = 0;
	while(primes[i] != 0)
	{
		printf("%d ", primes[i]);
		i++;
	}
	printf("\n");
}

void test()
{
	printf("Hello bpf!\n");
}

int main()
{
	int c[] = {0, 1, 2, 3 ,4, 5}, p[10];
	findPrime(c, 6, p);
	printPrime(p);
	
	return 0;
}
