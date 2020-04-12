#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// �ж�num�Ƿ�Ϊ����: ���򷵻�true, ���򷵻�false 
bool isPrime(const int num)
{
	if(num < 2)
		return false;
	for(int i = 2; i < (int)sqrt(num) + 1; i++)
		if(num % i == 0)
			return false;
	return true;
}

// ����start��ʼ����end�����������в�����������������primes[]�У���0Ԫ��Ϊ��β 
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

// ������nums[]��ǰn��Ԫ���в�����������������primes[]�У���0Ԫ��Ϊ��β 
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

// ����ǰ2�������õ�������(��0Ԫ�ؽ���)������� 
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
