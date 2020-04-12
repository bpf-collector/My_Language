/*
 * @Description: ����С��Ϸ
 * @Author: bpf
 * @Date: 2019-08-11 8:19:56
 * @LastEditTime: 2019-09-27 20:46:35
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include "wordGame.h"

int set_wordsNum[4] = {10, 20, 20, 20};
char set_wordsMode[4][4] = {"a", "a", "Aa", "Aa"};
char set_fileName[4][18] = {"data_Level_1.txt", "data_Level_2.txt", "data_Level_3.txt", "data_Level_4.txt"};

struct Player
{
	char userName[12];	// �û��� 
	int wordsNum;		// �ַ����� 
	char wordsMode[4];	// �ַ�ģʽ 
	float time;			// ʹ��ʱ�� 
	char date[28];		// ��ǰʱ�� 
}player;

void proBar(char sign, int sleep)
{
	/*
	fun:	��ӡ������
	:sign:	��ӡ�ķ���
	:sleep:	����ʱ�� 
	*/
	char rate[50] = "";
	for(int i = 0; i <= 50; i++)
	{
		rate[i] = sign;
		printf("��=============== ��%s��  %d%%\r", rate, i*2);
		Sleep(sleep);
	}
	printf("\n");
}

void getRandWord(int n, char *mode, char *words)
{
	/*
	fun:	��ȡn������ַ�
	:n:		����ַ��ĸ���
	:mode:	����ַ���ģʽ
	:word:	�洢����ַ�
	*/
	char ch;
	// ������������� 
	srand( (unsigned int)time(NULL) );
	if(!strcmp(mode, "a"))
		for(int i = 0; i < n; i++)
		{
			ch = rand()%26 + 97;
			//printf("%c", ch);
			*(words + i) = ch;
		}
	else if(!strcmp(mode, "A"))
		for(int i = 0; i < n; i++)
		{
			ch = rand()%26 + 65;
			//printf("%c", ch);
			*(words + i) = ch;
		}
	else if(!strcmp(mode, "Aa") || !strcmp(mode, "aA"))
		for(int i = 0; i < n; i++)
		{
			ch = rand()%52 + 65;
			if(ch > 90 && ch < 97)
				ch += 6;
			//printf("%c", ch);
			*(words + i) = ch;
		}
	else
		printf("���ַ�ģʽ���ô���\n");
}

void startGame(char *gameLevel, char *words)
{
	/*
	fun:	��ʼ��Ϸ��������Ϸ��� 
	:gameLevel:	��Ϸ�Ѷ� 
	:words:	�洢����ַ� 
	*/
	int i = 0; 
	char set_gameLevel[4][10] = {"����", "�м�", "�߼�", "�Զ���"};
	
	printf("��============================================================================��\n");
	printf("��=======================          ������Ϸ          =======================��\n");
	printf("��============================================================================��\n");
	printf("��===========================       ��Ϸ���       ===========================��\n");
	printf("��=============== ѡ����Ϸ�Ѷȣ��ڼ����ϴ����Ӧ��Ӣ���ַ������ִ���ʱ������Ϸ��\n");
	printf("��=============== ����˭���ٶȿ�ɣ�\n");
	printf("��============================================================================��\n");
	printf("��===========================       ��Ϸ�Ѷ�       ===========================��\n");
	printf("��=============== * �ͼ�\n");
	printf("��=============== ** �м�\n");
	printf("��=============== *** �߼�\n");
	printf("��=============== **** �Զ���\n");
	printf("��=============== ��ѡ��");
	scanf("%s", gameLevel);
	switch( strlen(gameLevel) )
	{
		case 1:
		case 2:
		case 3:
			printf("��===========================       ��Ϸ����       ===========================��\n");
			printf("��=============== ��Ϸ�Ѷȣ�%s\n", set_gameLevel[ strlen(gameLevel) - 1 ]);
			printf("��=============== �ַ�������%d\n", set_wordsNum[ strlen(gameLevel) - 1 ]);
			printf("��=============== �ַ�ģʽ��%s\n", set_wordsMode[ strlen(gameLevel) - 1 ]);
			break;
		case 4:
			printf("��===========================       ��Ϸ����       ===========================��\n");
			printf("��=============== ��Ϸ�Ѷȣ�%s\n", set_gameLevel[ strlen(gameLevel) - 1 ]);
			printf("��=============== �ַ�������");
			scanf("%d", &set_wordsNum[ strlen(gameLevel) - 1 ]);
			printf("��=============== �ַ�ģʽ��");
			scanf("%s", set_wordsMode[ strlen(gameLevel) - 1 ]);
			break;
	}
	printf("��===========================       ��Ϸ����       ===========================��\n");
	proBar('*', 120);
	printf("��===========================       ��Ϸ��ʼ       ===========================��\n");
	getRandWord(set_wordsNum[ strlen(gameLevel) - 1 ], set_wordsMode[ strlen(gameLevel) - 1 ], words);
	printf("��=============== ��ȡ����ַ���");
	for(i = 0; i < 3; i++)
	{
		printf(".");
		Sleep(600);
	}
	Sleep(600);
	printf(" OK!\n");
	for(i = 3; i >= 0; i--)
	{
		printf("��=============== ��Ϸ������ʼ��%d\r", i);
		Sleep(1000);
	}
	
	clock_t begin, end;
	char ch;
	bool flag = true;
	printf("��=============== ��ȡ���ַ���%s\n", words);
	printf("��=============== �������ַ���");
	begin = clock();
	for(int i = 0; i < set_wordsNum[ strlen(gameLevel) - 1 ]; i++)
	{
		ch = _getch();
		printf("%c", ch);
		if( !judgeChar(ch, i, words) )
		{
			flag = false;
			break;
		}
	}
	end = clock();
	if(flag)
		printf("\n��=============== ��ϲ��ս�ɹ����ٽ�����Ŷ��\n");
	else
		printf("\n��=============== �Ͳ�һ����ˣ��´μ���Ŷ��\n");
	printf("��=============== ��ʱ %.2f s\n", (float)(end - begin)/CLOCKS_PER_SEC );
	
	char data_S_R[2];
	int data_R_Num;
	printf("\n��=============== ��Ҫ������Ϸ������(Y/N)��");
	scanf("%s", &data_S_R);
	if(!strcmp(data_S_R, "Y") || !strcmp(data_S_R, "y"))
	{
		printf("��===========================       ��������       ===========================��\n");
		printf("��=============== �������û�����");
		scanf("%s", player.userName);
		player.wordsNum = set_wordsNum[ strlen(gameLevel) - 1 ];
		player.time = (float)(end - begin)/CLOCKS_PER_SEC;
		strcpy(player.wordsMode, set_wordsMode[ strlen(gameLevel) - 1 ]);
		
		saveData(set_fileName[ strlen(gameLevel) - 1 ]);
		Sleep(800);
		printf("\n��=============== ��Ϸ���ݱ���ɹ���\n");
	}
	printf("\n��=============== ��Ҫ��ȡ��Ϸ������(Y/N)��");
	scanf("%s", &data_S_R);
	if(!strcmp(data_S_R, "Y") || !strcmp(data_S_R, "y"))
	{
		printf("\n��=============== �������ȡ������");
		scanf("%d", &data_R_Num);
		readData(set_fileName[ strlen(gameLevel) - 1 ], data_R_Num);
	}
}

