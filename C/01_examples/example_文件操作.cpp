// ex_�ļ�����
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
	    printf("���ļ�ʧ�ܣ�\n");
	    return;
	}
	
	int shuru;
	printf("\n��ѡ���ı�������ʽ( 1.���뵥���ַ�\t2.�����ַ���\t3.�������� )��");
	scanf("%d", &shuru);
	
	if (shuru == 1)
	{
		char A;
		printf("�������ַ���");
		scanf("%s", &A);
		fputc(A, fp);
		
	}
	
	else if (shuru == 2)
	{
		int n = 20;
		char ch[n];
		getchar();
		printf("�������ַ�����");
		gets(ch);
		fputs (ch, fp);
	}
	
	else if (shuru == 3)
	{
		int shu;
		printf("���������֣�");
		scanf("%d", &shu);
		fprintf (fp, "%d", shu);
		
	}
	
	else
	{ printf("\t�������"); }
	
	fclose (fp);
}

void read (char filename[]) 
{
	FILE * fp = NULL;
	fp=fopen (filename, "r");
	
	if (fp == NULL)
	{
	    printf("���ļ�ʧ�ܣ�\n");
	    return;
	}
	
	int shuru;
	printf("\n��ѡ���Ķ��ı���ʽ( 1.�������ַ�\t2.���ַ���\t3.������ )��");
	scanf("%d", &shuru);
	
	if (shuru == 1)
	{
		char f;
		fscanf (fp, "%c", &f);
		printf("�ļ��е�����: %c", f);
	}
	
	else if (shuru == 2)
	{ 
		printf("�ļ��е�����: ");
		char f[40];
		fgets(f, 40, fp);
		printf("%s", f);
	}
	
	else if (shuru == 3)
	{
		int f;
		fscanf (fp, "%d", &f);
		printf("�ļ��е�����: %d", f);
	}
	
	else
	{ printf("\t�������"); }
	
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
	printf("     �˳�����������£����빦������ǰ�����ּ���ѡ��\n\n");
	printf("\t1.д���ļ�\n\t2.�����ļ�\n");
	printf("\n\t\t��ѡ��");
	scanf("%d", &choose);
	printf("\n");
	
	if (choose == 1)
	{ 
		printf("\t   ��ѡΪд���ļ���(��Ϊ�ı��ļ�)\n");
		write(filename);
	}
	else if (choose == 2)
	{
		printf("\t   ��ѡΪ�����ļ���(��Ϊ�ı��ļ�)\n");
		read(filename);
	}
	else 
	{ printf("�������"); }
}

int main ()
{
	char n;
	do 
	{
	    control (); 
	    printf("\n\n\t�Ƿ����������y����������n�˳���\n�����룺");
	    scanf ("%s", &n);
	    system ("cls");
	}while (n == 'y');
	Del();
	return 0;
}



 
