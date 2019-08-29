// ex_��������
#include <stdio.h>
//��������
void student_average(float score[][5], float average[], int student, int subject); // ����ѧ���ɼ�ƽ����
void subject_average(float score[][5], float average[], int student, int subject); // �����Ŀ�ɼ�ƽ����
void max_score(float score[][5], int student,int subject); // �����߷�
double average_variance(float average[], int student);     // ����ƽ���ַ���
void print_num(float date[], int n);    // �������

int main()
{
	float score[10][5],stu_average[10],sub_average[5];
							// score[][] �洢ѧ���ɼ���stu_average[] �洢ѧ��ƽ���֣�sub_average[] �洢��Ŀƽ����

	int i,j,M,C=5;   // M ��ʾѧ������; C ��ʾ�γ���Ŀ

	printf("������ѧ������(Ĭ��Ϊ5�ſ�)��");    // ����ѧ������
	scanf("%d",&M);

	for(i=0;i<M;i++)  // �������ѧ���ĳɼ�
	{
		printf("NO.%d:",i+1);
		for(j=0;j<C;j++)
			scanf("%f",&score[i][j]);
	}

	student_average(score,stu_average,M,C);  // ���ú���������ѧ���ɼ�ƽ����
	printf("\nstudent average score:");
	print_num(stu_average,M);                // ���ú��������ѧ���ɼ�ƽ����


	subject_average(score,sub_average,M,C);  // ���ú����������Ŀ�ɼ�ƽ����
	printf("\n\nsubject average score:");
	print_num(sub_average,C);                // ���ú����������Ŀ�ɼ�ƽ����


	max_score(score,M,C);                    // ���ú����������߷�
	

	putchar('\n');
	double variance = average_variance(stu_average,M);   // ���ú���������ƽ���ַ���
	printf("average variance=%.2f\n",variance);
	
	return 0;
}

void student_average(float score[][5],float average[],int student,int subject)  // ����ѧ���ɼ�ƽ����
{
	int i,j;
	float sum;  // sum ���
	for(i=0;i<student;i++)
	{
		for(j=0,sum=0;j<subject;j++)
			sum += score[i][j];
		average[i] = sum / subject;  // average[] ������ѧ����ƽ����
	}
}

void subject_average(float score[][5],float average[],int student,int subject)  // �����Ŀ�ɼ�ƽ����
{
	int i,j;
	float sum;  // sum ���
	for(j=0;j<subject;j++)
	{
		for(i=0,sum=0;i<student;i++)
			sum += score[i][j];
		average[j] = sum / student;  // average[] �����ſ�Ŀ��ƽ����
	}
}

void max_score(float score[][5],int student,int subject)  // �����߷�
{
	int i,j,max_stu,max_sub;
	float Max=0;              // Max ��¼��߷�,max_stu ��¼��߷ֶ�Ӧ��ѧ��,max_sub ��¼��߷ֶ�Ӧ�Ŀ�Ŀ
	for(i=0;i<student;i++)
		for(j=0;j<subject;j++)
			if(score[i][j]>Max)
			{
				Max = score[i][j];
				max_stu = i;
				max_sub = j;
			}
	printf("\n\nscore[%d][%d] = %.1f is the highest.\n", max_stu+1, max_sub+1, score[max_stu][max_sub]);
}

double average_variance(float average[], int student)  // ����ƽ���ַ���
{
	double sum1 = 0, sum2 = 0;  // sum1 �����һ�����(��ƽ��)��sum2 ����ڶ������
	for(int i=0; i<student; i++)
	{
		sum1 += average[i] * average[i];
		sum2 += average[i];
	}
	return ( sum1 / student - (sum2 / student) * (sum2 / student) );
}

void print_num(float date[], int n)
{
	int i;
	for(i=0; i<n; i++)
		printf("%.1f  ", date[i]);
}
