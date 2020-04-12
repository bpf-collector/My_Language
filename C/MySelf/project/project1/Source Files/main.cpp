#include <stdio.h>
#include <windows.h>
#include "MySelf.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

// File: MS_LeapYear
void run_leapYear()
{
	int year;
	printf("���ܣ��ж�����(Judge leap year)\n");
	printf("���룺���(Year): ");
	scanf("%d", &year);
	if(year > 0)
		if(leapYear(year))
			printf("\n�����%d ������(YES)", year);
		else
			printf("\n�����%d ��������(NO)", year);
	else
		printf("\nError: Year input");
}

// File: MS_sound
void run_sound()
{
	int Hz, time;
	printf("���ܣ�������(Buzzer)\n");
	printf("���룺Ƶ��(Hz) ʱ��(ms)[�ո�ֿ�]��");
	scanf("%d %d", &Hz, &time);
	sound(Hz, time);
}

void run_random()
{
	int num = 0, randList[100];
	printf("���ܣ������(randint)\n");
	printf("���룺���������(num)��");
	scanf("%d", &num);
	random(num, randList);
	for(int i = 0; i < num; i++)
		printf("%d ", randList[i]);
}

void run_prime()
{
	int number = 0;
	printf("���ܣ��ж�����(Judge prime)\n");;
	printf("���룺һ������(number)��");
	scanf("%d", &number);
	if (prime(number))
		printf("\n�����%d ������(YES)", number);
	else
		printf("\n�����%d ��������(YES)", number);
}

void run_equation()
{
	double a, b, c;
	printf("���ܣ���ⷽ��(Solve equation)[ax^2 + bx + c = 0]\n");
	printf("���룺3��ϵ��(Input 3 parameters)[�ո�ֿ�]:");
	scanf("%lf %lf %lf", &a, &b, &c);
	equation(a, b, c);
}

void run_wordsCount()
{
	char str[1024];
	printf("���ܣ����ʼ�����(Words counter)\n");
	printf("���룺������Ӣ�ľ���(Sentence in English)��");
	getchar(); gets(str);
	printf("\n��������ʸ�����%d", wordsCount(str));
}

void run_fibonacci()
{
	int n = 10;
	printf("���ܣ�쳲���������(Fibonacci)\n");
	printf("���룺��ʾ������");
	scanf("%d", &n);
	Fibonacci(n);
}

void run_hanio()
{
	int n;
	printf("���ܣ���ŵ��(Hanio)\n");
	printf("���룺��ŵ�����Ӹ�����");
	scanf("%d", &n);
	printf("������ƶ�˳�����£�\n");
	Hanio(n, 'A', 'B', 'C');
}

void run_leastMutiple()
{
    int m = 1, n = 1;
    printf("���ܣ���������������С������(Least comman mutiple)\n");
    printf("���룺��������[�ո�ֿ�]��");
	scanf("%d %d", &m, &n);
    printf("\n�����%d", Multiple(m,n));
}

void run_maximumDivisor()
{
    int m = 1, n = 1;
    printf("���ܣ������������������Լ��(Maximum comman divisor)\n");
    printf("���룺��������[�ո�ֿ�]��");
	scanf("%d %d", &m, &n);
    printf("\n�����%d",Dividor(m,n));
}

void run_pi()
{
	printf("���ܣ�����Pi\n");
	printf("�����pi = %f", Pi());
}

int menu()
{
	int choose = 0;
	system("cls");
	printf("01. ����        02. ������\n");
	printf("03. ����        04. �����\n");
	printf("05. ��ⷽ��    06. ���ʼ�����\n");
	printf("07. ��ŵ��      08. 쳲���������\n");
	printf("09. ��С������  10. ���Լ��\n");
	printf("11. ����Pi      12. ...\n");
	printf("��ѡ��");
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
