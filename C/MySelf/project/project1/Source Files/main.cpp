#include <stdio.h>
#include <windows.h>
#include "MySelf.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

// File: MS_LeapYear
void run_leapYear()
{
	int year;
	printf("功能：判断闰年(Judge leap year)\n");
	printf("输入：年份(Year): ");
	scanf("%d", &year);
	if(year > 0)
		if(leapYear(year))
			printf("\n结果：%d 是闰年(YES)", year);
		else
			printf("\n结果：%d 不是闰年(NO)", year);
	else
		printf("\nError: Year input");
}

// File: MS_sound
void run_sound()
{
	int Hz, time;
	printf("功能：蜂鸣器(Buzzer)\n");
	printf("输入：频率(Hz) 时间(ms)[空格分开]：");
	scanf("%d %d", &Hz, &time);
	sound(Hz, time);
}

void run_random()
{
	int num = 0, randList[100];
	printf("功能：随机数(randint)\n");
	printf("输入：随机数个数(num)：");
	scanf("%d", &num);
	random(num, randList);
	for(int i = 0; i < num; i++)
		printf("%d ", randList[i]);
}

void run_prime()
{
	int number = 0;
	printf("功能：判断素数(Judge prime)\n");;
	printf("输入：一个数字(number)：");
	scanf("%d", &number);
	if (prime(number))
		printf("\n结果：%d 是素数(YES)", number);
	else
		printf("\n结果：%d 不是素数(YES)", number);
}

void run_equation()
{
	double a, b, c;
	printf("功能：求解方程(Solve equation)[ax^2 + bx + c = 0]\n");
	printf("输入：3个系数(Input 3 parameters)[空格分开]:");
	scanf("%lf %lf %lf", &a, &b, &c);
	equation(a, b, c);
}

void run_wordsCount()
{
	char str[1024];
	printf("功能：单词计数器(Words counter)\n");
	printf("输入：请输入英文句子(Sentence in English)：");
	getchar(); gets(str);
	printf("\n结果：单词个数：%d", wordsCount(str));
}

void run_fibonacci()
{
	int n = 10;
	printf("功能：斐波那契数列(Fibonacci)\n");
	printf("输入：显示个数：");
	scanf("%d", &n);
	Fibonacci(n);
}

void run_hanio()
{
	int n;
	printf("功能：汉诺塔(Hanio)\n");
	printf("输入：汉诺塔碟子个数：");
	scanf("%d", &n);
	printf("结果：移动顺序如下：\n");
	Hanio(n, 'A', 'B', 'C');
}

void run_leastMutiple()
{
    int m = 1, n = 1;
    printf("功能：求两个整数的最小公倍数(Least comman mutiple)\n");
    printf("输入：两个整数[空格分开]：");
	scanf("%d %d", &m, &n);
    printf("\n结果：%d", Multiple(m,n));
}

void run_maximumDivisor()
{
    int m = 1, n = 1;
    printf("功能：求两个整数的最最大公约数(Maximum comman divisor)\n");
    printf("输入：两个整数[空格分开]：");
	scanf("%d %d", &m, &n);
    printf("\n结果：%d",Dividor(m,n));
}

void run_pi()
{
	printf("功能：计算Pi\n");
	printf("结果：pi = %f", Pi());
}

int menu()
{
	int choose = 0;
	system("cls");
	printf("01. 闰年        02. 蜂鸣器\n");
	printf("03. 素数        04. 随机数\n");
	printf("05. 求解方程    06. 单词计数器\n");
	printf("07. 汉诺塔      08. 斐波那契数列\n");
	printf("09. 最小公倍数  10. 最大公约数\n");
	printf("11. 计算Pi      12. ...\n");
	printf("请选择：");
	scanf("%d", &choose);
	
	return choose;
}

int main(int argc, char** argv)
{
	int choose = 0;
	do{
		choose = menu();
		printf("\n");
		switch(choose)
		{
			case -1: break;
			case 1: run_leapYear(); break;
			case 2: run_sound(); break;
			case 3: run_prime(); break;
			case 4: run_random(); break;
			case 5: run_equation(); break;
			case 6: run_wordsCount(); break;
			case 7: run_hanio(); break;
			case 8: run_fibonacci(); break;
			case 9: run_leastMutiple(); break;
			case 10: run_maximumDivisor(); break;
			case 11: run_pi(); break;
			default: printf("Error: Input out of range.");
		}
		printf("\n");
		system("pause");
	}while(choose != -1);
	
	system("pause");
	return 0;
}
