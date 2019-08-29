// ex_函数调用
#include <stdio.h>
//函数声明
void student_average(float score[][5], float average[], int student, int subject); // 计算学生成绩平均数
void subject_average(float score[][5], float average[], int student, int subject); // 计算科目成绩平均数
void max_score(float score[][5], int student,int subject); // 求出最高分
double average_variance(float average[], int student);     // 计算平均分方差
void print_num(float date[], int n);    // 输出数据

int main()
{
	float score[10][5],stu_average[10],sub_average[5];
							// score[][] 存储学生成绩，stu_average[] 存储学生平均分，sub_average[] 存储科目平均分

	int i,j,M,C=5;   // M 表示学生人数; C 表示课程数目

	printf("请输入学生人数(默认为5门课)：");    // 输入学生人数
	scanf("%d",&M);

	for(i=0;i<M;i++)  // 输入各个学生的成绩
	{
		printf("NO.%d:",i+1);
		for(j=0;j<C;j++)
			scanf("%f",&score[i][j]);
	}

	student_average(score,stu_average,M,C);  // 调用函数，计算学生成绩平均数
	printf("\nstudent average score:");
	print_num(stu_average,M);                // 调用函数，输出学生成绩平均数


	subject_average(score,sub_average,M,C);  // 调用函数，计算科目成绩平均数
	printf("\n\nsubject average score:");
	print_num(sub_average,C);                // 调用函数，输出科目成绩平均数


	max_score(score,M,C);                    // 调用函数，求出最高分
	

	putchar('\n');
	double variance = average_variance(stu_average,M);   // 调用函数，计算平均分方差
	printf("average variance=%.2f\n",variance);
	
	return 0;
}

void student_average(float score[][5],float average[],int student,int subject)  // 计算学生成绩平均数
{
	int i,j;
	float sum;  // sum 求和
	for(i=0;i<student;i++)
	{
		for(j=0,sum=0;j<subject;j++)
			sum += score[i][j];
		average[i] = sum / subject;  // average[] 数组存放学生的平均数
	}
}

void subject_average(float score[][5],float average[],int student,int subject)  // 计算科目成绩平均数
{
	int i,j;
	float sum;  // sum 求和
	for(j=0;j<subject;j++)
	{
		for(i=0,sum=0;i<student;i++)
			sum += score[i][j];
		average[j] = sum / student;  // average[] 数组存放科目的平均数
	}
}

void max_score(float score[][5],int student,int subject)  // 求出最高分
{
	int i,j,max_stu,max_sub;
	float Max=0;              // Max 记录最高分,max_stu 记录最高分对应的学生,max_sub 记录最高分对应的科目
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

double average_variance(float average[], int student)  // 计算平均分方差
{
	double sum1 = 0, sum2 = 0;  // sum1 求出第一个求和(含平方)，sum2 求出第二个求和
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
