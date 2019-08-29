// example_switch()
#include <stdio.h>

void level(float score)
{
	char level;
	if (score>=100)
		score = 99;
	switch((int)(score/10))
	{
		case 0: 
		case 1: 
		case 2: 
		case 3: 
		case 4: 
		case 5: level = 'E'; break;
		case 6: level = 'D'; break;
		case 7: level = 'C'; break;
		case 8: level = 'B'; break;
		case 9: level = 'A'; break;
	}
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
