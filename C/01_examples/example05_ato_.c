/*
#include <stdlib.h>
atoi(str):	ɨ���ַ����������ո񣬴����ֻ������ſ�ʼ�������ֻ�����ַ�������ת��Ϊint
atof(str):	ɨ���ַ����������ո񣬴����ֻ������ſ�ʼ�������ֻ�����ַ�������ת��Ϊfloat
atol(str):	ɨ���ַ����������ո񣬴����ֻ������ſ�ʼ�������ֻ�����ַ�������ת��Ϊlong
*/

#include <stdio.h>
#include <stdlib.h>
void fun_ato_()
{
	char qq[] = "    1566780663@qq.com";
	char price[] = "    198.98  Yuan  ";
	char id[] = "    2018310143       ";
	
	printf("QQ: %d\n", atoi(qq));
	printf("Price: %f\n", atof(price));
	printf("ID: %ld\n", atol(id));
}

void run()
{
	fun_ato_();
} 
