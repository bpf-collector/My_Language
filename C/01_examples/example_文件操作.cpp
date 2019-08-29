// ex_文件操作
#include <stdio.h>
#include <stdlib.h>
#include <windows.h> 
#include <string.h>

void write (char filename[])
{
	FILE * fp = NULL;
	fp=fopen (filename, "w");
	
	if (fp == NULL)
	{
	    printf("打开文件失败！\n");
	    return;
	}
	
	int shuru;
	printf("\n请选择文本输入形式( 1.输入单个字符\t2.输入字符串\t3.输入数字 )：");
	scanf("%d", &shuru);
	
	if (shuru == 1)
	{
		char A;
		printf("请输入字符：");
		scanf("%s", &A);
		fputc(A, fp);
		
	}
	
	else if (shuru == 2)
	{
		int n = 20;
		char ch[n];
		getchar();
		printf("请输入字符串：");
		gets(ch);
		fputs (ch, fp);
	}
	
	else if (shuru == 3)
	{
		int shu;
		printf("请输入数字：");
		scanf("%d", &shu);
		fprintf (fp, "%d", shu);
		
	}
	
	else
	{ printf("\t输入错误！"); }
	
	fclose (fp);
}

void read (char filename[]) 
{
	FILE * fp = NULL;
	fp=fopen (filename, "r");
	
	if (fp == NULL)
	{
	    printf("打开文件失败！\n");
	    return;
	}
	
	int shuru;
	printf("\n请选择阅读文本形式( 1.读单个字符\t2.读字符串\t3.读数字 )：");
	scanf("%d", &shuru);
	
	if (shuru == 1)
	{
		char f;
		fscanf (fp, "%c", &f);
		printf("文件中的内容: %c", f);
	}
	
	else if (shuru == 2)
	{ 
		printf("文件中的内容: ");
		char f[40];
		fgets(f, 40, fp);
		printf("%s", f);
	}
	
	else if (shuru == 3)
	{
		int f;
		fscanf (fp, "%d", &f);
		printf("文件中的内容: %d", f);
	}
	
	else
	{ printf("\t输入错误！"); }
	
	fclose (fp);
}

void Del()
{
	system("del -Q file_made");
}

void control ()
{
	char filename[] = "file_made";
	int choose;
	printf("^^*************************************************************^^\n");
	printf("     此程序的作用如下，输入功能名称前的数字即可选择！\n\n");
	printf("\t1.写入文件\n\t2.读出文件\n");
	printf("\n\t\t请选择：");
	scanf("%d", &choose);
	printf("\n");
	
	if (choose == 1)
	{ 
		printf("\t   所选为写入文件！(仅为文本文件)\n");
		write(filename);
	}
	else if (choose == 2)
	{
		printf("\t   所选为读出文件！(仅为文本文件)\n");
		read(filename);
	}
	else 
	{ printf("输入错误！"); }
}

int main ()
{
	char n;
	do 
	{
	    control (); 
	    printf("\n\n\t是否继续？输入y继续，输入n退出！\n请输入：");
	    scanf ("%s", &n);
	    system ("cls");
	}while (n == 'y');
	Del();
	return 0;
}



 
