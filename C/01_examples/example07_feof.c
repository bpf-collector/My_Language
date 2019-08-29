/* feof(FILE *fp): ���fp�Ƿ�Ϊ�ļ���β 
	���֮ǰ�����ȶ�ȡ������⵱ǰ��ȡ���ַ��Ƿ�Ϊ�ļ��������� */
#include <stdio.h>
#include <windows.h>

void createFile(char *fileName)
{
	FILE *fp = fopen(fileName, "w");
	fclose(fp);
}

void writeFile(char *fileName, char *text)
{
	FILE *fp = fopen(fileName, "w");
	fprintf(fp, "%s", text);
	fclose(fp);
}

void readFile(char *fileName)
{
	char tmp;
	FILE *fp = fopen(fileName, "r");
	if(fp == NULL)
		printf("�ļ������ڣ�\n");
	while(1)
	{
		printf("%c ", fgetc(fp));
		if(feof(fp))
			break;
	}
	fclose(fp);
}

void deleteFile(char *fileName)
{
	char tmp[20];
	sprintf(tmp, "del %s", fileName);
	system(tmp);
}

void run()
{
	char fileName[] = "example_feof_text.txt";
	char text[] = "abcdefg";
	createFile(fileName);
	writeFile(fileName, text);
	readFile(fileName);
	deleteFile(fileName);
}
