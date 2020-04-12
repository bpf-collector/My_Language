// File: MS_wordsCount
#include <stdio.h>

int wordsCount(char *str)
{
	int word = 0, sum = 0;
	char c;
	for(int i=0; (c=str[i])!='\0'; i++)
	{
		if(c == ' ' || c == ',' || c == '.' || c == '?' || c == '!')
			word = 0;
		else if(word == 0)
		{
			word = 1;
			sum++;
		}
	}
	return sum;
}
