// File: MS_Hanio[ººÅµËþ]
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
