/*
#include <stdlib.h>
atoi(str):	扫描字符串，跳过空格，从数字或正负号开始，非数字或结束字符结束，转换为int
atof(str):	扫描字符串，跳过空格，从数字或正负号开始，非数字或结束字符结束，转换为float
atol(str):	扫描字符串，跳过空格，从数字或正负号开始，非数字或结束字符结束，转换为long
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
