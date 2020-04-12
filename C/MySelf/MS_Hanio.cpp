/*
 * @Author: bpf
 * @Date: 2019-09-13 15:49:56
 * @LastEditTime: 2019-09-27 20:28:05
 * @Description: ººÅµËþ
 */
#include <stdio.h>

void move(char A, char B)
{
	printf("%c -> %c\n", A, B);
}
void Hanio(int n, char A, char B, char C)
{
	if(n == 1)
		move(A, C);
	else
	{
		Hanio(n-1, A, C, B);
		move(A, C);
		Hanio(n-1, B, A, C);
	}
}