bool judgeChar(char ch, int n, char *words)
{
	/*
	fun:	�ж�������ַ��Ƿ���ȷ
	:ch: 	����ĵ����ַ�
	:n:		������ַ���λ��(-1)
	:words:	�洢����ַ�
	*/
	return ch == *(words + n);
}

void saveData(char *fileName)
{
	/*
	fun:		������Ϸ���
	:fileName:	������ļ��� 
	*/
	FILE * fp = fopen(fileName, "a");
	if(fp == NULL)
	{
		printf("��=============== �ļ���ʧ�ܣ�\n");
		initFile(fileName); 
	}
	else
	{
		time_t cTime;
		time(&cTime);
		strcpy(player.date, ctime(&cTime));
		fprintf(fp, "|%12s|%4d|%4s|%6.2f|%28s", player.userName, player.wordsNum, player.wordsMode, player.time, player.date);
	}
	fclose(fp);
}

void readData(char *fileName, int N)
{
	/*
	fun:		��ȡ��Ϸ���
	:fileName:	������ļ��� 
	:N:			��ȡ���ݵĸ��� 
	*/
	char tmp[60];
	FILE *fp = fopen(fileName, "r");
	if(fp == NULL)
	{
		printf("��=============== �ļ���ʧ�ܣ�\n");
		initFile(fileName); 
	}
	else
	{
		for(int i = 0; i < N; i++)
		{
			memset(tmp, 0, 60);
			fgets(tmp, 60, fp);
			printf("%s\n", tmp);
		}
	}
	fclose(fp);
}

void printMenu() 
{
	/*
	fun:	��ӡ�˵��� 
	*/
	printf("��============================================================================��\n");
	printf("��=======================           ~WELCOME~          =======================��\n");
	printf("��============================================================================��\n");
	printf("��=============== * ��ʼ��Ϸ\n");
	printf("��=============== ** �鿴����\n");
	printf("��=============== *** ��Ϸ����\n");
	printf("��=============== **** �˵�\n");
}

void MainProcess()
{
	printMenu();
	char choose[5] = "";
	
	while(1)
	{
		printf("\n��=============== �˵���ѡ��");
		scanf("%s", choose);
		switch( strlen(choose) )
		{
			case 1:
				char words[100], gameLevel[5];
				memset(words, 0, 100);
				system("cls");
				startGame(gameLevel, words);
				printMenu();
				break;
			case 2:
				char readType[8];
				memset(readType, 0, 8);
				int data_R_Num;
				printf("��===========================       ��Ϸ����       ===========================��\n");
				printf("��=============== * ����\n");
				printf("��=============== ** �м�\n");
				printf("��=============== *** �߼�\n");
				printf("��=============== **** �Զ���\n");
				printf("��=============== ������鿴���ͣ�");
				scanf("%s", readType);
				printf("\n��=============== �������ȡ������");
				scanf("%d", &data_R_Num);
				readData(set_fileName[ strlen(readType) - 1 ], data_R_Num);
				break;
			case 3:
				printf("��===========================       ��Ϸ����       ===========================��\n");
				printf("��=============== �汾��1.0.0\n");
				printf("��=============== ���ڣ�2019.8.11\n");
				printf("��=============== ���ߣ�@ bpf\n");
				break;
			case 4:
				system("cls");
				printMenu();
				break;
		}
	}
	
}

void initFile(char *fileName)
{
	/*
	fun:		�ļ�������ʱ����
	:fileName:	�ļ��� 
	*/
	FILE * fp = fopen(fileName, "w");
	fclose(fp);
}

int main()
{
	MainProcess();
	return 0;
}
