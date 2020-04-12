/*
 * @Description: 打字小游戏
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
	char userName[12];	// 用户名 
	int wordsNum;		// 字符个数 
	char wordsMode[4];	// 字符模式 
	float time;			// 使用时间 
	char date[28];		// 当前时间 
}player;

void proBar(char sign, int sleep)
{
	/*
	fun:	打印进度条
	:sign:	打印的符号
	:sleep:	休眠时间 
	*/
	char rate[50] = "";
	for(int i = 0; i <= 50; i++)
	{
		rate[i] = sign;
		printf("！=============== 【%s】  %d%%\r", rate, i*2);
		Sleep(sleep);
	}
	printf("\n");
}

void getRandWord(int n, char *mode, char *words)
{
	/*
	fun:	获取n个随机字符
	:n:		随机字符的个数
	:mode:	随机字符的模式
	:word:	存储随机字符
	*/
	char ch;
	// 设置随机数种子 
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
		printf("！字符模式设置错误！\n");
}

void startGame(char *gameLevel, char *words)
{
	/*
	fun:	开始游戏，保存游戏结果 
	:gameLevel:	游戏难度 
	:words:	存储随机字符 
	*/
	int i = 0; 
	char set_gameLevel[4][10] = {"初级", "中级", "高级", "自定义"};
	
	printf("！============================================================================！\n");
	printf("！=======================          打字游戏          =======================！\n");
	printf("！============================================================================！\n");
	printf("！===========================       游戏简介       ===========================！\n");
	printf("！=============== 选择游戏难度，在键盘上打出对应的英文字符，出现错误时结束游戏。\n");
	printf("！=============== 看看谁的速度快吧！\n");
	printf("！============================================================================！\n");
	printf("！===========================       游戏难度       ===========================！\n");
	printf("！=============== * 低级\n");
	printf("！=============== ** 中级\n");
	printf("！=============== *** 高级\n");
	printf("！=============== **** 自定义\n");
	printf("！=============== 请选择：");
	scanf("%s", gameLevel);
	switch( strlen(gameLevel) )
	{
		case 1:
		case 2:
		case 3:
			printf("！===========================       游戏设置       ===========================！\n");
			printf("！=============== 游戏难度：%s\n", set_gameLevel[ strlen(gameLevel) - 1 ]);
			printf("！=============== 字符个数：%d\n", set_wordsNum[ strlen(gameLevel) - 1 ]);
			printf("！=============== 字符模式：%s\n", set_wordsMode[ strlen(gameLevel) - 1 ]);
			break;
		case 4:
			printf("！===========================       游戏设置       ===========================！\n");
			printf("！=============== 游戏难度：%s\n", set_gameLevel[ strlen(gameLevel) - 1 ]);
			printf("！=============== 字符个数：");
			scanf("%d", &set_wordsNum[ strlen(gameLevel) - 1 ]);
			printf("！=============== 字符模式：");
			scanf("%s", set_wordsMode[ strlen(gameLevel) - 1 ]);
			break;
	}
	printf("！===========================       游戏加载       ===========================！\n");
	proBar('*', 120);
	printf("！===========================       游戏开始       ===========================！\n");
	getRandWord(set_wordsNum[ strlen(gameLevel) - 1 ], set_wordsMode[ strlen(gameLevel) - 1 ], words);
	printf("！=============== 获取随机字符中");
	for(i = 0; i < 3; i++)
	{
		printf(".");
		Sleep(600);
	}
	Sleep(600);
	printf(" OK!\n");
	for(i = 3; i >= 0; i--)
	{
		printf("！=============== 游戏即将开始：%d\r", i);
		Sleep(1000);
	}
	
	clock_t begin, end;
	char ch;
	bool flag = true;
	printf("！=============== 获取的字符：%s\n", words);
	printf("！=============== 请输入字符：");
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
		printf("\n！=============== 恭喜挑战成功，再接再励哦！\n");
	else
		printf("\n！=============== 就差一点点了！下次加油哦！\n");
	printf("！=============== 用时 %.2f s\n", (float)(end - begin)/CLOCKS_PER_SEC );
	
	char data_S_R[2];
	int data_R_Num;
	printf("\n！=============== 想要保存游戏数据吗(Y/N)？");
	scanf("%s", &data_S_R);
	if(!strcmp(data_S_R, "Y") || !strcmp(data_S_R, "y"))
	{
		printf("！===========================       保存数据       ===========================！\n");
		printf("！=============== 请输入用户名：");
		scanf("%s", player.userName);
		player.wordsNum = set_wordsNum[ strlen(gameLevel) - 1 ];
		player.time = (float)(end - begin)/CLOCKS_PER_SEC;
		strcpy(player.wordsMode, set_wordsMode[ strlen(gameLevel) - 1 ]);
		
		saveData(set_fileName[ strlen(gameLevel) - 1 ]);
		Sleep(800);
		printf("\n！=============== 游戏数据保存成功！\n");
	}
	printf("\n！=============== 想要读取游戏数据吗(Y/N)？");
	scanf("%s", &data_S_R);
	if(!strcmp(data_S_R, "Y") || !strcmp(data_S_R, "y"))
	{
		printf("\n！=============== 请输入读取个数：");
		scanf("%d", &data_R_Num);
		readData(set_fileName[ strlen(gameLevel) - 1 ], data_R_Num);
	}
}

bool judgeChar(char ch, int n, char *words)
{
	/*
	fun:	判断输入的字符是否正确
	:ch: 	输入的单个字符
	:n:		输入的字符的位置(-1)
	:words:	存储随机字符
	*/
	return ch == *(words + n);
}

void saveData(char *fileName)
{
	/*
	fun:		保存游戏结果
	:fileName:	保存的文件名 
	*/
	FILE * fp = fopen(fileName, "a");
	if(fp == NULL)
	{
		printf("！=============== 文件打开失败！\n");
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
	fun:		读取游戏结果
	:fileName:	保存的文件名 
	:N:			读取数据的个数 
	*/
	char tmp[60];
	FILE *fp = fopen(fileName, "r");
	if(fp == NULL)
	{
		printf("！=============== 文件打开失败！\n");
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
	fun:	打印菜单栏 
	*/
	printf("！============================================================================！\n");
	printf("！=======================           ~WELCOME~          =======================！\n");
	printf("！============================================================================！\n");
	printf("！=============== * 开始游戏\n");
	printf("！=============== ** 查看排名\n");
	printf("！=============== *** 游戏详情\n");
	printf("！=============== **** 菜单\n");
}

void MainProcess()
{
	printMenu();
	char choose[5] = "";
	
	while(1)
	{
		printf("\n！=============== 菜单请选择：");
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
				printf("！===========================       游戏排名       ===========================！\n");
				printf("！=============== * 初级\n");
				printf("！=============== ** 中级\n");
				printf("！=============== *** 高级\n");
				printf("！=============== **** 自定义\n");
				printf("！=============== 请输入查看类型：");
				scanf("%s", readType);
				printf("\n！=============== 请输入读取个数：");
				scanf("%d", &data_R_Num);
				readData(set_fileName[ strlen(readType) - 1 ], data_R_Num);
				break;
			case 3:
				printf("！===========================       游戏详情       ===========================！\n");
				printf("！=============== 版本：1.0.0\n");
				printf("！=============== 日期：2019.8.11\n");
				printf("！=============== 作者：@ bpf\n");
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
	fun:		文件不存在时创建
	:fileName:	文件名 
	*/
	FILE * fp = fopen(fileName, "w");
	fclose(fp);
}

int main()
{
	MainProcess();
	return 0;
}
