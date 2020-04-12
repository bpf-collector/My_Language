/*
 * @Author: bpf
 * @Date: 2019-09-13 15:49:56
 * @LastEditTime: 2019-09-27 20:26:21
 * @Description: Count words of a centences which in English
 */
#include <stdio.h>

int wordsCount(char *str)
{
	int word = 0, sum = 0, i = 0;
	char c;
	for (i = 0; (c = str[i]) != '\0'; i++)
	{
		if (c == ' ' || c == ',' || c == '.' || c == '?' || c == '!')
			word = 0;
		else if (word == 0)
		{
			word = 1;
			sum++;
		}
	}
	return sum;
}
