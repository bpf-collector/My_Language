// example_if()
#include <stdio.h>

void level(float score)
{
	char level;
	if (score<60)
		level = 'E';
	else if (score<70)
		level = 'D';
	else if (score<80)
		level = 'C';
	else if (score<90)
		level = 'B';
	else
		level = 'A';
	printf("Your level is: %c\n",level);
}
int main()
{
	float score;
	printf("\tThis application will give you a level which depends on your score.\n");
	printf("Please enter your score:");
	scanf("%f",&score);
	if (score < 0)
		printf("\n\t\tData enter error!\n");
	else
		level(score);
	return 0;
}
